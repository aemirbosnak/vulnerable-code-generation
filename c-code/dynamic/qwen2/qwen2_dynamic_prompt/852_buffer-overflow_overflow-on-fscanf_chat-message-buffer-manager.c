#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void handle_message(char *buffer) {
    char name[BUFFER_SIZE];
    int age;

    printf("Enter your name: ");
    if (fscanf(stdin, "%9s", name) != 1) {
        fprintf(stderr, "Error reading name\n");
        return;
    }

    printf("Enter your age: ");
    if (fscanf(stdin, "%d", &age) != 1) {
        fprintf(stderr, "Error reading age\n");
        return;
    }

    printf("Hello, %s! You are %d years old.\n", name, age);
}

int main() {
    char input[20];

    printf("Welcome to the Chat Message Buffer Manager!\n");

    while (1) {
        printf("Enter a message: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        handle_message(input);
    }

    return 0;
}
