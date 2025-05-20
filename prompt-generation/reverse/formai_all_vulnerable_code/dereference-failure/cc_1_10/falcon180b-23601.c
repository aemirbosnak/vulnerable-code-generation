//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 64
#define MIN_PASSWORD_LENGTH 8

char *generate_password(int length) {
    char *password = (char *)malloc(length + 1);
    if (password == NULL) {
        printf("Error: Could not allocate memory for password.\n");
        exit(1);
    }

    int i;
    for (i = 0; i < length; i++) {
        char c = rand() % 3 + 'a';
        if (isalpha(c)) {
            password[i] = c;
        } else {
            i--;
        }
    }

    password[i] = '\0';

    return password;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <password length>\n", argv[0]);
        exit(1);
    }

    int length = atoi(argv[1]);

    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        printf("Error: Password length must be between %d and %d characters.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        exit(1);
    }

    char *password = generate_password(length);

    printf("Random password: %s\n", password);

    free(password);

    return 0;
}