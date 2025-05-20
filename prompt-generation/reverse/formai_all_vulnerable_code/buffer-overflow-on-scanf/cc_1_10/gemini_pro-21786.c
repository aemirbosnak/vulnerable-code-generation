//GEMINI-pro DATASET v1.0 Category: Password management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

// Password storage structure
typedef struct password_entry {
    char *username;
    char *password;
} password_entry;

// Thread argument structure
typedef struct thread_args {
    password_entry *passwords;
    int num_passwords;
} thread_args;

// Thread function to compare a given password with the stored passwords
void *compare_password(void *args) {
    thread_args *arg = (thread_args *)args;

    char input_password[100];
    printf("Enter the password to compare: ");
    scanf("%s", input_password);

    int found = 0;
    for (int i = 0; i < arg->num_passwords; i++) {
        if (strcmp(arg->passwords[i].password, input_password) == 0) {
            printf("Password found for user: %s\n", arg->passwords[i].username);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Password not found!\n");
    }

    return NULL;
}

int main() {
    // Initialize the password database
    password_entry passwords[3] = {
        {"Alice", "password1"},
        {"Bob", "password2"},
        {"Charlie", "password3"}
    };

    int num_passwords = 3;

    // Create a thread argument structure
    thread_args args;
    args.passwords = passwords;
    args.num_passwords = num_passwords;

    // Create a thread to compare the password
    pthread_t thread;
    pthread_create(&thread, NULL, compare_password, &args);

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    return 0;
}