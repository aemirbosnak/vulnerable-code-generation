//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Appointment {
    char name[50];
    char date[50];
    char time[50];
} Appointment;

int main() {
    Appointment appointments[MAX];
    int i = 0;
    int choice;
    char name[50];
    char date[50];
    char time[50];

    printf("OMG, you're in the Appointment Scheduler!\n");
    printf("------------------------------------------------------------\n");
    printf("1. Create an Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Edit an Appointment\n");
    printf("4. Delete an Appointment\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter your name: ");
            scanf("%s", appointments[i].name);

            printf("Enter the date (dd/mm/yyyy): ");
            scanf("%s", appointments[i].date);

            printf("Enter the time (hh:mm): ");
            scanf("%s", appointments[i].time);

            i++;
            break;
        case 2:
            for (i = 0; i < MAX; i++) {
                if (appointments[i].name[0] != '\0') {
                    printf("Name: %s\n", appointments[i].name);
                    printf("Date: %s\n", appointments[i].date);
                    printf("Time: %s\n", appointments[i].time);
                    printf("------------------------------------------------------------\n");
                }
            }
            break;
        case 3:
            printf("Enter the name of the appointment you want to edit: ");
            scanf("%s", name);

            for (i = 0; i < MAX; i++) {
                if (strcmp(appointments[i].name, name) == 0) {
                    printf("Enter the new date (dd/mm/yyyy): ");
                    scanf("%s", appointments[i].date);

                    printf("Enter the new time (hh:mm): ");
                    scanf("%s", appointments[i].time);
                }
            }
            break;
        case 4:
            printf("Enter the name of the appointment you want to delete: ");
            scanf("%s", name);

            for (i = 0; i < MAX; i++) {
                if (strcmp(appointments[i].name, name) == 0) {
                    appointments[i].name[0] = '\0';
                }
            }
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}