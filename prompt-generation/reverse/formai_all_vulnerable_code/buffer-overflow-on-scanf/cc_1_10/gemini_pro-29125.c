//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// POP3 commands
#define USER "USER"
#define PASS "PASS"
#define STAT "STAT"
#define LIST "LIST"
#define RETR "RETR"
#define TOP "TOP"
#define DELE "DELE"
#define NOOP "NOOP"
#define RSET "RSET"
#define QUIT "QUIT"

// POP3 response codes
#define OK "+OK"
#define ERR "-ERR"

// POP3 port
#define POP3_PORT 110

// Maximum line length
#define MAX_LINE_LENGTH 1024

// Function to send a command to the POP3 server
int send_command(int sock, char *command) {
    // Send the command to the server
    if (send(sock, command, strlen(command), 0) == -1) {
        perror("send");
        return -1;
    }

    // Receive the response from the server
    char response[MAX_LINE_LENGTH];
    if (recv(sock, response, MAX_LINE_LENGTH, 0) == -1) {
        perror("recv");
        return -1;
    }

    // Check the response code
    if (strncmp(response, OK, 3) != 0) {
        printf("Error: %s\n", response);
        return -1;
    }

    return 0;
}

// Function to get the number of messages on the server
int get_num_messages(int sock) {
    // Send the STAT command to the server
    if (send_command(sock, STAT) == -1) {
        return -1;
    }

    // Receive the response from the server
    char response[MAX_LINE_LENGTH];
    if (recv(sock, response, MAX_LINE_LENGTH, 0) == -1) {
        perror("recv");
        return -1;
    }

    // Extract the number of messages from the response
    int num_messages;
    if (sscanf(response, "+OK %d", &num_messages) != 1) {
        printf("Error: Invalid response: %s\n", response);
        return -1;
    }

    return num_messages;
}

// Function to list the messages on the server
int list_messages(int sock) {
    // Send the LIST command to the server
    if (send_command(sock, LIST) == -1) {
        return -1;
    }

    // Receive the response from the server
    char response[MAX_LINE_LENGTH];
    while (recv(sock, response, MAX_LINE_LENGTH, 0) > 0) {
        // Check if the response is the end of the list
        if (strcmp(response, ".") == 0) {
            break;
        }

        // Print the message number and size
        int message_number, message_size;
        if (sscanf(response, "%d %d", &message_number, &message_size) != 2) {
            printf("Error: Invalid response: %s\n", response);
            return -1;
        }

        printf("Message %d: %d bytes\n", message_number, message_size);
    }

    return 0;
}

// Function to retrieve a message from the server
int retrieve_message(int sock, int message_number) {
    // Send the RETR command to the server
    char command[MAX_LINE_LENGTH];
    sprintf(command, "RETR %d", message_number);
    if (send_command(sock, command) == -1) {
        return -1;
    }

    // Receive the response from the server
    char response[MAX_LINE_LENGTH];
    while (recv(sock, response, MAX_LINE_LENGTH, 0) > 0) {
        // Check if the response is the end of the message
        if (strcmp(response, ".") == 0) {
            break;
        }

        // Print the message
        printf("%s", response);
    }

    return 0;
}

// Function to delete a message from the server
int delete_message(int sock, int message_number) {
    // Send the DELE command to the server
    char command[MAX_LINE_LENGTH];
    sprintf(command, "DELE %d", message_number);
    if (send_command(sock, command) == -1) {
        return -1;
    }

    return 0;
}

// Function to quit the POP3 session
int quit_session(int sock) {
    // Send the QUIT command to the server
    if (send_command(sock, QUIT) == -1) {
        return -1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    // Check if the user specified the POP3 server address
    if (argc < 2) {
        printf("Usage: %s <POP3 server address>\n", argv[0]);
        return 1;
    }

    // Get the POP3 server address
    char *server_address = argv[1];

    // Create a socket for the POP3 session
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    // Connect to the POP3 server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr(server_address);
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Receive the welcome message from the server
    char response[MAX_LINE_LENGTH];
    if (recv(sock, response, MAX_LINE_LENGTH, 0) == -1) {
        perror("recv");
        return 1;
    }

    // Check if the server is ready
    if (strncmp(response, OK, 3) != 0) {
        printf("Error: %s\n", response);
        return 1;
    }

    // Log in to the POP3 server
    char username[MAX_LINE_LENGTH];
    char password[MAX_LINE_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    char command[MAX_LINE_LENGTH];
    sprintf(command, "%s %s", USER, username);
    if (send_command(sock, command) == -1) {
        return 1;
    }

    sprintf(command, "%s %s", PASS, password);
    if (send_command(sock, command) == -1) {
        return 1;
    }

    // Get the number of messages on the server
    int num_messages = get_num_messages(sock);
    if (num_messages == -1) {
        return 1;
    }

    printf("There are %d messages on the server.\n", num_messages);

    // List the messages on the server
    if (list_messages(sock) == -1) {
        return 1;
    }

    // Retrieve a message from the server
    int message_number;
    printf("Enter the number of the message you want to retrieve: ");
    scanf("%d", &message_number);

    if (retrieve_message(sock, message_number) == -1) {
        return 1;
    }

    // Delete a message from the server
    printf("Enter the number of the message you want to delete: ");
    scanf("%d", &message_number);

    if (delete_message(sock, message_number) == -1) {
        return 1;
    }

    // Quit the POP3 session
    if (quit_session(sock) == -1) {
        return 1;
    }

    // Close the socket
    close(sock);

    return 0;
}