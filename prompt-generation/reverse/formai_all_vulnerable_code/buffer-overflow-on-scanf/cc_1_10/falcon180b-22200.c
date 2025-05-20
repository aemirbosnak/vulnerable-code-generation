//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT "80"

struct hostent *gethostbyname(const char *name);

int main() {
    char target_ip[20];
    char target_domain[100];
    char buffer[BUFFER_SIZE];
    int sockfd, numbytes;
    struct hostent *he;
    struct sockaddr_in serv_addr;

    printf("Enter IP address or domain name: ");
    scanf("%s", target_domain);

    he = gethostbyname(target_domain);
    if(he == NULL) {
        printf("Host not found\n");
        exit(1);
    }

    strcpy(target_ip, inet_ntoa(*(struct in_addr*)he->h_addr));

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(PORT));
    serv_addr.sin_addr.s_addr = inet_addr(target_ip);

    if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    while(1) {
        memset(buffer, 0, BUFFER_SIZE);
        numbytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if(numbytes <= 0) {
            printf("No data received\n");
            break;
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}