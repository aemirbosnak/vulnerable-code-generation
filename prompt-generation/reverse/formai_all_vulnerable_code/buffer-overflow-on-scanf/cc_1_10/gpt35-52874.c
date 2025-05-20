//FormAI DATASET v1.0 Category: System administration ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void checkDisk();
void checkMemory();
void checkLoad();

int main()
{
    int choice;

    printf("Welcome to the System Admin CLI. Please select an option:\n");
    printf("1. Check Disk Space\n");
    printf("2. Check Memory Usage\n");
    printf("3. Check Load Average\n");
    printf("4. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            checkDisk();
            break;
        case 2:
            checkMemory();
            break;
        case 3:
            checkLoad();
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid option. Please try again.\n");
            break;
    }

    return 0;
}

void checkDisk()
{
    system("df -h");
}

void checkMemory()
{
    system("free -m");
    char swap[100];
    FILE *f = fopen("/proc/swaps", "r");
    fgets(swap, 100, f);
    fclose(f);
    if (strcmp(swap, "") == 0) {
        printf("Warning: Swap is not enabled on this system!\n");
    }
}

void checkLoad()
{
    char load[100];
    double loadavg;
    FILE *f = fopen("/proc/loadavg", "r");
    fgets(load, 100, f);
    fclose(f);
    sscanf(load, "%lf", &loadavg);
    printf("Load Average: %.2lf\n", loadavg);
}