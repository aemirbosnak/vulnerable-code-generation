//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 15

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    time_t appointment_time;
} appointment;

int num_appointments = 0;
appointment appointments[MAX_APPOINTMENTS];

void add_appointment(char* name, char* phone, time_t appointment_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, no more appointments available.\n");
        return;
    }

    strncpy(appointments[num_appointments].name, name, MAX_NAME_LEN);
    strncpy(appointments[num_appointments].phone, phone, MAX_PHONE_LEN);
    appointments[num_appointments].appointment_time = appointment_time;

    num_appointments++;
    printf("Appointment added.\n");
}

void view_appointments() {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s (%s) - %s\n", appointments[i].name, appointments[i].phone, ctime(&appointments[i].appointment_time));
    }
}

void remove_appointment(char* name, char* phone) {
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0 && strcmp(appointments[i].phone, phone) == 0) {
            num_appointments--;
            printf("Appointment removed.\n");
            return;
        }
    }

    printf("Appointment not found.\n");
}

int main() {
    srand(time(NULL));

    add_appointment("John Doe", "123-456-7890", time(NULL) + rand() % 86400);
    add_appointment("Jane Doe", "987-654-3210", time(NULL) + rand() % 86400);

    view_appointments();

    remove_appointment("John Doe", "123-456-7890");

    view_appointments();

    return 0;
}