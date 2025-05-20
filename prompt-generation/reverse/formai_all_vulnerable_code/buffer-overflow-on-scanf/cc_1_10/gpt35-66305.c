//FormAI DATASET v1.0 Category: String manipulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str1[50], str2[50];
    int len1, len2, i, j, choice;
    char temp;

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    printf("\nString 1: %s", str1);
    printf("\nString 2: %s", str2);

    printf("\n1. Concatenate the strings");
    printf("\n2. Find the length of each string");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: // concatenate the strings
            printf("\nString 1 after concatenation: %s", strcat(str1, str2)); // using strcat function
            break;
        
        case 2: // find the length of each string
            printf("\nLength of string 1: %d", len1);
            printf("\nLength of string 2: %d", len2);
            break;
        default:
            printf("\nInvalid choice");
    }

    // swap characters of string 1 between even and odd indexes
    for(i = 0; i < len1; i+=2) {
        if((i+1) < len1) {
            temp = str1[i];
            str1[i] = str1[i+1];
            str1[i+1] = temp;
        }
    }

    printf("\nString 1 after swapping characters between even and odd indexes: %s", str1);

    // reverse the second string
    for(i = 0, j = len2-1; i < j; i++, j--) {
        temp = str2[i];
        str2[i] = str2[j];
        str2[j] = temp;
    }

    printf("\nString 2 after reversing: %s", str2);

    // remove all occurrences of a character from string 1
    printf("\nEnter the character to remove from string 1: ");
    scanf(" %c", &temp); // space before %c to consume any previous new line character

    for(i = 0; i < len1; i++) {
        if(str1[i] == temp) {
            for(j = i; j < len1; j++) {
                str1[j] = str1[j+1];
            }
            len1--;
            i--;
        }
    }

    printf("\nString 1 after removing all occurrences of the character: %s", str1);

    return 0;
}