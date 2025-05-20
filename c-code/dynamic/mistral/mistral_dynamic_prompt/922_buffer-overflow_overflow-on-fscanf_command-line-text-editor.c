#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

char editor[1024];

void edit() {
    int size = sizeof(editor) - 1;
    printf("\nEditor\n");
    printf("------------------\n");
    printf("Current file: %s\n", editor);
    printf("\n[A]dd\n[L]oad\n[S]ave\n[Q]uit\n");
    char command;
    scanf("%c", &command);

    switch (command) {
        case 'A':
            // Add code here for adding text
            break;
        case 'L':
            // Load code here for loading a file
            break;
        case 'S':
            // Save code here for saving the file
            break;
        case 'Q':
            exit(0);
        default:
            printf("Invalid command.\n");
            edit(); // Recursive function call for main menu
    }
}

void main() {
    int i = 0;
    char input[256];

    printf("Enter the initial file content (enter '.' to save and exit):\n");
    while (1) {
        fgets(input, sizeof(input), stdin);

        if (strstr(input, ".") != NULL) {
            strcpy(editor, input);
            break;
        }

        strncat(editor, input, sizeof(editor) - strlen(editor) - 1);
    }

    edit();
}
