//Falcon-180B DATASET v1.0 Category: Recursive ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

// Function to reverse a given string
void reverseString(char* str) {
    int i = 0, j = strlen(str) - 1;
    char temp;

    // Swap characters starting from both ends
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to print a given string in reverse order
void printReverse(char* str) {
    int i = 0;

    // Iterate through the string and print each character in reverse order
    while (str[i]!= '\0') {
        printf("%c", str[i]);
        i++;
    }
}

// Recursive function to print a given string in reverse order
void recursivePrintReverse(char* str, int start, int end) {
    if (start >= end) {
        printf("%c", str[start]);
        return;
    }

    // Recursively call the function with incremented start index and decremented end index
    recursivePrintReverse(str, start + 1, end - 1);

    // Print the last character
    printf("%c", str[end]);
}

int main() {
    char str[100];

    // Get input string from user
    printf("Enter a string: ");
    scanf("%s", str);

    // Reverse the input string
    reverseString(str);

    // Print the reversed string in reverse order
    printf("\nReversed string in reverse order:\n");
    recursivePrintReverse(str, 0, strlen(str) - 1);

    return 0;
}