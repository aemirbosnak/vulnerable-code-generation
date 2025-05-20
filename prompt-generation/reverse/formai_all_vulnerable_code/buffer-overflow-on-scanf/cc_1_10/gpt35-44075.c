//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char command[20];
    char password[10] = "12345";
    int attempts = 0;
    int paranoidMode = 0;

    while (1)
    {
        printf("Enter command: ");
        scanf(" %s", command);

        if (strcmp(command, "launch-drone") == 0)
        {
            if (paranoidMode)
            {
                printf("Paranoid mode activated. Enter password to launch drone: ");
                scanf(" %s", password);

                if (strcmp(password, "12345") == 0)
                {
                    printf("Drone launched successfully.\n");
                }
                else
                {
                    attempts++;
                    if (attempts >= 3)
                    {
                        printf("Too many failed attempts. System locked down.\n");
                        exit(0);
                    }

                    printf("Incorrect password. Try again.\n");
                }
            }
            else
            {
                printf("Drone launched successfully.\n");
            }
        }
        else if (strcmp(command, "toggle-paranoid-mode") == 0)
        {
            paranoidMode = !paranoidMode;
            printf("Paranoid mode %s.\n", paranoidMode ? "activated" : "deactivated");
        }
        else if (strcmp(command, "exit") == 0)
        {
            printf("Exiting program.\n");
            exit(0);
        }
        else
        {
            printf("Unknown command.\n");
        }
    }

    return 0;
}