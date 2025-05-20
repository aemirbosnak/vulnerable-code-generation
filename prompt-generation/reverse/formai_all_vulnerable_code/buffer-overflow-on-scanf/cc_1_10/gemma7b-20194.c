//Gemma-7B DATASET v1.0 Category: System administration ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void morph_system_admin()
{
    char cmd[256];
    int sys_admin_flag = 0;
    char username[32];
    char password[32];

    system("clear");

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "supersecret") == 0)
    {
        sys_admin_flag = 1;
    }

    if (sys_admin_flag == 1)
    {
        printf("Welcome, System Administrator!\n");

        printf("Enter command: ");
        scanf("%s", cmd);

        if (strcmp(cmd, "reboot") == 0)
        {
            system("reboot");
        }
        else if (strcmp(cmd, "shutdown") == 0)
        {
            system("shutdown -h now");
        }
        else if (strcmp(cmd, "useradd") == 0)
        {
            printf("Enter new user name: ");
            scanf("%s", username);

            printf("Enter new user password: ");
            scanf("%s", password);

            system("useradd -m -c $USER -p $PASSWD");
        }
        else if (strcmp(cmd, "userdel") == 0)
        {
            printf("Enter user name: ");
            scanf("%s", username);

            system("userdel $USER");
        }
        else
        {
            printf("Invalid command.\n");
        }
    }
    else
    {
        printf("Access denied.\n");
    }
}

int main()
{
    morph_system_admin();

    return 0;
}