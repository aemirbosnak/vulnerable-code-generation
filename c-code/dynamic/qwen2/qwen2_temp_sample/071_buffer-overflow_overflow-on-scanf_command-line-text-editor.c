#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

void edit_line(char *line) {
    printf("Enter your line: ");
    scanf("%[^\n]%*c", line);
}

int main() {
    char line[MAX_LINE_LENGTH];
    int choice;

    while (1) {
        printf("\nText Editor Menu:\n");
        printf("1. Edit Line\n");
        printf("2. Display Line\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d%*c", &choice);

        switch (choice) {
            case 1:
                edit_line(line);
                break;
            case 2:
                printf("Current Line: %s\n", line);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
