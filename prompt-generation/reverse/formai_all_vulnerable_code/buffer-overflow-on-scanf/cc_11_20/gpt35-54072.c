//FormAI DATASET v1.0 Category: System administration ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice, user_count = 0, cpu_load, ram_usage, disk_space;
    char username[20];

    printf("Welcome to the system administration program!\n");

    while (1) {
        printf("\nPlease select an option:\n");
        printf("1. Add user\n");
        printf("2. Show user count\n");
        printf("3. Check CPU load\n");
        printf("4. Check RAM usage\n");
        printf("5. Check disk space\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter username: ");
                scanf("%s", username);
                printf("User %s added successfully!\n", username);
                user_count++;
                break;
            case 2:
                printf("\nCurrent user count: %d\n", user_count);
                break;
            case 3:
                printf("\nEnter CPU load: ");
                scanf("%d", &cpu_load);
                if (cpu_load > 80) {
                    printf("WARNING: High CPU usage detected! Taking action...\n");
                    // code to reduce CPU load goes here
                }
                else {
                    printf("CPU usage within normal range.\n");
                }
                break;
            case 4:
                printf("\nEnter RAM usage: ");
                scanf("%d", &ram_usage);
                if (ram_usage > 90) {
                    printf("WARNING: High RAM usage detected! Taking action...\n");
                    // code to reduce RAM usage goes here
                }
                else {
                    printf("RAM usage within normal range.\n");
                }
                break;
            case 5:
                printf("\nEnter disk space usage: ");
                scanf("%d", &disk_space);
                if (disk_space > 70) {
                    printf("WARNING: High disk space usage detected! Taking action...\n");
                    // code to free up disk space goes here
                }
                else {
                    printf("Disk space usage within normal range.\n");
                }
                break;
            case 6:
                printf("\nThank you for using the system administration program!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}