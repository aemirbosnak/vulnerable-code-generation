//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 10

struct Appointment {
    int day; // day of the month
    int time; // 24-hour format
    int duration; // in minutes
    char patient[50];
};

struct Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0; // current number of appointments scheduled

bool is_available(int day, int time, int duration) {
    // check if there are any conflicting appointments
    for (int i = 0; i < num_appointments; i++) {
        int start_time = appointments[i].time;
        int end_time = start_time + appointments[i].duration;
        if (appointments[i].day == day &&
            ((time >= start_time && time < end_time) ||
             (time + duration > start_time && time + duration <= end_time))) {
            return false;
        }
    }
    return true;
}

void schedule_appointment() {
    // input the appointment details
    struct Appointment appt;
    printf("Enter day of month (1-31): ");
    scanf("%d", &appt.day);
    printf("Enter time in 24-hour format (0-23): ");
    scanf("%d", &appt.time);
    printf("Enter duration in minutes: ");
    scanf("%d", &appt.duration);
    printf("Enter patient name: ");
    scanf("%s", appt.patient);
    
    // check if the slot is available
    if (is_available(appt.day, appt.time, appt.duration)) {
        appointments[num_appointments] = appt;
        num_appointments++;
        printf("Appointment scheduled successfully!\n");
    } else {
        printf("Sorry, that slot is not available.\n");
    }
}

void view_appointments() {
    // print the list of appointments
    printf("Day\tTime\tDuration\tPatient\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%d\t%d\t%d\t\t%s\n",
               appointments[i].day, appointments[i].time,
               appointments[i].duration, appointments[i].patient);
    }
}

int main() {
    printf("Welcome to the appointment scheduler!\n");
    while (true) {
        printf("Choose an option:\n");
        printf("1. Schedule an appointment\n");
        printf("2. View appointments\n");
        printf("3. Quit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                schedule_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}