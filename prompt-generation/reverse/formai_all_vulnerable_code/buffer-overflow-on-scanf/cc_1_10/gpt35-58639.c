//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

struct Date {
    int day;
    int month;
    int year;
};

struct Time {
    int hour;
    int minute;
};

struct Appointment {
    char name[20];
    struct Date date;
    struct Time time;
};

struct Appointment appointments[MAX_APPOINTMENTS];  // array of appointments
int num_appointments = 0;

void display_menu() {
    printf("Appointment Scheduler\n");
    printf("---------------------\n");
    printf("1. View Appointments\n");
    printf("2. Add Appointment\n");
    printf("3. Cancel Appointment\n");
    printf("4. Quit\n");
    printf("Please enter your choice: ");
}

void display_appointments() {
    if (num_appointments == 0) {
        printf("There are no appointments scheduled.\n");
        return;
    }
    printf("%-20s %-10s %-10s %-10s \n", "Name", "Date", "Time", "Index");
    printf("-------------------------------------------------\n");
    for (int i=0; i<num_appointments; i++) {
        printf("%-20s %02d/%02d/%d  %02d:%02d     %2d\n",
            appointments[i].name,
            appointments[i].date.day, appointments[i].date.month, appointments[i].date.year,
            appointments[i].time.hour, appointments[i].time.minute, i);
    }
}

void add_appointment() {
    if (num_appointments == MAX_APPOINTMENTS) {
        printf("Maximum appointments reached. Cannot schedule a new appointment.\n");
        return;
    }
    struct Appointment new_appointment;
    printf("Please enter the name of the appointment (less than 20 characters): ");
    scanf("%19s", new_appointment.name);
    printf("Please enter the date of the appointment (mm/dd/yyyy): ");
    scanf("%02d/%02d/%04d", &new_appointment.date.month,
        &new_appointment.date.day, &new_appointment.date.year);
    printf("Please enter the time of the appointment (hh:mm in 24 hour format): ");
    scanf("%02d:%02d", &new_appointment.time.hour, &new_appointment.time.minute);
    appointments[num_appointments] = new_appointment;
    num_appointments++;
    printf("Appointment added successfully.\n");
}

void cancel_appointment() {
    int index;
    printf("Please enter the index of the appointment you would like to cancel: ");
    scanf("%d", &index);
    if (index < 0 || index >= num_appointments) {
        printf("Invalid index. Please enter a valid index between 0 and %d.\n", num_appointments - 1);
        return;
    }
    for (int i=index; i<num_appointments-1; i++) {
        appointments[i] = appointments[i+1];
    }
    num_appointments--;
    printf("Appointment cancelled successfully.\n");
}

int main() {
    int choice;
    bool quit = false;
    printf("Welcome to the Appointment Scheduler!\n");
    while (!quit) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display_appointments();
                break;
            case 2:
                add_appointment();
                break;
            case 3:
                cancel_appointment();
                break;
            case 4:
                quit = true;
                printf("Goodbye! Thank you for using the Appointment Scheduler.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                break;
        }
    }
    return 0;
}