//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<signal.h>
#include<fcntl.h>

#define BUFSIZE 4096

// Function to recursively handle requests and responses
void recursive_proxy(int browser_sockfd, struct sockaddr_in addr, int addr_len) {
    char buffer[BUFSIZE]; 
    memset(buffer, 0, BUFSIZE);
    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_sockfd < 0) {
        perror("Error: Could not create server socket!"); 
        return; 
    }
    if(connect(server_sockfd, (struct sockaddr*)&addr, addr_len) < 0) {
        perror("Error: Could not connect to server!"); 
        return; 
    }

    fd_set read_set;
    FD_ZERO(&read_set);
    FD_SET(browser_sockfd, &read_set); 
    FD_SET(server_sockfd, &read_set);

    int max_fd = (browser_sockfd > server_sockfd) ? browser_sockfd : server_sockfd;

    while(1) {
        if(select(max_fd + 1, &read_set, NULL, NULL, NULL) < 0) {
            perror("Error: Could not select sockets"); 
            break; 
        }
        if(FD_ISSET(browser_sockfd, &read_set)) {
            int nread = recv(browser_sockfd, buffer, BUFSIZE - 1, 0);
            if(nread < 0) {
                perror("Error: Could not read from browser socket"); 
                break; 
            }
            if(nread == 0) {
                printf("End of file from browser socket\n"); 
                break; 
            }
            buffer[nread] = '\0';
            printf("Received %d bytes from browser\n", nread); 

            if(send(server_sockfd, buffer, nread, 0) < 0) {
                perror("Error: Could not send request to server"); 
                break; 
            }
        }

        if(FD_ISSET(server_sockfd, &read_set)) {
            int nread = recv(server_sockfd, buffer, BUFSIZE - 1, 0);
            if(nread < 0) {
                perror("Error: Could not read from server socket"); 
                break; 
            }
            if(nread == 0) {
                printf("End of file from server socket\n"); 
                break; 
            }
            buffer[nread] = '\0';
            printf("Received %d bytes from server\n", nread); 

            if(send(browser_sockfd, buffer, nread, 0) < 0) {
                perror("Error: Could not send response to browser"); 
                break; 
            }
        }
    } 
    close(browser_sockfd); 
    close(server_sockfd);
}

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Usage: %s <port>\n", argv[0]); 
        exit(EXIT_FAILURE); 
    }
    int port = atoi(argv[1]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error: Could not create socket!"); 
        exit(EXIT_FAILURE); 
    } 
    int opt = 1;
    if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("Error: Could not set socket options!"); 
        exit(EXIT_FAILURE); 
    } 
    struct sockaddr_in server_addr, browser_addr; 
    server_addr.sin_family = AF_INET; 
    server_addr.sin_addr.s_addr = INADDR_ANY; 
    server_addr.sin_port = htons(port); 

    if(bind(sockfd, (const struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error: Could not bind!"); 
        exit(EXIT_FAILURE); 
    }
    if(listen(sockfd, SOMAXCONN) < 0) {
        perror("Error: Could not listen!"); 
        exit(EXIT_FAILURE); 
    }

    while(1) {
        socklen_t addr_len = sizeof(browser_addr);
        int browser_sockfd = accept(sockfd, (struct sockaddr *)&browser_addr, &addr_len);
        if(browser_sockfd < 0) {
            perror("Error: Could not accept!"); 
            continue; 
        } 
        printf("Accepted connection from %s:%d\n", inet_ntoa(browser_addr.sin_addr), ntohs(browser_addr.sin_port)); 

        // The target address will be localhost:8080
        struct sockaddr_in target_addr;
        memset(&target_addr, 0, sizeof(target_addr));
        target_addr.sin_family = AF_INET;
        target_addr.sin_port = htons(8080);
        inet_pton(AF_INET, "127.0.0.1", &target_addr.sin_addr.s_addr);

        recursive_proxy(browser_sockfd, target_addr, sizeof(target_addr)); 
    } 
    close(sockfd); 
    return 0; 
}