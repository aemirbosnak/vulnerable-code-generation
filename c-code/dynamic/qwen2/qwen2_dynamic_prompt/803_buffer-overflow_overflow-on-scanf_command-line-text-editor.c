#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 10

void edit_text(char *text) {
    char input[MAX_LINE_LENGTH];
    printf("Enter text to edit: ");
    scanf("%s", input);
    strcat(text, input);
}

int main() {
    char text[20] = "Initial text";
    int choice;

    while (1) {
        printf("\nText Editor Menu:\n");
        printf("1. Edit Text\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            edit_text(text);
        } else if (choice == 2) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }

    printf("Final text: %s\n", text);
    return 0;
}
