//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define HTTP_PORT "80"
#define BACKLOG 10

// function to get sockaddr, IPv4 or IPv6
void *get_in_addr(struct sockaddr *sa) {
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }
    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

// main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: proxy <port>\n");
        return 1;
    }
    
    int sockfd, new_fd;
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_storage their_addr;
    socklen_t sin_size;
    int yes = 1;
    char s[INET6_ADDRSTRLEN];
    int rv;
    char buf[512];
    char method[10], url[200], version[10], host[50], path[100], request[512];
    
    // set up hints struct
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    
    // getaddrinfo
    if ((rv = getaddrinfo(NULL, argv[1], &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }
    
    // loop through all results and bind to first one possible
    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("proxy: socket");
            continue;
        }
        
        // set SO_REUSEADDR
        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
            perror("proxy: setsockopt");
            exit(1);
        }
        
        if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("proxy: bind");
            continue;
        }
        
        break;
    }
    
    // if not bound exit
    if (p == NULL) {
        fprintf(stderr, "proxy: failed to bind\n");
        return 2;
    }
    
    // free servinfo;
    freeaddrinfo(servinfo);
    
    // listen
    if (listen(sockfd, BACKLOG) == -1) {
        perror("proxy: listen");
        exit(1);
    }
    
    printf("proxy: waiting for connections...\n");
    
    while(1) {  // main accept() loop
        sin_size = sizeof their_addr;
        new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
        if (new_fd == -1) {
            perror("proxy: accept");
            continue;
        }
        inet_ntop(their_addr.ss_family, get_in_addr((struct sockaddr *)&their_addr), s, sizeof s);
        printf("proxy: got connection from %s\n", s);
        
        if (!fork()) {  // this is the child process
            close(sockfd); // child doesn't need the listener
            
            // read from client (browser)
            if (recv(new_fd, buf, sizeof buf, 0) == -1) {
                perror("recv");
                exit(1);
            }
            
            printf("%s\n", buf);
            
            sscanf(buf, "%s %s %s\n", method, url, version);
            
            // get host & path
            if (strncmp(url, "http://", 7) == 0) {
                strcpy(url, url + 7);
            }
            sscanf(url, "%[^/]/%s", host, path);
            
            // build new request
            sprintf(request, "%s /%s %s\r\nHost: %s\r\nConnection: close\r\n\r\n", method, path, version, host);
            
            printf("%s\n", request);
            
            // set up hints struct for getaddrinfo
            memset(&hints, 0, sizeof hints);
            hints.ai_family = AF_UNSPEC;
            hints.ai_socktype = SOCK_STREAM;
            
            // getaddrinfo
            if ((rv = getaddrinfo(host, HTTP_PORT, &hints, &servinfo)) != 0) {
                fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
                exit(1);
            }
            
            // loop through all results and connect to first one possible
            for (p = servinfo; p != NULL; p = p->ai_next) {
                if ((new_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
                    perror("proxy: socket");
                    continue;
                }
                
                if (connect(new_fd, p->ai_addr, p->ai_addrlen) == -1) {
                    close(new_fd);
                    perror("proxy: connect");
                    continue;
                }
                
                break;
            }
            
            // if not connected exit
            if (p == NULL) {
                fprintf(stderr, "proxy: failed to connect\n");
                exit(2);
            }
            
            freeaddrinfo(servinfo); // all done with this structure
            
            // send request to server
            if (send(new_fd, request, strlen(request), 0) == -1) {
                perror("proxy: send");
                exit(1);
            }
            
            // read from server and send to client
            while (recv(new_fd, buf, sizeof buf, 0) > 0) {
                send(new_fd, buf, strlen(buf), 0);
            }
            
            close(new_fd);
            printf("proxy: client connection closed\n");
            exit(0);
        }
        
        // parent doesn't need this
        close(new_fd);
    }
    
    return 0;
}