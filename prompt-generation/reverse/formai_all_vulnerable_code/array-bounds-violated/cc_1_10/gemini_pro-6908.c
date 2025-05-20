//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_DATA_SIZE 1024

// Function to create a socket connection to the FTP server
int create_socket(char *ip_address, int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        return -1;
    }

    // Set the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip_address);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        return -1;
    }

    return sockfd;
}

// Function to send a command to the FTP server
int send_command(int sockfd, char *command) {
    int bytes_sent;

    // Send the command to the server
    bytes_sent = send(sockfd, command, strlen(command), 0);
    if (bytes_sent == -1) {
        perror("Error sending command");
        return -1;
    }

    return bytes_sent;
}

// Function to receive a response from the FTP server
int receive_response(int sockfd, char *response) {
    int bytes_received;

    // Receive the response from the server
    bytes_received = recv(sockfd, response, MAX_DATA_SIZE, 0);
    if (bytes_received == -1) {
        perror("Error receiving response");
        return -1;
    }

    // Terminate the response with a null character
    response[bytes_received] = '\0';

    return bytes_received;
}

// Function to download a file from the FTP server
int download_file(int sockfd, char *filename) {
    int bytes_received;
    char data[MAX_DATA_SIZE];
    FILE *fp;

    // Open the file for writing
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Send the RETR command to the server
    if (send_command(sockfd, "RETR ") == -1) {
        return -1;
    }

    // Receive the file data from the server
    while ((bytes_received = receive_response(sockfd, data)) > 0) {
        // Write the file data to the file
        fwrite(data, 1, bytes_received, fp);
    }

    // Close the file
    fclose(fp);

    return 0;
}

// Function to upload a file to the FTP server
int upload_file(int sockfd, char *filename) {
    int bytes_sent;
    char data[MAX_DATA_SIZE];
    FILE *fp;

    // Open the file for reading
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Send the STOR command to the server
    if (send_command(sockfd, "STOR ") == -1) {
        return -1;
    }

    // Read the file data and send it to the server
    while ((bytes_sent = fread(data, 1, MAX_DATA_SIZE, fp)) > 0) {
        // Send the file data to the server
        if (send(sockfd, data, bytes_sent, 0) == -1) {
            perror("Error sending file data");
            return -1;
        }
    }

    // Close the file
    fclose(fp);

    return 0;
}

// Function to list the files on the FTP server
int list_files(int sockfd) {
    int bytes_received;
    char data[MAX_DATA_SIZE];

    // Send the LS command to the server
    if (send_command(sockfd, "LS") == -1) {
        return -1;
    }

    // Receive the file list from the server
    while ((bytes_received = receive_response(sockfd, data)) > 0) {
        // Print the file list
        printf("%s", data);
    }

    return 0;
}

// Function to delete a file on the FTP server
int delete_file(int sockfd, char *filename) {
    int bytes_received;
    char data[MAX_DATA_SIZE];

    // Send the DELE command to the server
    if (send_command(sockfd, "DELE ") == -1) {
        return -1;
    }

    // Receive the response from the server
    if ((bytes_received = receive_response(sockfd, data)) == -1) {
        return -1;
    }

    // Print the response from the server
    printf("%s", data);

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    int sockfd;
    char command[MAX_DATA_SIZE];
    char response[MAX_DATA_SIZE];

    // Check if the user has provided enough arguments
    if (argc < 3) {
        printf("Usage: %s <ip_address> <port>\n", argv[0]);
        return 1;
    }

    // Create a socket connection to the FTP server
    sockfd = create_socket(argv[1], atoi(argv[2]));
    if (sockfd == -1) {
        return 1;
    }

    // Main loop
    while (1) {
        // Prompt the user for a command
        printf("> ");
        fgets(command, MAX_DATA_SIZE, stdin);

        // Remove the newline character from the command
        command[strlen(command) - 1] = '\0';

        // Send the command to the FTP server
        if (send_command(sockfd, command) == -1) {
            break;
        }

        // Receive the response from the FTP server
        if (receive_response(sockfd, response) == -1) {
            break;
        }

        // Print the response from the FTP server
        printf("%s", response);

        // Check if the user has entered the EXIT command
        if (strcmp(command, "EXIT") == 0) {
            break;
        }
    }

    // Close the socket connection to the FTP server
    close(sockfd);

    return 0;
}