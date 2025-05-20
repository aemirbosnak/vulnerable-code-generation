//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void reverseString(char* str);
int isPalindrome(char* str);
void countVowelsConsonants(char* str, int* vowels, int* consonants);
void convertCase(char* str);
void displayMenu();

int main() {
    char str[MAX_LENGTH];
    int option;
    int vowels, consonants;

    printf("Enter a string (max %d characters): ", MAX_LENGTH - 1);
    fgets(str, MAX_LENGTH, stdin);
    
    // Remove the newline character if present
    str[strcspn(str, "\n")] = 0;

    do {
        displayMenu();
        printf("Choose an option (1-6): ");
        scanf("%d", &option);
        getchar();  // Clear the newline character from the input buffer
        
        switch (option) {
            case 1:
                printf("Original String: %s\n", str);
                reverseString(str);
                printf("Reversed String: %s\n", str);
                break;

            case 2:
                if (isPalindrome(str)) {
                    printf("The string is a palindrome.\n");
                } else {
                    printf("The string is not a palindrome.\n");
                }
                break;

            case 3:
                vowels = consonants = 0;
                countVowelsConsonants(str, &vowels, &consonants);
                printf("Vowels: %d, Consonants: %d\n", vowels, consonants);
                break;

            case 4:
                convertCase(str);
                printf("Converted Case: %s\n", str);
                break;

            case 5:
                printf("The length of the string is: %lu\n", strlen(str));
                break;

            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }
        
        printf("\n");
    } while (option != 6);

    return 0;
}

void reverseString(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

int isPalindrome(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}

void countVowelsConsonants(char* str, int* vowels, int* consonants) {
    *vowels = *consonants = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (isalpha(ch)) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                (*vowels)++;
            } else {
                (*consonants)++;
            }
        }
    }
}

void convertCase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        } else {
            str[i] = toupper(str[i]);
        }
    }
}

void displayMenu() {
    printf("=== String Manipulation Menu ===\n");
    printf("1. Reverse the string\n");
    printf("2. Check if the string is a palindrome\n");
    printf("3. Count vowels and consonants\n");
    printf("4. Convert case (uppercase to lowercase and vice versa)\n");
    printf("5. Get the length of the string\n");
    printf("6. Exit\n");
}