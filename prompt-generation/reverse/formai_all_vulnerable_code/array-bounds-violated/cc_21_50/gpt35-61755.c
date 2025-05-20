//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock_desc;
    struct sockaddr_in server_address;
    char username[BUFFER_SIZE], password[BUFFER_SIZE], buffer[BUFFER_SIZE];
    char *response, *ptr;
    int response_size, count, i;

    if (argc != 3) {
        printf("Usage: %s <server_ip> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // create socket
    sock_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_desc == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // create server structure
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(atoi(argv[2]));

    // connect to server
    if (connect(sock_desc, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // receive welcome messages from server
    count = recv(sock_desc, buffer, BUFFER_SIZE, 0);
    if (count == -1) {
        perror("Error receiving from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // send username
    printf("Username: ");
    fgets(username, BUFFER_SIZE, stdin);
    username[strlen(username)-1] = '\0'; // remove newline character

    snprintf(buffer, BUFFER_SIZE, "USER %s\r\n", username);
    if (send(sock_desc, buffer, strlen(buffer), 0) == -1) {
        perror("Error sending to server");
        exit(EXIT_FAILURE);
    }

    // receive response and check for errors
    response = (char *)malloc(BUFFER_SIZE * sizeof(char));
    response_size = 0;
    while (1) {
        count = recv(sock_desc, buffer, BUFFER_SIZE, 0);
        if (count == -1) {
            perror("Error receiving from server");
            exit(EXIT_FAILURE);
        }
        buffer[count] = '\0';
        response = (char *)realloc(response, (response_size + count) * sizeof(char));
        strncpy(&response[response_size], buffer, count);
        response_size += count;
        if (response_size >= 5 && strncmp(&response[response_size - 5], "\r\nOK\r\n", 5) == 0) {
            break;
        } else if (response_size >= 5 && strncmp(&response[response_size - 5], "\r\nERR\r\n", 6) == 0) {
            printf("Error: invalid username\n");
            exit(EXIT_FAILURE);
        }
    }

    // send password
    printf("Password: ");
    fgets(password, BUFFER_SIZE, stdin);
    password[strlen(password)-1] = '\0'; // remove newline character

    snprintf(buffer, BUFFER_SIZE, "PASS %s\r\n", password);
    if (send(sock_desc, buffer, strlen(buffer), 0) == -1) {
        perror("Error sending to server");
        exit(EXIT_FAILURE);
    }

    // receive response and check for errors
    response = (char *)realloc(response, BUFFER_SIZE * sizeof(char));
    response_size = 0;
    while (1) {
        count = recv(sock_desc, buffer, BUFFER_SIZE, 0);
        if (count == -1) {
            perror("Error receiving from server");
            exit(EXIT_FAILURE);
        }
        buffer[count] = '\0';
        response = (char *)realloc(response, (response_size + count) * sizeof(char));
        strncpy(&response[response_size], buffer, count);
        response_size += count;
        if (response_size >= 5 && strncmp(&response[response_size - 5], "\r\nOK\r\n", 5) == 0) {
            break;
        } else if (response_size >= 5 && strncmp(&response[response_size - 5], "\r\nERR\r\n", 6) == 0) {
            printf("Error: invalid password\n");
            exit(EXIT_FAILURE);
        }
    }

    // list emails and retrieve one
    printf("Listing emails...\n");
    snprintf(buffer, BUFFER_SIZE, "LIST\r\n");
    if (send(sock_desc, buffer, strlen(buffer), 0) == -1) {
        perror("Error sending to server");
        exit(EXIT_FAILURE);
    }

    // receive list and print to console
    response = (char *)realloc(response, BUFFER_SIZE * sizeof(char));
    response_size = 0;
    while (1) {
        count = recv(sock_desc, buffer, BUFFER_SIZE, 0);
        if (count == -1) {
            perror("Error receiving from server");
            exit(EXIT_FAILURE);
        }
        buffer[count] = '\0';
        response = (char *)realloc(response, (response_size + count) * sizeof(char));
        strncpy(&response[response_size], buffer, count);
        response_size += count;
        if (response_size >= 5 && strncmp(&response[response_size - 5], "\r\n.\r\n", 5) == 0) {
            break;
        }
    }
    printf("%s", response);

    printf("Enter email number to retrieve: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    buffer[strlen(buffer)-1] = '\0'; // remove newline character

    snprintf(buffer, BUFFER_SIZE, "RETR %s\r\n", buffer);
    if (send(sock_desc, buffer, strlen(buffer), 0) == -1) {
        perror("Error sending to server");
        exit(EXIT_FAILURE);
    }

    // receive email and print to console
    response = (char *)realloc(response, BUFFER_SIZE * sizeof(char));
    response_size = 0;
    while (1) {
        count = recv(sock_desc, buffer, BUFFER_SIZE, 0);
        if (count == -1) {
            perror("Error receiving from server");
            exit(EXIT_FAILURE);
        }
        buffer[count] = '\0';
        response = (char *)realloc(response, (response_size + count) * sizeof(char));
        strncpy(&response[response_size], buffer, count);
        response_size += count;
        ptr = strstr(response, "\r\n.\r\n");
        if (ptr != NULL) {
            *ptr = '\0';
            break;
        }
    }
    printf("%s", response);

    // quit session
    printf("Quitting session...\n");
    snprintf(buffer, BUFFER_SIZE, "QUIT\r\n");
    if (send(sock_desc, buffer, strlen(buffer), 0) == -1) {
        perror("Error sending to server");
        exit(EXIT_FAILURE);
    }

    // receive goodbye message from server
    response = (char *)realloc(response, BUFFER_SIZE * sizeof(char));
    response_size = 0;
    while (1) {
        count = recv(sock_desc, buffer, BUFFER_SIZE, 0);
        if (count == -1) {
            perror("Error receiving from server");
            exit(EXIT_FAILURE);
        }
        buffer[count] = '\0';
        response = (char *)realloc(response, (response_size + count) * sizeof(char));
        strncpy(&response[response_size], buffer, count);
        response_size += count;
        if (response_size >= 5 && strncmp(&response[response_size - 5], "\r\nOK\r\n", 5) == 0) {
            break;
        }
    }
    printf("%s", response);

    // cleanup
    free(response);
    close(sock_desc);

    return 0;
}