//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // maximum size of the array
#define MAX_STRING_LENGTH 50 // maximum length of a string

typedef struct {
    char *strings[MAX_SIZE]; // array of strings
    int numStrings; // number of strings in the array
} StringArray;

// function to create a new string array
StringArray *createStringArray() {
    StringArray *array = (StringArray *) malloc(sizeof(StringArray));
    array->numStrings = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        array->strings[i] = NULL;
    }
    return array;
}

// function to add a string to the array
void addString(StringArray *array, char *string) {
    if (array->numStrings >= MAX_SIZE) {
        printf("Error: cannot add more strings to the array\n");
        return;
    }
    array->strings[array->numStrings] = (char *) malloc(MAX_STRING_LENGTH * sizeof(char));
    strcpy(array->strings[array->numStrings], string);
    array->numStrings++;
}

// function to search for a string in the array
int searchString(StringArray *array, char *searchString) {
    for (int i = 0; i < array->numStrings; i++) {
        if (strcmp(array->strings[i], searchString) == 0) {
            return i;
        }
    }
    return -1; // string not found
}

// function to print the contents of the array
void printArray(StringArray *array) {
    printf("Strings in the array:\n");
    for (int i = 0; i < array->numStrings; i++) {
        printf("%s\n", array->strings[i]);
    }
}

int main() {
    StringArray *array = createStringArray();
    char string1[MAX_STRING_LENGTH] = "hello";
    char string2[MAX_STRING_LENGTH] = "world";
    char string3[MAX_STRING_LENGTH] = "programming";
    addString(array, string1);
    addString(array, string2);
    addString(array, string3);
    printArray(array);

    int index = searchString(array, "world");
    if (index!= -1) {
        printf("Found \"world\" at index %d\n", index);
    } else {
        printf("\"world\" not found in the array\n");
    }

    return 0;
}