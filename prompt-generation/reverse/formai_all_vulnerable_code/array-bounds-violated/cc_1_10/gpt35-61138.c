//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
#define MAX_ATTEMPTS 5

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Welcome to the Intrusion Detection System\n");
    printf("Please enter your access key: ");

    // read user input
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // clean up newline character at end of input
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    // check access key
    if (strcmp(input, "accesskey123") != 0) {
        printf("Access denied\n");
        return 1;
    }

    printf("Access granted\n");

    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        printf("Please enter your password: ");

        // read user input
        fgets(input, MAX_INPUT_LENGTH, stdin);

        // clean up newline character at end of input
        if (input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }

        // check password
        if (strcmp(input, "password456") == 0) {
            printf("Correct password\n");
            return 0;
        }

        printf("Incorrect password\n");

        attempts++;
    }

    printf("Too many attempts, system locking down\n");

    return 1;
}