//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

void ping(char *hostname)
{
    int sock;
    struct hostent *hostinfo;
    struct sockaddr_in server_addr;
    char buffer[1024];
    int bytes_recvd;
    int status;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    hostinfo = gethostbyname(hostname);
    if (hostinfo == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7); // Echo port
    memcpy(&server_addr.sin_addr.s_addr, hostinfo->h_addr, hostinfo->h_length);

    status = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (status == -1) {
        if (errno == ECONNREFUSED) {
            printf("Host is down\n");
        } else {
            printf("Error connecting to host\n");
        }
        exit(1);
    }

    bytes_recvd = recv(sock, buffer, sizeof(buffer), 0);
    if (bytes_recvd == -1) {
        printf("Error receiving data\n");
        exit(1);
    }

    printf("Ping successful\n");
    printf("Received %d bytes of data\n", bytes_recvd);
    printf("Data: %s\n", buffer);

    close(sock);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    ping(argv[1]);

    return 0;
}