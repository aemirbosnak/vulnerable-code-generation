//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverse(char* str) {
    int len = strlen(str);
    char temp[len];
    int i, j;

    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp[i] = str[j];
        temp[j] = str[i];
    }

    strcpy(str, temp);
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int len = strlen(str);
    int i;

    for (i = 0; i < len / 2; i++) {
        if (str[i]!= str[len - i - 1]) {
            return 0;
        }
    }

    return 1;
}

// Function to remove all consonants from a string
void removeConsonants(char* str) {
    int i;

    for (i = 0; str[i]!= '\0'; i++) {
        if (str[i]!= 'a' && str[i]!= 'e' && str[i]!= 'i' && str[i]!= 'o' && str[i]!= 'u') {
            str[i] = '\0';
        }
    }
}

// Function to count the number of vowels in a string
int countVowels(char* str) {
    int i, count = 0;

    for (i = 0; str[i]!= '\0'; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            count++;
        }
    }

    return count;
}

int main() {
    char str[100];

    // Get user input
    printf("Enter a string: ");
    scanf("%s", str);

    // Reverse the string
    reverse(str);
    printf("Reversed string: %s\n", str);

    // Check if the string is a palindrome
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    // Remove all consonants from the string
    removeConsonants(str);
    printf("String with consonants removed: %s\n", str);

    // Count the number of vowels in the string
    int vowelCount = countVowels(str);
    printf("Number of vowels in the string: %d\n", vowelCount);

    return 0;
}