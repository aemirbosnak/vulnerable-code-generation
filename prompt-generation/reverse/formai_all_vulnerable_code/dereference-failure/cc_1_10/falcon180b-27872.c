//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>

#define MAX 100
#define PORT 12345
#define SA struct sockaddr

int main(int argc, char *argv[])
{
    char *server_name;
    char *server_ip;
    int sockfd;
    struct hostent *he;
    struct sockaddr_in server_addr;

    if (argc!= 3) {
        printf("Usage: %s <server_name> <server_ip>\n", argv[0]);
        exit(1);
    }

    server_name = argv[1];
    server_ip = argv[2];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: socket creation failed\n");
        exit(1);
    }

    he = gethostbyname(server_name);
    if (he == NULL) {
        printf("Error: host not found\n");
        exit(1);
    }

    memcpy(&server_addr.sin_addr, he->h_addr, he->h_length);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (connect(sockfd, (SA *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: connection failed\n");
        exit(1);
    }

    send(sockfd, server_ip, strlen(server_ip), 0);
    recv(sockfd, server_ip, MAX, 0);

    printf("Server IP: %s\n", server_ip);

    close(sockfd);
    return 0;
}