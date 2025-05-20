#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void vulnerableFunction(char *input) {
    int number;
    char name[20];
    
    printf("Enter a number: ");
    if (sscanf(input, "%d", &number) == 1) {
        printf("Number entered: %d\n", number);
    } else {
        printf("Invalid input.\n");
    }
    
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    printf("Hello, %s\n", name);
}

int main() {
    char userInput[100];
    
    printf("Welcome to the Text-Based Game Engine!\n");
    printf("Type 'play' to start the game or 'exit' to quit.\n");
    while (1) {
        printf("> ");
        fgets(userInput, sizeof(userInput), stdin);
        if (strncmp(userInput, "play", 4) == 0) {
            vulnerableFunction("999999999999999999"); // Deliberate buffer overflow input
            break;
        } else if (strncmp(userInput, "exit", 4) == 0) {
            break;
        } else {
            printf("Unknown command.\n");
        }
    }
    
    return 0;
}
