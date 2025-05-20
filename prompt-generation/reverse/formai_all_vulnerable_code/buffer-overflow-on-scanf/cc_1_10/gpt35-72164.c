//FormAI DATASET v1.0 Category: System administration ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

int main(){
    char password[20];
    printf("Please enter the password to continue:\n");
    scanf("%s", password);

    if(strcmp(password, "admin123")==0){
        printf("Access Granted!\n");
        printf("Welcome to the System Administration Program\n");
        printf("-------------------------------\n");
        printf("Here are the available commands:\n");
        printf("1. Check system status\n");
        printf("2. View system logs\n");
        printf("3. Backup system files\n");
        printf("4. Restore system files\n");
        printf("5. Change system username and password\n");
        printf("6. Shutdown the system\n");

        int choice;
        printf("Enter your choice (1-6):\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("System Status:\n");
                system("uptime");
                break;
            case 2:
                printf("System Logs:\n");
                system("tail /var/log/syslog");
                break;
            case 3:
                printf("Backing up system files...\n");
                system("sudo tar -czvf system_backup.tar.gz /");
                printf("Backup complete!\n");
                break;
            case 4:
                printf("Restoring system files...\n");
                system("sudo tar -xzvf system_backup.tar.gz -C /");
                printf("Restore complete!\n");
                break;
            case 5:
                printf("Changing username and password...\n");
                system("sudo passwd");
                break;
            case 6:
                printf("Shutting down the system...\n");
                system("sudo shutdown now");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    else{
        printf("Access Denied!");
    }
    return 0;
}