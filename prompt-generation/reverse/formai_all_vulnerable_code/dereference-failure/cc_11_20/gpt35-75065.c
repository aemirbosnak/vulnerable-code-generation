//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_address> <port_number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server_address = argv[1];
    int port_number = atoi(argv[2]);

    /* Create a socket */
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR: Failed to create socket");
        exit(EXIT_FAILURE);
    }

    /* Set up the socket address structure */
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(server_address);
    serv_addr.sin_port = htons(port_number);

    /* Connect to the server */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR: Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s:%d\n", server_address, port_number);

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read = -1;
    FILE *local_file = NULL;
    int num_bytes_written = 0;

    /* Request a file from the server */
    do {
        printf("Enter the name of the file you want to retrieve (or 'exit' to quit): ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if (strcmp(buffer, "exit") == 0) {
            printf("Exiting...\n");
            close(sockfd);
            exit(EXIT_SUCCESS);
        }

        /* Send the request to the server */
        ssize_t bytes_sent = write(sockfd, buffer, strlen(buffer));
        if (bytes_sent < 0) {
            perror("ERROR: Failed to send request to server");
            continue;
        }

        /* Receive the response from the server */
        bytes_read = read(sockfd, buffer, BUFFER_SIZE - 1);
        if (bytes_read < 0) {
            perror("ERROR: Failed to read response from server");
            continue;
        }

        buffer[bytes_read] = '\0';
        if (strcmp(buffer, "404") == 0) {
            printf("The file %s could not be found on the server\n", buffer);
            continue;
        }

        /* Open a local file for writing */
        if ((local_file = fopen(buffer, "wb")) == NULL) {
            perror("ERROR: Failed to open local file for writing");
            continue;
        }

        /* Write the received bytes to the local file */
        num_bytes_written = fwrite(buffer, 1, bytes_read, local_file);
        if (num_bytes_written < 0) {
            perror("ERROR: Failed to write bytes to local file");
            continue;
        }

        printf("Successfully retrieved file: %s\n", buffer);

    } while (bytes_read <= 0);

    /* Close the socket and local file */
    close(sockfd);
    fclose(local_file);

    return 0;
}