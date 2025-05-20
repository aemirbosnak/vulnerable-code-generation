//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverse(char* str, int start, int end) {
    char temp;
    while (start < end) {
        temp = *(str+start);
        *(str+start) = *(str+end);
        *(str+end) = temp;
        start++;
        end--;
    }
}

// Function to print a string
void printString(char* str, int size) {
    printf("%s\n", str);
}

// Function to check if a string is a palindrome
int isPalindrome(char* str, int size) {
    int i;
    for (i = 0; i < size/2; i++) {
        if (*(str+i)!= *(str+size-1-i)) {
            return 0;
        }
    }
    return 1;
}

// Recursive function to generate all possible substrings of a string
void generateSubstrings(char* str, int start, int end, int size, void (*print)(char*, int), int (*check)(char*, int)) {
    if (start > end) {
        // Base case: print the empty string
        print("", 0);
        return;
    }
    // Recursive case: generate all substrings of size k
    for (int k = start; k <= end; k++) {
        int newSize = size - k;
        char* newStr = (char*)malloc(newSize+1);
        strncpy(newStr, str+k, newSize);
        newStr[newSize] = '\0';
        print(newStr, newSize);
        free(newStr);
    }
}

// Main function
int main() {
    char input[1000];
    printf("Enter a string: ");
    scanf("%s", input);
    int size = strlen(input);
    // Call the recursive function to generate all possible substrings and print them
    generateSubstrings(input, 0, size-1, size, printString, isPalindrome);
    return 0;
}