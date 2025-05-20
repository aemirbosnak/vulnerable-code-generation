//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: rigorous
// appointment_scheduler.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct appointment {
    char* name;
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int duration;
} appointment;

int main() {
    int num_appointments;
    printf("Enter the number of appointments: ");
    scanf("%d", &num_appointments);

    appointment appointments[num_appointments];
    for (int i = 0; i < num_appointments; i++) {
        appointments[i].name = malloc(sizeof(char) * 50);
        printf("Enter the name of the appointment: ");
        scanf("%s", appointments[i].name);

        printf("Enter the day of the appointment: ");
        scanf("%d", &appointments[i].day);

        printf("Enter the month of the appointment: ");
        scanf("%d", &appointments[i].month);

        printf("Enter the year of the appointment: ");
        scanf("%d", &appointments[i].year);

        printf("Enter the hour of the appointment: ");
        scanf("%d", &appointments[i].hour);

        printf("Enter the minute of the appointment: ");
        scanf("%d", &appointments[i].minute);

        printf("Enter the duration of the appointment: ");
        scanf("%d", &appointments[i].duration);
    }

    int num_available_slots;
    printf("Enter the number of available slots: ");
    scanf("%d", &num_available_slots);

    int available_slots[num_available_slots];
    for (int i = 0; i < num_available_slots; i++) {
        available_slots[i] = i + 1;
    }

    int num_appointments_scheduled = 0;
    while (num_appointments_scheduled < num_appointments) {
        int appointment_index = rand() % num_appointments;
        int available_slot_index = rand() % num_available_slots;

        if (appointments[appointment_index].duration <= available_slots[available_slot_index]) {
            appointments[appointment_index].duration = available_slots[available_slot_index];
            available_slots[available_slot_index] -= appointments[appointment_index].duration;
            num_appointments_scheduled++;
        }
    }

    for (int i = 0; i < num_appointments; i++) {
        printf("%s: %d/%d/%d %d:%d\n", appointments[i].name, appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].hour, appointments[i].minute);
    }

    return 0;
}