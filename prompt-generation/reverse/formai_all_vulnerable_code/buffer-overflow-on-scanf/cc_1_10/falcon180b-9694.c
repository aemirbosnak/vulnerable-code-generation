//Falcon-180B DATASET v1.0 Category: Educational ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// function to check if a character is a letter
int isLetter(char c) {
    if(isalpha(c)) {
        return 1;
    } else {
        return 0;
    }
}

// function to check if a string is a palindrome
int isPalindrome(char* str) {
    int i = 0, j = strlen(str) - 1;
    while(i < j) {
        if(!isLetter(str[i]) &&!isLetter(str[j])) {
            i++;
            j--;
        } else if(tolower(str[i])!= tolower(str[j])) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main() {
    srand(time(NULL));
    int n;
    printf("Enter the number of palindromes to generate: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int length = rand() % 10 + 1;
        char* palindrome = (char*)malloc(length * sizeof(char));
        for(int j = 0; j < length; j++) {
            char c = rand() % 26 + 'a';
            palindrome[j] = c;
        }
        palindrome[length-1] = tolower(palindrome[length-1]);
        for(int j = length-2; j >= 0; j--) {
            palindrome[j] = tolower(palindrome[j]);
        }
        printf("%s is a palindrome: %s\n", palindrome, isPalindrome(palindrome)? "Yes" : "No");
        free(palindrome);
    }

    return 0;
}