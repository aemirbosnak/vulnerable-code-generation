//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    time_t appointment_time;
    int duration;
} appointment;

void add_appointment(appointment* a, char* name, char* phone, time_t appt_time, int dur) {
    strcpy(a->name, name);
    strcpy(a->phone, phone);
    a->appointment_time = appt_time;
    a->duration = dur;
}

void display_appointments(appointment* a, int num_appts) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appts; i++) {
        printf("Name: %s\nPhone: %s\nAppointment Time: %s\nDuration: %d minutes\n\n", a[i].name, a[i].phone, ctime(&a[i].appointment_time), a[i].duration);
    }
}

int main() {
    appointment a[MAX_APPOINTMENTS];
    int num_appts = 0;

    printf("Welcome to the Appointment Scheduler!\n");

    while (num_appts < MAX_APPOINTMENTS) {
        printf("Enter name (or 'done' to finish): ");
        scanf("%s", a[num_appts].name);
        if (strcmp(a[num_appts].name, "done") == 0) {
            break;
        }
        printf("Enter phone number: ");
        scanf("%s", a[num_appts].phone);
        printf("Enter appointment time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", a[num_appts].appointment_time);
        printf("Enter duration (in minutes): ");
        scanf("%d", &a[num_appts].duration);
        num_appts++;
    }

    printf("Appointments:\n");
    display_appointments(a, num_appts);

    return 0;
}