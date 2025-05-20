//FormAI DATASET v1.0 Category: String manipulation ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * This is a program that demonstrates various string manipulation functions 
 * implemented in C language.
 * 
 * Written by: Linus Torvalds (The creator of Linux)
 * Date: 22nd December, 2021
 */

int main() {
    char str[100];
    int len;

    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    len = strlen(str);

    printf("\nOriginal String:\n");
    printf("%s\n", str);
    printf("Length of string: %d\n", len);

    /* Reverse string function */
    char *rev;
    rev = (char*) malloc (len * sizeof(char));
    int i, j;
    for(i = 0, j = len-1; i < len; i++, j--) {
        *(rev+i) = *(str+j);
    }
    *(rev+i) = '\0';

    printf("\nReversed String:\n");
    printf("%s\n", rev);

    /*Copy string function */
    char *copy;
    copy = (char*) malloc (len * sizeof(char));
    strcpy(copy, str);

    printf("\nCopied String:\n");
    printf("%s\n", copy);

    /* Concatenate string function */
    char s[100];
    printf("\nEnter a string to concatenate: ");
    scanf(" %[^\n]s", s);

    char *concat;
    concat = (char*) malloc ((len + strlen(s)) * sizeof(char));
    strcpy(concat, str);
    strcat(concat, s);

    printf("\nConcatenated String:\n");
    printf("%s\n", concat);

    /* Checking if Palindrome */
    int flag = 0;
    for(i = 0; i < len; i++) {
        if(*(str+i) != *(str+len-i-1))
            flag = 1;
    }
    if(flag == 1)
        printf("\nIt is not a Palindrome.\n");
    else
        printf("\nIt is a Palindrome.\n");

    return 0;
}