#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 500
#define MAX_MESSAGE_SIZE 100

typedef struct {
    char message[MAX_MESSAGE_SIZE];
    int timestamp;
    char username[20];
} ChatMessage;

ChatMessage buffer[BUFFER_SIZE];
int bufferIndex = 0;

void addMessage(char* message, char* username) {
    strcpy(buffer[bufferIndex].message, message);
    strcpy(buffer[bufferIndex].username, username);
    buffer[bufferIndex].timestamp = time(NULL);
    bufferIndex = (bufferIndex + 1) % BUFFER_SIZE;
}

void printBuffer() {
    for (int i = 0; i < BUFFER_SIZE; i++) {
        printf("Time: %d | Username: %s | Message: %s\n", buffer[i].timestamp, buffer[i].username, buffer[i].message);
    }
}

int main() {
    char inputMessage[MAX_MESSAGE_SIZE];
    char inputUsername[20];

    while (1) {
        printf("Enter a message: ");
        scanf("%s", inputMessage);
        printf("Enter a username: ");
        scanf("%s", inputUsername);

        addMessage(inputMessage, inputUsername);

        system("clear");
        printBuffer();
    }

    return 0;
}
