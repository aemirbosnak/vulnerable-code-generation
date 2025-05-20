//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];

    // Get input string from user
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove leading/trailing whitespace
    char *ptr = input;
    while (*ptr && isspace(*ptr)) {
        ptr++;
    }
    strcpy(output, ptr);
    int length = strlen(output);
    while (length > 0 && isspace(output[length - 1])) {
        output[--length] = '\0';
    }

    // Reverse the string
    char *start = output;
    char *end = output + length - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    // Convert to uppercase
    for (int i = 0; i < length; i++) {
        output[i] = toupper(output[i]);
    }

    // Count vowels
    int vowelCount = 0;
    for (int i = 0; i < length; i++) {
        if (output[i] == 'A' || output[i] == 'E' || output[i] == 'I' || output[i] == 'O' || output[i] == 'U') {
            vowelCount++;
        }
    }

    // Output results
    printf("Reversed string: %s\n", output);
    printf("Uppercase string: %s\n", output);
    printf("Vowel count: %d\n", vowelCount);

    return 0;
}