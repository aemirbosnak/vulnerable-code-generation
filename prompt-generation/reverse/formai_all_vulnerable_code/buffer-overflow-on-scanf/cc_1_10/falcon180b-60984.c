//Falcon-180B DATASET v1.0 Category: Recursive ; Style: shape shifting
#include <stdio.h>

// Function to print a string in reverse order
void reverseString(char str[]) {
    int i, j;
    for (i = strlen(str) - 1, j = 0; i >= j; i--, j++) {
        printf("%c", str[i]);
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char str[]) {
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (str[i]!= str[j]) {
            return 0;
        }
    }
    return 1;
}

// Recursive function to generate all permutations of a string
void permute(char str[], int l, int r) {
    if (l == r) {
        printf("%s ", str);
        return;
    }
    for (int i = l; i <= r; i++) {
        str[l], str[i] = str[i], str[l];
        permute(str, l + 1, r);
        str[l], str[i] = str[i], str[l];
    }
}

int main() {
    char str[100];
    
    // Get input string from user
    printf("Enter a string: ");
    scanf("%s", str);
    
    // Check if the string is a palindrome
    if (isPalindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }
    
    // Generate all permutations of the string
    printf("All permutations of %s:\n", str);
    permute(str, 0, strlen(str) - 1);
    
    return 0;
}