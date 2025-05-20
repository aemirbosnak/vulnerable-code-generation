//Gemma-7B DATASET v1.0 Category: System administration ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sys_admin(char *command)
{
    if (strcmp(command, "users") == 0)
    {
        // List all users
        printf("Users:\n");
        system("cat /etc/passwd");
    }
    else if (strcmp(command, "adduser") == 0)
    {
        // Add a new user
        printf("Enter username:");
        char username[20];
        scanf("%s", username);

        printf("Enter password:");
        char password[20];
        scanf("%s", password);

        system("useradd -m -c \"My Comment\" -p $password $username");
    }
    else if (strcmp(command, "rmuser") == 0)
    {
        // Remove a user
        printf("Enter username:");
        char username[20];
        scanf("%s", username);

        system("userdel -r $username");
    }
    else if (strcmp(command, "files") == 0)
    {
        // List all files
        printf("Files:\n");
        system("ls");
    }
    else if (strcmp(command, "mkdir") == 0)
    {
        // Create a new directory
        printf("Enter directory name:");
        char directory[20];
        scanf("%s", directory);

        system("mkdir $directory");
    }
    else if (strcmp(command, "rm") == 0)
    {
        // Remove a file
        printf("Enter file name:");
        char filename[20];
        scanf("%s", filename);

        system("rm $filename");
    }
    else
    {
        // Invalid command
        printf("Invalid command.\n");
    }
}

int main()
{
    char command[20];

    printf("Enter command:");
    scanf("%s", command);

    sys_admin(command);

    return 0;
}