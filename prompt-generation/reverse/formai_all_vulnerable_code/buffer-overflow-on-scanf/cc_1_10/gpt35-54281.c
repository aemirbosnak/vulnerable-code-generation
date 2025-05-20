//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_APPOINTMENTS 1000
#define MAX_NAME_LENGTH 50

struct Appointment {
    char name[MAX_NAME_LENGTH];
    int month;
    int day;
    int hour;
};

struct Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void print_appointments() {
    printf("Upcoming Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%d/%d at %d:00 - %s\n", appointments[i].month, appointments[i].day, appointments[i].hour, appointments[i].name);
    }
}

bool is_available(int month, int day, int hour) {
    for (int i = 0; i < num_appointments; i++) {
        if (appointments[i].month == month && appointments[i].day == day && appointments[i].hour == hour) {
            return false;
        }
    }
    return true;
}

void add_appointment() {
    char name[MAX_NAME_LENGTH];
    int month, day, hour;
    printf("Please enter appointment name: ");
    scanf("%s", name);
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter day (1-31): ");
    scanf("%d", &day);
    printf("Enter hour (0-23): ");
    scanf("%d", &hour);
    if (!is_available(month, day, hour)) {
        printf("Sorry, that time slot is already taken.\n");
        return;
    }
    strcpy(appointments[num_appointments].name, name);
    appointments[num_appointments].month = month;
    appointments[num_appointments].day = day;
    appointments[num_appointments].hour = hour;
    num_appointments++;
    printf("Appointment scheduled.\n");
}

void remove_appointment() {
    int month, day, hour;
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter day (1-31): ");
    scanf("%d", &day);
    printf("Enter hour (0-23): ");
    scanf("%d", &hour);
    for (int i = 0; i < num_appointments; i++) {
        if (appointments[i].month == month && appointments[i].day == day && appointments[i].hour == hour) {
            num_appointments--;
            appointments[i] = appointments[num_appointments];
            printf("Appointment removed.\n");
            return;
        }
    }
    printf("Sorry, couldn't find an appointment at that time.\n");
}

int main() {
    int choice = 0;
    while (choice != 4) {
        printf("Welcome to the Appointment Scheduler!\n");
        printf("1. View Appointments\n");
        printf("2. Schedule Appointment\n");
        printf("3. Remove Appointment\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                print_appointments();
                break;
            case 2:
                add_appointment();
                break;
            case 3:
                remove_appointment();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}