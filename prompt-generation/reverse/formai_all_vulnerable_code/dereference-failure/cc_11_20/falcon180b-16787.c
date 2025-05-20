//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main() {
    char input[MAX_LENGTH];
    char *output = NULL;
    int length;

    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);
    length = strlen(input);

    // Remove leading and trailing spaces
    output = malloc(length + 1);
    strcpy(output, input);
    while (isspace(*output)) {
        output++;
    }
    while (isspace(output[length - 1])) {
        output[length - 1] = '\0';
        length--;
    }

    // Reverse the string
    char *temp = output;
    char *end = output + length - 1;
    while (temp < end) {
        char c = *temp;
        *temp++ = *end;
        *end-- = c;
    }

    // Convert to uppercase
    for (int i = 0; i < length; i++) {
        output[i] = toupper(output[i]);
    }

    // Count vowels
    int vowel_count = 0;
    for (int i = 0; i < length; i++) {
        if (output[i] == 'A' || output[i] == 'E' || output[i] == 'I' || output[i] == 'O' || output[i] == 'U') {
            vowel_count++;
        }
    }

    // Output the result
    printf("Original string: %s\n", input);
    printf("Modified string: %s\n", output);
    printf("Number of vowels: %d\n", vowel_count);

    free(output);
    return 0;
}