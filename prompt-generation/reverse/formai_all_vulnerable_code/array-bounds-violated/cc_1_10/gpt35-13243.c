//FormAI DATASET v1.0 Category: Networking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
 
int main()
{
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
     
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
     
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));
     
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(5555);
     
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
     
    char buffer[1024];
    int len, n;
     
    len = sizeof(cliaddr); 
     
    while (1) {
        n = recvfrom(sockfd, (char *)buffer, 1024, MSG_WAITALL, (struct sockaddr *)&cliaddr, &len);
        buffer[n] = '\0';
     
        printf("Client : %s\n", buffer);
        if (strncmp(buffer, "exit", 4) == 0) {
            printf("Server exit\n");
            break;
        }
        else {
            printf("Server : ");
            fgets(buffer, 1024, stdin);
            sendto(sockfd, (const char *)buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr *)&cliaddr, len);
        }
    }
     
    close(sockfd);
     
    return 0;
}