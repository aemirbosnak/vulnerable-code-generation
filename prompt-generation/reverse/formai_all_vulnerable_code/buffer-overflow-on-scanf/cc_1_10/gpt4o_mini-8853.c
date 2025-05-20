//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void get_cpu_load() {
    FILE *fp;
    char buffer[256];

    printf("CPU Load Information:\n");
    fp = popen("top -bn1 | grep 'Cpu(s)'", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    pclose(fp);
    printf("\n");
}

void get_memory_usage() {
    FILE *fp;
    char buffer[256];

    printf("Memory Usage Information:\n");
    fp = popen("free -h", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    pclose(fp);
    printf("\n");
}

void get_disk_usage() {
    FILE *fp;
    char buffer[256];

    printf("Disk Usage Information:\n");
    fp = popen("df -h", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    pclose(fp);
    printf("\n");
}

void get_network_info() {
    FILE *fp;
    char buffer[256];

    printf("Network Information:\n");
    fp = popen("ifconfig | grep 'inet '", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    pclose(fp);
    printf("\n");
}

void display_menu() {
    printf("System Administration Utility\n");
    printf("1. CPU Load\n");
    printf("2. Memory Usage\n");
    printf("3. Disk Usage\n");
    printf("4. Network Information\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                get_cpu_load();
                break;
            case 2:
                get_memory_usage();
                break;
            case 3:
                get_disk_usage();
                break;
            case 4:
                get_network_info();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}