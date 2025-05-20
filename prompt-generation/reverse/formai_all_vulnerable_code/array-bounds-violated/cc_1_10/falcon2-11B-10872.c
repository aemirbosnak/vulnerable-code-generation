//Falcon2-11B DATASET v1.0 Category: Palindrome Checker ; Style: romantic
#include <stdio.h>

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        if (str[start++]!= str[end--]) {
            return 0;
        }
    }
    return 1;
}

// Function to generate a palindrome of a given length
char* generatePalindrome(int length) {
    char temp[length + 1];
    temp[length] = '\0';
    int i;

    for (i = 0; i < length; i++) {
        temp[i] = 'a';
    }

    for (i = 0; i < length; i++) {
        printf("%c", temp[length - i - 1]);
    }
    printf("\n");

    return temp;
}

int main() {
    int length;
    char* pal;

    printf("Enter the length of the palindrome: ");
    scanf("%d", &length);

    pal = generatePalindrome(length);

    if (isPalindrome(pal)) {
        printf("This is a palindrome.\n");
    } else {
        printf("This is not a palindrome.\n");
    }

    return 0;
}