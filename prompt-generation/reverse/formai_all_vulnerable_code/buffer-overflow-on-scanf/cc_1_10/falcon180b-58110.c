//Falcon-180B DATASET v1.0 Category: Recursive ; Style: Claude Shannon
#include<stdio.h>

// Function to print a string in reverse order
void reverseString(char str[], int start, int end) {
    char temp;
    while (start < end) {
        temp = *(str+start);
        *(str+start) = *(str+end);
        *(str+end) = temp;
        start++;
        end--;
    }
}

// Function to check if a given string is a palindrome
int isPalindrome(char str[]) {
    int len = strlen(str);
    for (int i=0; i<len/2; i++) {
        if (str[i]!= str[len-i-1])
            return 0;
    }
    return 1;
}

// Recursive function to generate all possible permutations of a given string
void permute(char str[], int left, int right) {
    // Base case: if left index equals right index, print the string
    if (left == right) {
        printf("%s\n", str);
        return;
    }

    // Recursive case: swap characters and generate permutations
    for (int i=left; i<=right; i++) {
        str[left] = str[i];
        permute(str, left+1, right);
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Check if the given string is a palindrome
    if (isPalindrome(str))
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);

    // Generate all possible permutations of the given string
    printf("All possible permutations:\n");
    permute(str, 0, strlen(str)-1);

    return 0;
}