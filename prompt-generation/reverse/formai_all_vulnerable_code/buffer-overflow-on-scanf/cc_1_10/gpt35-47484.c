//FormAI DATASET v1.0 Category: String manipulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define STRCAT 1
#define STRCMP 2
#define STRLEN 3

int main() {

    // Declare variables
    char string1[MAX_LENGTH], string2[MAX_LENGTH], result[MAX_LENGTH], operation;
    int index, strLength;

    // Prompt user for input
    printf("Enter operation (c for strcat, p for strcmp, l for strlen): ");
    scanf("%c", &operation);

    // Conduct operation based on user input
    switch(operation) {
        case 'c':
            printf("Enter first string: ");
            scanf("%s", string1);
            printf("Enter second string: ");
            scanf("%s", string2);
            strcat(string1, string2);
            printf("Concatenated string: %s\n", string1);
            break;
        case 'p':
            printf("Enter first string: ");
            scanf("%s", string1);
            printf("Enter second string: ");
            scanf("%s", string2);
            if(strcmp(string1, string2) == 0) {
                printf("Strings are equal\n");
            } else {
                printf("Strings are not equal\n");
            }
            break;
        case 'l':
            printf("Enter string: ");
            scanf("%s", string1);
            strLength = strlen(string1);
            printf("Length of string: %d\n", strLength);
            break;
        default:
            printf("Invalid operation\n");
    }

    return 0;
}