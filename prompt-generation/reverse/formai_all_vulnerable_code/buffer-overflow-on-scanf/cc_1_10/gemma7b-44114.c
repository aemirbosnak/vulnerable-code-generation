//Gemma-7B DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>

void sys_admin(int);

int main()
{
    sys_admin(0);
    return 0;
}

void sys_admin(int current_level)
{
    int choice;

    if (current_level == 0)
    {
        printf("Welcome to the System Administration Menu.\n");
        printf("Please select an option:\n");
        printf("1. View System Information\n");
        printf("2. Modify System Settings\n");
        printf("3. Add New User Account\n");
        printf("4. Delete User Account\n");
        printf("5. Exit\n");
    }

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("System information:\n");
            printf("CPU usage: %d%%\n", rand() % 100);
            printf("Memory usage: %d%%\n", rand() % 100);
            printf("Disk usage: %d%%\n", rand() % 100);
            break;
        case 2:
            printf("Enter new system setting: ");
            scanf("%s", "");
            break;
        case 3:
            printf("Enter new user name: ");
            scanf("%s", "");
            printf("Enter new user password: ");
            scanf("%s", "");
            break;
        case 4:
            printf("Enter user name to delete: ");
            scanf("%s", "");
            break;
        case 5:
            printf("Thank you for using the System Administration Menu.\n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    sys_admin(current_level + 1);
}