//FormAI DATASET v1.0 Category: Password management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define MAX_PASSWORDS 10

// Define a global struct for the password manager
struct passwordManager {
    char passwords[MAX_PASSWORDS][20];
    int count;
    pthread_mutex_t lock;
};

// Initialize the password manager
struct passwordManager pm = {
    .passwords = {"password123", "letmein", "123456789", "qwerty", "abc123", "111111", "12345678", 
                  "password1", "superman", "login"},
    .count = MAX_PASSWORDS,
    .lock = PTHREAD_MUTEX_INITIALIZER
};

// Define a function for checking if a password is valid
int is_valid_password(char* password) 
{
    // Check if password is in the list of valid passwords
    for (int i = 0; i < pm.count; i++) {
        if (strcmp(pm.passwords[i], password) == 0) {
            return 1;
        }
    }
    
    return 0;
}

// Define a function for changing the password
void change_password(char* old_password, char* new_password) 
{
    // Acquire the lock to ensure that changes are made securely
    pthread_mutex_lock(&pm.lock);
    
    // Check if the old password is valid
    if (!is_valid_password(old_password)) {
        printf("Invalid old password.\n");
        pthread_mutex_unlock(&pm.lock);
        return;
    }

    // Check if the new password is valid
    if (!is_valid_password(new_password)) {
        printf("Invalid new password.\n");
        pthread_mutex_unlock(&pm.lock);
        return;
    }
    
    // Update the password in the password manager
    for (int i = 0; i < pm.count; i++) {
        if (strcmp(pm.passwords[i], old_password) == 0) {
            strcpy(pm.passwords[i], new_password);
            printf("Password changed successfully!\n");
            break;
        }
    }
    
    // Release the lock
    pthread_mutex_unlock(&pm.lock);
}

// Define a thread function for changing the password
void* thread_func(void* arg) 
{
    // Extract the old and new password from the argument
    char* passwords = (char*) arg;
    char old_password[20], new_password[20];
    sscanf(passwords, "%s %s", old_password, new_password);
    
    // Change the password
    change_password(old_password, new_password);
    
    // Exit the thread
    pthread_exit(NULL);
}

// Main function
int main()
{
    // Create two threads to change the password
    pthread_t thread1, thread2;
    
    // Specify the old and new passwords for the threads
    char passwords1[] = "password123 mynewpassword";
    char passwords2[] = "letmein mypassword";
    
    // Start the threads
    if (pthread_create(&thread1, NULL, thread_func, passwords1) != 0) {
        printf("Error creating thread 1.\n");
        return 1;
    }
    
    if (pthread_create(&thread2, NULL, thread_func, passwords2) != 0) {
        printf("Error creating thread 2.\n");
        return 1;
    }
    
    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    // Print the final list of passwords
    printf("The final list of passwords is:\n");
    for (int i = 0; i < pm.count; i++) {
        printf("%s\n", pm.passwords[i]);
    }
    
    return 0;
}