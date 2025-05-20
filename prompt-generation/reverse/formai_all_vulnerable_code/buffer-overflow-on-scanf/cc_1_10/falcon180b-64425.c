//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverse(char* str) {
    int i, j;
    char temp;
    
    // Iterate through half of the string
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        // Swap characters
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to remove vowels from a string
void remove_vowels(char* str) {
    char vowels[] = "aeiouAEIOU";
    char* p;
    
    // Iterate through the string
    for (p = str; *p!= '\0'; p++) {
        // Check if the character is a vowel
        if (strchr(vowels, *p)!= NULL) {
            // Remove the vowel
            *p = '\0';
        }
    }
}

// Function to check if a string is a palindrome
int is_palindrome(char* str) {
    int i, j;
    
    // Iterate through half of the string
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        // Check if characters match
        if (str[i]!= str[j]) {
            // Not a palindrome
            return 0;
        }
    }
    
    // Palindrome
    return 1;
}

int main() {
    char str[100];
    
    // Get input string from user
    printf("Enter a string: ");
    scanf("%s", str);
    
    // Reverse the string
    reverse(str);
    printf("Reversed string: %s\n", str);
    
    // Remove vowels from the string
    remove_vowels(str);
    printf("String without vowels: %s\n", str);
    
    // Check if the string is a palindrome
    if (is_palindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    
    return 0;
}