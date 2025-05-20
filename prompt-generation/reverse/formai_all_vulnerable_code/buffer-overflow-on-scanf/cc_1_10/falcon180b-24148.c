//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char *password;
    int length;
    int *strength;
} PasswordData;

void *check_password_strength(void *param) {
    PasswordData *data = param;
    int strength = 0;
    int i;

    for (i = 0; i < data->length; i++) {
        if (isalpha(data->password[i])) {
            strength++;
        } else if (isdigit(data->password[i])) {
            strength++;
        } else if (ispunct(data->password[i])) {
            strength++;
        }
    }

    if (strength < 3) {
        *data->strength = 1; // Weak
    } else if (strength < 5) {
        *data->strength = 2; // Medium
    } else {
        *data->strength = 3; // Strong
    }

    return NULL;
}

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    int password_length;
    int strength;
    int i;
    pthread_t threads[MAX_THREADS];

    printf("Enter a password: ");
    scanf("%s", password);
    password_length = strlen(password);

    if (password_length > MAX_PASSWORD_LENGTH) {
        printf("Password is too long.\n");
        return 1;
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, check_password_strength, &(PasswordData){.password = password,.length = password_length,.strength = &strength});
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    if (strength == 1) {
        printf("Weak password.\n");
    } else if (strength == 2) {
        printf("Medium password.\n");
    } else {
        printf("Strong password.\n");
    }

    return 0;
}