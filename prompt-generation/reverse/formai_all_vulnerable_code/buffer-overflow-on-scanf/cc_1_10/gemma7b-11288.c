//Gemma-7B DATASET v1.0 Category: System administration ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    system("clear");
    system("echo \"Welcome to the C System Administration Interface!\"");

    char cmd[255];

    printf("Enter a command: ");
    scanf("%s", cmd);

    if (strcmp(cmd, "reboot") == 0)
    {
        system("shutdown -r");
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
    else if (strcmp(cmd, "list") == 0)
    {
        system("apt-get list");
    }
    else
    {
        system("echo \"Invalid command. Please try again.\"");
    }

    system("echo \"Thank you for using the C System Administration Interface!\"");

    return 0;
}