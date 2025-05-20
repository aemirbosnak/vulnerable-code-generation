//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: curious
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    char input[MAX_SIZE];
    char output[MAX_SIZE];
    int i, j, k, n;
    int flag = 0;
    char delimiter;
    char *token;

    // Prompting user for input
    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);

    // Removing trailing newline character
    input[strcspn(input, "\n")] = '\0';

    // Prompting user for delimiter
    printf("Enter a delimiter: ");
    scanf("%c", &delimiter);

    // Prompting user for operation
    printf("Enter the operation: ");
    scanf(" %c", &flag);

    // Splitting the string using delimiter
    token = strtok(input, &delimiter);
    n = 0;
    while (token!= NULL) {
        strcpy(output + n * MAX_SIZE, token);
        n++;
        token = strtok(NULL, &delimiter);
    }
    output[n * MAX_SIZE] = '\0';

    // Performing the operation
    switch (flag) {
        case 'U':
            for (i = 0; i < strlen(output); i++) {
                output[i] = toupper(output[i]);
            }
            break;
        case 'L':
            for (i = 0; i < strlen(output); i++) {
                output[i] = tolower(output[i]);
            }
            break;
        case 'R':
            for (i = strlen(output) - 1, j = 0; i >= 0; i--, j++) {
                output[j] = output[i];
            }
            output[strlen(output)] = '\0';
            break;
        case 'S':
            for (i = 0, j = strlen(output) - 1; i < j; i++, j--) {
                k = output[i];
                output[i] = output[j];
                output[j] = k;
            }
            break;
        default:
            printf("Invalid operation!\n");
            return 0;
    }

    // Printing the result
    printf("Output: %s\n", output);

    return 0;
}