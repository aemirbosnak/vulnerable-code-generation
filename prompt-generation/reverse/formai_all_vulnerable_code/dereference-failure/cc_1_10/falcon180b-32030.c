//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

int main()
{
    // Example strings
    char string1[] = "Hello, world!";
    char string2[] = "This is a test.";

    // Length of the strings
    int length1 = strlen(string1);
    int length2 = strlen(string2);

    // Concatenate the strings
    char* concatenatedString = malloc(length1 + length2 + 1);
    strcpy(concatenatedString, string1);
    strcat(concatenatedString, string2);

    // Print the concatenated string
    printf("Concatenated string: %s\n", concatenatedString);

    // Reverse the concatenated string
    char* reversedString = malloc(length1 + length2 + 1);
    strcpy(reversedString, concatenatedString);
    int i = 0, j = strlen(reversedString) - 1;
    while (i < j)
    {
        char temp = reversedString[i];
        reversedString[i] = reversedString[j];
        reversedString[j] = temp;
        i++;
        j--;
    }

    // Print the reversed string
    printf("Reversed string: %s\n", reversedString);

    // Convert the concatenated string to uppercase
    char* uppercasedString = malloc(length1 + length2 + 1);
    strcpy(uppercasedString, concatenatedString);
    for (int k = 0; k < strlen(uppercasedString); k++)
    {
        uppercasedString[k] = toupper(uppercasedString[k]);
    }

    // Print the uppercased string
    printf("Uppercased string: %s\n", uppercasedString);

    // Convert the reversed string to lowercase
    char* lowercasedString = malloc(length1 + length2 + 1);
    strcpy(lowercasedString, reversedString);
    for (int k = 0; k < strlen(lowercasedString); k++)
    {
        lowercasedString[k] = tolower(lowercasedString[k]);
    }

    // Print the lowercased string
    printf("Lowercased string: %s\n", lowercasedString);

    // Free the dynamically allocated memory
    free(concatenatedString);
    free(reversedString);
    free(uppercasedString);
    free(lowercasedString);

    return 0;
}