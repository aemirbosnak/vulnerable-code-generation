//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024

int main() {
    char string1[MAX_STRING_LENGTH];
    char string2[MAX_STRING_LENGTH];
    int string1_length = 0;
    int string2_length = 0;

    printf("Enter the first string: ");
    scanf("%s", string1);

    printf("Enter the second string: ");
    scanf("%s", string2);

    string1_length = strlen(string1);
    string2_length = strlen(string2);

    printf("The first string is: %s\n", string1);
    printf("The second string is: %s\n", string2);

    printf("The length of the first string is: %d\n", string1_length);
    printf("The length of the second string is: %d\n", string2_length);

    char *concatenated_string = (char *)malloc(string1_length + string2_length + 1);
    strcpy(concatenated_string, string1);
    strcat(concatenated_string, string2);

    printf("The concatenated string is: %s\n", concatenated_string);

    int compare_result = strcmp(string1, string2);
    if (compare_result == 0) {
        printf("The two strings are equal.\n");
    } else if (compare_result < 0) {
        printf("The first string is less than the second string.\n");
    } else {
        printf("The first string is greater than the second string.\n");
    }

    char *substring = strstr(string1, string2);
    if (substring != NULL) {
        printf("The second string is a substring of the first string.\n");
    } else {
        printf("The second string is not a substring of the first string.\n");
    }

    char *token = strtok(string1, " ");
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, " ");
    }

    free(concatenated_string);

    return 0;
}