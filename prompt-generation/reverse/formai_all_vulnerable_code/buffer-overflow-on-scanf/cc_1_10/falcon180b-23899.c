//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void reverseString(char* str) {
    int i, j;
    char temp;

    for(i=0, j=strlen(str)-1; i<j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void removeSpaces(char* str) {
    int i, j;

    for(i=0, j=0; str[i]!='\0'; i++) {
        if(str[i]!=' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

int isPalindrome(char* str) {
    int i, j;
    char temp;

    for(i=0, j=strlen(str)-1; i<j; i++, j--) {
        if(str[i]!=str[j]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str1[MAX_SIZE], str2[MAX_SIZE];

    printf("Enter a string: ");
    scanf("%s", str1);

    printf("Reverse of string 1: ");
    reverseString(str1);
    printf("%s\n", str1);

    printf("Enter another string: ");
    scanf("%s", str2);

    printf("Reverse of string 2: ");
    reverseString(str2);
    printf("%s\n", str2);

    printf("Is string 1 a palindrome? %s\n", isPalindrome(str1)? "Yes" : "No");
    printf("Is string 2 a palindrome? %s\n", isPalindrome(str2)? "Yes" : "No");

    removeSpaces(str1);
    printf("String 1 without spaces: %s\n", str1);

    removeSpaces(str2);
    printf("String 2 without spaces: %s\n", str2);

    return 0;
}