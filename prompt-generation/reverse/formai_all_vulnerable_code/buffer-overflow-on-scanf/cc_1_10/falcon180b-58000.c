//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    char date[20];
    char time[20];
} Appointment;

void addAppointment(Appointment *appointments, int numAppointments, char *name, char *date, char *time) {
    if (numAppointments >= MAX_APPOINTMENTS) {
        printf("Sorry, the appointment schedule is full.\n");
        return;
    }
    strcpy(appointments[numAppointments].name, name);
    strcpy(appointments[numAppointments].date, date);
    strcpy(appointments[numAppointments].time, time);
    numAppointments++;
}

void displayAppointments(Appointment *appointments, int numAppointments) {
    printf("Appointment Schedule:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s on %s at %s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

int main() {
    int numAppointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];
    char name[50];
    char date[20];
    char time[20];
    while (1) {
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", date);
        printf("Enter time (HH:MM): ");
        scanf("%s", time);
        addAppointment(appointments, numAppointments, name, date, time);
        printf("\nDo you want to add another appointment? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'n' || choice == 'N') {
            break;
        }
    }
    displayAppointments(appointments, numAppointments);
    return 0;
}