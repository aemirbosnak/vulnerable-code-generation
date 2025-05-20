//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: single-threaded
/*
 * appointment_scheduler.c
 *
 * A simple appointment scheduler program in a single-threaded style.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structures

typedef struct {
    char name[50];
    char phone_number[20];
    char email[50];
    int appointment_date;
    int appointment_time;
} Appointment;

typedef struct {
    int size;
    Appointment *appointments;
} Scheduler;

// Functions

Scheduler* create_scheduler(int size) {
    Scheduler *scheduler = malloc(sizeof(Scheduler));
    scheduler->size = size;
    scheduler->appointments = malloc(size * sizeof(Appointment));
    return scheduler;
}

void add_appointment(Scheduler *scheduler, Appointment appointment) {
    scheduler->appointments[scheduler->size++] = appointment;
}

void print_appointment(Appointment appointment) {
    printf("Name: %s\n", appointment.name);
    printf("Phone Number: %s\n", appointment.phone_number);
    printf("Email: %s\n", appointment.email);
    printf("Appointment Date: %d\n", appointment.appointment_date);
    printf("Appointment Time: %d\n", appointment.appointment_time);
}

void print_scheduler(Scheduler *scheduler) {
    for (int i = 0; i < scheduler->size; i++) {
        print_appointment(scheduler->appointments[i]);
    }
}

int main() {
    Scheduler *scheduler = create_scheduler(10);
    Appointment appointment1 = {"John Doe", "123-456-7890", "johndoe@example.com", 2023, 10};
    Appointment appointment2 = {"Jane Doe", "987-654-3210", "janedoe@example.com", 2023, 12};
    add_appointment(scheduler, appointment1);
    add_appointment(scheduler, appointment2);
    print_scheduler(scheduler);
    return 0;
}