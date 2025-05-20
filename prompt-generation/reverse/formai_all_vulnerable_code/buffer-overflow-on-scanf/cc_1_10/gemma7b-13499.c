//Gemma-7B DATASET v1.0 Category: Password management ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

#define PASSWORD_FILE "passwords.txt"

int main()
{
    system("/bin/clear");
    char username[20];
    printf("Enter your username: ");
    scanf("%s", username);

    system("/bin/clear");

    char password[20];
    printf("Enter your password: ");
    scanf("%s", password);

    FILE *fp;
    fp = fopen(PASSWORD_FILE, "r");

    char stored_username[20];
    char stored_password[20];

    int i = 0;
    while (fscanf(fp, "%s %s\n", stored_username, stored_password) != EOF)
    {
        if (strcmp(username, stored_username) == 0)
        {
            if (strcmp(password, stored_password) == 0)
            {
                printf("Access granted.\n");
                exit(0);
            }
            else
            {
                printf("Incorrect password.\n");
                exit(1);
            }
        }
        i++;
    }

    fclose(fp);

    printf("Invalid username.\n");
    exit(1);
}