//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PW_MIN_LENGTH 8
#define PW_MAX_LENGTH 255
#define PW_TYPES 4

typedef enum {
    PW_TYPE_LOWER,
    PW_TYPE_UPPER,
    PW_TYPE_DIGIT,
    PW_TYPE_SYMBOL,
} pw_type;

char *pw_chars[] = {
    "abcdefghijklmnopqrstuvwxyz",
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
    "0123456789",
    "!@#$%^&*()"
};

int main(int argc, char *argv[]) {
    int pw_length, pw_type_count, i, j;
    char *pw = NULL;
    char *pw_types = NULL;

    // Parse command line arguments.
    if (argc < 2 || argc > 4) {
        fprintf(stderr, "Usage: %s <length> <types>\n", argv[0]);
        return EXIT_FAILURE;
    }

    pw_length = atoi(argv[1]);
    if (pw_length < PW_MIN_LENGTH || pw_length > PW_MAX_LENGTH) {
        fprintf(stderr, "Password length must be between %d and %d.\n", PW_MIN_LENGTH, PW_MAX_LENGTH);
        return EXIT_FAILURE;
    }

    pw_type_count = argc - 2;
    if (pw_type_count > PW_TYPES) {
        fprintf(stderr, "Maximum %d password types allowed.\n", PW_TYPES);
        return EXIT_FAILURE;
    }

    // Allocate memory for password and password types.
    pw = malloc(pw_length + 1);
    if (pw == NULL) {
        fprintf(stderr, "Failed to allocate memory for password.\n");
        return EXIT_FAILURE;
    }

    pw_types = malloc(pw_type_count + 1);
    if (pw_types == NULL) {
        fprintf(stderr, "Failed to allocate memory for password types.\n");
        free(pw);
        return EXIT_FAILURE;
    }

    // Parse password types.
    for (i = 0; i < pw_type_count; i++) {
        pw_types[i] = argv[i + 2][0];
        if (pw_types[i] < 'a' || pw_types[i] > 'z' || pw_types[i] < 'A' || pw_types[i] > 'Z' || pw_types[i] < '0' || pw_types[i] > '9' || pw_types[i] < '!' || pw_types[i] > ')') {
            fprintf(stderr, "Invalid password type: '%c'.\n", pw_types[i]);
            free(pw);
            free(pw_types);
            return EXIT_FAILURE;
        }
    }

    // Seed random number generator.
    srand(time(NULL));

    // Generate password.
    for (i = 0; i < pw_length; i++) {
        // Select a random password type.
        pw_type type = rand() % pw_type_count;

        // Select a random character from the selected password type.
        j = rand() % strlen(pw_chars[type]);

        // Append the character to the password.
        pw[i] = pw_chars[type][j];
    }

    // Terminate the password string.
    pw[pw_length] = '\0';

    // Print the password.
    printf("%s\n", pw);

    // Free memory.
    free(pw);
    free(pw_types);

    return EXIT_SUCCESS;
}