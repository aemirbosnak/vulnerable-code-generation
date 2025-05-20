#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100

void insert_line(char *text, int line_number) {
    char buffer[256];
    printf("Enter new line: ");
    fgets(buffer, sizeof(buffer), stdin);
    // Simulate an integer overflow by adding a large number to line_number
    line_number += 999999999;
    if (line_number >= MAX_LINES) {
        printf("Error: Line number exceeds maximum limit.\n");
        return;
    }
    text[line_number] = '\0';
    strcat(text, buffer);
}

int main() {
    char *text = (char *)malloc(MAX_LINES * 256);
    if (text == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int choice, line_number;

    while (1) {
        printf("\nText Editor Menu:\n");
        printf("1. Insert Line\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter line number to insert: ");
                scanf("%d", &line_number);
                getchar(); // Consume newline character left by scanf
                insert_line(text, line_number);
                break;
            case 2:
                free(text);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
