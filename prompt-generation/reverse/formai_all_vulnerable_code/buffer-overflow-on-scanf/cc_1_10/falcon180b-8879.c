//Falcon-180B DATASET v1.0 Category: Recursive ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print the array in reverse order
void printReverse(char *str, int start, int end) {
    char temp[100];
    int len = end - start + 1;

    // Copy the substring into temp
    strncpy(temp, str + start, len);
    temp[len] = '\0';

    // Reverse the substring
    for (int i = 0; i < len / 2; i++) {
        char c = temp[i];
        temp[i] = temp[len - i - 1];
        temp[len - i - 1] = c;
    }

    // Print the reversed substring
    printf("%s\n", temp);
}

// Recursive function to print all permutations of a string
void permute(char *str, int start, int end) {
    // Base case: if start == end, print the character
    if (start == end) {
        printf("%c\n", str[start]);
        return;
    }

    // Recursive case: permute the substring and print each permutation
    for (int i = start; i <= end; i++) {
        // Swap the first character with the current character
        char temp = str[start];
        str[start] = str[i];
        str[i] = temp;

        // Recursively permute the remaining substring
        permute(str, start + 1, end);

        // Swap the first character back
        temp = str[start];
        str[start] = str[i];
        str[i] = temp;
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Call the recursive function to print all permutations
    permute(str, 0, strlen(str) - 1);

    return 0;
}