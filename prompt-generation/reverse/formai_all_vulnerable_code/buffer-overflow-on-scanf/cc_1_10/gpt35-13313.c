//FormAI DATASET v1.0 Category: System administration ; Style: satisfied
#include <stdio.h>

void printOptions() {
    printf("System Configuration Options:\n");
    printf("1. Change time zone\n");
    printf("2. Add new user\n");
    printf("3. Check disk usage\n");
    printf("4. Restart system\n");
    printf("5. Exit\n\n");
}

void changeTimeZone() {
    printf("Enter new time zone: ");
    char timeZone[50];
    scanf("%s", timeZone);
    printf("Time zone changed to %s\n\n", timeZone);
}

void addUser() {
    printf("Enter username: ");
    char username[50];
    scanf("%s", username);
    printf("Enter password: ");
    char password[50];
    scanf("%s", password);
    printf("User %s added successfully\n\n", username);
}

void checkDiskUsage() {
    printf("Disk usage:\n");
    system("df -h");
    printf("\n");
}

void restartSystem() {
    printf("Are you sure you want to restart the system? (Y/N)\n");
    char confirm;
    scanf(" %c", &confirm);
    if(confirm == 'Y' || confirm == 'y') {
        printf("Restarting system...\n");
        system("reboot");
    } else {
        printf("Restart cancelled\n\n");
    }
}

int main() {
    int option;
    
    printf("Welcome to System Admin!\n\n");
    
    while(1) {
        printOptions();
        
        printf("Enter option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                printf("\n");
                changeTimeZone();
                break;
            case 2:
                printf("\n");
                addUser();
                break;
            case 3:
                printf("\n");
                checkDiskUsage();
                break;
            case 4:
                printf("\n");
                restartSystem();
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
                break;
            default:
                printf("Invalid option\n\n");
        }
    }
    
    return 0;
}