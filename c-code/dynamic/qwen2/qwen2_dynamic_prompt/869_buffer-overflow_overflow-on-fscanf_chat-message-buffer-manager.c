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
    fscanf(stdin, "%s", name);
    printf("Enter your age: ");
    fscanf(stdin, "%d", &age);

    printf("Name: %s\nAge: %d\n", name, age);
}

int main() {
    char input[200];

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
