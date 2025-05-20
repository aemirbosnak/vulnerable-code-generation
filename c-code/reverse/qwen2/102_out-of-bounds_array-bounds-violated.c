#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

void sanitize_input(char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '<' || input[i] == '>' || input[i] == '&') {
            input[i] = ' ';
        } else if (input[i] == '/') {
            input[i] = '_';
        }
    }
}

int main() {
    char name[MAX_INPUT_SIZE];
    char email[MAX_INPUT_SIZE];

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    sanitize_input(name);

    printf("Enter your email: ");
    fgets(email, sizeof(email), stdin);
    sanitize_input(email);

    printf("Welcome, %s! Your email is %s\n", name, email);

    return 0;
}
