#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_INPUT 1024

void sanitize_input(char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isalpha(input[i]) && !isspace(input[i])) {
            input[i] = ' ';
        }
    }
}

int main() {
    char name[MAX_INPUT];
    char description[MAX_INPUT];

    printf("Enter your character's name: ");
    fgets(name, sizeof(name), stdin);
    sanitize_input(name);

    printf("Describe your character's background: ");
    fgets(description, sizeof(description), stdin);
    sanitize_input(description);

    printf("\nCharacter Name: %s\n", name);
    printf("Background Description: %s\n", description);

    return 0;
}
