//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#define BUFFERSIZE 4096

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFERSIZE];

    if (argc < 3)
    {
        fprintf(stderr, "\nusage %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
        error("\nError opening socket\n");

    server = gethostbyname(argv[1]);

    if (server == NULL)
    {
        fprintf(stderr, "\nError, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr_list[0], (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("\nError connecting\n");

    printf("\nSuccessfully connected to the FTP Server\n");

    int option = 1;
    int data_sockfd;
    char command[500];
    char data[BUFFERSIZE + 1];
    char *pch;
    char *filename;

    while (1)
    {
        printf("\n> ");
        bzero(command, 500);
        bzero(data, BUFFERSIZE + 1);
        fgets(command, 500, stdin);

        pch = strtok(command, " ");

        if (pch != NULL && strcmp(pch, "put") == 0)
        {
            filename = strtok(NULL, " ");
            filename[strcspn(filename, "\n")] = 0;

            FILE *fp = fopen(filename, "r");

            if (fp == NULL)
            {
                printf("\nError opening file\n");
                continue;
            }

            printf("\nUploading file to server...\n");

            if (write(sockfd, command, strlen(command)) < 0)
                error("\nError writing to socket\n");

            bzero(buffer, BUFFERSIZE);
            read(sockfd, buffer, BUFFERSIZE);

            if (strcmp(buffer, "OK") == 0)
            {
                while (!feof(fp))
                {
                    bzero(data, BUFFERSIZE);
                    n = fread(data, 1, BUFFERSIZE, fp);

                    if (send(data_sockfd, data, n, 0) < 0)
                        error("\nError writing to socket\n");
                }

                printf("\nFile uploaded successfully\n");
            }
            else
            {
                printf("\nError uploading file\n");
            }

            fclose(fp);
        }
        else if (pch != NULL && strcmp(pch, "get") == 0)
        {
            filename = strtok(NULL, " ");
            filename[strcspn(filename, "\n")] = 0;

            printf("\nDownloading file from server...\n");

            if (write(sockfd, command, strlen(command)) < 0)
                error("\nError writing to socket\n");

            bzero(buffer, BUFFERSIZE);
            read(sockfd, buffer, BUFFERSIZE);

            if (strcmp(buffer, "OK") == 0)
            {
                FILE *fp = fopen(filename, "w");

                while (1)
                {
                    n = recv(data_sockfd, data, BUFFERSIZE, 0);

                    if (n <= 0)
                        break;

                    fwrite(data, sizeof(char), n, fp);
                }

                printf("\nFile downloaded successfully\n");
                fclose(fp);
            }
            else
            {
                printf("\nError downloading file\n");
            }
        }
        else
        {
            if (write(sockfd, command, strlen(command)) < 0)
                error("\nError writing to socket\n");

            if (strcmp(command, "quit\n") == 0)
            {
                break;
            }

            bzero(buffer, BUFFERSIZE);
            read(sockfd, buffer, BUFFERSIZE);

            if (strcmp(buffer, "OK") != 0)
            {
                printf("\n%s\n", buffer);
                continue;
            }

            data_sockfd = accept(sockfd, (struct sockaddr *) NULL, NULL);

            if (data_sockfd < 0)
                error("\nError accepting socket\n");

            printf("\n");

            while (1)
            {
                bzero(data, BUFFERSIZE + 1);
                n = recv(data_sockfd, data, BUFFERSIZE, 0);

                if (n <= 0)
                    break;

                printf("%s", data);
            }

            close(data_sockfd);
        }
    }

    close(sockfd);
    return 0;
}