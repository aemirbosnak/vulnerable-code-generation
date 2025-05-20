//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    char date[10];
    char time[10];
} Appointment;

int numAppointments = 0;
Appointment appointments[MAX_APPOINTMENTS];

void addAppointment() {
    printf("Enter name: ");
    scanf("%s", appointments[numAppointments].name);
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", appointments[numAppointments].date);
    printf("Enter time (hh:mm): ");
    scanf("%s", appointments[numAppointments].time);
    numAppointments++;
}

void viewAppointments() {
    printf("Upcoming appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s - %s @ %s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

void removeAppointment() {
    printf("Enter name of appointment to remove: ");
    scanf("%s", appointments[numAppointments-1].name);
    numAppointments--;
}

int main() {
    int choice;
    do {
        printf("\nAppointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Remove appointment\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                removeAppointment();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);
    return 0;
}