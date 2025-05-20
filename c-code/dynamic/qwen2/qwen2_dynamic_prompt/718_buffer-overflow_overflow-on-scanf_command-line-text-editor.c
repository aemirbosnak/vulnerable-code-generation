#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void edit_text(char *text) {
    char buffer[10];
    printf("Enter new text: ");
    scanf("%s", buffer);
    strcat(text, buffer);
}

int main() {
    char *text = malloc(20);
    if (text == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    strcpy(text, "Initial text");

    while (1) {
        printf("Current text: %s\n", text);
        printf("1. Edit text\n2. Exit\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            edit_text(text);
        } else if (choice == 2) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    free(text);
    return 0;
}
