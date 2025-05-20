//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void shape_shifting(int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void monitor_ram_usage() {
    system("free | awk '/Mem/{printf \"RAM usage: %.2f%%\", $3*100/$2 }'");
}

int main() {
    int rows = 10;
    int cols = 20;
    int choice;

    while (1) {
        printf("\n");
        printf("Enter 1 to monitor RAM usage\n");
        printf("Enter 2 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("clear");
                printf("Monitoring RAM usage:\n");
                monitor_ram_usage();
                break;
            case 2:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }

        printf("\n");
        printf("Enter 1 to continue or any other key to exit\n");
        scanf("%d", &choice);
        if (choice!= 1) {
            break;
        }
        printf("\n");
        system("clear");
        printf("Press any key to continue...\n");
        getchar();
        shape_shifting(rows, cols);
        rows++;
        cols++;
    }

    return 0;
}