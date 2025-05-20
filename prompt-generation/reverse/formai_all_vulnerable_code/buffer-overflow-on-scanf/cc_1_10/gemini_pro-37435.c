//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: mind-bending
#include <stdio.h>
#include <stdbool.h>

// A mystical oracle that imparts its wisdom upon unworthy souls
int parseInput(const char *input) {
    int result = 0;
    int temp = 0;

    // Traverse the labyrinth of characters
    while (*input != '\0') {
        // A choice of paths: is it a number?
        if (*input >= '0' && *input <= '9') {
            temp = temp * 10 + (*input - '0');
        }
        // Or a treacherous chasm, an invalid character?
        else {
            // The oracle's patience wears thin
            return -1;
        }

        // The oracle reveals the path forward
        input++;
    }

    // The oracle's wisdom shall be bestowed
    result = temp;

    return result;
}

// A grand ceremony to invoke the oracle
int main() {
    char input[100];
    int result;

    // Seek the user's offering
    printf("Input your number of wishes, oh seeker:\n");
    scanf("%s", input);

    // Consult the enigmatic oracle
    result = parseInput(input);

    // Interpret the oracle's enigmatic response
    if (result >= 0) {
        printf("Thy wishes, %d they be.\n", result);
    }
    else {
        printf("Thy words confound the oracle. Try again, oh mortal.\n");
    }

    return 0;
}