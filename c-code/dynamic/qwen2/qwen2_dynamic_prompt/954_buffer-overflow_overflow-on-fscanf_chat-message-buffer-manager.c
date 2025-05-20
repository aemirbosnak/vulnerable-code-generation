#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

void handle_message(char *buffer) {
    char name[BUFFER_SIZE];
    int age;

    printf("Enter your name: ");
    if (fscanf(stdin, "%15s", name) != 1) {
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
    char input[256];

    printf("Welcome to the Chat Message Buffer Manager!\n");

    while (1) {
        printf("Enter a message: ");
        fgets(input, sizeof(input), stdin);

        if (input[0] == 'q' || input[0] == 'Q') {
            break;
        }

        handle_message(input);
    }

    return 0;
}
