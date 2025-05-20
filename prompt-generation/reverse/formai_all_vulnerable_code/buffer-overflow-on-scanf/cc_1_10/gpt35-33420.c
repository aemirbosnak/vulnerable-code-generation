//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of attempts
#define MAX_ATTEMPTS 3

// Define the username and password
#define USERNAME "admin"
#define PASSWORD "password"

void detect_invasion(char *username, char *password, int attempts)
{
    // Check if the number of attempts exceeds the maximum allowed
    if (attempts >= MAX_ATTEMPTS)
    {
        printf("Intrusion detected. Please contact the system administrator.\n");
        exit(0);
    }

    // Check if the username and password match the predefined values
    if (strcmp(username, USERNAME) != 0 || strcmp(password, PASSWORD) != 0)
    {
        printf("Incorrect username or password. Please try again.\n");

        // Increment the number of attempts
        attempts++;

        char new_username[20];
        char new_password[20];

        // Prompt the user to enter new credentials
        printf("Enter username: ");
        scanf("%s", new_username);

        printf("Enter password: ");
        scanf("%s", new_password);

        // Recursively call the function with the new credentials
        detect_invasion(new_username, new_password, attempts);
    }

    else
    {
        printf("Welcome, %s!\n", username);
    }
}

int main()
{
    char username[20];
    char password[20];

    // Prompt the user to enter credentials
    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    detect_invasion(username, password, 0);

    return 0;
}