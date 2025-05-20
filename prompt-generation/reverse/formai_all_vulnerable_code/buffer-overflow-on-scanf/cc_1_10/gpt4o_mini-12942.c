//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256

void cryptic_transform(char *str, int shift) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            char base = islower(str[i]) ? 'a' : 'A';
            str[i] = (str[i] - base + shift) % 26 + base;
        }
    }
}

void cryptic_reverse(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void cryptic_uppercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void cryptic_lowercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

void cryptic_duplicate(const char *str, char *result) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        result[j++] = str[i];
        result[j++] = str[i];
    }
    result[j] = '\0';
}

void print_menu() {
    printf("Cryptic String Manipulation Menu:\n");
    printf("1. Transform (Caesar Cipher)\n");
    printf("2. Reverse\n");
    printf("3. Uppercase\n");
    printf("4. Lowercase\n");
    printf("5. Duplicate\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char input[MAX_LENGTH];
    char result[MAX_LENGTH * 2];  // To account for duplication
    int choice, shift;

    while (1) {
        printf("Enter your string (max %d characters): ", MAX_LENGTH - 1);
        fgets(input, MAX_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove trailing newline

        print_menu();
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter shift value for transformation: ");
                scanf("%d", &shift);
                getchar(); // consume newline
                cryptic_transform(input, shift);
                printf("Transformed string: %s\n", input);
                break;

            case 2:
                cryptic_reverse(input);
                printf("Reversed string: %s\n", input);
                break;

            case 3:
                cryptic_uppercase(input);
                printf("Uppercase string: %s\n", input);
                break;

            case 4:
                cryptic_lowercase(input);
                printf("Lowercase string: %s\n", input);
                break;

            case 5:
                cryptic_duplicate(input, result);
                printf("Duplicated string: %s\n", result);
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\n"); // New line for better readability
    }
    return 0;
}