//Falcon-180B DATASET v1.0 Category: Recursive ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverseString(char* str, int start, int end) {
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
int isPalindrome(char* str, int length) {
    int i;
    for (i = 0; i < length/2; i++) {
        if (*(str+i)!= *(str+length-1-i)) {
            return 0;
        }
    }
    return 1;
}

// Recursive function to generate all permutations of a string
void generatePermutations(char* str, int start, int end) {
    int i;
    if (start == end) {
        printf("%s ", str);
        return;
    }
    for (i = start; i <= end; i++) {
        strcpy(str+start, str+i);
        generatePermutations(str, start+1, end);
    }
}

// Main function
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    int length = strlen(input);

    // Check if the input string is a palindrome
    if (isPalindrome(input, length)) {
        printf("The input string is a palindrome.\n");
    } else {
        printf("The input string is not a palindrome.\n");
    }

    // Generate all permutations of the input string
    printf("\nAll permutations of the input string:\n");
    generatePermutations(input, 0, length-1);

    return 0;
}