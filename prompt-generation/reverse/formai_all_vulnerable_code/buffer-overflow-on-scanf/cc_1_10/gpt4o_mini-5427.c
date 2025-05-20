//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: protected
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void reverseString(char str[]);
int isPalindrome(char str[]);
int countVowels(const char str[]);
int countConsonants(const char str[]);
void concatenateStrings(char result[], const char str1[], const char str2[]);

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH], result[MAX_LENGTH * 2];
    int choice;

    printf("String Manipulation Program\n");
    printf("1. Reverse a string\n");
    printf("2. Check if a string is a palindrome\n");
    printf("3. Count vowels and consonants in a string\n");
    printf("4. Concatenate two strings\n");
    printf("5. Exit\n");

    while (1) {
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter a string to reverse: ");
                fgets(str1, MAX_LENGTH, stdin);
                str1[strcspn(str1, "\n")] = '\0'; // Remove newline character
                reverseString(str1);
                printf("Reversed string: %s\n", str1);
                break;

            case 2:
                printf("Enter a string to check for palindrome: ");
                fgets(str1, MAX_LENGTH, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                if (isPalindrome(str1)) {
                    printf("\"%s\" is a palindrome.\n", str1);
                } else {
                    printf("\"%s\" is not a palindrome.\n", str1);
                }
                break;

            case 3:
                printf("Enter a string to count vowels and consonants: ");
                fgets(str1, MAX_LENGTH, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                int vowels = countVowels(str1);
                int consonants = countConsonants(str1);
                printf("Vowels: %d, Consonants: %d\n", vowels, consonants);
                break;

            case 4:
                printf("Enter the first string: ");
                fgets(str1, MAX_LENGTH, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Enter the second string: ");
                fgets(str2, MAX_LENGTH, stdin);
                str2[strcspn(str2, "\n")] = '\0';
                concatenateStrings(result, str1, str2);
                printf("Concatenated string: %s\n", result);
                break;

            case 5:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}

void reverseString(char str[]) {
    int n = strlen(str);
    char temp;
    for (int i = 0; i < n / 2; i++) {
        temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

int isPalindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (tolower(str[left]) != tolower(str[right])) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    return 1; // Is a palindrome
}

int countVowels(const char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

int countConsonants(const char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (isalnum(ch) && !(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
            count++;
        }
    }
    return count;
}

void concatenateStrings(char result[], const char str1[], const char str2[]) {
    strcpy(result, str1);
    strcat(result, str2);
}