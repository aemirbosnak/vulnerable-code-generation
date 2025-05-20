//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: happy
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    char reversed[MAX_LENGTH];
    char capitalized[MAX_LENGTH];
    char lowercased[MAX_LENGTH];
    char trimmed[MAX_LENGTH];
    char *substr;
    int length;

    // Get user input
    printf("Enter a string: ");
    scanf("%s", input);

    // Reverse the string
    strcpy(reversed, input);
    length = strlen(reversed);
    for (int i = 0; i < length / 2; i++) {
        char temp = reversed[i];
        reversed[i] = reversed[length - i - 1];
        reversed[length - i - 1] = temp;
    }

    // Capitalize the first letter of the string
    strcpy(capitalized, input);
    capitalized[0] = toupper(capitalized[0]);

    // Convert the string to lowercase
    strcpy(lowercased, input);
    for (int i = 0; i < strlen(lowercased); i++) {
        lowercased[i] = tolower(lowercased[i]);
    }

    // Remove leading and trailing whitespace from the string
    strcpy(trimmed, input);
    while (isspace(trimmed[0])) {
        strcpy(trimmed, &trimmed[1]);
    }
    while (isspace(trimmed[strlen(trimmed) - 1])) {
        trimmed[strlen(trimmed) - 1] = '\0';
    }

    // Extract a substring from the string
    substr = strstr(input, "world");
    strcpy(output, substr);

    // Output the results
    printf("Original string: %s\n", input);
    printf("Reversed string: %s\n", reversed);
    printf("Capitalized string: %s\n", capitalized);
    printf("Lowercased string: %s\n", lowercased);
    printf("Trimmed string: %s\n", trimmed);
    printf("Substring: %s\n", output);

    return 0;
}