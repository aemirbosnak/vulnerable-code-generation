//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    // Get hostname and port from command line arguments
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        exit(1);
    }

    // Get the IP address of the hostname
    struct hostent *hostent = gethostbyname(hostname);
    if (hostent == NULL)
    {
        perror("gethostbyname");
        exit(1);
    }

    // Create a sockaddr_in struct to hold the server's address
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr = *((struct in_addr *)hostent->h_addr_list[0]);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
    {
        perror("connect");
        exit(1);
    }

    // Send a USER command to the server
    char username[BUF_SIZE];
    printf("Enter your username: ");
    scanf("%s", username);
    char user_cmd[BUF_SIZE];
    snprintf(user_cmd, BUF_SIZE, "USER %s\r\n", username);
    if (send(sockfd, user_cmd, strlen(user_cmd), 0) == -1)
    {
        perror("send");
        exit(1);
    }

    // Receive the response from the server
    char buf[BUF_SIZE];
    if (recv(sockfd, buf, BUF_SIZE, 0) == -1)
    {
        perror("recv");
        exit(1);
    }

    // Check the response code to see if the username is valid
    if (strncmp(buf, "331", 3) != 0)
    {
        printf("Invalid username\n");
        exit(1);
    }

    // Send a PASS command to the server
    char password[BUF_SIZE];
    printf("Enter your password: ");
    scanf("%s", password);
    char pass_cmd[BUF_SIZE];
    snprintf(pass_cmd, BUF_SIZE, "PASS %s\r\n", password);
    if (send(sockfd, pass_cmd, strlen(pass_cmd), 0) == -1)
    {
        perror("send");
        exit(1);
    }

    // Receive the response from the server
    if (recv(sockfd, buf, BUF_SIZE, 0) == -1)
    {
        perror("recv");
        exit(1);
    }

    // Check the response code to see if the password is valid
    if (strncmp(buf, "230", 3) != 0)
    {
        printf("Invalid password\n");
        exit(1);
    }

    // Print the welcome message from the server
    printf("%s", buf);

    // Main loop
    while (1)
    {
        // Display the FTP prompt
        printf("ftp> ");

        // Get the command from the user
        char cmd[BUF_SIZE];
        scanf("%s", cmd);

        // Handle the command
        if (strcmp(cmd, "quit") == 0)
        {
            // Send a QUIT command to the server
            char quit_cmd[BUF_SIZE];
            snprintf(quit_cmd, BUF_SIZE, "QUIT\r\n");
            if (send(sockfd, quit_cmd, strlen(quit_cmd), 0) == -1)
            {
                perror("send");
                exit(1);
            }

            // Receive the response from the server
            if (recv(sockfd, buf, BUF_SIZE, 0) == -1)
            {
                perror("recv");
                exit(1);
            }

            // Print the response message from the server
            printf("%s", buf);

            // Close the socket
            close(sockfd);

            // Exit the main loop
            break;
        }
        else if (strcmp(cmd, "ls") == 0)
        {
            // Send a LIST command to the server
            char list_cmd[BUF_SIZE];
            snprintf(list_cmd, BUF_SIZE, "LIST\r\n");
            if (send(sockfd, list_cmd, strlen(list_cmd), 0) == -1)
            {
                perror("send");
                exit(1);
            }

            // Receive the response from the server
            while (recv(sockfd, buf, BUF_SIZE, 0) > 0)
            {
                // Print the response message from the server
                printf("%s", buf);
            }
        }
        else if (strcmp(cmd, "get") == 0)
        {
            // Get the file name from the user
            char filename[BUF_SIZE];
            printf("Enter the file name: ");
            scanf("%s", filename);

            // Send a RETR command to the server
            char retr_cmd[BUF_SIZE];
            snprintf(retr_cmd, BUF_SIZE, "RETR %s\r\n", filename);
            if (send(sockfd, retr_cmd, strlen(retr_cmd), 0) == -1)
            {
                perror("send");
                exit(1);
            }

            // Open a file to write the data to
            FILE *fp = fopen(filename, "w");
            if (fp == NULL)
            {
                perror("fopen");
                exit(1);
            }

            // Receive the response from the server and write it to the file
            while (recv(sockfd, buf, BUF_SIZE, 0) > 0)
            {
                fwrite(buf, 1, strlen(buf), fp);
            }

            // Close the file
            fclose(fp);
        }
        else if (strcmp(cmd, "put") == 0)
        {
            // Get the file name from the user
            char filename[BUF_SIZE];
            printf("Enter the file name: ");
            scanf("%s", filename);

            // Open the file to read the data from
            FILE *fp = fopen(filename, "r");
            if (fp == NULL)
            {
                perror("fopen");
                exit(1);
            }

            // Send a STOR command to the server
            char stor_cmd[BUF_SIZE];
            snprintf(stor_cmd, BUF_SIZE, "STOR %s\r\n", filename);
            if (send(sockfd, stor_cmd, strlen(stor_cmd), 0) == -1)
            {
                perror("send");
                exit(1);
            }

            // Send the file data to the server
            while (!feof(fp))
            {
                fread(buf, 1, BUF_SIZE, fp);
                if (send(sockfd, buf, strlen(buf), 0) == -1)
                {
                    perror("send");
                    exit(1);
                }
            }

            // Close the file
            fclose(fp);
        }
        else
        {
            // Print an error message
            printf("Invalid command\n");
        }
    }

    return 0;
}