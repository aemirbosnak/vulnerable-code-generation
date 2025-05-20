#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

char editor[MAX_SIZE];

void print_editor() {
    for (int i = 0; i < MAX_SIZE; ++i) {
        printf("%c", editor[i]);
    }
    printf("\n");
}

void edit_mode() {
    char input[10];
    printf("Edit mode. Enter 'q' to quit.\n");
    while (1) {
        fgets(input, sizeof(input), stdin);
        strncat(editor, input, sizeof(editor) - strlen(editor) - 1);
        print_editor();
        if (strcmp(input, "q\n") == 0) {
            break;
        }
    }
}

int main() {
    char buffer[10];

    printf("Text editor.\n");
    while (1) {
        printf("Type 'e' to enter edit mode.\n");
        fgets(buffer, sizeof(buffer), stdin);
        if (strcmp(buffer, "e\n") == 0) {
            edit_mode();
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
