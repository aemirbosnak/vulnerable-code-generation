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
    fscanf(stdin, "%s", name);
    printf("Enter your age: ");
    fscanf(stdin, "%d", &age);

    printf("Name: %s\nAge: %d\n", name, age);
}

int main() {
    char input[256];

    while (1) {
        printf("Enter a command: ");
        fgets(input, sizeof(input), stdin);

        if (input[0] == 'm') {
            handle_message(input + 2); // Simulate receiving a message
        } else if (input[0] == 'q') {
            break;
        }
    }

    return 0;
}
