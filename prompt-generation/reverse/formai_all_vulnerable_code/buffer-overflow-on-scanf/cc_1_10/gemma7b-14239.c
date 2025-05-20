//Gemma-7B DATASET v1.0 Category: Building a FTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define PORT 21

int main()
{
    int sockfd, n, len;
    struct sockaddr_in servaddr;
    char buf[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to the server
    servaddr.sin_port = htons(PORT);
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Send and receive files
    while (1)
    {
        // Get the file name from the user
        printf("Enter file name: ");
        scanf("%s", buf);

        // Send the file name to the server
        n = write(sockfd, buf, strlen(buf) + 1);
        if (n < 0)
        {
            perror("Error sending file name");
            exit(1);
        }

        // Receive the file data from the server
        len = read(sockfd, buf, 1024);
        if (len < 0)
        {
            perror("Error receiving file data");
            exit(1);
        }

        // Write the file data to a file
        FILE *fp = fopen(buf, "w");
        if (fp == NULL)
        {
            perror("Error opening file");
            exit(1);
        }
        fwrite(buf, len, 1, fp);
        fclose(fp);

        // Check if the user wants to continue
        printf("Do you want to continue? (Y/N): ");
        scanf("%s", buf);

        // If the user does not want to continue, break out of the loop
        if (buf[0] == 'N' || buf[0] == 'n')
        {
            break;
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}