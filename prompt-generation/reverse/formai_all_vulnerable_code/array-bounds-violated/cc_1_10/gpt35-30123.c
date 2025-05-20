//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if the given string is a palindrome 
int isPalindrome(char str[])
{
    int len = strlen(str);
    int j = len - 1;
    
    // Loop through the string
    for (int i = 0; i < len; i++) {
        
        // Ignore non-alphanumeric characters
        while (!isalnum(str[i])) {
            i++;
        }
        while (!isalnum(str[j])) {
            j--;
        }
        
        // Check if the letters are the same
        if (tolower(str[i]) != tolower(str[j])) {
            return 0;
        }
        
        j--;
    }
    
    return 1;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove trailing newline if present
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    if (isPalindrome(str)) {
        printf("%s is a palindrome\n", str);
    }
    else {
        printf("%s is not a palindrome\n", str);
    }

    return 0;
}