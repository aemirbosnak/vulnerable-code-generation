//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0

#define MAX_THREADS 10
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int strength;
} Password;

void *check_password_strength(void *param);
int get_password_strength(char *password);

int main() {
    pthread_t threads[MAX_THREADS];
    int num_threads = 0;
    char input_password[MAX_PASSWORD_LENGTH + 1];
    Password passwords[MAX_THREADS];

    printf("Enter a password to check its strength: ");
    scanf("%s", input_password);

    strcpy(passwords[num_threads].password, input_password);
    pthread_create(&threads[num_threads], NULL, check_password_strength, &passwords[num_threads]);
    num_threads++;

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *check_password_strength(void *param) {
    Password *password = param;
    int strength = get_password_strength(password->password);

    printf("Thread %d: Password strength is %d\n", pthread_self(), strength);

    pthread_exit(0);
}

int get_password_strength(char *password) {
    int length = strlen(password);
    int uppercase = 0;
    int lowercase = 0;
    int numbers = 0;
    int symbols = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
        } else if (islower(password[i])) {
            lowercase = 1;
        } else if (isdigit(password[i])) {
            numbers = 1;
        } else {
            symbols = 1;
        }
    }

    int strength = 0;

    if (length >= 8) {
        strength++;
    }

    if (uppercase && lowercase) {
        strength++;
    } else if (uppercase || lowercase) {
        strength++;
    }

    if (numbers && symbols) {
        strength++;
    } else if (numbers || symbols) {
        strength++;
    }

    return strength;
}