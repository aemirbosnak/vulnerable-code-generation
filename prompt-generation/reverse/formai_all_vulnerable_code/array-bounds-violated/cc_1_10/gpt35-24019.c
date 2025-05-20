//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 1234

int main() {
    int sockfd, connected, bytes_recv, true = 1;
    char recv_data[1024], send_data[1024];
    struct sockaddr_in server_addr, client_addr;
    int sin_size;

    printf("\n **** I am a TCP/IP chatbot ****\n");

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    // set socket options
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &true, sizeof(int)) == -1) {
        perror("Socket options setting failed");
        exit(1);
    }

    // set server address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(server_addr.sin_zero), 8);

    // bind socket to server address and port
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("Socket binding failed");
        exit(1);
    }

    // listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("Socket listening failed");
        exit(1);
    }

    // accept incoming connections
    sin_size = sizeof(struct sockaddr_in);
    connected = accept(sockfd, (struct sockaddr*)&client_addr, &sin_size);
    printf("Client (%s) is now connected.\n", inet_ntoa(client_addr.sin_addr));

    while (1) {
        // receive message from client
        bytes_recv = recv(connected, recv_data, 1024, 0);
        recv_data[bytes_recv] = '\0';

        if (strcmp(recv_data, "quit") == 0) {
            printf("Client has disconnected.\n");
            close(connected);
            break;
        }
    
        printf("Client: %s", recv_data);

        // get message from user
        fgets(send_data, 1024, stdin);
    
        // send message to client
        if (send(connected, send_data, strlen(send_data), 0) == -1) {
            perror("Socket sending failed");
            close(connected);
            exit(1);
        }
    }

    close(sockfd);
    return 0;
}