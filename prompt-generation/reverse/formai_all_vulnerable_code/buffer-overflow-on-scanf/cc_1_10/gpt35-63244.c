//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 50    // maximum number of appointments for the day

// define Appointment structure
typedef struct appointment {
    char name[50];
    int hour;
    int minute;
} Appointment;

// define Appointment Schedule structure
typedef struct appointment_schedule {
    Appointment appointments[MAX_SIZE];
    int num_appointments;
} AppointmentSchedule;

// function prototypes
void add_appointment(AppointmentSchedule *schedule, char *name, int hour, int minute);
void print_appointments(AppointmentSchedule *schedule);
bool is_available(AppointmentSchedule *schedule, int hour, int minute);
void handle_appointment_request(AppointmentSchedule *schedule);

// main function
int main() {
    AppointmentSchedule schedule;
    schedule.num_appointments = 0;
    char choice;    // user's choice to add or view appointments

    while (true) {
        printf("Enter 'a' to add an appointment or 'v' to view all appointments for the day: ");
        scanf(" %c", &choice);
        if (choice == 'a') {
            handle_appointment_request(&schedule);
        } else if (choice == 'v') {
            print_appointments(&schedule);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// function to add an appointment to the schedule
void add_appointment(AppointmentSchedule *schedule, char *name, int hour, int minute) {
    if (schedule->num_appointments >= MAX_SIZE) {
        printf("Maximum number of appointments reached for the day.\n");
        return;
    }
    if (!is_available(schedule, hour, minute)) {
        printf("Appointment time is not available.\n");
        return;
    }
    Appointment new_appointment;
    strcpy(new_appointment.name, name);
    new_appointment.hour = hour;
    new_appointment.minute = minute;
    schedule->appointments[schedule->num_appointments++] = new_appointment;
    printf("Appointment added successfully.\n");
}

// function to print all appointments for the day
void print_appointments(AppointmentSchedule *schedule) {
    printf("Appointments for the day:\n");
    for (int i = 0; i < schedule->num_appointments; i++) {
        printf("%d:%02d - %s\n", schedule->appointments[i].hour, schedule->appointments[i].minute, schedule->appointments[i].name);
    }
}

// function to check if an appointment time is available
bool is_available(AppointmentSchedule *schedule, int hour, int minute) {
    for (int i = 0; i < schedule->num_appointments; i++) {
        if (schedule->appointments[i].hour == hour && schedule->appointments[i].minute == minute) {
            return false;
        }
    }
    return true;
}

// function to handle user's appointment request
void handle_appointment_request(AppointmentSchedule *schedule) {
    char name[50];
    int hour, minute;
    printf("Enter name: ");
    scanf(" %[^\n]", name);
    printf("Enter hour (0-23): ");
    scanf("%d", &hour);
    printf("Enter minute (0-59): ");
    scanf("%d", &minute);
    add_appointment(schedule, name, hour, minute);
}