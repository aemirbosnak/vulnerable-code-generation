//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *name;
    time_t start_time;
    time_t end_time;
} Appointment;

typedef struct {
    Appointment *appointments;
    int num_appointments;
} AppointmentList;

AppointmentList *create_appointment_list() {
    AppointmentList *list = malloc(sizeof(AppointmentList));
    list->appointments = NULL;
    list->num_appointments = 0;
    return list;
}

void add_appointment(AppointmentList *list, Appointment *appointment) {
    list->appointments = realloc(list->appointments, (list->num_appointments + 1) * sizeof(Appointment));
    list->appointments[list->num_appointments] = *appointment;
    list->num_appointments++;
}

void print_appointment(Appointment *appointment) {
    printf("%s (%s - %s)\n", appointment->name, ctime(&appointment->start_time), ctime(&appointment->end_time));
}

void print_appointment_list(AppointmentList *list) {
    for (int i = 0; i < list->num_appointments; i++) {
        print_appointment(&list->appointments[i]);
    }
}

int main() {
    AppointmentList *list = create_appointment_list();

    Appointment appointment1 = {
        .name = "John Doe",
        .start_time = time(NULL),
        .end_time = time(NULL) + 3600
    };

    Appointment appointment2 = {
        .name = "Jane Doe",
        .start_time = time(NULL) + 3600,
        .end_time = time(NULL) + 7200
    };

    add_appointment(list, &appointment1);
    add_appointment(list, &appointment2);

    print_appointment_list(list);

    return 0;
}