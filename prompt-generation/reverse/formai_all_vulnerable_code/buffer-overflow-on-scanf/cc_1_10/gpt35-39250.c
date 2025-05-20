//FormAI DATASET v1.0 Category: Digital Diary ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int choice;
    char task[50], location[50], date[50], time[50], description[100];

    do {
        printf("\nWelcome to the Digital Diary\n");
        printf("1. Add new task\n");
        printf("2. Search for a task\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter Task: ");
                scanf("%s", task);
                printf("Enter Location: ");
                scanf("%s", location);
                printf("Enter Date: ");
                scanf("%s", date);
                printf("Enter Time: ");
                scanf("%s", time);
                printf("Enter Description: ");
                scanf("%s", description);

                // Store task in local database
                FILE *fp = fopen("data.txt", "a");
                fprintf(fp, "%s,%s,%s,%s,%s\n", task, location, date, time, description);
                fclose(fp);
                break;
            case 2:
                printf("\nEnter Task to search: ");
                scanf("%s", task);

                // Query other machines for the task
                // Receive results and display to user

                break;
            case 3:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice\n");
        }
    } while (choice != 3);
    
    return 0;
}