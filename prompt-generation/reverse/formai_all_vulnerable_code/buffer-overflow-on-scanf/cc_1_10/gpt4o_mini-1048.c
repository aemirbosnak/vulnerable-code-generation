//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: high level of detail
#include <stdio.h>
#include <string.h>

// Function prototype
void permute(char *str, int left, int right);

// Main function
int main() {
    char str[100];
    
    // Input string from user
    printf("Enter a string: ");
    scanf("%s", str);
    
    // Calculate the length of the string
    int n = strlen(str);
    
    // Generate all permutations
    printf("All permutations of the string \"%s\" are:\n", str);
    permute(str, 0, n - 1);
    
    return 0;
}

// Helper function to swap characters at position i and j in a string
void swap(char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Recursive function to generate permutations of the string
void permute(char *str, int left, int right) {
    // Base case: if left index is equal to right index,
    // we have a complete permutation, we print it
    if (left == right) {
        printf("%s\n", str);
    } else {
        // Iterate through the string,
        // fixing one character at a time
        for (int i = left; i <= right; i++) {
            // Swap the current character with the leftmost character
            swap((str + left), (str + i));
            
            // Recursively call permute() with the next left index
            permute(str, left + 1, right);
            
            // Backtrack: restore the original string
            swap((str + left), (str + i)); // backtrack
        }
    }
}