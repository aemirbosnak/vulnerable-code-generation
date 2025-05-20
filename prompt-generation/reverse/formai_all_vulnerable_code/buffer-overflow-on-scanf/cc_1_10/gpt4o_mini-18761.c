//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 256

void displayMenu() {
    printf("=== Cryptic String Manipulation ===\n");
    printf("1. Reverse a String\n");
    printf("2. Convert to Uppercase\n");
    printf("3. Convert to Lowercase\n");
    printf("4. Count Vowels and Consonants\n");
    printf("5. Merge Two Strings\n");
    printf("6. Exit\n");
    printf("===================================\n");
}

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void countVowelsAndConsonants(const char *str, int *vowels, int *consonants) {
    *vowels = 0;
    *consonants = 0;
    for (int i = 0; str[i]; i++) {
        char ch = tolower(str[i]);
        if (isalpha(ch)) {
            if (strchr("aeiou", ch)) {
                (*vowels)++;
            } else {
                (*consonants)++;
            }
        }
    }
}

void mergeStrings(char *dest, const char *src) {
    strcat(dest, src);
}

int main() {
    char str1[MAX_STR_LEN], str2[MAX_STR_LEN];
    int choice, vowels, consonants;

    while (1) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter a string to reverse: ");
                fgets(str1, MAX_STR_LEN, stdin);
                str1[strcspn(str1, "\n")] = 0; // Remove newline
                reverseString(str1);
                printf("Reversed String: %s\n", str1);
                break;

            case 2:
                printf("Enter a string to convert to uppercase: ");
                fgets(str1, MAX_STR_LEN, stdin);
                str1[strcspn(str1, "\n")] = 0; // Remove newline
                toUpperCase(str1);
                printf("Uppercase String: %s\n", str1);
                break;

            case 3:
                printf("Enter a string to convert to lowercase: ");
                fgets(str1, MAX_STR_LEN, stdin);
                str1[strcspn(str1, "\n")] = 0; // Remove newline
                toLowerCase(str1);
                printf("Lowercase String: %s\n", str1);
                break;

            case 4:
                printf("Enter a string to count vowels and consonants: ");
                fgets(str1, MAX_STR_LEN, stdin);
                str1[strcspn(str1, "\n")] = 0; // Remove newline
                countVowelsAndConsonants(str1, &vowels, &consonants);
                printf("Vowels: %d, Consonants: %d\n", vowels, consonants);
                break;

            case 5:
                printf("Enter the first string: ");
                fgets(str1, MAX_STR_LEN, stdin);
                str1[strcspn(str1, "\n")] = 0; // Remove newline
                printf("Enter the second string: ");
                fgets(str2, MAX_STR_LEN, stdin);
                str2[strcspn(str2, "\n")] = 0; // Remove newline
                mergeStrings(str1, str2);
                printf("Merged String: %s\n", str1);
                break;

            case 6:
                printf("Exiting the program...\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
        
        printf("\n");
    }

    return 0;
}