#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void processInput(char *buffer) {
    char name[10];
    strcpy(name, buffer);
    if (strcmp(name, "admin") == 0) {
        printf("Access granted to the game engine console.\n");
        // Now we have a vulnerable spot for a buffer overflow
        char command[256];
        printf("Enter a command: ");
        gets(command);
        printf("You entered: %s\n", command);
    } else {
        printf("Incorrect password. Access denied.\n");
    }
}

int main() {
    printf("Enter your username: ");
    char input[1024];
    gets(input);
    processInput(input);
    return 0;
}
