//Gemma-7B DATASET v1.0 Category: System administration ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void main()
{
    system("clear");
    system("echo \"Welcome to the C System Administration Lab\"");
    system("sleep 2");
    system("clear");

    char cmd[256];

    printf("Enter a command: ");
    scanf("%s", cmd);

    if (strcmp(cmd, "reboot") == 0)
    {
        system("reboot");
    }
    else if (strcmp(cmd, "shutdown") == 0)
    {
        system("shutdown -p");
    }
    else if (strcmp(cmd, "update") == 0)
    {
        system("apt-get update");
    }
    else if (strcmp(cmd, "upgrade") == 0)
    {
        system("apt-get upgrade");
    }
    else if (strcmp(cmd, "install") == 0)
    {
        system("apt-get install");
    }
    else if (strcmp(cmd, "remove") == 0)
    {
        system("apt-get remove");
    }
    else
    {
        printf("Invalid command. Please try again.\n");
    }

    system("sleep 2");
    system("clear");

    printf("Thank you for using the C System Administration Lab.\n");
    system("pause");
}