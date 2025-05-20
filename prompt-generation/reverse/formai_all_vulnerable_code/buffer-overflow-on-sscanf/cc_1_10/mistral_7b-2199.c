//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 100
#define MIN_NUMBER 1
#define MAX_NUMBER 10

bool is_valid_input(char *input, int *number) {
    bool valid = true;
    int num;

    if (strlen(input) > MAX_INPUT_SIZE) {
        printf("Error: Input too long.\n");
        valid = false;
        return valid;
    }

    if (sscanf(input, "%d%n", &num, &input[*number]) != 1) {
        printf("Error: Invalid input.\n");
        valid = false;
        return valid;
    }

    if (number && (*number < 0 || *number >= strlen(input))) {
        printf("Error: Invalid input format.\n");
        valid = false;
        return valid;
    }

    if (number && num < MIN_NUMBER || num > MAX_NUMBER) {
        printf("Error: Number out of range.\n");
        valid = false;
        return valid;
    }

    *number = strlen(input) - (*number);

    return valid;
}

void print_menu() {
    printf("\n--- MENU ---\n");
    printf("1. Input number\n");
    printf("2. Exit\n");
}

int main() {
    char input[MAX_INPUT_SIZE];
    int number;
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;

                if (is_valid_input(input, &number)) {
                    printf("You entered: %d\n", number);
                }

                break;
            case 2:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}