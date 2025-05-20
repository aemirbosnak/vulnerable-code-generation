//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    int socket_fd, port_no, n;
    struct sockaddr_in server_addr, client_addr;
    struct hostent *server;
    char buffer[1024];

    if (argc!= 2) {
        printf("Usage: %s port_no\n", argv[0]);
        exit(0);
    }

    port_no = atoi(argv[1]);

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port_no);

    if (connect(socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("ERROR connecting");
        exit(1);
    }

    while ((n = recv(socket_fd, buffer, 1024, 0)) > 0) {
        printf("%s\n", buffer);
        buffer[n] = '\0';
        send(socket_fd, buffer, strlen(buffer), 0);
    }

    printf("Server closed the connection.\n");
    close(socket_fd);

    return 0;
}