//Gemma-7B DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void sys_admin(int level)
{
    if (level > 5)
    {
        return;
    }

    printf("Level: %d\n", level);

    switch (level)
    {
        case 0:
            printf("Welcome to the main menu.\n");
            break;
        case 1:
            printf("Options for user management.\n");
            break;
        case 2:
            printf("Options for system monitoring.\n");
            break;
        case 3:
            printf("Options for security settings.\n");
            break;
        case 4:
            printf("Options for network management.\n");
            break;
        case 5:
            printf("Options for advanced system tuning.\n");
            break;
    }

    printf("Please choose an option: ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            sys_admin(level + 1);
            break;
        case 2:
            sys_admin(level + 1);
            break;
        case 3:
            sys_admin(level + 1);
            break;
        case 4:
            sys_admin(level + 1);
            break;
        case 5:
            sys_admin(level + 1);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

int main()
{
    sys_admin(0);

    return 0;
}