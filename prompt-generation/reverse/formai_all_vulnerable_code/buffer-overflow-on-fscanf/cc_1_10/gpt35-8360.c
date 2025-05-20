//FormAI DATASET v1.0 Category: System event logger ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define a structure to hold system event information */
struct event {
    char type[20];
    char description[100];
    char date[20];
    char time[20];
};

int main() {
    int choice;
    struct event e;
    FILE *fp;

    /* Print the menu and get user input */
    printf("System Event Logger\n");
    printf("1. Log an event\n");
    printf("2. Display all events\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while (choice != 3) {
        /* Perform the selected action */
        switch (choice) {
            case 1:
                printf("Enter event type: ");
                scanf("%s", e.type);
                printf("Enter event description: ");
                scanf("%s", e.description);
                time_t now = time(NULL);
                strftime(e.date, 20, "%m/%d/%Y", localtime(&now));
                strftime(e.time, 20, "%H:%M:%S", localtime(&now));

                /* Open the file to append the event */
                fp = fopen("events.txt", "a");
                if (fp == NULL) {
                    printf("Error opening file!");
                    exit(1);
                }

                /* Write the event to the file */
                fprintf(fp, "%s\t%s\t%s\t%s\n", e.type, e.description, e.date, e.time);

                /* Close the file */
                fclose(fp);
                printf("Event logged successfully.\n\n");
                break;

            case 2:
                /* Open the file to display all events */
                fp = fopen("events.txt", "r");
                if (fp == NULL) {
                    printf("Error opening file!");
                    exit(1);
                }

                /* Read and display each event */
                printf("Type\tDescription\tDate\tTime\n");
                while (fscanf(fp, "%s\t%s\t%s\t%s", e.type, e.description, e.date, e.time) != EOF) {
                    printf("%s\t%s\t%s\t%s\n", e.type, e.description, e.date, e.time);
                }

                /* Close the file */
                fclose(fp);
                printf("\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }

        /* Print the menu and get user input again */
        printf("System Event Logger\n");
        printf("1. Log an event\n");
        printf("2. Display all events\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    /* Exit the program */
    printf("Exiting...\n");
    return 0;
}