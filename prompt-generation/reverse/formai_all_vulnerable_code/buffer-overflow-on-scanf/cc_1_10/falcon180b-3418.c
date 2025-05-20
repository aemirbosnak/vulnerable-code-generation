//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Alan Turing
#include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverseString(char* str) {
    int length = strlen(str);
    char* reversed = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - i - 1];
    }
    reversed[length] = '\0';
    strcpy(str, reversed);
    free(reversed);
}

// Function to count the number of vowels in a string
int countVowels(char* str) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            count++;
        }
    }
    return count;
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i]!= str[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to remove all vowels from a string
void removeVowels(char* str) {
    int length = strlen(str);
    char* vowels = "aeiouAEIOU";
    char* result = malloc(length + 1);
    int resultIndex = 0;
    for (int i = 0; i < length; i++) {
        if (strchr(vowels, str[i]) == NULL) {
            result[resultIndex] = str[i];
            resultIndex++;
        }
    }
    result[resultIndex] = '\0';
    strcpy(str, result);
    free(result);
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    // Reverse the string
    printf("Reversed string: ");
    reverseString(input);
    printf("%s\n", input);

    // Count the number of vowels
    int vowelCount = countVowels(input);
    printf("Number of vowels: %d\n", vowelCount);

    // Check if the string is a palindrome
    int isPal = isPalindrome(input);
    if (isPal == 1) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    // Remove all vowels from the string
    printf("String without vowels: ");
    removeVowels(input);
    printf("%s\n", input);

    return 0;
}