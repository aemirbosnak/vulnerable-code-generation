//FormAI DATASET v1.0 Category: System administration ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shutdown()
{
    // System shutdown function
    system("shutdown -h now");
}

void restart()
{
    // System restart function
    system("reboot");
}

void disk_space()
{
    // Check disk space function
    system("df -h");
}

void update_system()
{
    // System update function
    system("sudo apt-get update && sudo apt-get upgrade && sudo apt-get dist-upgrade");
}

void firewall()
{
    // Firewall status function
    system("ufw status");
}

void open_firewall_port()
{
    // Open firewall port function
    int port;
    printf("Enter the port to open: ");
    scanf("%d", &port);
    char command[50];
    sprintf(command, "sudo ufw allow %d/tcp", port);
    system(command);
}

int main()
{
    // System administration menu
    int choice;

    do {
        printf("\nSystem Administration Menu:\n");
        printf("1. Shutdown the System\n");
        printf("2. Restart the System\n");
        printf("3. Check Disk Space\n");
        printf("4. Update the System\n");
        printf("5. Check Firewall Status\n");
        printf("6. Open Firewall Port\n");
        printf("0. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                shutdown();
                break;
            case 2:
                restart();
                break;
            case 3:
                disk_space();
                break;
            case 4:
                update_system();
                break;
            case 5:
                firewall();
                break;
            case 6:
                open_firewall_port();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        } 
    } while (choice != 0);

    return 0;
}