//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_CRED_LENGTH 20
#define MAX_ATTEMPTS 3

int main()
{
    char username[MAX_CRED_LENGTH];
    char password[MAX_CRED_LENGTH];
    int attempt = 1;
    char line[MAX_LINE_LENGTH];
    FILE *fptr;

    printf("Welcome to the Intrusion Detection System\n");

    while (attempt <= MAX_ATTEMPTS)
    {
        printf("Please enter your username: ");
        scanf("%s", username);
        printf("Please enter your password: ");
        scanf("%s", password);

        // Open the file containing the credentials
        fptr = fopen("credentials.txt", "r");

        if (fptr == NULL)
        {
            printf("Error occurred while opening the file\n");
            exit(1);
        }

        // Check if the credentials are valid
        while (fgets(line, MAX_LINE_LENGTH, fptr) != NULL)
        {
            strtok(line, "\n");
            if (strcmp(line, username) == 0)
            {
                if (fgets(line, MAX_LINE_LENGTH, fptr) != NULL)
                {
                    strtok(line, "\n");
                    if (strcmp(line, password) == 0)
                    {
                        printf("Login successful\n");
                        fclose(fptr);
                        return 0;
                    }
                }
            }
        }
        printf("Invalid credentials. Please try again.\n");
        fclose(fptr);
        attempt++;
    }

    printf("Maximum login attempts reached. System shutting down.\n");
    return 0;
}