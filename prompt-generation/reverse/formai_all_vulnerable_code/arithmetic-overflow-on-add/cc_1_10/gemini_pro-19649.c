//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Appointment {
    char *description;
    time_t start;
    time_t end;
} Appointment;

Appointment *create_appointment(char *description, time_t start, time_t end) {
    Appointment *appointment = malloc(sizeof(Appointment));
    appointment->description = strdup(description);
    appointment->start = start;
    appointment->end = end;
    return appointment;
}

void destroy_appointment(Appointment *appointment) {
    free(appointment->description);
    free(appointment);
}

typedef struct AppointmentList {
    Appointment **appointments;
    size_t size;
    size_t capacity;
} AppointmentList;

AppointmentList *create_appointment_list() {
    AppointmentList *list = malloc(sizeof(AppointmentList));
    list->appointments = malloc(sizeof(Appointment *) * 10);
    list->size = 0;
    list->capacity = 10;
    return list;
}

void destroy_appointment_list(AppointmentList *list) {
    for (size_t i = 0; i < list->size; i++) {
        destroy_appointment(list->appointments[i]);
    }
    free(list->appointments);
    free(list);
}

void add_appointment_to_list(AppointmentList *list, Appointment *appointment) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->appointments = realloc(list->appointments, sizeof(Appointment *) * list->capacity);
    }
    list->appointments[list->size++] = appointment;
}

void print_appointment_list(AppointmentList *list) {
    for (size_t i = 0; i < list->size; i++) {
        printf("%s: %s - %s\n", list->appointments[i]->description, ctime(&list->appointments[i]->start), ctime(&list->appointments[i]->end));
    }
}

int main() {
    AppointmentList *list = create_appointment_list();
    add_appointment_to_list(list, create_appointment("Lunch with Bob", time(NULL) + 60 * 60, time(NULL) + 90 * 60));
    add_appointment_to_list(list, create_appointment("Meeting with Alice", time(NULL) + 120 * 60, time(NULL) + 150 * 60));
    add_appointment_to_list(list, create_appointment("Dinner with Carol", time(NULL) + 180 * 60, time(NULL) + 210 * 60));

    print_appointment_list(list);
    destroy_appointment_list(list);

    return 0;
}