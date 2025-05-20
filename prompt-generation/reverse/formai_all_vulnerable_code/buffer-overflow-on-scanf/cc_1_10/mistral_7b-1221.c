//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char message[256];
    int line_number;
} error_message;

error_message error;
int gnome_appeared = 0;

void talking_gnome(const char* error_message) {
    if (!gnome_appeared) {
        printf("\nA talking gnome appears, gazing intently into a mystical crystal ball...\n");
        gnome_appeared = 1;
    }

    printf("Gnome: %s\n", error_message);

    printf("\nGnome: I see the error in the code. Let me help you clean it up.\n");
    printf("Gnome: *waves enchanted broomstick*\n");
}

void error_handler(const char* error_message, int line_number) {
    strcpy(error.message, error_message);
    error.line_number = line_number;

    talking_gnome(error_message);
}

int main(void) {
    int a, b;
    char str[256];

    printf("Once upon a time, in a land of code...\n");

    while (1) {
        printf("Enter two integers: ");
        scanf("%d%d", &a, &b);

        if (feof(stdin)) {
            error_handler("User entered EOF while scanning for integers.", __LINE__);
            continue;
        }

        printf("Enter a string: ");
        scanf("%s", str);

        if (strlen(str) > 255) {
            error_handler("String is too long.", __LINE__);
            continue;
        }

        int c = a / b;

        if (b == 0) {
            error_handler("Division by zero.", __LINE__);
            continue;
        }

        printf("The quotient of %d and %d is: %d\n", a, b, c);

        printf("Do you want to calculate another quotient? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'n') {
            printf("Thank you for using our magical error handling system! Goodbye!\n");
            break;
        }
    }

    return 0;
}