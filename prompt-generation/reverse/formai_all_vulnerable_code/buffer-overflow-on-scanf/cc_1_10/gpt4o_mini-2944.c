//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void to_uppercase(char str[]);
void to_lowercase(char str[]);
void reverse_string(char str[]);
void count_vowels_consonants(char str[]);
void find_substring(char str[], char sub[]);

int main() {
    char str[MAX_LENGTH];
    char sub[MAX_LENGTH];

    printf("Welcome to the String Analyzer!\n");
    printf("Please enter a string (max %d characters): ", MAX_LENGTH - 1);
    fgets(str, MAX_LENGTH, stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = 0;

    int choice;
    do {
        printf("\nChoose an operation:\n");
        printf("1. Convert to Uppercase\n");
        printf("2. Convert to Lowercase\n");
        printf("3. Reverse the String\n");
        printf("4. Count Vowels and Consonants\n");
        printf("5. Find a Substring\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from the buffer

        switch (choice) {
            case 1:
                to_uppercase(str);
                printf("Uppercase: %s\n", str);
                break;
            case 2:
                to_lowercase(str);
                printf("Lowercase: %s\n", str);
                break;
            case 3:
                reverse_string(str);
                printf("Reversed: %s\n", str);
                break;
            case 4:
                count_vowels_consonants(str);
                break;
            case 5:
                printf("Enter a substring to find: ");
                fgets(sub, MAX_LENGTH, stdin);
                sub[strcspn(sub, "\n")] = 0; // Remove newline
                find_substring(str, sub);
                break;
            case 6:
                printf("Exiting the String Analyzer. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

void to_uppercase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void to_lowercase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void reverse_string(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void count_vowels_consonants(char str[]) {
    int vowels = 0, consonants = 0;
    
    for (int i = 0; str[i]; i++) {
        char c = tolower(str[i]);
        if (isalpha(c)) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    
    printf("Vowels: %d, Consonants: %d\n", vowels, consonants);
}

void find_substring(char str[], char sub[]) {
    if (strstr(str, sub) != NULL) {
        printf("Substring '%s' found in the string!\n", sub);
    } else {
        printf("Substring '%s' not found in the string.\n", sub);
    }
}