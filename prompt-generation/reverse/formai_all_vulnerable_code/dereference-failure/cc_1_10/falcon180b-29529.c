//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1024

int main() {
    char input[MAX_LENGTH];
    char *output = malloc(MAX_LENGTH * sizeof(char));

    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove leading and trailing spaces
    input[strcspn(input, "\n")] = '\0';
    output[0] = '\0';
    strcat(output, input);
    strcat(output, " ");

    // Reverse the string
    char *ptr = output;
    char *end = output + strlen(output) - 1;
    while (ptr < end) {
        char temp = *ptr;
        *ptr = *end;
        *end = temp;
        ptr++;
        end--;
    }

    // Convert to uppercase
    for (int i = 0; i < strlen(output); i++) {
        output[i] = toupper(output[i]);
    }

    // Count number of vowels
    int vowelCount = 0;
    for (int i = 0; i < strlen(output); i++) {
        if (output[i] == 'A' || output[i] == 'E' || output[i] == 'I' || output[i] == 'O' || output[i] == 'U' || output[i] == 'Y') {
            vowelCount++;
        }
    }

    // Print the result
    printf("Reversed string: %s\n", output);
    printf("Number of vowels: %d\n", vowelCount);

    return 0;
}