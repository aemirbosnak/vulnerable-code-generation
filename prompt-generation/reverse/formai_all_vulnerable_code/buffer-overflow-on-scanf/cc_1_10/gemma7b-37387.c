//Gemma-7B DATASET v1.0 Category: System administration ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_USER_NAME_LENGTH 255

int main()
{
    char username[MAX_USER_NAME_LENGTH];
    char password[MAX_USER_NAME_LENGTH];
    char command[MAX_USER_NAME_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "secret") == 0)
    {
        printf("Welcome, administrator!\n");
        printf("Enter a command: ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0)
        {
            printf("Enter the new user's name: ");
            scanf("%s", username);

            printf("Enter the new user's password: ");
            scanf("%s", password);

            FILE *fp = fopen("/etc/passwd", "a");
            fprintf(fp, "%s:%s:0:0:0:%%s::\n", username, password, username);
            fclose(fp);

            printf("User created successfully!\n");
        }
        else if (strcmp(command, "delete") == 0)
        {
            printf("Enter the user's name: ");
            scanf("%s", username);

            FILE *fp = fopen("/etc/passwd", "r");
            char line[MAX_USER_NAME_LENGTH];
            int found = 0;

            while (fgets(line, MAX_USER_NAME_LENGTH, fp) != NULL)
            {
                if (strcmp(line, username) == 0)
                {
                    found = 1;
                    break;
                }
            }

            if (found)
            {
                FILE *fp2 = fopen("/etc/passwd", "w");
                fprintf(fp2, "%s\n", line);
                fclose(fp2);

                printf("User deleted successfully!\n");
            }
            else
            {
                printf("User not found.\n");
            }
        }
        else
        {
            printf("Invalid command.\n");
        }
    }
    else
    {
        printf("Invalid credentials.\n");
    }

    return 0;
}