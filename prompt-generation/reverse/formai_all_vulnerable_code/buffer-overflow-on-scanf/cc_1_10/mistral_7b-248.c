//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LENGTH 16
#define CHAR_SET_SIZE 64

char char_set[] = "!@#$%^&*()_+-={}[]|\\:;\"'<>,.?/~`";

void secure_random_bytes(unsigned char *buf, size_t size) {
    unsigned int seed = time(NULL);
    for (size_t i = 0; i < size; ++i) {
        buf[i] = (unsigned char)(rand_r(&seed) % CHAR_SET_SIZE);
    }
}

void print_password(const char *char_set, size_t length) {
    unsigned char password[LENGTH];
    secure_random_bytes(password, length);

    printf("Your secure password is: ");
    for (size_t i = 0; i < length; ++i) {
        putchar(char_set[password[i]]);
    }
    putchar('\n');
}

int main() {
    srand(time(NULL));

    puts("Welcome, mortal, to the crypt of secrets.\n");
    puts("Enter the length of your desired password (1-16): ");
    int password_length;
    scanf("%d", &password_length);

    if (password_length < 1 || password_length > LENGTH) {
        puts("Your choice is invalid.\n");
        return EXIT_FAILURE;
    }

    puts("Your password will be generated using the following mystic symbols:\n");
    for (size_t i = 0; i < strlen(char_set); ++i) {
        putchar(char_set[i]);
    }
    putchar('\n');

    print_password(char_set, password_length);

    return EXIT_SUCCESS;
}