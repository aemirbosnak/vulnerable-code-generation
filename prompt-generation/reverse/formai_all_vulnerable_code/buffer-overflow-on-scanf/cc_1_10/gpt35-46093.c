//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Appointment {
    char name[50];
    char date[20];
    char time[20];
};

void scheduleAppointment(struct Appointment appointments[], int *numAppointments);
void printAppointments(struct Appointment appointments[], int numAppointments);

int main() {
    struct Appointment appointments[20];
    int numAppointments = 0;
    int option;

    do {
        printf("\nAppointment Scheduler\n");
        printf("1. Schedule Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                scheduleAppointment(appointments, &numAppointments);
                break;
            case 2:
                printAppointments(appointments, numAppointments);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 3);

    return 0;
}

void scheduleAppointment(struct Appointment appointments[], int *numAppointments) {
    printf("\nScheduling Appointment\n");

    if (*numAppointments == 20) {
        printf("Sorry, you can only have a maximum of 20 appointments scheduled.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", appointments[*numAppointments].name);

    printf("Enter date (MM/DD/YYYY): ");
    scanf("%s", appointments[*numAppointments].date);

    printf("Enter time (HH:MM AM/PM): ");
    scanf("%s", appointments[*numAppointments].time);

    printf("Appointment scheduled for %s on %s at %s.\n", appointments[*numAppointments].name, appointments[*numAppointments].date, appointments[*numAppointments].time);

    (*numAppointments)++;
}

void printAppointments(struct Appointment appointments[], int numAppointments) {
    printf("\nViewing Appointments\n");

    if (numAppointments == 0) {
        printf("You have no appointments scheduled.\n");
        return;
    }

    for (int i = 0; i < numAppointments; i++) {
        printf("Appointment %d\n", i+1);
        printf("Name: %s\n", appointments[i].name);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
    }
}