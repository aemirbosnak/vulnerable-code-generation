//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

// Function prototypes
void reverseString(char str[], char reversed[]);
int countVowels(const char str[]);
void swapStrings(char str1[], char str2[]);

int main() {
    char str1[MAX_LEN], str2[MAX_LEN], reversed[MAX_LEN];
    int choice, vowelCount;

    printf("Welcome to the String Manipulation Program!\n");
    printf("Please enter the first string (max %d characters): ", MAX_LEN - 1);
    fgets(str1, MAX_LEN, stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove newline character

    printf("Please enter the second string (max %d characters): ", MAX_LEN - 1);
    fgets(str2, MAX_LEN, stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove newline character

    do {
        printf("\nChoose an option:\n");
        printf("1. Reverse the first string\n");
        printf("2. Count vowels in the first string\n");
        printf("3. Swap the two strings\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the input buffer

        switch (choice) {
            case 1:
                reverseString(str1, reversed);
                printf("Reversed string: %s\n", reversed);
                break;
            case 2:
                vowelCount = countVowels(str1);
                printf("Number of vowels in the first string: %d\n", vowelCount);
                break;
            case 3:
                printf("Before swapping:\n");
                printf("String 1: %s\n", str1);
                printf("String 2: %s\n", str2);
                swapStrings(str1, str2);
                printf("After swapping:\n");
                printf("String 1: %s\n", str1);
                printf("String 2: %s\n", str2);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// Function to reverse a string
void reverseString(char str[], char reversed[]) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - i - 1];
    }
    reversed[len] = '\0'; // Null-terminate the reversed string
}

// Function to count the number of vowels in a string
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

// Function to swap two strings
void swapStrings(char str1[], char str2[]) {
    char temp[MAX_LEN];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}