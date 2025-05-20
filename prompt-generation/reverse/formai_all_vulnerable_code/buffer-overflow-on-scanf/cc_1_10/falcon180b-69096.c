//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define MAX_NUM_OF_STRINGS 100

typedef struct {
    char *string;
    int length;
} String;

void initializeStrings(String *strings, int numOfStrings) {
    int i;
    for (i = 0; i < numOfStrings; i++) {
        strings[i].string = NULL;
        strings[i].length = 0;
    }
}

void addString(String *strings, int numOfStrings, char *newString) {
    int i;
    for (i = 0; i < numOfStrings; i++) {
        if (strings[i].string == NULL) {
            strings[i].string = newString;
            strings[i].length = strlen(newString);
            break;
        }
    }
}

int compareStrings(char *string1, char *string2) {
    int i;
    for (i = 0; i < strlen(string1); i++) {
        if (string1[i]!= string2[i]) {
            return 0;
        }
    }
    return 1;
}

int searchStrings(String *strings, int numOfStrings, char *searchString) {
    int i;
    for (i = 0; i < numOfStrings; i++) {
        if (compareStrings(strings[i].string, searchString)) {
            printf("String found at index %d\n", i);
            return 1;
        }
    }
    printf("String not found\n");
    return 0;
}

int main() {
    int numOfStrings, i;
    printf("Enter number of strings to search: ");
    scanf("%d", &numOfStrings);
    String strings[numOfStrings];
    initializeStrings(strings, numOfStrings);
    char inputString[MAX_STRING_LENGTH];
    while (1) {
        printf("Enter string to add: ");
        scanf("%s", inputString);
        addString(strings, numOfStrings, inputString);
        printf("Enter'search' to search for a string, or any other key to continue adding strings: ");
        scanf("%s", inputString);
        if (strcmp(inputString, "search") == 0) {
            char searchString[MAX_STRING_LENGTH];
            printf("Enter string to search for: ");
            scanf("%s", searchString);
            searchStrings(strings, numOfStrings, searchString);
        }
    }
    return 0;
}