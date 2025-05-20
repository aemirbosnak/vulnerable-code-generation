//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

typedef struct {
    char *string;
    int length;
} String;

void initializeString(String *string, char *initialValue) {
    string->string = (char *) malloc(MAX_STRING_LENGTH * sizeof(char));
    string->length = strlen(initialValue);
    strcpy(string->string, initialValue);
}

void destroyString(String *string) {
    free(string->string);
    string->string = NULL;
    string->length = 0;
}

void concatenateStrings(String *string1, String *string2) {
    char *newString = (char *) malloc((string1->length + string2->length + 1) * sizeof(char));
    strcpy(newString, string1->string);
    strcat(newString, string2->string);
    destroyString(string1);
    string1->string = newString;
    string1->length = strlen(newString);
}

int main() {
    String string1, string2;

    initializeString(&string1, "My love for you is like a red, red rose");
    initializeString(&string2, "That's newly sprung in June");

    printf("String 1: %s\n", string1.string);
    printf("String 2: %s\n", string2.string);

    concatenateStrings(&string1, &string2);

    printf("Concatenated string: %s\n", string1.string);

    destroyString(&string1);
    destroyString(&string2);

    return 0;
}