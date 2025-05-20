#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void readMessage(char *buffer) {
    fgets(buffer, BUFFER_SIZE, stdin);
}

void printMessage(char *buffer) {
    printf("%s", buffer);
}

int main() {
    char message[BUFFER_SIZE];
    char *end;

    printf("Enter your message (max length: %d):\n", BUFFER_SIZE);
    readMessage(message);

    // Oops! Buffer overflow as input is not checked for size
    strcat(message, " Extra characters appended for fun!");

    printMessage(message);

    return 0;
}
