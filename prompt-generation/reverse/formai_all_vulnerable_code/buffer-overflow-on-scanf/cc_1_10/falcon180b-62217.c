//Falcon-180B DATASET v1.0 Category: Text processing ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

char *removeSpaces(char *str);
void reverseString(char *str, int start, int end);
void printString(char *str, int start, int end);

int main() {
    char str[MAX];

    printf("Enter a string: ");
    scanf("%[^\n]", str);

    printf("Original string: %s\n", str);

    char *newStr = removeSpaces(str);

    printf("String without spaces: %s\n", newStr);

    reverseString(newStr, 0, strlen(newStr)-1);

    printf("Reversed string: %s\n", newStr);

    return 0;
}

char *removeSpaces(char *str) {
    int len = strlen(str);
    char *newStr = malloc(len + 1);

    int j = 0;
    for (int i = 0; i < len; i++) {
        if (!isspace(str[i])) {
            newStr[j++] = str[i];
        }
    }

    newStr[j] = '\0';

    return newStr;
}

void reverseString(char *str, int start, int end) {
    char temp;
    while (start < end) {
        temp = str[start];
        str[start++] = str[end];
        str[end--] = temp;
    }
}

void printString(char *str, int start, int end) {
    for (int i = start; i <= end; i++) {
        printf("%c", str[i]);
    }
}