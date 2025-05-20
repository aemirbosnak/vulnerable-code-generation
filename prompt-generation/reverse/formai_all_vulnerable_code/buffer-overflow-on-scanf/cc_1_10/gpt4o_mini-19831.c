//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 128

typedef struct {
    char *passwords[MAX_PASSWORDS];
    int count;
    int length;
    int use_uppercase;
    int use_lowercase;
    int use_numbers;
    int use_special;
} PasswordArgs;

void *generate_password(void *args) {
    PasswordArgs *pArgs = (PasswordArgs *)args;
    const char *uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *lowercase = "abcdefghijklmnopqrstuvwxyz";
    const char *numbers = "0123456789";
    const char *special = "!@#$%^&*()-_=+[]{}|;:,.<>?";

    char choices[MAX_LENGTH];
    int total_choices = 0;

    if (pArgs->use_uppercase) {
        strcpy(choices + total_choices, uppercase);
        total_choices += strlen(uppercase);
    }
    if (pArgs->use_lowercase) {
        strcpy(choices + total_choices, lowercase);
        total_choices += strlen(lowercase);
    }
    if (pArgs->use_numbers) {
        strcpy(choices + total_choices, numbers);
        total_choices += strlen(numbers);
    }
    if (pArgs->use_special) {
        strcpy(choices + total_choices, special);
        total_choices += strlen(special);
    }

    if (total_choices == 0) {
        fprintf(stderr, "No character types selected for password generation.\n");
        pthread_exit(NULL);
    }

    for (int i = 0; i < pArgs->count; ++i) {
        pArgs->passwords[i] = (char *)malloc(pArgs->length + 1);
        if (!pArgs->passwords[i]) {
            fprintf(stderr, "Memory allocation failed.\n");
            pthread_exit(NULL);
        }

        for (int j = 0; j < pArgs->length; j++) {
            pArgs->passwords[i][j] = choices[rand() % total_choices];
        }
        pArgs->passwords[i][pArgs->length] = '\0'; // Null-terminate the string
    }

    pthread_exit(NULL);
}

int main() {
    srand(time(NULL)); // Seed for randomness

    PasswordArgs pArgs;
    pthread_t thread;

    printf("Enter number of passwords to generate: ");
    scanf("%d", &pArgs.count);

    printf("Enter desired password length (1-%d): ", MAX_LENGTH);
    scanf("%d", &pArgs.length);
    if (pArgs.length < 1 || pArgs.length > MAX_LENGTH) {
        fprintf(stderr, "Password length must be between 1 and %d.\n", MAX_LENGTH);
        return 1;
    }

    printf("Include uppercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &pArgs.use_uppercase);
    printf("Include lowercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &pArgs.use_lowercase);
    printf("Include numbers? (1 for yes, 0 for no): ");
    scanf("%d", &pArgs.use_numbers);
    printf("Include special characters? (1 for yes, 0 for no): ");
    scanf("%d", &pArgs.use_special);

    pthread_create(&thread, NULL, generate_password, (void *)&pArgs);
    pthread_join(thread, NULL);

    printf("\nGenerated Passwords:\n");
    for (int i = 0; i < pArgs.count; ++i) {
        printf("%s\n", pArgs.passwords[i]);
        free(pArgs.passwords[i]); // Free allocated memory
    }

    return 0;
}