//FormAI DATASET v1.0 Category: Password management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_PASSWORDS 5
#define MAX_TRIES 3

// Global Variables and Structures
char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH] = { "123456", "password", "secret", "admin", "letmein" };
bool isPasswordCracked = false;
int currentPasswordIndex = 0;

// Function Declaration
void* passwordCracker(void* arg);

int main(int argc, char** argv)
{
    pthread_t crackerThread;
    int status;

    status = pthread_create(&crackerThread, NULL, &passwordCracker, NULL);

    // Wait for the thread to complete
    pthread_join(crackerThread, NULL);

    if(isPasswordCracked)
    {
        printf("\nPassword Cracked!");
    }
    else
    {
        printf("\nAll Passwords Failed to Crack.");
    }

    return 0;
}

void* passwordCracker(void* arg)
{
    int i, j, count;
    char attempt[MAX_PASSWORD_LENGTH];

    for(i = 0; i < MAX_PASSWORDS; i++)
    {
        for(j = 0; j < MAX_TRIES; j++)
        {
            printf("\nThread: Trying to crack password %d (Attempt %d of %d)...", i + 1, j + 1, MAX_TRIES);

            printf("\nEnter Password: ");
            scanf("%s", attempt);

            if(strcmp(attempt, passwords[i]) == 0)
            {
                printf("\nThread: Password %d Cracked Successfully!\n", i + 1);
                isPasswordCracked = true;
                pthread_exit(NULL);
            }
        }

        printf("\nThread: Password %d Failed to Crack.\n", i + 1);

        // Increment Password Index to Try Next Password
        currentPasswordIndex = i + 1;

        // Sleep for 1 Second to Simulate Delay
        sleep(1);
    }

    pthread_exit(NULL);
}