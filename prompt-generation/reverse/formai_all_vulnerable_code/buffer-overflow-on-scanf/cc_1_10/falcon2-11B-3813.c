//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int startTime;
    int endTime;
    char name[50];
} Appointment;

void addAppointment(Appointment *appointments, int size, Appointment newAppointment) {
    if (size < 100) {
        appointments[size] = newAppointment;
        size++;
    } else {
        printf("Appointment schedule is full. Please try again later.\n");
    }
}

void printAppointments(Appointment *appointments, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s %d:%d\n", appointments[i].name, appointments[i].startTime, appointments[i].endTime);
    }
}

int main() {
    Appointment appointments[100];
    int size = 0;

    srand(time(NULL));
    char name[50];

    while (1) {
        printf("Enter name for appointment (or type 'exit' to quit): ");
        scanf("%s", name);

        if (strcmp(name, "exit") == 0) {
            break;
        }

        Appointment newAppointment;
        newAppointment.startTime = rand() % 1000;
        newAppointment.endTime = rand() % 1000;

        addAppointment(appointments, size, newAppointment);
        printf("Appointment added for %s\n", name);

        printAppointments(appointments, size);
    }

    return 0;
}