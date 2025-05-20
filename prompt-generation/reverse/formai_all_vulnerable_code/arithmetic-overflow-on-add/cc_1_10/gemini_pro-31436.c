//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

// The two lovers, Romeo and Juliet
struct lover {
    char *name;
    int socket;
    struct sockaddr_in addr;
};

// Initialize a lover
void init_lover(struct lover *lover, char *name, char *ip, int port) {
    lover->name = strdup(name);
    lover->socket = socket(AF_INET, SOCK_STREAM, 0);
    lover->addr.sin_family = AF_INET;
    lover->addr.sin_addr.s_addr = inet_addr(ip);
    lover->addr.sin_port = htons(port);
}

// Send a message from one lover to another
void send_message(struct lover *sender, struct lover *receiver, char *message) {
    int len = strlen(message);
    send(sender->socket, &len, sizeof(len), 0);
    send(sender->socket, message, len, 0);
}

// Receive a message from one lover to another
char *receive_message(struct lover *receiver) {
    int len;
    recv(receiver->socket, &len, sizeof(len), 0);
    char *message = malloc(len + 1);
    recv(receiver->socket, message, len, 0);
    message[len] = '\0';
    return message;
}

// The main function
int main() {
    // Initialize the two lovers
    struct lover romeo, juliet;
    init_lover(&romeo, "Romeo", "127.0.0.1", 8080);
    init_lover(&juliet, "Juliet", "127.0.0.1", 8081);

    // Connect the two lovers
    if (connect(romeo.socket, (struct sockaddr *)&romeo.addr, sizeof(romeo.addr)) == -1) {
        perror("Romeo: connect");
        exit(1);
    }
    if (connect(juliet.socket, (struct sockaddr *)&juliet.addr, sizeof(juliet.addr)) == -1) {
        perror("Juliet: connect");
        exit(1);
    }

    // The conversation between the two lovers
    char *message;
    while (1) {
        // Romeo sends a message to Juliet
        message = receive_message(&romeo);
        printf("Romeo: %s\n", message);
        free(message);

        // Juliet sends a message to Romeo
        message = receive_message(&juliet);
        printf("Juliet: %s\n", message);
        free(message);
    }

    // Close the two lovers
    close(romeo.socket);
    close(juliet.socket);

    return 0;
}