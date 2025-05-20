//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: introspective
//This simple HTTP proxy accepts HTTP requests from a client and forwards them to the target server.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    int server_sock, client_sock, port;
    struct sockaddr_in server_addr, client_addr;
    char request[1024], response[1024];
    char *target_ip;
    int target_port;
    struct sockaddr_in target_addr;
    int target_sock;

    //Parse command line arguments to get proxy port and target server ip and port.
    if (argc != 3) {
        printf("Usage: %s <proxy-port> <target-server-ip:port>\n", argv[0]);
        exit(1);
    }
    port = atoi(argv[1]);
    target_ip = strtok(argv[2], ":");
    target_port = atoi(strtok(NULL, ""));

    //Create server socket.
    server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_sock < 0) {
        perror("socket() failed");
        exit(1);
    }

    //Bind server socket to proxy port.
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);
    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind() failed");
        exit(1);
    }

    //Listen for client connections.
    if (listen(server_sock, 5) < 0) {
        perror("listen() failed");
        exit(1);
    }

    printf("Proxy listening on port %d\n", port);

    //Main proxy loop.
    while (1) {
        int request_len, response_len;

        //Wait for client to connect.
        socklen_t client_addr_len = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_sock < 0) {
            perror("accept() failed");
            continue;
        }

        printf("Received connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        //Read client request.
        request_len = read(client_sock, request, sizeof(request) - 1);
        if (request_len < 0) {
            perror("read() failed");
            close(client_sock);
            continue;
        }
        request[request_len] = '\0';

        printf("Received request from client:\n%s\n", request);

        //Create target server socket.
        target_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (target_sock < 0) {
            perror("socket() failed");
            close(client_sock);
            continue;
        }

        //Connect to target server.
        memset(&target_addr, 0, sizeof(target_addr));
        target_addr.sin_family = AF_INET;
        target_addr.sin_addr.s_addr = inet_addr(target_ip);
        target_addr.sin_port = htons(target_port);
        if (connect(target_sock, (struct sockaddr *) &target_addr, sizeof(target_addr)) < 0) {
            perror("connect() failed");
            close(client_sock);
            close(target_sock);
            continue;
        }

        printf("Connected to target server %s:%d\n", target_ip, target_port);

        //Forward client request to target server.
        if (write(target_sock, request, request_len) < 0) {
            perror("write() failed");
            close(client_sock);
            close(target_sock);
            continue;
        }

        //Read target server response.
        response_len = read(target_sock, response, sizeof(response) - 1);
        if (response_len < 0) {
            perror("read() failed");
            close(client_sock);
            close(target_sock);
            continue;
        }
        response[response_len] = '\0';

        printf("Received response from target server:\n%s\n", response);

        //Forward target server response to client.
        if (write(client_sock, response, response_len) < 0) {
            perror("write() failed");
            close(client_sock);
            close(target_sock);
            continue;
        }

        printf("Forwarded response to client\n");

        //Close client and target sockets.
        close(client_sock);
        close(target_sock);
    }

    return 0;
}