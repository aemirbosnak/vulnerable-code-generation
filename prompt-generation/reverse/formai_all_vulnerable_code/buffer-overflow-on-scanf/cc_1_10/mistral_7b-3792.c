//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MIN_LENGTH 16
#define MAX_LENGTH 64
#define CHAR_SET_SIZE 62
#define RANDOM_BUFFER_SIZE 256

void generate_random_bytes(unsigned char* buffer, size_t size) {
    if (sizeof(unsigned) * 8 < (int)size * 8) {
        fprintf(stderr, "Buffer too large to generate random bytes!\n");
        exit(EXIT_FAILURE);
    }

    if (getrandom(buffer, size, 0) != size) {
        perror("getrandom() failed");
        exit(EXIT_FAILURE);
    }
}

void generate_password(char* password, size_t length) {
    unsigned char random_buffer[RANDOM_BUFFER_SIZE];
    generate_random_bytes(random_buffer, RANDOM_BUFFER_SIZE);

    size_t i, j;
    for (i = 0; i < length; i++) {
        char c = random_buffer[RANDOM_BUFFER_SIZE * getrandom() / (RANDOM_BUFFER_SIZE * RANDOM_BUFFER_SIZE) % (RANDOM_BUFFER_SIZE / CHAR_SET_SIZE)];

        if (isdigit(c)) {
            c += rand() % 10;
        }

        password[i] = (isalnum(c) || isspace(c) || c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '_' || c == '+' || c == '=' || c == '-' || c == '+' || c == '|' || c == '`' || c == '~') ? c : random_buffer[RANDOM_BUFFER_SIZE * getrandom() / (RANDOM_BUFFER_SIZE * RANDOM_BUFFER_SIZE) % (RANDOM_BUFFER_SIZE / CHAR_SET_SIZE)];
    }

    password[length] = '\0';
}

int main() {
    srand(time(NULL));

    size_t length;
    printf("Enter password length (min %d, max %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%zu", &length);

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        fprintf(stderr, "Invalid password length!\n");
        exit(EXIT_FAILURE);
    }

    char password[length + 1];
    generate_password(password, length);

    printf("Generated password: %s\n", password);

    return EXIT_SUCCESS;
}