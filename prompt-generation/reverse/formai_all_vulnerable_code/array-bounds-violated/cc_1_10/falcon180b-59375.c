//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD_LENGTH 12

/*
 * Generates a random password of length PASSWORD_LENGTH
 */
char *generate_password() {
    char password[PASSWORD_LENGTH + 1] = { 0 };
    int i;

    /* Add lowercase letters */
    for (i = 0; i < 26; i++) {
        password[i] = 'a' + i;
    }

    /* Add uppercase letters */
    for (i = 0; i < 26; i++) {
        password[i + 26] = 'A' + i;
    }

    /* Add numbers */
    for (i = 0; i < 10; i++) {
        password[i + 52] = '0' + i;
    }

    /* Add special characters */
    password[62] = '!';
    password[63] = '@';
    password[64] = '#';
    password[65] = '$';

    srand(time(NULL));
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        int rand_index = rand() % 66;
        password[i] = password[rand_index];
    }

    return strdup(password);
}

/*
 * Prints the generated password to the console
 */
void print_password(char *password) {
    printf("Your password is: %s\n", password);
}

/*
 * Frees the memory allocated for the password
 */
void free_password(char *password) {
    free(password);
}

int main() {
    char *password = generate_password();
    print_password(password);
    free_password(password);

    return 0;
}