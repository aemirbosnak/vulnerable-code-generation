//Falcon-180B DATASET v1.0 Category: Recursive ; Style: genious
#include <stdio.h>

// Function to print a string in reverse order
void reverseString(char* str, int start, int end) {
    char temp;

    // One by one move boundary of substring
    for (int i = start; i < end; i++) {

        // Swap characters at start and end
        temp = *(str+start);
        *(str+start) = *(str+end);
        *(str+end) = temp;

        // Move boundary one step forward
        start++;
        end--;
    }
}

// Function to check if a string is palindrome
int isPalindrome(char* str, int start, int end) {
    while (start < end) {
        if (*(str+start)!= *(str+end))
            return 0;
        start++;
        end--;
    }
    return 1;
}

// Recursive function to generate all permutations of a string
void generatePermutations(char* str, int start, int n) {
    // Base case: if all characters are processed, print the string
    if (start == n) {
        printf("%s ", str);
        return;
    }

    // Permutations using the current character
    for (int i = start; i <= n; i++) {
        str[start] = *(str+i);
        generatePermutations(str, start+1, n);
    }
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    // Call functions to generate palindromes and permutations
    printf("\nPalindromes:\n");
    for (int i = 0; i < strlen(input); i++) {
        for (int j = i+1; j <= strlen(input); j++) {
            reverseString(input, i, j);
            if (isPalindrome(input, 0, strlen(input)-1))
                printf("%s ", input);
        }
    }
    printf("\n\nPermutations:\n");
    generatePermutations(input, 0, strlen(input));

    return 0;
}