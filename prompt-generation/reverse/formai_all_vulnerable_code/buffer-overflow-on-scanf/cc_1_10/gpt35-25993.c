//FormAI DATASET v1.0 Category: String manipulation ; Style: inquisitive
// Hey there! Are you ready to explore the world of C string manipulation?
// This program will help you to understand the basic string operations in C.

#include <stdio.h>
#include <string.h>

int main()
{
    char str1[20], str2[20], temp[20]; //declare variables

    //let's start with string copying operation
    printf("Enter string 1: ");
    scanf("%s", str1);

    printf("\nEnter string 2: ");
    scanf("%s", str2);

    printf("\nString before copying:\n");
    printf("\nString 1: %s", str1);
    printf("\nString 2: %s", str2);

    strcpy(temp, str1); //copy string 1 to temp variable
    strcpy(str1, str2); //copy string 2 to string 1
    strcpy(str2, temp); //copy temp(not string 1) to string 2

    printf("\n\nStrings after copying:\n");
    printf("String 1: %s", str1);
    printf("\nString 2: %s", str2);

    //now we will concatenate two strings
    printf("\n\nEnter a string to concatenate: ");
    scanf("%s", temp);

    strcat(str1, temp); //concatenate string 1 and temp
    printf("\nConcatenated String: %s", str1);

    //now let's compare two strings
    printf("\n\nEnter two strings to compare: ");
    scanf("%s%s", str1, str2);

    if (strcmp(str1, str2) == 0)
    {
        printf("\nStrings are equal!");
    }
    else
    {
        printf("\nStrings are not equal!");
    }

    //now we will find the length of a string
    printf("\n\nEnter a string: ");
    scanf("%s", str1);

    int len = strlen(str1);
    printf("\nLength of the string is: %d", len);

    return 0;
}

/*Isn't it amazing how easily we can manipulate strings in C?
Whether it is copying two strings, concatenating them,
comparing them or finding the length of a string, 
C provides a wide range of string functions to do it quickly and effectively.*/