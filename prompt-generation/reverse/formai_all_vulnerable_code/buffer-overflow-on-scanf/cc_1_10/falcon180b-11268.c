//Falcon-180B DATASET v1.0 Category: Recursive ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string
void reverseString(char *str, int start, int end) {
    char temp;
    while (start < end) {
        temp = *(str+start);
        *(str+start) = *(str+end);
        *(str+end) = temp;
        start++;
        end--;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char *str, int start, int end) {
    while (start < end) {
        if (tolower(*(str+start))!= tolower(*(str+end))) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

// Recursive function to generate all permutations of a string
void generatePermutations(char *str, int start, int end) {
    if (start == end) {
        printf("%s ", str);
        return;
    }
    for (int i = start; i <= end; i++) {
        str[start] = str[i];
        generatePermutations(str, start+1, end);
    }
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    int length = strlen(input);

    // Remove spaces and punctuation from the input string
    char *output = (char *)malloc(length*sizeof(char));
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (isalnum(input[i])) {
            output[j] = tolower(input[i]);
            j++;
        }
    }
    output[j] = '\0';

    // Check if the modified string is a palindrome
    int isPal = isPalindrome(output, 0, j-1);

    // Generate all permutations of the modified string
    printf("\nPermutations of the string (excluding spaces and punctuation):\n");
    generatePermutations(output, 0, j-1);

    if (isPal) {
        printf("\nThe modified string is a palindrome.\n");
    } else {
        printf("\nThe modified string is not a palindrome.\n");
    }

    return 0;
}