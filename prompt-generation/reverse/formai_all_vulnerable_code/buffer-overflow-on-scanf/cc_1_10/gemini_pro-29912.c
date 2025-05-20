//GEMINI-pro DATASET v1.0 Category: Password management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Global variables
pthread_mutex_t password_lock;
pthread_cond_t password_cond;
int password_entered = 0;
char password[32];

// Function to get the password from the user
void *get_password(void *arg)
{
    sem_t *sem = (sem_t *)arg;

    // Wait for the user to enter the password
    sem_wait(sem);

    // Get the password from the user
    printf("Enter your password: ");
    scanf("%s", password);

    // Signal that the password has been entered
    pthread_mutex_lock(&password_lock);
    password_entered = 1;
    pthread_cond_signal(&password_cond);
    pthread_mutex_unlock(&password_lock);

    return NULL;
}

// Function to wait for the password to be entered
void wait_for_password()
{
    // Lock the password lock
    pthread_mutex_lock(&password_lock);

    // Wait for the password to be entered
    while (!password_entered) {
        pthread_cond_wait(&password_cond, &password_lock);
    }

    // Unlock the password lock
    pthread_mutex_unlock(&password_lock);
}

// Function to check the password
int check_password(char *password)
{
    // Check if the password is correct
    if (strcmp(password, "password") == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Main function
int main()
{
    // Initialize the semaphore
    sem_t sem;
    sem_init(&sem, 0, 0);

    // Create the thread to get the password from the user
    pthread_t thread;
    pthread_create(&thread, NULL, get_password, &sem);

    // Wait for the password to be entered
    wait_for_password();

    // Check the password
    int correct_password = check_password(password);

    // Print the result
    if (correct_password) {
        printf("Password is correct\n");
    } else {
        printf("Password is incorrect\n");
    }

    // Destroy the thread
    pthread_join(thread, NULL);

    // Destroy the semaphore
    sem_destroy(&sem);

    return 0;
}