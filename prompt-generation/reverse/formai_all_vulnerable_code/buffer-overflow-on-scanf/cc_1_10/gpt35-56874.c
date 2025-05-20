//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

typedef struct appointment {
    char name[50];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

void printAppointment(Appointment a) {
    printf("%s's appointment: %d-%d-%d %d:%d\n", a.name, a.month, a.day, a.year, a.hour, a.minute);
}

void printAppointments(Appointment appointments[], int count) {
    printf("Your appointments:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: ", i+1);
        printAppointment(appointments[i]);
    }
}

void addAppointment(Appointment appointments[], int *count) {
    if (*count == MAX_APPOINTMENTS) {
        printf("You have reached the maximum number of appointments.\n");
        return;
    }

    char name[50];
    int day, month, year, hour, minute;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the date (DD MM YYYY): ");
    scanf("%d %d %d", &day, &month, &year);

    printf("Enter the time (HH MM, 24-hour format): ");
    scanf("%d %d", &hour, &minute);

    Appointment newAppointment = { 0 };
    strcpy(newAppointment.name, name);
    newAppointment.day = day;
    newAppointment.month = month;
    newAppointment.year = year;
    newAppointment.hour = hour;
    newAppointment.minute = minute;

    appointments[*count] = newAppointment;
    (*count)++;

    printf("Appointment added successfully.\n");
}

void removeAppointment(Appointment appointments[], int *count) {
    int index;

    printf("Enter the index of the appointment you want to remove: ");
    scanf("%d", &index);

    if (index < 1 || index > *count) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index-1; i < *count-1; i++) {
        appointments[i] = appointments[i+1];
    }

    (*count)--;

    printf("Appointment removed successfully.\n");

}

void displayMenu() {
    printf("\n");
    printf("1. View appointments\n");
    printf("2. Add appointment\n");
    printf("3. Remove appointment\n");
    printf("4. Exit program\n");
    printf("\n");
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;
    int choice;

    printf("========================\n");
    printf("Appointment Scheduler\n");
    printf("========================\n");

    while (1) {
        displayMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printAppointments(appointments, count);
                break;
            case 2:
                addAppointment(appointments, &count);
                break;
            case 3:
                removeAppointment(appointments, &count);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}