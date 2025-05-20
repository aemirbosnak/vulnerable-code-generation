//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverseString(char* str) {
    int i = 0;
    int j = strlen(str) - 1;
    char temp;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to count the number of vowels in a string
int countVowels(char* str) {
    int count = 0;
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};

    for (int i = 0; str[i]!= '\0'; i++) {
        for (int j = 0; j < 5; j++) {
            if (str[i] == vowels[j]) {
                count++;
                break;
            }
        }
    }

    return count;
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int i = 0;
    int j = strlen(str) - 1;

    while (i < j) {
        if (str[i]!= str[j]) {
            return 0;
        }
        i++;
        j--;
    }

    return 1;
}

int main() {
    char input[100];
    int choice, length;

    // Get user input
    printf("Enter a string: ");
    scanf("%s", input);

    // Get user choice of operation
    printf("Enter your choice:\n");
    printf("1. Reverse the string\n");
    printf("2. Count the number of vowels in the string\n");
    printf("3. Check if the string is a palindrome\n");
    scanf("%d", &choice);

    // Perform operation based on user choice
    switch (choice) {
        case 1:
            reverseString(input);
            printf("Reversed string: %s\n", input);
            break;
        case 2:
            length = strlen(input);
            printf("Number of vowels: %d\n", countVowels(input));
            break;
        case 3:
            if (isPalindrome(input)) {
                printf("The string is a palindrome.\n");
            } else {
                printf("The string is not a palindrome.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}