//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define DEFAULT_PORT 21
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <hostname> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    char *filename = argv[2];

    // Get the IP address of the host
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL)
    {
        fprintf(stderr, "Error: Could not resolve hostname\n");
        return EXIT_FAILURE;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        fprintf(stderr, "Error: Could not create socket\n");
        return EXIT_FAILURE;
    }

    // Connect to the host
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(DEFAULT_PORT);
    memcpy(&serv_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        fprintf(stderr, "Error: Could not connect to host\n");
        return EXIT_FAILURE;
    }

    // Send the USER command
    char user_cmd[MAX_BUFFER_SIZE];
    sprintf(user_cmd, "USER anonymous\r\n");
    if (send(sockfd, user_cmd, strlen(user_cmd), 0) < 0)
    {
        fprintf(stderr, "Error: Could not send USER command\n");
        return EXIT_FAILURE;
    }

    // Receive the response to the USER command
    char user_resp[MAX_BUFFER_SIZE];
    if (recv(sockfd, user_resp, MAX_BUFFER_SIZE, 0) < 0)
    {
        fprintf(stderr, "Error: Could not receive response to USER command\n");
        return EXIT_FAILURE;
    }

    // Send the PASS command
    char pass_cmd[MAX_BUFFER_SIZE];
    sprintf(pass_cmd, "PASS anonymous@\r\n");
    if (send(sockfd, pass_cmd, strlen(pass_cmd), 0) < 0)
    {
        fprintf(stderr, "Error: Could not send PASS command\n");
        return EXIT_FAILURE;
    }

    // Receive the response to the PASS command
    char pass_resp[MAX_BUFFER_SIZE];
    if (recv(sockfd, pass_resp, MAX_BUFFER_SIZE, 0) < 0)
    {
        fprintf(stderr, "Error: Could not receive response to PASS command\n");
        return EXIT_FAILURE;
    }

    // Send the TYPE command
    char type_cmd[MAX_BUFFER_SIZE];
    sprintf(type_cmd, "TYPE I\r\n");
    if (send(sockfd, type_cmd, strlen(type_cmd), 0) < 0)
    {
        fprintf(stderr, "Error: Could not send TYPE command\n");
        return EXIT_FAILURE;
    }

    // Receive the response to the TYPE command
    char type_resp[MAX_BUFFER_SIZE];
    if (recv(sockfd, type_resp, MAX_BUFFER_SIZE, 0) < 0)
    {
        fprintf(stderr, "Error: Could not receive response to TYPE command\n");
        return EXIT_FAILURE;
    }

    // Send the RETR command
    char retr_cmd[MAX_BUFFER_SIZE];
    sprintf(retr_cmd, "RETR %s\r\n", filename);
    if (send(sockfd, retr_cmd, strlen(retr_cmd), 0) < 0)
    {
        fprintf(stderr, "Error: Could not send RETR command\n");
        return EXIT_FAILURE;
    }

    // Receive the response to the RETR command
    char retr_resp[MAX_BUFFER_SIZE];
    if (recv(sockfd, retr_resp, MAX_BUFFER_SIZE, 0) < 0)
    {
        fprintf(stderr, "Error: Could not receive response to RETR command\n");
        return EXIT_FAILURE;
    }

    // Open a file for writing
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Could not open file for writing\n");
        return EXIT_FAILURE;
    }

    // Write the contents of the file to the file
    while (1)
    {
        char buffer[MAX_BUFFER_SIZE];
        int bytes_read = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
        if (bytes_read <= 0)
        {
            break;
        }

        fwrite(buffer, 1, bytes_read, fp);
    }

    // Close the file
    fclose(fp);

    // Send the QUIT command
    char quit_cmd[MAX_BUFFER_SIZE];
    sprintf(quit_cmd, "QUIT\r\n");
    if (send(sockfd, quit_cmd, strlen(quit_cmd), 0) < 0)
    {
        fprintf(stderr, "Error: Could not send QUIT command\n");
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}