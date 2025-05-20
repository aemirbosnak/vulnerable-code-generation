//Gemma-7B DATASET v1.0 Category: System administration ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256

int main()
{
    char cmd[MAX_CMD_LEN];

    printf("Enter a command: ");

    fgets(cmd, MAX_CMD_LEN, stdin);

    // Remove newline character from the end of the command
    cmd[strcspn(cmd, "\n")] = '\0';

    // Check if the command is valid
    if (strcmp(cmd, "help") == 0)
    {
        printf("Available commands:\n");
        printf("  help\n");
        printf("  shutdown\n");
        printf("  reboot\n");
        printf("  passwd\n");
    }
    else if (strcmp(cmd, "shutdown") == 0)
    {
        printf("Are you sure you want to shutdown? (Y/N): ");

        char answer;
        scanf("%c", &answer);

        if (answer == 'Y')
        {
            system("shutdown -h now");
        }
    }
    else if (strcmp(cmd, "reboot") == 0)
    {
        printf("Are you sure you want to reboot? (Y/N): ");

        char answer;
        scanf("%c", &answer);

        if (answer == 'Y')
        {
            system("reboot");
        }
    }
    else if (strcmp(cmd, "passwd") == 0)
    {
        printf("Enter your new password: ");

        char new_passwd[MAX_CMD_LEN];
        scanf("%s", new_passwd);

        system("passwd");
    }
    else
    {
        printf("Invalid command.\n");
    }

    return 0;
}