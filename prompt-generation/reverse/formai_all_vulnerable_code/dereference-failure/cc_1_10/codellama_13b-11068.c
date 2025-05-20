//Code Llama-13B DATASET v1.0 Category: Secure Password Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 16
#define MIN_PASSWORD_LENGTH 8

void generate_password(char *password, int length) {
    // Generate random bytes for the password
    unsigned char *bytes = malloc(length);
    if (bytes == NULL) {
        printf("Error: unable to allocate memory for password.\n");
        return;
    }
    for (int i = 0; i < length; i++) {
        bytes[i] = (unsigned char) rand();
    }

    // Convert the random bytes to a printable password
    int j = 0;
    for (int i = 0; i < length; i++) {
        char c = (char) (bytes[i] % 94) + 33;
        password[j++] = c;
    }
    password[j] = '\0';

    // Print the generated password
    printf("Generated password: %s\n", password);

    // Free the memory used by the random bytes
    free(bytes);
}

int main(int argc, char **argv) {
    // Check if the length argument is provided
    if (argc < 2) {
        printf("Usage: %s <length>\n", argv[0]);
        return 1;
    }

    // Get the password length
    int length = atoi(argv[1]);

    // Check if the length is valid
    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        printf("Error: password length must be between %d and %d characters.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        return 1;
    }

    // Generate the password
    char password[MAX_PASSWORD_LENGTH + 1];
    generate_password(password, length);

    return 0;
}