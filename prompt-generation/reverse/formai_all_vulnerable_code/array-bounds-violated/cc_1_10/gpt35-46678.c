//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void printAscii(char *input, int len);

int main()
{
    char input[1000];
    printf("Enter text to convert to ASCII art:\n");
    fgets(input, 1000, stdin);
    int len = strlen(input);
    // Remove newline character at the end of the input string
    if (input[len-1] == '\n') {
        input[len-1] = '\0';
        len--;
    }
    
    // Call recursive function to print ASCII art
    printAscii(input, len);
    
    return 0;
}

// Recursive function to print ASCII art of input string
void printAscii(char *input, int len) {
    if (len == 0) {
        return;
    }
    // Calculate index of middle character
    int mid = len / 2;
    // Check if length of string is odd or even
    int is_odd = len % 2;
    printf("\n");
    // Print top half of ASCII art
    for (int i=mid-1; i>=0; i--) {
        printf(" ");
    }
    printf("%c\n", input[mid]);
    // Print bottom half of ASCII art
    for (int i=0; i<mid; i++) {
        printf(" ");
    }
    if (is_odd) {
        printf("%c\n", input[mid+1]);
    }
    else {
        printf("%c\n", input[mid]);
    }
    // Call function recursively with left and right halves of string
    char left[1000], right[1000];
    memcpy(left, input, mid);
    left[mid] = '\0';
    int right_len = len - mid - 1;
    memcpy(right, input+mid+1, right_len);
    right[right_len] = '\0';
    printAscii(left, mid);
    printAscii(right, right_len);
}