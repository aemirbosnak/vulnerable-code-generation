#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 10

void vulnerable_editor() {
    char buffer[MAX_INPUT_SIZE];
    printf("Welcome to the Vulnerable Text Editor!\n");
    printf("Enter your text: ");
    scanf("%s", buffer);
    printf("You entered: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <option>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "-v") == 0) {
        vulnerable_editor();
    } else {
        fprintf(stderr, "Invalid option: %s\n", argv[1]);
        return 1;
    }

    return 0;
}
