//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a Threshold Value for Intrusion Detection
#define THRESHOLD 15

int main()
{
    // Define an array to store the login attempts
    char attempts[50][50];
    int count = 0; // Counter for number of login attempts
    int flag = 0; // Flag for Intrusion Detection

    printf("Welcome to the Login Page!\n");

    // Loop through login attempts
    while (1)
    {
        char username[50];
        char password[50];

        // Prompt user for username and password
        printf("Username: ");
        scanf("%s", username);
        printf("Password: ");
        scanf("%s", password);

        // Store the login attempt in the array
        strcpy(attempts[count], username);

        // Count the number of unique login attempts
        int unique_count = 0;
        for (int i = 0; i <= count; i++)
        {
            int match = 0;
            for (int j = 0; j <= i; j++)
            {
                if (strcmp(attempts[i], attempts[j]) == 0)
                {
                    match++;
                }
            }
            if (match == 1)
            {
                unique_count++;
            }
        }

        // Check if unique login attempts exceed the threshold value
        if (unique_count > THRESHOLD)
        {
            printf("Intrusion Detected!\n");
            flag = 1; // Set flag to indicate intrusion
        }

        // Increment the login attempt count
        count++;

        // Simulate login process
        int login_success = rand() % 2;

        if (login_success)
        {
            printf("Login Successful!\n");
        }
        else
        {
            printf("Incorrect Username or Password. Please try again.\n");
        }

        // Check if flag is set to indicate intrusion
        if (flag)
        {
            printf("Please contact system administrator immediately!\n");
            break;
        }
    }

    return 0;
}