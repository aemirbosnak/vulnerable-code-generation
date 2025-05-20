//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX 100
#define PORT 8080
#define SA struct sockaddr

int sockfd, newsockfd, valread;
char senddata[MAX], recvdata[MAX];

struct sockaddr_in servaddr, cliaddr;

void *thread(void *ptr)
{
    char *data = (char *)ptr;
    send(newsockfd, data, strlen(data), 0);
}

int main()
{
    int n;
    pthread_t threadid;
    char input[MAX];
    char hostname[20];
    char message[100] = "Smart Home Light Control System\r\n";

    printf("Enter hostname: ");
    scanf("%s", hostname);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        printf("socket failed");
        exit(0);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(hostname);
    servaddr.sin_port = htons(PORT);

    if (connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) < 0)
    {
        printf("connect failed");
        exit(0);
    }

    printf("Connected to server...\n");

    while (1)
    {
        memset(input, 0, sizeof(input));
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "on") == 0)
        {
            send(sockfd, "on", strlen("on"), 0);
        }
        else if (strcmp(input, "off") == 0)
        {
            send(sockfd, "off", strlen("off"), 0);
        }
        else if (strcmp(input, "dim") == 0)
        {
            printf("Enter dim value (0-100): ");
            scanf("%d", &n);
            sprintf(input, "dim %d", n);
            send(sockfd, input, strlen(input), 0);
        }
        else
        {
            printf("Invalid command\n");
        }

        valread = read(sockfd, recvdata, sizeof(recvdata));
        recvdata[valread] = '\0';
        printf("%s", recvdata);
    }

    return 0;
}