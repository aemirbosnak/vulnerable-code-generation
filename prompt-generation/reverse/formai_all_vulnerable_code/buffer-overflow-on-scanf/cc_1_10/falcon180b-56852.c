//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

int main() {
    char input[MAX_LINE_LENGTH];
    char *substring;
    int substring_length;
    int index;

    printf("Enter a string: ");
    fgets(input, MAX_LINE_LENGTH, stdin);

    // Remove leading/trailing whitespace
    input[strcspn(input, "\n")] = '\0';
    input[strspn(input, " \t\n\r\f\v")] = '\0';

    // Get substring to search for
    printf("Enter a substring to search for: ");
    scanf("%s", input);
    substring = input;
    substring_length = strlen(substring);

    // Search for substring and count occurrences
    int count = 0;
    char *result = strstr(input, substring);
    while (result!= NULL) {
        count++;
        result += substring_length;
        result = strstr(result, substring);
    }

    // Replace substring with another string
    printf("Enter a string to replace '%s' with: ", substring);
    scanf("%s", input);
    for (index = 0; index < strlen(input); index++) {
        if (input[index] == '\n') {
            input[index] = '\0';
        }
    }
    index = 0;
    while ((result = strstr(input, substring))!= NULL) {
        strncpy(result, input + index, strlen(substring));
        index += strlen(input + index);
    }
    printf("Result: %s\n", input);

    return 0;
}