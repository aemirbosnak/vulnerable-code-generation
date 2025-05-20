//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    int length;

    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);
    length = strlen(input);

    // Remove leading/trailing whitespace
    while (isspace(input[0])) {
        memmove(input, input + 1, length);
        length--;
    }
    while (isspace(input[length - 1])) {
        input[length - 1] = '\0';
        length--;
    }

    // Convert to uppercase
    for (int i = 0; i < length; i++) {
        input[i] = toupper(input[i]);
    }

    // Remove non-alphanumeric characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(input[i])) {
            input[i] = '\0';
        }
    }

    // Remove consecutive non-alphanumeric characters
    char *ptr = strtok(input, " ");
    while (ptr!= NULL) {
        strcat(output, ptr);
        strcat(output, " ");
        ptr = strtok(NULL, " ");
    }

    // Remove leading/trailing whitespace
    while (isspace(output[0])) {
        memmove(output, output + 1, strlen(output));
    }
    while (isspace(output[strlen(output) - 1])) {
        output[strlen(output) - 1] = '\0';
    }

    printf("Sanitized string: %s\n", output);

    return 0;
}