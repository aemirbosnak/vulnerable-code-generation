//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct Palindrome {
    char str[MAX_SIZE];
    int len;
    int flag;
} Palindrome;

void reverseString(char *str, int start, int end) {
    char temp;
    for (; start < end; start++, end--) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
    }
}

int isPalindrome(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

void printPalindromes(Palindrome *pList, int count) {
    printf("Total Palindromes found: %d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%s\n", pList[i].str);
    }
}

Palindrome *createPalindrome(char *str) {
    Palindrome *newPalindrome = (Palindrome *)malloc(sizeof(Palindrome));
    strcpy(newPalindrome->str, str);
    newPalindrome->len = strlen(str);
    newPalindrome->flag = isPalindrome(str);
    return newPalindrome;
}

int main() {
    char input[MAX_SIZE];
    int n, i;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    Palindrome *palindromeList = (Palindrome *)calloc(n, sizeof(Palindrome));

    for (i = 0; i < n; i++) {
        printf("Enter a string: ");
        scanf("%s", input);
        palindromeList[i] = *createPalindrome(input);
    }

    int count = 0;

    for (i = 0; i < n; i++) {
        if (palindromeList[i].flag == 1) {
            count++;
            Palindrome temp = palindromeList[i];
            Palindrome *newPalindrome = (Palindrome *)realloc(palindromeList, sizeof(Palindrome) * (count + 1));
            newPalindrome[count] = temp;
            palindromeList = newPalindrome;
        }
    }

    printPalindromes(palindromeList, count);

    free(palindromeList);

    return 0;
}