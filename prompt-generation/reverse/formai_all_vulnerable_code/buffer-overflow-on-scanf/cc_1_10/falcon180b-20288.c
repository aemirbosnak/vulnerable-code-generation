//Falcon-180B DATASET v1.0 Category: Recursive ; Style: introspective
#include <stdio.h>

//Function to print the string in reverse order
void reverseString(char str[], int start, int end) {
    char temp;
    int i;
    if (start >= end)
        return;
    temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    for (i = start + 1; i <= end - 1; i++) {
        temp = str[i];
        str[i] = str[end - i + start];
        str[end - i + start] = temp;
    }
}

//Function to check if the string is a palindrome
int isPalindrome(char str[]) {
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (str[i]!= str[j])
            return 0;
    }
    return 1;
}

//Function to generate all possible substrings of a given string
void generateSubstrings(char str[], int start, int end, char subStr[]) {
    if (start == end) {
        subStr[end] = '\0';
        printf("%s\n", subStr);
        return;
    }
    for (int i = start; i <= end; i++) {
        subStr[i - start] = str[i];
        generateSubstrings(str, start, i - 1, subStr);
    }
}

int main() {
    char inputStr[100];
    printf("Enter a string: ");
    scanf("%s", inputStr);
    printf("The original string is: %s\n", inputStr);
    printf("The reverse of the string is: ");
    reverseString(inputStr, 0, strlen(inputStr) - 1);
    printf("%s\n", inputStr);
    if (isPalindrome(inputStr))
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");
    printf("All possible substrings of the given string are:\n");
    char subStr[100];
    generateSubstrings(inputStr, 0, strlen(inputStr) - 1, subStr);
    return 0;
}