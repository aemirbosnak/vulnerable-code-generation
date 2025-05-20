//FormAI DATASET v1.0 Category: System administration ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void show_menu() {
    printf("Please select an option:\n");
    printf("1. Check system resources\n");
    printf("2. Restart a service\n");
    printf("3. View logs\n");
    printf("4. Restart the system\n");
    printf("5. Exit\n");
}

void check_resources() {
    printf("Checking system resources...\n");
    // code to check system resources
    printf("System resources OK.\n");
}

void restart_service() {
    char service_name[50];
    printf("Please enter the name of the service to restart: ");
    scanf("%s", service_name);
    
    printf("Restarting %s service...\n", service_name);
    // code to restart service
    printf("%s service restarted.\n", service_name);
}

void view_logs() {
    char log_file[50];
    printf("Please enter the name of the log file to view: ");
    scanf("%s", log_file);
    
    printf("Viewing %s log file...\n", log_file);
    // code to view log file
}

void restart_system() {
    printf("Restarting the system...\n");
    // code to restart system
    printf("System restarted.\n");
}

int main() {
    bool running = true;
    int option;
    
    while (running) {
        show_menu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                check_resources();
                break;
            case 2:
                restart_service();
                break;
            case 3:
                view_logs();
                break;
            case 4:
                restart_system();
                break;
            case 5:
                printf("Goodbye!\n");
                running = false;
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }
    
    return 0;
}