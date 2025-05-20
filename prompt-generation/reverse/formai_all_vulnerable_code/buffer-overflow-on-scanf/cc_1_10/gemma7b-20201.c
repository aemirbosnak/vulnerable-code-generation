//Gemma-7B DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void sys_admin(int level)
{
    int choice;
    char cmd[20];

    if (level == 0)
    {
        printf("Enter 'help' for more information, 'exit' to quit: ");
        scanf("%s", cmd);

        if (strcmp(cmd, "help") == 0)
        {
            printf("Available commands:\n"
                   "1. user add\n"
                   "2. user delete\n"
                   "3. system restart\n"
                   "4. log view\n"
                   "5. exit\n");
        }
        else if (strcmp(cmd, "exit") == 0)
        {
            exit(0);
        }
        else
        {
            printf("Invalid command. Please try again.\n");
        }
    }
    else
    {
        printf("Enter the command: ");
        scanf("%s", cmd);

        if (strcmp(cmd, "user add") == 0)
        {
            sys_admin(1);
        }
        else if (strcmp(cmd, "user delete") == 0)
        {
            sys_admin(1);
        }
        else if (strcmp(cmd, "system restart") == 0)
        {
            sys_admin(1);
        }
        else if (strcmp(cmd, "log view") == 0)
        {
            sys_admin(1);
        }
        else
        {
            printf("Invalid command. Please try again.\n");
        }
    }
}

int main()
{
    sys_admin(0);

    return 0;
}