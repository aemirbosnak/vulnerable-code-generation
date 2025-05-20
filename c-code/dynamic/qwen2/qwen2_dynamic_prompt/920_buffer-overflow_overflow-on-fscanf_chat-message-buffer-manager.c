#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void process_message(char *buffer) {
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

    printf("Name: %s, Age: %d\n", name, age);
}

int main() {
    char input[20];

    printf("Welcome to the Chat Message Buffer Manager!\n");

    while (1) {
        printf("Enter a message: ");
        fgets(input, sizeof(input), stdin);

        if (input[0] == 'q' || input[0] == 'Q') {
            break;
        }

        process_message(input);
    }

    return 0;
}
