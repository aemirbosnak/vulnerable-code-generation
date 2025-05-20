//Gemma-7B DATASET v1.0 Category: System administration ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

void sys_admin(void)
{
    char cmd[256];

    printf("Welcome to the C System Administration Interface!\n");
    printf("Please enter a command: ");

    fgets(cmd, 256, stdin);

    if (strcmp(cmd, "shutdown") == 0)
    {
        system("shutdown -h now");
    }
    else if (strcmp(cmd, "reboot") == 0)
    {
        system("reboot");
    }
    else if (strcmp(cmd, "useradd") == 0)
    {
        printf("Enter the new user's name: ");
        char username[256];
        scanf("%s", username);

        printf("Enter the new user's password: ");
        char password[256];
        scanf("%s", password);

        system("useradd -m -p $password $username");
    }
    else if (strcmp(cmd, "userdel") == 0)
    {
        printf("Enter the user's name: ");
        char username[256];
        scanf("%s", username);

        system("userdel $username");
    }
    else if (strcmp(cmd, "passwd") == 0)
    {
        printf("Enter the user's name: ");
        char username[256];
        scanf("%s", username);

        printf("Enter the new password: ");
        char new_password[256];
        scanf("%s", new_password);

        system("passwd $username -e $new_password");
    }
    else
    {
        printf("Invalid command. Please try again.\n");
    }
}

int main()
{
    sys_admin();

    return 0;
}