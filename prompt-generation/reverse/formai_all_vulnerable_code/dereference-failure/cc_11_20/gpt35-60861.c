//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>


#define BUFFER_SIZE 4096

int main(int argc, char **argv) {

    // check if enough arguments are provided
    if (argc < 4) {
        printf("Usage: %s <listen-port> <destination-IP> <destination-port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // parse arguments
    int listen_port = atoi(argv[1]);
    char *destination_ip = argv[2];
    int destination_port = atoi(argv[3]);

    // create socket
    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
        perror("socket failed");
        return EXIT_FAILURE;
    }

    // bind socket
    struct sockaddr_in serv_addr, cli_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(listen_port);
    if (bind(server_sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        return EXIT_FAILURE;
    }

    // listen for incoming connections
    if (listen(server_sockfd, 5) < 0) {
        perror("listen failed");
        return EXIT_FAILURE;
    }

    // print server information to console
    printf("HTTP proxy server started on port %d\n", listen_port);
    printf("Proxying HTTP requests to %s:%d ...\n", destination_ip, destination_port);

    while (true) {

        // accept incoming connections
        socklen_t clilen = sizeof(cli_addr);
        int client_sockfd = accept(server_sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (client_sockfd < 0) {
            perror("accept failed");
            return EXIT_FAILURE;
        }

        // read client request
        char buffer[BUFFER_SIZE];
        bzero(buffer, BUFFER_SIZE);
        int n = read(client_sockfd, buffer, BUFFER_SIZE);
        if (n < 0) {
            perror("read failed");
            return EXIT_FAILURE;
        }

        // print client request to console
        printf("--> Client request (%d bytes):\n", n);
        printf("%s\n", buffer);

        // create socket to destination server
        int dest_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (dest_sockfd < 0) {
            perror("socket failed");
            return EXIT_FAILURE;
        }

        // get address information for destination server
        struct hostent *dest_host = gethostbyname(destination_ip);
        if (dest_host == NULL) {
            perror("gethostbyname failed");
            return EXIT_FAILURE;
        }
        struct sockaddr_in dest_addr;
        bzero((char *) &dest_addr, sizeof(dest_addr));
        dest_addr.sin_family = AF_INET;
        bcopy((char *) dest_host->h_addr, (char *)&dest_addr.sin_addr.s_addr, dest_host->h_length);
        dest_addr.sin_port = htons(destination_port);

        // connect to destination server
        if (connect(dest_sockfd, (struct sockaddr *) &dest_addr, sizeof(dest_addr)) < 0) {
            perror("connect failed");
            return EXIT_FAILURE;
        }

        // forward client request to destination server
        n = write(dest_sockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("write to destination failed");
            return EXIT_FAILURE;
        }
        
        // read response from destination server
        bzero(buffer, BUFFER_SIZE);
        n = read(dest_sockfd, buffer, BUFFER_SIZE);
        if (n < 0) {
            perror("read from destination failed");
            return EXIT_FAILURE;
        }

        // print response from destination server to console
        printf("<-- Response from destination (%d bytes):\n", n);
        printf("%s\n", buffer);
        
        // forward response to client
        n = write(client_sockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("write to client failed");
            return EXIT_FAILURE;
        }

        // close sockets
        close(client_sockfd);
        close(dest_sockfd);
    }

    return EXIT_SUCCESS;
}