//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    char string[MAX_SIZE];
    char *newString;
    int length;

    printf("Enter a string: ");
    fgets(string, MAX_SIZE, stdin);
    length = strlen(string);

    // Remove leading and trailing spaces
    while (isspace(string[0])) {
        strcpy(string, &string[1]);
        length--;
    }
    while (isspace(string[length - 1])) {
        string[length - 1] = '\0';
        length--;
    }

    // Convert to uppercase
    for (int i = 0; i < length; i++) {
        string[i] = toupper(string[i]);
    }

    // Reverse the string
    for (int i = 0; i < length / 2; i++) {
        char temp = string[i];
        string[i] = string[length - i - 1];
        string[length - i - 1] = temp;
    }

    // Allocate memory for the new string
    newString = (char *)malloc(length * sizeof(char));

    // Copy the reversed string to the new string
    strcpy(newString, string);

    // Print the new string
    printf("New string: %s\n", newString);

    // Free the memory allocated for the new string
    free(newString);

    return 0;
}