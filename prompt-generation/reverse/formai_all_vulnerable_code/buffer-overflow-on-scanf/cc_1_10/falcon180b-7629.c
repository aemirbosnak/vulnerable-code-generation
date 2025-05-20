//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverseString(char* str) {
    int i = 0;
    int j = strlen(str) - 1;
    char temp;

    // Swap characters from both ends
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int i = 0;
    int j = strlen(str) - 1;

    // Compare characters from both ends
    while (i < j) {
        if (str[i]!= str[j]) {
            return 0;
        }
        i++;
        j--;
    }

    return 1;
}

// Function to count the number of vowels in a string
int countVowels(char* str) {
    int count = 0;

    // Iterate through the string and count vowels
    for (int i = 0; str[i]!= '\0'; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            count++;
        }
    }

    return count;
}

int main() {
    char str[100];

    // Get input string from user
    printf("Enter a string: ");
    scanf("%s", str);

    // Reverse the string
    reverseString(str);
    printf("Reversed string: %s\n", str);

    // Check if the string is a palindrome
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    // Count the number of vowels in the string
    int vowelCount = countVowels(str);
    printf("Number of vowels in the string: %d\n", vowelCount);

    return 0;
}