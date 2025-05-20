//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100

void convertToDate(char *input) {
    struct tm tm;
    char buffer[80];
    char *format[] = { "%d-%m-%Y", "%m/%d/%Y", "%Y.%m.%d", "%B %d, %Y" }; // Several date formats
    int numFormats = sizeof(format) / sizeof(format[0]);
    int valid = 0;

    for (int i = 0; i < numFormats; i++) {
        if (strptime(input, format[i], &tm) != NULL) {
            valid = 1;
            break;
        }
    }

    if (valid) {
        strftime(buffer, sizeof(buffer), "%A, %d %B %Y", &tm);
        printf("Converted Date: %s\n", buffer);
    } else {
        printf("Invalid date format: %s\n", input);
    }
}

void shapeShiftingMenu() {
    printf("Welcome to the Date Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Convert a date\n");
    printf("2. Exit\n");
}

int main() {
    char input[MAX_INPUT];
    int choice;

    while (1) {
        shapeShiftingMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input, please enter a number.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        switch (choice) {
        case 1:
            printf("Enter the date (formats: dd-mm-yyyy, mm/dd/yyyy, yyyy.mm.dd, Month dd, yyyy): ");
            scanf(" %[^\n]", input); // Read a whole line
            convertToDate(input);
            break;
        case 2:
            printf("Exiting the program. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please enter 1 or 2.\n");
            break;
        }
    }

    return 0;
}