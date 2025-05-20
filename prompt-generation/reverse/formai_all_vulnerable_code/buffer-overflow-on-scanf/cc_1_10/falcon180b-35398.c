//Falcon-180B DATASET v1.0 Category: Recursive ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print the string in reverse order
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

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int len = strlen(str);

    // Remove spaces and punctuation marks from the string
    char* newStr = (char*)malloc(len*sizeof(char));
    int newLen = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            newStr[newLen++] = str[i];
        }
    }
    newStr[newLen] = '\0';

    // Check if the modified string is a palindrome
    int isPal = isPalindrome(newStr, 0, newLen-1);
    if (isPal) {
        printf("The string is a palindrome.\n");
    }
    else {
        printf("The string is not a palindrome.\n");
    }

    // Reverse the modified string
    reverseString(newStr, 0, newLen-1);
    printf("The reversed string is: %s\n", newStr);

    free(newStr);
    return 0;
}