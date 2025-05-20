//FormAI DATASET v1.0 Category: Task Scheduler ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("Welcome to Grateful Task Scheduler!\n");

    while(1) {
        printf("\nPlease choose the task you want to schedule:\n");
        printf("1. Send Email\n");
        printf("2. Backup Files\n");
        printf("3. Run System Update\n");
        printf("4. Shutdown Computer\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Sending email...\n");
                sleep(2);
                printf("Email sent!\n");
                break;
            case 2:
                printf("Backing up files...\n");
                sleep(3);
                printf("Files backed up!\n");
                break;
            case 3:
                printf("Running system update...\n");
                sleep(5);
                printf("System update complete!\n");
                break;
            case 4:
                printf("Shutting down computer...\n");
                sleep(1);
                printf("Goodbye!\n");
                exit(0);
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
                break;
        }
    }

    return 0;
}