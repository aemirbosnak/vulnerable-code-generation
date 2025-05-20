//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
    int appointment_time;
} appointment;

void surreal_appointment_scheduler() {
    int num_appointments, i, j;
    appointment *appointments;
    char input[100];

    printf("Welcome to the Surreal Appointment Scheduler!\n");
    printf("How many appointments would you like to schedule? ");
    scanf("%d", &num_appointments);

    appointments = (appointment *) malloc(num_appointments * sizeof(appointment));

    for (i = 0; i < num_appointments; i++) {
        printf("Enter the name for appointment %d: ", i+1);
        scanf("%s", appointments[i].name);
        printf("Enter the age for %s: ", appointments[i].name);
        scanf("%d", &appointments[i].age);
        printf("Enter the preferred appointment time (in minutes from now) for %s: ", appointments[i].name);
        scanf("%d", &appointments[i].appointment_time);
        appointments[i].appointment_time += time(NULL);
    }

    for (i = 0; i < num_appointments; i++) {
        for (j = i+1; j < num_appointments; j++) {
            if (appointments[i].appointment_time > appointments[j].appointment_time) {
                appointment temp = appointments[i];
                appointments[i] = appointments[j];
                appointments[j] = temp;
            }
        }
    }

    printf("Appointments scheduled:\n");
    for (i = 0; i < num_appointments; i++) {
        printf("%s (%d years old) at %d minutes from now\n", appointments[i].name, appointments[i].age, appointments[i].appointment_time - time(NULL));
    }

    free(appointments);
}

int main() {
    surreal_appointment_scheduler();
    return 0;
}