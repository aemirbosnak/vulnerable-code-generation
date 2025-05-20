//Gemma-7B DATASET v1.0 Category: Building a FTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define HOST "localhost"
#define PORT 2121

int main()
{
    // Building the futuristic spaceship
    system("clear");
    printf("__________________________________\n");
    printf("                 _|\n");
    printf("                 _|| |\n");
    printf("                 _||_|\n");
    printf("__________________________________\n");

    // Connecting to the FTP server
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));
    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr(HOST);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Sending and receiving files
    char filename[256];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    char buffer[1024];
    int bytesRead;
    while ((bytesRead = recv(sockfd, buffer, 1024, 0)) > 0)
    {
        fwrite(buffer, bytesRead, 1, fp);
    }

    fclose(fp);
    close(sockfd);

    // Landing the spaceship
    system("clear");
    printf("__________________________________\n");
    printf("                 _|\n");
    printf("                 _|| |\n");
    printf("                 _||_|\n");
    printf("__________________________________\n");

    return 0;
}