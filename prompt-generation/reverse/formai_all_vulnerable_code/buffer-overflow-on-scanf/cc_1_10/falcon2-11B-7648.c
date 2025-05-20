//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int id;
    char date[20];
} Appointment;

void printAppointment(Appointment appt) {
    printf("Name: %s\n", appt.name);
    printf("ID: %d\n", appt.id);
    printf("Date: %s\n", appt.date);
}

void addAppointment(Appointment *appts, int numAppts, Appointment newAppt) {
    if (numAppts == 0) {
        appts[0] = newAppt;
    } else if (numAppts == 1) {
        appts[0] = newAppt;
        appts[1] = newAppt;
    } else {
        appts[numAppts - 1] = newAppt;
    }
}

int main() {
    Appointment appts[3];
    int numAppts = 0;
    srand(time(NULL));

    while (1) {
        printf("Enter a name (or 0 to exit): ");
        char name[50];
        scanf("%s", name);

        if (strcmp(name, "0") == 0) {
            break;
        }

        printf("Enter an ID: ");
        int id;
        scanf("%d", &id);

        printf("Enter a date (MM/DD/YYYY): ");
        char date[20];
        scanf("%s", date);

        Appointment newAppt = {
           .name = name,
           .id = id,
           .date = date
        };

        addAppointment(appts, numAppts, newAppt);

        numAppts++;
    }

    for (int i = 0; i < numAppts; i++) {
        printAppointment(appts[i]);
        printf("\n");
    }

    return 0;
}