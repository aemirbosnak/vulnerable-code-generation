//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 10

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[50];
    Date date;
    char time[10];
} Appointment;

void clearScreen() {
    system("clear"); // For Linux/Unix
    // system("cls"); // For Windows
}

void displayMenu() {
    clearScreen();
    printf("APPOINTMENT SCHEDULER\n\n");
    printf("1. Add Appointment\n");
    printf("2. Show Appointments\n");
    printf("3. Exit\n");
}

int getSelection() {
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void addAppointment(Appointment appointments[], int *count) {
    if (*count >= MAX_APPOINTMENTS) {
        printf("\nUnable to add appointment. Maximum limit reached.\n");
        printf("Press Enter to continue...");
        getchar(); getchar();
        return;
    }

    clearScreen();
    printf("ADD APPOINTMENT\n\n");

    Appointment newAppointment;

    printf("Enter name: ");
    scanf("%s", newAppointment.name);

    printf("Enter date (dd mm yyyy): ");
    scanf("%d %d %d", &newAppointment.date.day, &newAppointment.date.month, &newAppointment.date.year);

    printf("Enter time (hh:mm): ");
    scanf("%s", newAppointment.time);

    appointments[*count] = newAppointment;
    (*count)++;

    printf("\nAppointment added successfully.\n");
    printf("Press Enter to continue...");
    getchar(); getchar();
}

void showAppointments(Appointment appointments[], int count) {
    if (count == 0) {
        printf("\nNo appointments found.\n");
        printf("Press Enter to continue...");
        getchar(); getchar();
        return;
    }

    clearScreen();

    printf("APPOINTMENTS\n");
    printf("---------------------------------------------------------\n");
    printf("Name                  | Date          | Time          \n");
    printf("---------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-22s | %02d/%02d/%d   | %-10s\n",
            appointments[i].name,
            appointments[i].date.day,
            appointments[i].date.month,
            appointments[i].date.year,
            appointments[i].time);
    }

    printf("---------------------------------------------------------\n");
    printf("Total Appointments: %d\n", count);
    printf("Press Enter to continue...");
    getchar(); getchar();
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;

    while (1) {
        displayMenu();

        int choice = getSelection();

        switch (choice) {
            case 1: addAppointment(appointments, &count); break;
            case 2: showAppointments(appointments, count); break;
            case 3: clearScreen(); printf("Goodbye!"); return 0;
            default: printf("\nInvalid choice. Try again.\n"); getchar(); getchar();
        }
    }

    return 0;
}