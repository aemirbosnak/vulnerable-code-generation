//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t appointmentTime;
    int duration;
} appointment;

void printAppointment(appointment app) {
    printf("Name: %s\n", app.name);
    printf("Appointment Time: %s\n", ctime(&app.appointmentTime));
    printf("Duration: %d minutes\n", app.duration);
}

int compareAppointments(const void *a, const void *b) {
    appointment appA = *(appointment *)a;
    appointment appB = *(appointment *)b;

    time_t diff = difftime(appA.appointmentTime, appB.appointmentTime);

    if (diff == 0) {
        return 0;
    } else if (diff < 0) {
        return -1;
    } else {
        return 1;
    }
}

int main() {
    int numAppointments;
    appointment appointments[MAX_APPOINTMENTS];

    printf("Enter the number of appointments: ");
    scanf("%d", &numAppointments);

    for (int i = 0; i < numAppointments; i++) {
        printf("Enter the name for appointment %d: ", i + 1);
        scanf("%s", appointments[i].name);

        printf("Enter the appointment time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", appointments[i].name);

        appointments[i].appointmentTime = strptime(appointments[i].name, "%Y-%m-%d %H:%M:%S", NULL);

        printf("Enter the duration of the appointment (in minutes): ");
        scanf("%d", &appointments[i].duration);
    }

    qsort(appointments, numAppointments, sizeof(appointment), compareAppointments);

    for (int i = 0; i < numAppointments; i++) {
        printAppointment(appointments[i]);
    }

    return 0;
}