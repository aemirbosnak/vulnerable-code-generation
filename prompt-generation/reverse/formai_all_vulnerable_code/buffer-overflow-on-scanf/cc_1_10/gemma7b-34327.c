//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store appointment details
typedef struct Appointment {
    char name[50];
    char email[50];
    char phone[20];
    int day;
    int month;
    int year;
} Appointment;

// Function to compare appointments
int compareAppointments(Appointment a, Appointment b) {
    return a.day - b.day;
}

// Function to schedule an appointment
void scheduleAppointment(Appointment *appointment) {
    printf("Enter your name: ");
    scanf("%s", appointment->name);

    printf("Enter your email address: ");
    scanf("%s", appointment->email);

    printf("Enter your phone number: ");
    scanf("%s", appointment->phone);

    printf("Enter the day of your appointment: ");
    scanf("%d", &appointment->day);

    printf("Enter the month of your appointment: ");
    scanf("%d", &appointment->month);

    printf("Enter the year of your appointment: ");
    scanf("%d", &appointment->year);
}

// Function to display appointments
void displayAppointments(Appointment *appointments) {
    int i = 0;
    for (i = 0; appointments[i].name[0] != '\0'; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Email: %s\n", appointments[i].email);
        printf("Phone: %s\n", appointments[i].phone);
        printf("Date: %d/%d/%d\n", appointments[i].day, appointments[i].month, appointments[i].year);
        printf("\n");
    }
}

int main() {
    // Create an array of appointments
    Appointment appointments[10];

    // Schedule an appointment
    scheduleAppointment(&appointments[0]);

    // Schedule another appointment
    scheduleAppointment(&appointments[1]);

    // Display all appointments
    displayAppointments(appointments);

    // Sort the appointments by date
    qsort(appointments, 2, sizeof(Appointment), compareAppointments);

    // Display the sorted appointments
    displayAppointments(appointments);

    return 0;
}