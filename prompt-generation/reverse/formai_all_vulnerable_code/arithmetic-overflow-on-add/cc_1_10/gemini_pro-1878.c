//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Appointment {
    time_t start;
    time_t end;
    char *description;
} Appointment;

typedef struct AppointmentList {
    Appointment *appointments;
    int numAppointments;
} AppointmentList;

AppointmentList *createAppointmentList() {
    AppointmentList *list = malloc(sizeof(AppointmentList));
    list->appointments = NULL;
    list->numAppointments = 0;
    return list;
}

void addAppointment(AppointmentList *list, Appointment *appointment) {
    list->appointments = realloc(list->appointments, (list->numAppointments + 1) * sizeof(Appointment));
    list->appointments[list->numAppointments++] = *appointment;
}

void printAppointmentList(AppointmentList *list) {
    for (int i = 0; i < list->numAppointments; i++) {
        Appointment *appointment = &list->appointments[i];
        printf("%s: %s - %s\n", appointment->description, ctime(&appointment->start), ctime(&appointment->end));
    }
}

void freeAppointmentList(AppointmentList *list) {
    for (int i = 0; i < list->numAppointments; i++) {
        free(list->appointments[i].description);
    }
    free(list->appointments);
    free(list);
}

int main() {
    AppointmentList *list = createAppointmentList();

    Appointment appointment1 = {
        .start = time(NULL),
        .end = time(NULL) + 3600,
        .description = "Meeting with John"
    };

    Appointment appointment2 = {
        .start = time(NULL) + 7200,
        .end = time(NULL) + 10800,
        .description = "Meeting with Mary"
    };

    addAppointment(list, &appointment1);
    addAppointment(list, &appointment2);

    printAppointmentList(list);

    freeAppointmentList(list);

    return 0;
}