//FormAI DATASET v1.0 Category: System administration ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int choice;

    printf("Welcome to the System Administration Program!\n");
    printf("Please select an option below.\n");
    printf("1. Check system date and time\n");
    printf("2. View system users\n");
    printf("3. View system processes\n");
    printf("4. View system memory usage\n");
    printf("5. View system hard disk status\n");
    printf("6. Exit program\n");

    scanf("%d", &choice);

    while(choice != 6) {
        switch(choice) {
            case 1:
                system("date");
                break;
            case 2:
                system("who");
                break;
            case 3:
                system("ps -aux");
                break;
            case 4:
                system("free -m");
                break;
            case 5:
                system("df -h");
                break;
            default:
                printf("Invalid option selected.\n");
        }

        printf("\nPlease select an option below.\n");
        printf("1. Check system date and time\n");
        printf("2. View system users\n");
        printf("3. View system processes\n");
        printf("4. View system memory usage\n");
        printf("5. View system hard disk status\n");
        printf("6. Exit program\n");

        scanf("%d", &choice);
    }

    printf("Thank you for using the System Administration Program!\n");

    return 0;
}