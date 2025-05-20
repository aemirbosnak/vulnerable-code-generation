//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    time_t appointment_time;
} Appointment;

Appointment* appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment(char* name, char* phone_number, time_t appointment_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, the appointment book is full.\n");
        return;
    }

    int index = num_appointments;
    appointments[index] = (Appointment*) malloc(sizeof(Appointment));
    strcpy(appointments[index]->name, name);
    strcpy(appointments[index]->phone_number, phone_number);
    appointments[index]->appointment_time = appointment_time;

    num_appointments++;
}

void view_appointments() {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    for (int i = 0; i < num_appointments; i++) {
        struct tm* appointment_time_struct = localtime(&appointments[i]->appointment_time);
        char appointment_time_string[20];
        strftime(appointment_time_string, 20, "%Y-%m-%d %H:%M:%S", appointment_time_struct);

        printf("%s (%s)\n", appointments[i]->name, appointment_time_string);
    }
}

void remove_appointment(char* name) {
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i]->name, name) == 0) {
            free(appointments[i]);
            appointments[i] = NULL;
            num_appointments--;
            printf("Appointment for %s removed.\n", name);
            return;
        }
    }

    printf("No appointment found for %s.\n", name);
}

int main() {
    add_appointment("John Doe", "555-1234", time(NULL) + (60*60*24*7));
    add_appointment("Jane Smith", "555-5678", time(NULL) + (60*60*24*3));

    view_appointments();

    remove_appointment("John Doe");

    view_appointments();

    return 0;
}