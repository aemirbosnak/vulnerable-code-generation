#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void edit_text(char *text, int line_number, const char *new_line) {
    if (line_number <= 0 || strlen(new_line) >= MAX_LINE_LENGTH) {
        printf("Error: Invalid input.\n");
        return;
    }

    // Simulate editing by overwriting memory
    strcpy(text + (line_number - 1) * MAX_LINE_LENGTH, new_line);
}

int main() {
    char text[10][MAX_LINE_LENGTH] = {0};
    int choice, line_number;

    while (1) {
        printf("\nText Editor Menu:\n");
        printf("1. Edit Line\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter line number to edit (1-10): ");
                scanf("%d", &line_number);
                getchar(); // Consume newline character

                printf("Enter new line (max %d characters): ", MAX_LINE_LENGTH - 1);
                fgets(text[line_number - 1], MAX_LINE_LENGTH, stdin);
                text[line_number - 1][strcspn(text[line_number - 1], "\n")] = '\0';

                edit_text((char *)text, line_number, text[line_number - 1]);
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
