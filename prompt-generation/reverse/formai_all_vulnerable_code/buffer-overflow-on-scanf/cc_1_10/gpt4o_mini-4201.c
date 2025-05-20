//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_PASSWORD_LENGTH 128
#define NUM_THREADS 5

typedef struct {
    int length;
    int upper;
    int lower;
    int digits;
    int special;
} PasswordOptions;

char generateRandomCharacter(int upper, int lower, int digits, int special) {
    char c;
    int choice;

    while (1) {
        choice = rand() % 4;
        if (choice == 0 && upper) {
            c = 'A' + rand() % 26;  // Uppercase letter
            break;
        } else if (choice == 1 && lower) {
            c = 'a' + rand() % 26;  // Lowercase letter
            break;
        } else if (choice == 2 && digits) {
            c = '0' + rand() % 10;   // Digit
            break;
        } else if (choice == 3 && special) {
            char specialChars[] = "!@#$%^&*()-_=+[]{}|;:,.<>?";
            c = specialChars[rand() % strlen(specialChars)];
            break;
        }
    }

    return c;
}

void *generatePassword(void *args) {
    PasswordOptions *options = (PasswordOptions *)args;
    char password[MAX_PASSWORD_LENGTH + 1];
    
    for (int i = 0; i < options->length; i++) {
        password[i] = generateRandomCharacter(options->upper, options->lower, options->digits, options->special);
    }
    password[options->length] = '\0';

    printf("Generated Password: %s\n", password);
    return NULL;
}

void askForPasswordOptions(PasswordOptions *options) {
    printf("Enter password length (1-%d): ", MAX_PASSWORD_LENGTH);
    scanf("%d", &options->length);
    if (options->length < 1 || options->length > MAX_PASSWORD_LENGTH) {
        printf("Invalid length. Setting to default length 12.\n");
        options->length = 12;
    }
    
    printf("Include uppercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &options->upper);
    printf("Include lowercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &options->lower);
    printf("Include digits? (1 for yes, 0 for no): ");
    scanf("%d", &options->digits);
    printf("Include special characters? (1 for yes, 0 for no): ");
    scanf("%d", &options->special);
}

int main() {
    srand(time(NULL));
    
    PasswordOptions options;
    askForPasswordOptions(&options);
    
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, generatePassword, (void *)&options)) {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}