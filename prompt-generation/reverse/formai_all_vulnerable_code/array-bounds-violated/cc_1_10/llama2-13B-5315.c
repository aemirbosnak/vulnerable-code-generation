//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    char word[MAX_LENGTH];
    int i, j, k, count = 0;

    printf("Enter a sentence or phrase: ");
    fgets(input, MAX_LENGTH, stdin);

    // Tokenize the input
    for (i = 0; input[i] != '\0'; i++) {
        if (isspace(input[i])) {
            count++;
        } else {
            word[k] = input[i];
            k++;
            if (k == MAX_LENGTH) {
                break;
            }
        }
    }

    // Reverse the words
    for (i = 0; i < k; i++) {
        for (j = 0; j < k - i - 1; j++) {
            char temp = word[j];
            word[j] = word[j + 1];
            word[j + 1] = temp;
        }
    }

    // Print the reversed sentence
    for (i = 0; i < k; i++) {
        printf("%c", word[i]);
    }

    // Add some randomness
    for (i = 0; i < count; i++) {
        int random = rand() % 2;
        if (random == 0) {
            word[k - i - 1] = word[i];
        } else {
            word[i] = word[k - i - 1];
        }
    }

    // Print the final output
    for (i = 0; i < k; i++) {
        printf("%c", word[i]);
    }

    return 0;
}