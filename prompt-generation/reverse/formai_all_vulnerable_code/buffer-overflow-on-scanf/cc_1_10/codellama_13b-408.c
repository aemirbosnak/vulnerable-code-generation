//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: Ada Lovelace
/*
 * A unique C Appointment Scheduler example program in an Ada Lovelace style
 *
 * Written by [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

// Structure to represent an appointment
typedef struct {
    char name[30];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

// Function to read an appointment from the user
void readAppointment(Appointment *appointment) {
    printf("Enter the name of the appointment: ");
    scanf("%s", appointment->name);
    printf("Enter the day of the appointment (1-31): ");
    scanf("%d", &appointment->day);
    printf("Enter the month of the appointment (1-12): ");
    scanf("%d", &appointment->month);
    printf("Enter the year of the appointment: ");
    scanf("%d", &appointment->year);
    printf("Enter the hour of the appointment (0-23): ");
    scanf("%d", &appointment->hour);
    printf("Enter the minute of the appointment (0-59): ");
    scanf("%d", &appointment->minute);
}

// Function to print an appointment
void printAppointment(Appointment appointment) {
    printf("%s (%d/%d/%d at %d:%d)\n", appointment.name, appointment.day, appointment.month, appointment.year, appointment.hour, appointment.minute);
}

// Function to compare two appointments based on their date and time
int compareAppointments(const void *a, const void *b) {
    Appointment *appointment1 = (Appointment *)a;
    Appointment *appointment2 = (Appointment *)b;
    if (appointment1->day != appointment2->day) {
        return appointment1->day - appointment2->day;
    } else if (appointment1->month != appointment2->month) {
        return appointment1->month - appointment2->month;
    } else if (appointment1->year != appointment2->year) {
        return appointment1->year - appointment2->year;
    } else if (appointment1->hour != appointment2->hour) {
        return appointment1->hour - appointment2->hour;
    } else {
        return appointment1->minute - appointment2->minute;
    }
}

// Function to sort appointments based on their date and time
void sortAppointments(Appointment appointments[], int n) {
    qsort(appointments, n, sizeof(Appointment), compareAppointments);
}

// Function to find the next appointment
Appointment *findNextAppointment(Appointment appointments[], int n, time_t currentTime) {
    for (int i = 0; i < n; i++) {
        if (appointments[i].day == 0) {
            continue;
        }
        struct tm appointmentTime = {appointments[i].hour, appointments[i].minute, 0, appointments[i].day, appointments[i].month - 1, appointments[i].year - 1900};
        time_t appointmentTimestamp = mktime(&appointmentTime);
        if (appointmentTimestamp > currentTime) {
            return &appointments[i];
        }
    }
    return NULL;
}

int main() {
    // Initialize the appointments array
    Appointment appointments[MAX_APPOINTMENTS];
    int n = 0;

    // Read appointments from the user
    while (n < MAX_APPOINTMENTS) {
        readAppointment(&appointments[n]);
        n++;
    }

    // Sort the appointments based on their date and time
    sortAppointments(appointments, n);

    // Find the next appointment
    time_t currentTime = time(NULL);
    Appointment *nextAppointment = findNextAppointment(appointments, n, currentTime);

    // Print the next appointment
    if (nextAppointment != NULL) {
        printf("The next appointment is: ");
        printAppointment(*nextAppointment);
    } else {
        printf("There are no upcoming appointments.\n");
    }

    return 0;
}