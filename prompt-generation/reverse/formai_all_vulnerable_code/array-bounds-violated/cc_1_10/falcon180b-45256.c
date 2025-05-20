//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    char str1[MAX_SIZE];
    char str2[MAX_SIZE];
    char result[MAX_SIZE];

    //get user input for string 1
    printf("Enter string 1: ");
    fgets(str1, MAX_SIZE, stdin);

    //remove leading and trailing spaces from string 1
    int i = 0;
    int j = strlen(str1) - 1;
    while (isspace(str1[i])) {
        i++;
    }
    while (isspace(str1[j])) {
        j--;
    }
    str1[j] = '\0';

    //get user input for string 2
    printf("Enter string 2: ");
    fgets(str2, MAX_SIZE, stdin);

    //remove leading and trailing spaces from string 2
    i = 0;
    j = strlen(str2) - 1;
    while (isspace(str2[i])) {
        i++;
    }
    while (isspace(str2[j])) {
        j--;
    }
    str2[j] = '\0';

    //concatenate string 1 and string 2
    strcat(result, str1);
    strcat(result, " ");
    strcat(result, str2);

    //print the concatenated string
    printf("Concatenated string: %s\n", result);

    //copy string 1 to string 3
    strcpy(result, str1);

    //print string 3
    printf("String 3: %s\n", result);

    //reverse string 1
    for (i = 0, j = strlen(str1) - 1; i < j; i++, j--) {
        char temp = str1[i];
        str1[i] = str1[j];
        str1[j] = temp;
    }

    //print the reversed string
    printf("Reversed string: %s\n", str1);

    //replace all occurrences of a character in string 1
    char oldChar, newChar;
    printf("Enter the character to be replaced: ");
    scanf("%c", &oldChar);
    printf("Enter the new character: ");
    scanf("%c", &newChar);
    for (i = 0; str1[i]!= '\0'; i++) {
        if (str1[i] == oldChar) {
            str1[i] = newChar;
        }
    }

    //print the modified string
    printf("Modified string: %s\n", str1);

    return 0;
}