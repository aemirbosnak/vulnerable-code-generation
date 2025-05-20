//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: optimized
// POP3 Client example program in optimized style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

#define POP3_PORT 110
#define MAX_MSG_SIZE 1024
#define MAX_LINE_SIZE 256
#define MAX_MSGS 100

typedef struct {
    char subject[MAX_LINE_SIZE];
    char from[MAX_LINE_SIZE];
    char date[MAX_LINE_SIZE];
    char msg_id[MAX_LINE_SIZE];
    char body[MAX_MSG_SIZE];
} POP3Message;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <server> <user>\n", argv[0]);
        return 1;
    }

    // Get server and user information from command line arguments
    char *server = argv[1];
    char *user = argv[2];

    // Create a socket for the POP3 connection
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    // Connect to the POP3 server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, server, &server_addr.sin_addr);
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        close(sock);
        return 1;
    }

    // Get the list of messages
    char line[MAX_LINE_SIZE];
    if (recv(sock, line, MAX_LINE_SIZE, 0) == -1) {
        perror("recv");
        close(sock);
        return 1;
    }

    // Parse the list of messages and get the total number of messages
    int num_msgs = 0;
    char *ptr = strtok(line, " ");
    while (ptr != NULL) {
        if (strcmp(ptr, "+OK") == 0) {
            num_msgs++;
        }
        ptr = strtok(NULL, " ");
    }

    // Allocate memory for the messages
    POP3Message *msgs = malloc(num_msgs * sizeof(POP3Message));
    if (msgs == NULL) {
        perror("malloc");
        close(sock);
        return 1;
    }

    // Get the list of messages again and extract the information
    if (recv(sock, line, MAX_LINE_SIZE, 0) == -1) {
        perror("recv");
        close(sock);
        return 1;
    }

    int msg_index = 0;
    ptr = strtok(line, " ");
    while (ptr != NULL) {
        if (strcmp(ptr, "+OK") == 0) {
            // Get the message size
            if (recv(sock, line, MAX_LINE_SIZE, 0) == -1) {
                perror("recv");
                close(sock);
                return 1;
            }
            int msg_size = atoi(line);

            // Get the message body
            char msg_body[msg_size];
            if (recv(sock, msg_body, msg_size, 0) == -1) {
                perror("recv");
                close(sock);
                return 1;
            }

            // Parse the message body and extract the information
            char *msg_ptr = strtok(msg_body, "\n");
            while (msg_ptr != NULL) {
                if (strncmp(msg_ptr, "Subject: ", 9) == 0) {
                    strcpy(msgs[msg_index].subject, msg_ptr + 9);
                } else if (strncmp(msg_ptr, "From: ", 6) == 0) {
                    strcpy(msgs[msg_index].from, msg_ptr + 6);
                } else if (strncmp(msg_ptr, "Date: ", 6) == 0) {
                    strcpy(msgs[msg_index].date, msg_ptr + 6);
                } else if (strncmp(msg_ptr, "Message-ID: ", 12) == 0) {
                    strcpy(msgs[msg_index].msg_id, msg_ptr + 12);
                } else {
                    strcpy(msgs[msg_index].body, msg_ptr);
                }
                msg_ptr = strtok(NULL, "\n");
            }

            msg_index++;
        }
        ptr = strtok(NULL, " ");
    }

    // Print the messages
    for (int i = 0; i < num_msgs; i++) {
        printf("Subject: %s\n", msgs[i].subject);
        printf("From: %s\n", msgs[i].from);
        printf("Date: %s\n", msgs[i].date);
        printf("Message-ID: %s\n", msgs[i].msg_id);
        printf("Body: %s\n", msgs[i].body);
    }

    // Clean up
    free(msgs);
    close(sock);

    return 0;
}