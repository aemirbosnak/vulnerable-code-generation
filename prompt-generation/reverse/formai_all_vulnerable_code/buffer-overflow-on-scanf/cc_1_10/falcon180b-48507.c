//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    time_t appointment_time;
    int appointment_duration;
} appointment;

int main() {
    int num_appointments, i;
    appointment appointments[MAX_APPOINTMENTS];
    char input[100];

    printf("Welcome to the Appointment Scheduler!\n");
    printf("How many appointments do you have today? ");
    scanf("%d", &num_appointments);

    for (i = 0; i < num_appointments; i++) {
        printf("\nEnter appointment details for appointment %d:\n", i+1);
        printf("Name: ");
        scanf("%s", appointments[i].name);
        printf("Phone: ");
        scanf("%s", appointments[i].phone);
        printf("Email: ");
        scanf("%s", appointments[i].email);
        printf("Appointment time (in seconds since epoch): ");
        scanf("%ld", &appointments[i].appointment_time);
        printf("Appointment duration (in seconds): ");
        scanf("%d", &appointments[i].appointment_duration);
    }

    printf("\nToday's schedule:\n");
    for (i = 0; i < num_appointments; i++) {
        time_t now = time(NULL);
        time_t appointment_time = appointments[i].appointment_time;
        if (appointment_time > now) {
            appointment_time += appointments[i].appointment_duration;
        }
        if (appointment_time < now) {
            printf("%s - Missed appointment with %s\n", ctime(&appointment_time), appointments[i].name);
        } else {
            printf("%s - Upcoming appointment with %s\n", ctime(&appointment_time), appointments[i].name);
        }
    }

    return 0;
}