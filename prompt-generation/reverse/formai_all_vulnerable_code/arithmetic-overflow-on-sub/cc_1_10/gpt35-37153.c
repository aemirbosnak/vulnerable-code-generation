//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 50

struct appointment {
    int hour;
    int minute;
    char name[MAX_NAME_LENGTH];
};

struct appointment schedule[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment(int hour, int minute, char* name) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, all appointments are full.\n");
        return;
    }
    struct appointment new_appointment;
    new_appointment.hour = hour;
    new_appointment.minute = minute;
    strncpy(new_appointment.name, name, MAX_NAME_LENGTH);
    schedule[num_appointments++] = new_appointment;
    printf("Appointment added successfully.\n");
}

void print_schedule() {
    printf("Scheduled Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%02d:%02d - %s\n", schedule[i].hour, schedule[i].minute, schedule[i].name);
    }
}

bool is_available(int hour, int minute) {
    for (int i = 0; i < num_appointments; i++) {
        if (schedule[i].hour == hour && schedule[i].minute == minute) {
            return false;
        }
    }
    return true;
}

void remove_appointment(int index) {
    if (index < 0 || index >= num_appointments) {
        printf("Sorry, that is not a valid appointment number.\n");
        return;
    }
    for (int i = index; i < num_appointments-1; i++) {
        schedule[i] = schedule[i+1];
    }
    num_appointments--;
    printf("Appointment removed successfully.\n");
}

int main() {
    printf("Welcome to the Appointment Scheduler!\n");
    while (true) {
        printf("Enter '1' to add an appointment, '2' to view the schedule, '3' to remove an appointment, or '0' to quit.\n");
        int input;
        scanf("%d", &input);
        if (input == 0) {
            printf("Goodbye!\n");
            return 0;
        } else if (input == 1) {
            printf("Enter the time in HH:MM format (24-hour clock): ");
            int hour, minute;
            scanf("%d:%d", &hour, &minute);
            if (!is_available(hour, minute)) {
                printf("Sorry, that time is not available.\n");
                continue;
            }
            printf("Enter the name of the appointment: ");
            char name[MAX_NAME_LENGTH];
            scanf("%s", name);
            add_appointment(hour, minute, name);
        } else if (input == 2) {
            print_schedule();
        } else if (input == 3) {
            printf("Enter the number of the appointment to remove (1-%d): ", num_appointments);
            int index;
            scanf("%d", &index);
            remove_appointment(index-1);
        } else {
            printf("Invalid input, please try again.\n");
        }
    }
}