//FormAI DATASET v1.0 Category: System administration ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// module for checking disk usage
void check_disk_usage() {
    system("df -h");
}

// module for checking system memory
void check_memory_usage() {
    system("free -h");
}

// module for checking CPU usage
void check_cpu_usage() {
    system("top -bn1 | grep load | awk '{printf \"CPU Load: %.2f\", $(NF-2)}'");
}

int main() {
    int choice;
    printf("Welcome to System Administration Program\n");
    printf("----------------------------------------\n");
    printf("Choose an option:\n");
    printf("1. Check disk usage\n");
    printf("2. Check memory usage\n");
    printf("3. Check CPU usage\n");
    printf("4. Exit\n");
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                check_disk_usage();
                break;
            case 2:
                check_memory_usage();
                break;
            case 3:
                check_cpu_usage();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 4);
    return 0;
}