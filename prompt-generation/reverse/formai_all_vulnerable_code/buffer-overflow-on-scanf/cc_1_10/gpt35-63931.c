//FormAI DATASET v1.0 Category: System administration ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_menu();
void check_disk_space();
void check_memory_usage();
void check_network_status();
void reboot_system();

int main()
{
    int choice;

    // Display main menu to user
    display_menu();

    // Get user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            check_disk_space();
            break;
        case 2:
            check_memory_usage();
            break;
        case 3:
            check_network_status();
            break;
        case 4:
            reboot_system();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}

void display_menu()
{
    printf("=== System Administration Program ===\n");
    printf("1. Check disk space\n");
    printf("2. Check memory usage\n");
    printf("3. Check network status\n");
    printf("4. Reboot system\n");
}

void check_disk_space()
{
    system("df -h");
}

void check_memory_usage()
{
    system("free -m");
}

void check_network_status()
{
    system("ping www.google.com");
}

void reboot_system()
{
    char confirm[10];
    printf("Are you sure you want to reboot the system? (yes or no): ");
    scanf("%s", confirm);
    if(strcmp(confirm, "yes") == 0)
    {
        printf("Rebooting system...\n");
        system("reboot");
    }
    else
    {
        printf("System reboot cancelled.\n");
    }
}