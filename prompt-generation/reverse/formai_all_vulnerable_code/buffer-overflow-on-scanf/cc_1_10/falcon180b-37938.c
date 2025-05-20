//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

struct Appointment {
    char name[50];
    char date[11];
    char time[9];
    char reason[100];
};

void addAppointment(struct Appointment* appointments, int numAppointments) {
    printf("Enter name: ");
    scanf("%s", appointments[numAppointments].name);

    printf("Enter date (mm/dd/yyyy): ");
    scanf("%s", appointments[numAppointments].date);

    printf("Enter time (hh:mm AM/PM): ");
    scanf("%s", appointments[numAppointments].time);

    printf("Enter reason: ");
    scanf("%s", appointments[numAppointments].reason);

    numAppointments++;
}

void viewAppointments(struct Appointment* appointments, int numAppointments) {
    printf("Name\tDate\tTime\tReason\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s\t%s\t%s\t%s\n", appointments[i].name, appointments[i].date, appointments[i].time, appointments[i].reason);
    }
}

void deleteAppointment(struct Appointment* appointments, int numAppointments) {
    printf("Enter name to delete: ");
    char name[50];
    scanf("%s", name);

    int index = -1;
    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index!= -1) {
        for (int i = index; i < numAppointments - 1; i++) {
            appointments[i] = appointments[i + 1];
        }
        numAppointments--;
    } else {
        printf("Appointment not found.\n");
    }
}

int main() {
    struct Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;

    srand(time(NULL));

    addAppointment(appointments, numAppointments);
    addAppointment(appointments, numAppointments);
    addAppointment(appointments, numAppointments);

    viewAppointments(appointments, numAppointments);

    deleteAppointment(appointments, numAppointments);

    viewAppointments(appointments, numAppointments);

    return 0;
}