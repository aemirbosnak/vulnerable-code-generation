//Falcon-180B DATASET v1.0 Category: Recursive ; Style: grateful
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
        if (*(str+i)!= *(str+length-i-1)) {
            return 0;
        }
    }
    return 1;
}

// Recursive function to generate all permutations of a string
void generatePermutations(char* str, int start, int end, char** result, int* resultSize, int* resultCapacity) {
    if (start == end) {
        // Base case: single character string is a valid permutation
        *(result+(*resultSize)++) = strdup(str);
        return;
    }
    for (int i = start; i <= end; i++) {
        str[start] = str[i];
        generatePermutations(str, start+1, end, result, resultSize, resultCapacity);
    }
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    int length = strlen(input);
    
    // Check if input string is a palindrome
    if (isPalindrome(input, length)) {
        printf("The input string is a palindrome.\n");
    }
    else {
        // Generate all permutations of the input string
        char** result = NULL;
        int resultSize = 0;
        int resultCapacity = 0;
        generatePermutations(input, 0, length-1, result, &resultSize, &resultCapacity);
        
        // Print the number of permutations and the first 10 permutations
        printf("Number of permutations: %d\n", resultSize);
        printf("First 10 permutations:\n");
        int i;
        for (i = 0; i < resultSize && i < 10; i++) {
            printf("%s\n", result[i]);
        }
        
        // Free memory allocated for result array
        for (i = 0; i < resultSize; i++) {
            free(result[i]);
        }
        free(result);
    }
    
    return 0;
}