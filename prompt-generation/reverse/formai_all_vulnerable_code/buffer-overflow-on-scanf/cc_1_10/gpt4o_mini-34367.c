//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_cpu_usage() {
    FILE *fp;
    char buffer[1024];

    printf("\nCPU Usage:\n");
    fp = popen("top -bn1 | grep 'Cpu(s)'", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    pclose(fp);
}

void display_memory_usage() {
    FILE *fp;
    char buffer[1024];

    printf("\nMemory Usage:\n");
    fp = popen("free -h", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    pclose(fp);
}

void display_uptime() {
    FILE *fp;
    char buffer[1024];

    printf("\nSystem Uptime:\n");
    fp = popen("uptime -p", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    pclose(fp);
}

void clear_screen() {
    printf("\033[H\033[J");
}

void display_menu() {
    printf("System Administration Tool\n");
    printf("===========================\n");
    printf("1. Display CPU Usage\n");
    printf("2. Display Memory Usage\n");
    printf("3. Display System Uptime\n");
    printf("4. Clear Screen\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    do {
        display_menu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_cpu_usage();
                break;
            case 2:
                display_memory_usage();
                break;
            case 3:
                display_uptime();
                break;
            case 4:
                clear_screen();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please select a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}