//FormAI DATASET v1.0 Category: Browser Plugin ; Style: future-proof
#include <stdio.h>

// Function to check if a given string is a palindrome
int isPalindrome(char str[])
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to reverse a given string
void reverseString(char str[])
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to handle user input and output results
void handleInput()
{
    while (1) {
        // Get user input
        char input[100];
        printf("Enter a string: ");
        scanf("%s", input);

        // Check if the string is a palindrome
        int result = isPalindrome(input);
        if (result == 1) {
            printf("This is a palindrome!\n");
        } else {
            printf("This is not a palindrome!\n");
        }

        // Reverse the string
        reverseString(input);
        printf("Reversed string: %s\n", input);
    }
}

// Main function
int main()
{
    handleInput();
    return 0;
}