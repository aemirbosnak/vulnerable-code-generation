//Gemma-7B DATASET v1.0 Category: System administration ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

int main()
{
    char cmd[MAX_CMD_LEN];

    printf("Enter command: ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Check if command is "help"
    if (strcmp(cmd, "help") == 0)
    {
        printf("Available commands:\n");
        printf("  help\n");
        printf("  list\n");
        printf("  add [name] [value]\n");
        printf("  del [name]\n");
    }

    // Check if command is "list"
    else if (strcmp(cmd, "list") == 0)
    {
        // List all items
        printf("Items:\n");
        for (int i = 0; i < 10; i++)
        {
            printf("  %s: %d\n", "item_" + i, i + 1);
        }
    }

    // Check if command is "add"
    else if (strcmp(cmd, "add") == 0)
    {
        char name[MAX_CMD_LEN];
        int value;

        printf("Enter item name: ");
        fgets(name, MAX_CMD_LEN, stdin);

        printf("Enter item value: ");
        scanf("%d", &value);

        // Add item
        printf("Item %s added with value %d\n", name, value);
    }

    // Check if command is "del"
    else if (strcmp(cmd, "del") == 0)
    {
        char name[MAX_CMD_LEN];

        printf("Enter item name: ");
        fgets(name, MAX_CMD_LEN, stdin);

        // Delete item
        printf("Item %s deleted\n", name);
    }

    else
    {
        printf("Invalid command. Please try again.\n");
    }

    return 0;
}