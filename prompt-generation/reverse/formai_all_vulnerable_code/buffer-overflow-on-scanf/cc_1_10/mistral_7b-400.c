//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_LENGTH 12
#define MAX_LENGTH 16
#define CHAR_SET_SIZE 62

void generate_password(char *password, size_t length) {
    static char char_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-={[}]:;\"<>,.?/~`";
    size_t i, j;

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Error: Password length must be between %d and %d!\n", MIN_LENGTH, MAX_LENGTH);
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    for (i = 0; i < length; i++) {
        password[i] = char_set[rand() % CHAR_SET_SIZE];
    }

    for (i = 0; i < length / 2; i++) {
        j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    password[length] = '\0';
}

int main() {
    char password[MAX_LENGTH + 1];
    size_t length;

    printf("Surprisedly, I'll generate you a secure password now!\n");
    printf("How long should it be? (Between %d and %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%ld", &length);

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Error: Password length must be between %d and %d!\n", MIN_LENGTH, MAX_LENGTH);
        return EXIT_FAILURE;
    }

    generate_password(password, length);
    printf("Your new secure password is: %s\n", password);

    return EXIT_SUCCESS;
}