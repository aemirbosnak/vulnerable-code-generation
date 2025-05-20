//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void reverseString(char* str);
void concatenateStrings(char* str1, char* str2, char* result);
void changeCase(char* str);
int countVowels(const char* str);
void displayMenu();

int main() {
    int choice;
    char str1[256], str2[256], result[512];

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after choice input

        switch (choice) {
            case 1:
                printf("Enter a string to reverse: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0'; // Remove newline character
                reverseString(str1);
                break;

            case 2:
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0'; // Remove newline character
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0'; // Remove newline character
                concatenateStrings(str1, str2, result);
                printf("Concatenated String: %s\n", result);
                break;

            case 3:
                printf("Enter a string to change case: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0'; // Remove newline character
                changeCase(str1);
                break;

            case 4:
                printf("Enter a string to count vowels: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0'; // Remove newline character
                int vowelCount = countVowels(str1);
                printf("Number of vowels in the string: %d\n", vowelCount);
                break;

            case 5:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }

        printf("\n");

    } while (choice != 5);

    return 0;
}

void reverseString(char* str) {
    int len = strlen(str);
    char* reversed = (char*)malloc(len + 1);
    if (!reversed) {
        printf("Memory allocation failed!\n");
        return;
    }

    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0';
    printf("Reversed String: %s\n", reversed);
    free(reversed);
}

void concatenateStrings(char* str1, char* str2, char* result) {
    strcpy(result, str1);
    strcat(result, str2);
}

void changeCase(char* str) {
    for (int i = 0; str[i]; i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        } else if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
    printf("Changed Case String: %s\n", str);
}

int countVowels(const char* str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (strchr("aeiouAEIOU", str[i])) {
            count++;
        }
    }
    return count;
}

void displayMenu() {
    printf("String Manipulation Menu:\n");
    printf("1. Reverse a string\n");
    printf("2. Concatenate two strings\n");
    printf("3. Change the case of a string\n");
    printf("4. Count vowels in a string\n");
    printf("5. Exit\n");
}