//FormAI DATASET v1.0 Category: Text processing ; Style: paranoid
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_WORD_LENGTH 20

int main() {
    char input[MAX_INPUT_LENGTH]; // User input
    char words[MAX_INPUT_LENGTH][MAX_WORD_LENGTH]; // Array to store individual words
    int i, j = 0, k = 0, count = 0, length;

    printf("Enter some text: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Ensure input is not too long
    if (strlen(input) >= MAX_INPUT_LENGTH - 1) {
        printf("Input too long. Exiting.\n");
        return 1;
    }

    // Remove trailing newline character
    input[strlen(input) - 1] = '\0';

    // Split string into individual words
    length = strlen(input);
    for (i = 0; i < length; i++) {
        if (input[i] == ' ') {
            words[j][k] = '\0';
            j++;
            k = 0;
            count++;
        } else {
            words[j][k] = input[i];
            k++;
        }
    }
    words[j][k] = '\0';
    count++;

    // Check each word for suspicious characters
    for (i = 0; i < count; i++) {
        for (j = 0; j < strlen(words[i]); j++) {
            char c = words[i][j];
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == ' ')) {
                continue; // Normal character
            } else {
                // Suspicious character found
                printf("*** WARNING: Suspicious input detected on word '%s'. Please check for potential security threats. ***\n", words[i]);
                break;
            }
        }
    }

    return 0;
}