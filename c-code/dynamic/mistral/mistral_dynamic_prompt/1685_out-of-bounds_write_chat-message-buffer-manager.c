#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void processMessage(char* buffer) {
    char* message = "DevOps is fun! Let's automate the world!";
    char* processedMessage = (char*) malloc(strlen(message) + BUFFER_SIZE);
    strcpy(processedMessage, message);
    strcat(processedMessage, "\n\nYou said: ");
    strcat(processedMessage, buffer);
    printf("%s", processedMessage);
    free(processedMessage);
}

int main() {
    char input[BUFFER_SIZE];
    printf("Enter your message to process (max 100 chars): ");
    fgets(input, BUFFER_SIZE, stdin);
    processMessage(input);

    char extraData[10] = "This is extra data which we should never write but just for fun, let's put it here!";
    strcpy(input, extraData);
    processMessage(input);

    return 0;
}
