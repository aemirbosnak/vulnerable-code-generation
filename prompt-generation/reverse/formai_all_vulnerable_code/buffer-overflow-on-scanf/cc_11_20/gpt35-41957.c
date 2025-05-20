//FormAI DATASET v1.0 Category: String manipulation ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() {
    char string[1000], newString[1000];

    printf("Enter a string, dear user: ");
    fgets(string, 1000, stdin);

    printf("\nYour string is %d characters long.", strlen(string));

    for(int i=0; i<=strlen(string); i++) {
        if(string[i] == ' ') {
            newString[i] = '_';
        }
        else {
            newString[i] = string[i];
        }
    }

    printf("\nHere is your string with spaces replaced by underscores: %s", newString);

    int vowelCount = 0;

    for(int i=0; i<=strlen(string); i++) {
        if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u') {
            vowelCount++;
        }
    }

    if(vowelCount > 0) {
        printf("\nWow, your string has %d vowels!", vowelCount);
    }
    else {
        printf("\nSurprisingly, your string does not have any vowels.");
    }

    char substring[100];
    int length;

    printf("\nEnter a substring to search for in your original string: ");
    scanf("%s", substring);

    length = strlen(substring);

    char *result = strstr(string, substring);

    if(result == NULL) {
        printf("\nSorry my dear user, your substring was not found in your original string.");
    }
    else {
        printf("\nCongratulations my dear user, your substring was found in your original string at position %d!", result - string);
    }

    return 0;
}