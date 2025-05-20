#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void edit_text(char *text) {
    char buffer[10];
    printf("Enter new text: ");
    if (sscanf(text, "%9s", buffer) != 1) {
        fprintf(stderr, "Error reading input.\n");
        return;
    }
    printf("Text edited to: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <initial_text>\n", argv[0]);
        return 1;
    }

    char initial_text[100];
    snprintf(initial_text, sizeof(initial_text), "%s", argv[1]);

    while (1) {
        printf("Current text: %s\n", initial_text);
        printf("Options:\n");
        printf("1. Edit text\n");
        printf("2. Exit\n");
        printf("Choose an option: ");

        int choice;
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input.\n");
            continue;
        }

        switch (choice) {
            case 1:
                edit_text(initial_text);
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}
