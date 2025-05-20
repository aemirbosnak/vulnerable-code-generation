//Falcon-180B DATASET v1.0 Category: Recursive ; Style: peaceful
#include <stdio.h>

// Function to print a string in reverse order
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
int isPalindrome(char* str, int start, int end) {
    while (start < end) {
        if (*(str+start)!= *(str+end)) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

// Recursive function to generate all permutations of a string
void generatePermutations(char* str, int start, int end) {
    if (start == end) {
        printf("%s\n", str);
        return;
    }
    for (int i = start; i <= end; i++) {
        str[start] = *(str+i);
        generatePermutations(str, start+1, end);
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int n = strlen(str);

    // Call functions here
    reverseString(str, 0, n-1);
    printf("\nReversed string: %s\n", str);

    int result = isPalindrome(str, 0, n-1);
    if (result == 1) {
        printf("\nThe string is a palindrome.\n");
    } else {
        printf("\nThe string is not a palindrome.\n");
    }

    generatePermutations(str, 0, n-1);

    return 0;
}