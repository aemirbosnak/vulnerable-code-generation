//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main() {
    char input_string[MAX_LENGTH];
    char output_string[MAX_LENGTH];
    int i, j, k;
    int length;

    printf("Enter a string: ");
    scanf("%s", input_string);

    length = strlen(input_string);

    // Reverse the string
    for (i = 0, j = length - 1; i < j; i++, j--) {
        char temp = input_string[i];
        input_string[i] = input_string[j];
        input_string[j] = temp;
    }

    // Remove all vowels from the string
    for (i = 0; i < length; i++) {
        if (input_string[i] == 'a' || input_string[i] == 'e' || input_string[i] == 'i' || input_string[i] == 'o' || input_string[i] == 'u' || input_string[i] == 'A' || input_string[i] == 'E' || input_string[i] == 'I' || input_string[i] == 'O' || input_string[i] == 'U') {
            input_string[i] = '\0';
        }
    }

    // Count the number of vowels removed
    int vowels_removed = 0;
    for (i = 0; i < length; i++) {
        if (input_string[i] == '\0') {
            vowels_removed++;
        }
    }

    // Convert the string to uppercase
    for (i = 0; i < length; i++) {
        if (input_string[i]!= '\0') {
            input_string[i] = toupper(input_string[i]);
        }
    }

    // Copy the modified string to the output string
    strcpy(output_string, input_string);

    printf("Modified string: %s\n", output_string);

    return 0;
}