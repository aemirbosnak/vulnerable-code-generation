//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_THREADS 4

// Thread arguments
typedef struct {
    char *password;
    int *result;
} thread_args;

// Password requirements
#define MIN_LENGTH 8
#define MAX_LENGTH 32
#define MIN_LOWERCASE 1
#define MIN_UPPERCASE 1
#define MIN_DIGIT 1
#define MIN_SPECIAL 1

// Check if a character is lowercase
int is_lowercase(char c) {
    return c >= 'a' && c <= 'z';
}

// Check if a character is uppercase
int is_uppercase(char c) {
    return c >= 'A' && c <= 'Z';
}

// Check if a character is a digit
int is_digit(char c) {
    return c >= '0' && c <= '9';
}

// Check if a character is a special character
int is_special(char c) {
    return strchr("!@#$%^&*()_+-=[]{};':,./<>?", c) != NULL;
}

// Check if a password is strong
int is_strong_password(char *password) {
    int length = strlen(password);

    // Check length
    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        return 0;
    }

    // Check lowercase
    int num_lowercase = 0;
    for (int i = 0; i < length; i++) {
        if (is_lowercase(password[i])) {
            num_lowercase++;
        }
    }
    if (num_lowercase < MIN_LOWERCASE) {
        return 0;
    }

    // Check uppercase
    int num_uppercase = 0;
    for (int i = 0; i < length; i++) {
        if (is_uppercase(password[i])) {
            num_uppercase++;
        }
    }
    if (num_uppercase < MIN_UPPERCASE) {
        return 0;
    }

    // Check digit
    int num_digit = 0;
    for (int i = 0; i < length; i++) {
        if (is_digit(password[i])) {
            num_digit++;
        }
    }
    if (num_digit < MIN_DIGIT) {
        return 0;
    }

    // Check special
    int num_special = 0;
    for (int i = 0; i < length; i++) {
        if (is_special(password[i])) {
            num_special++;
        }
    }
    if (num_special < MIN_SPECIAL) {
        return 0;
    }

    // All requirements met
    return 1;
}

// Thread function
void *thread_func(void *args) {
    thread_args *a = (thread_args *)args;
    int result = is_strong_password(a->password);
    *a->result = result;
    return NULL;
}

int main() {
    // Get the number of passwords to check
    int num_passwords;
    printf("Enter the number of passwords to check: ");
    scanf("%d", &num_passwords);

    // Get the passwords
    char **passwords = (char **)malloc(num_passwords * sizeof(char *));
    for (int i = 0; i < num_passwords; i++) {
        char password[MAX_LENGTH + 1];
        printf("Enter password %d: ", i + 1);
        scanf("%s", password);
        passwords[i] = strdup(password);
    }

    // Create threads
    pthread_t threads[NUM_THREADS];
    int results[num_passwords];
    for (int i = 0; i < num_passwords; i++) {
        thread_args *args = (thread_args *)malloc(sizeof(thread_args));
        args->password = passwords[i];
        args->result = &results[i];
        pthread_create(&threads[i], NULL, thread_func, args);
    }

    // Join threads
    for (int i = 0; i < num_passwords; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print results
    for (int i = 0; i < num_passwords; i++) {
        if (results[i]) {
            printf("Password %d is strong\n", i + 1);
        } else {
            printf("Password %d is weak\n", i + 1);
        }
    }

    // Free memory
    for (int i = 0; i < num_passwords; i++) {
        free(passwords[i]);
    }
    free(passwords);

    return 0;
}