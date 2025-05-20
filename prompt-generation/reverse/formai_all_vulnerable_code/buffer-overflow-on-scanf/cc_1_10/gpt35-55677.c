//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: inquisitive
#include <stdio.h>
#include <string.h>

#define MAX_ATTEMPTS 3

int main()
{
    char password[30];

    int attempts = 0;
    int logged_in = 0;

    while (!logged_in && attempts < MAX_ATTEMPTS)
    {
        printf("Enter your password: ");
        scanf("%s", password);

        if (strcmp(password, "mypassword123") == 0)
        {
            logged_in = 1;
            printf("Welcome, user!\n");
        }
        else
        {
            printf("Incorrect password. Please try again.\n");
            attempts++;
        }
    }

    if (!logged_in)
    {
        printf("Too many incorrect attempts. Exiting program.\n");
        return 0;
    }

    // Intrusion detection system
    printf("Intrusion detection system activated. Please do not attempt to hack this system.\n");

    int seconds_since_login = 0;
    int max_idle_time = 10; // in seconds

    while (1)
    {
        printf("You have been logged in for %d seconds. Enter 'logout' to exit.\n", seconds_since_login++);
        
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "logout") == 0)
        {
            printf("Logging out.\n");
            return 0;
        }

        // Check if user has been idle for too long
        if (seconds_since_login > max_idle_time)
        {
            printf("You have been idle for too long. You will now be logged out.\n");
            return 0;
        }
    }

    return 0;
}