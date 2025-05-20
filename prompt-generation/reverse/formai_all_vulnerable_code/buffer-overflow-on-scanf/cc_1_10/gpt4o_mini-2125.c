//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define MAX_PASSWORD_LENGTH 20
#define CHARACTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-+=<>?/|[]{}"
#define NUM_CHARACTERS (sizeof(CHARACTERS) - 1)

typedef struct {
    int index;
    int length;
    char password[MAX_PASSWORD_LENGTH + 1];
} PasswordArgs;

void *generate_password(void *args) {
    PasswordArgs *pArgs = (PasswordArgs *)args;
    srand(time(NULL) ^ (pArgs->index + 1));

    for (int i = 0; i < pArgs->length; i++) {
        int randomIndex = rand() % NUM_CHARACTERS;
        pArgs->password[i] = CHARACTERS[randomIndex];
    }
    pArgs->password[pArgs->length] = '\0';
    return NULL;
}

void create_passwords(int count, int length) {
    pthread_t threads[count];
    PasswordArgs passwordArgs[count];

    for (int i = 0; i < count; i++) {
        passwordArgs[i].index = i;
        passwordArgs[i].length = length;

        if (pthread_create(&threads[i], NULL, generate_password, &passwordArgs[i]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < count; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread");
            exit(EXIT_FAILURE);
        }
        printf("Password %d: %s\n", i + 1, passwordArgs[i].password);
    }
}

int main() {
    int passwordCount, passwordLength;

    printf("Secure Password Generator\n");
    printf("Enter the number of passwords to generate: ");
    scanf("%d", &passwordCount);
    printf("Enter the desired password length (up to %d): ", MAX_PASSWORD_LENGTH);
    scanf("%d", &passwordLength);

    if (passwordLength > MAX_PASSWORD_LENGTH || passwordLength <= 0) {
        fprintf(stderr, "Password length must be between 1 and %d.\n", MAX_PASSWORD_LENGTH);
        return EXIT_FAILURE;
    }

    create_passwords(passwordCount, passwordLength);

    return EXIT_SUCCESS;
}