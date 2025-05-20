//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct appointment {
    char date[20];
    char time[10];
    char clientName[100];
    char description[255];
};

int main() {
    int choice;
    int numAppointments = 0;
    struct appointment appointments[100];

    printf("Welcome to the Appointment Scheduler!\n\n");

    while (1) {
        printf("Please choose one of the following options:\n");
        printf("1. Schedule an appointment\n");
        printf("2. View appointments\n");
        printf("3. Exit\n");
        printf("You chose: ");
        scanf("%d", &choice);
        printf("\n");

        if (choice == 1) {
            if (numAppointments >= 100) {
                printf("Sorry, you have reached the maximum number of appointments.\n\n");
                continue;
            }

            printf("Schedule an Appointment:\n");
            printf("Date (yyyy-mm-dd): ");
            scanf("%s", appointments[numAppointments].date);
            printf("Time (hh:mm): ");
            scanf("%s", appointments[numAppointments].time);
            printf("Client Name: ");
            scanf("%s", appointments[numAppointments].clientName);
            printf("Description: ");
            scanf("%s", appointments[numAppointments].description);
            numAppointments++;
            printf("Appointment scheduled successfully!\n\n");
        } else if (choice == 2) {
            printf("View Appointments:\n\n");
            printf("Num\tDate\t\tTime\t\tClient Name\tDescription\n");
            printf("---\t----\t\t----\t\t-----------\t-----------\n");
            for (int i = 0; i < numAppointments; i++) {
                printf("%d\t%s\t%s\t\t%s\t\t%s\n", i+1, appointments[i].date, appointments[i].time, appointments[i].clientName, appointments[i].description);
            }
            printf("\n");
        } else if (choice == 3) {
            printf("Exiting the Appointment Scheduler...\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}