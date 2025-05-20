//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

int main(void) {
    char input[MAX_LEN];
    char output[MAX_LEN];
    int i, j;

    printf("*** WELCOME TO SHOCKED TEXT PROCESSOR ***\n");
    printf("-----------------------------------------\n");

    printf("Enter some text: ");
    fgets(input, MAX_LEN, stdin);

    // Remove newline character from fgets
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    // Convert input to uppercase
    for (i = 0; input[i]; i++) {
        input[i] = toupper(input[i]);
    }

    // Process text
    for (i = 0; input[i]; i++) {
        if (input[i] == 'W' && (i < (strlen(input) - 3) || i == 0)) {
            for (j = i + 1; j < strlen(input); j++) {
                if (input[j] == 'O' && input[j + 1] == 'W') {
                    strncpy(output, input, i);
                    output[i] = '\0';
                    strcat(output, "SHOCKED!");
                    strcat(output, &input[i + 2]);
                    printf("%s\n", output);
                    i = strlen(output) - 1;
                    break;
                }
            }
        }
    }

    printf("-----------------------------------------\n");
    printf("Text processed: %s\n", input);
    printf("-----------------------------------------\n");

    return 0;
}