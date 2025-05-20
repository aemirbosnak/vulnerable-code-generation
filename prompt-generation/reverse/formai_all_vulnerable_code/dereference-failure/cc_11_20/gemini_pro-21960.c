//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    // Let us glean the wisdom of the command line.
    if (argc != 4)
    {
        printf("Usage: %s <hostname> <port> <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // A sanctuary for our connection to the distant server.
    int sockfd;
    // A beacon of communication, pointing to the server's abode.
    struct sockaddr_in server_addr;
    // A tapestry of bytes woven into commands.
    char buffer[256];

    // Let us open a portal to the server.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Prepare our ship for the voyage.
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Set sail for the server's harbor.
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
    {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Announce our desire to retrieve the coveted file.
    sprintf(buffer, "RETR %s", argv[3]);

    // Dispatch the command to the server.
    if (send(sockfd, buffer, strlen(buffer), 0) < 0)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Avast! The server responds.
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Decipher the server's reply. Is the treasure within our grasp?
    if (strncmp(buffer, "200 ", 4) != 0)
    {
        printf("Error retrieving file: %s\n", buffer);
        return EXIT_FAILURE;
    }

    // Prepare the vessel to receive the bounty.
    FILE *fp = fopen(argv[3], "w");
    if (fp == NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Plunder the file, byte by byte.
    int bytes_received;
    do
    {
        bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
        if (bytes_received < 0)
        {
            perror("recv");
            return EXIT_FAILURE;
        }
        else if (bytes_received > 0)
        {
            fwrite(buffer, sizeof(char), bytes_received, fp);
        }
    } while (bytes_received > 0);

    // Hoist the sails and bid farewell to the server.
    fclose(fp);
    close(sockfd);

    printf("File retrieved successfully!\n");

    return EXIT_SUCCESS;
}