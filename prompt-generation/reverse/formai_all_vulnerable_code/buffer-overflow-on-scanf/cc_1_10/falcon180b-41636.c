//Falcon-180B DATASET v1.0 Category: Recursive ; Style: all-encompassing
#include <stdio.h>

// Function to print a string in reverse order
void reverseString(char str[]) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char str[]) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (str[i]!= str[j]) {
            return 0;
        }
    }

    return 1;
}

// Function to generate all permutations of a string
void generatePermutations(char str[], int start, int end) {
    if (start == end) {
        printf("%s ", str);
        return;
    }

    for (int i = start; i <= end; i++) {
        str[start] = str[i];
        generatePermutations(str, start + 1, end);
    }
}

// Main function
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    // Reverse the input string
    reverseString(input);

    // Check if the reversed string is equal to the original string
    if (isPalindrome(input)) {
        printf("%s is a palindrome.\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }

    // Generate all permutations of the input string
    printf("\nAll permutations of %s:\n", input);
    generatePermutations(input, 0, strlen(input) - 1);

    return 0;
}