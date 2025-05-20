//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

int main() {
    char string1[MAX_STRING_LENGTH];
    char string2[MAX_STRING_LENGTH];
    char result[MAX_STRING_LENGTH];

    printf("Enter the first string: ");
    scanf("%s", string1);

    printf("Enter the second string: ");
    scanf("%s", string2);

    strcpy(result, string1);
    strcat(result, string2);

    printf("The concatenated string is: %s\n", result);

    int length1 = strlen(string1);
    int length2 = strlen(string2);
    int length = length1 + length2;

    char* reversed1 = malloc((length1 + 1) * sizeof(char));
    char* reversed2 = malloc((length2 + 1) * sizeof(char));
    char* reversed = malloc((length + 1) * sizeof(char));

    strcpy(reversed1, string1);
    strcpy(reversed2, string2);

    for (int i = 0; i < length1; i++) {
        reversed[i] = reversed1[length1 - 1 - i];
    }

    for (int i = 0; i < length2; i++) {
        reversed[length1 + i] = reversed2[length2 - 1 - i];
    }

    reversed[length] = '\0';

    printf("The reversed concatenated string is: %s\n", reversed);

    free(reversed1);
    free(reversed2);
    free(reversed);

    return 0;
}