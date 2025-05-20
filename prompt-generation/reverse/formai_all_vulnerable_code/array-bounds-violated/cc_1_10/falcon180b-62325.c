//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<math.h>

#define PORT 8080
#define MAX 100

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, clilen, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];

    FILE *fp;
    char filename[50];
    char ch;
    int count=0;

    fp = fopen("data.txt","r");
    if(fp==NULL)
    {
        printf("\n Unable to open file ");
        exit(0);
    }

    while((ch=fgetc(fp))!=EOF)
    {
        filename[count++] = ch;
    }

    filename[count] = '\0';
    fclose(fp);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        printf("\n Socket creation failed ");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if(bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\n Bind failed ");
        exit(0);
    }

    if(listen(sockfd, 5) < 0)
    {
        printf("\n Listen failed ");
        exit(0);
    }

    while(1)
    {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, (socklen_t*)&clilen);
        if(newsockfd < 0)
        {
            printf("\n Accept failed ");
            exit(0);
        }

        send(newsockfd, filename, strlen(filename), 0);

        close(newsockfd);
    }

    return 0;
}