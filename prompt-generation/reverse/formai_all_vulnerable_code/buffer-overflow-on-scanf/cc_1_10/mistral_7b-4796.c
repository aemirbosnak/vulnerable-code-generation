//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 12
#define MAX_LENGTH 20
#define CHAR_COUNT 48

char *generate_password(size_t length) {
    char *password;
    char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>/?`~";
    int random_index;

    password = (char *)malloc(length + 1);

    if (password == NULL) {
        fprintf(stderr, "Unable to allocate memory for password\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    for (size_t i = 0; i < length; i++) {
        random_index = rand() % CHAR_COUNT;
        password[i] = characters[random_index];
    }

    password[length] = '\0';

    for (size_t i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            random_index = rand() % (length - i) + i;
            char temp = password[i];
            password[i] = password[random_index];
            password[random_index] = temp;
        }
    }

    for (size_t i = 0; i < length; i++) {
        if (isupper(password[i])) {
            random_index = rand() % (length - i) + i;
            char temp = password[i];
            password[i] = password[random_index];
            password[random_index] = temp;
        }
    }

    free(password);

    return NULL;
}

int main() {
    size_t password_length;
    char *password;

    printf("Enter the length of the password (min %d, max %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%ld", &password_length);

    password = generate_password(password_length);

    if (password == NULL) {
        fprintf(stderr, "An error occurred while generating the password\n");
        exit(EXIT_FAILURE);
    }

    printf("Your new password is: %s\n", password);

    free(password);

    return EXIT_SUCCESS;
}