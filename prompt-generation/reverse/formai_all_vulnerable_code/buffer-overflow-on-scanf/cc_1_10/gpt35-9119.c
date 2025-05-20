//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Maximum number of appointments
#define MAX_APPOINTMENTS 10

// Structure to hold information about an appointment
struct Appointment {
    int day;
    int month;
    int year;
    char time[10];
    char description[50];
};

// Function to add a new appointment to the array
void addAppointment(struct Appointment appointments[], int count) {
    printf("Enter date (dd mm yyyy): ");
    scanf("%d %d %d", &appointments[count].day, &appointments[count].month, &appointments[count].year);
    printf("Enter time (hh:mm): ");
    scanf("%s", appointments[count].time);
    printf("Enter description: ");
    getchar();
    fgets(appointments[count].description, 50, stdin);
    printf("Appointment added successfully!\n");
}

// Function to print all appointments in the array
void printAppointments(struct Appointment appointments[], int count) {
    if (count == 0) {
        printf("No appointments added yet.\n");
    } else {
        printf("Date\t\tTime\tDescription\n");
        for (int i = 0; i < count; i++) {
            printf("%02d/%02d/%d\t%s\t%s", appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].time, appointments[i].description);
        }
    }
}

// Function to search for appointments on a particular day
void searchAppointments(struct Appointment appointments[], int count) {
    int day, month, year;
    bool found = false;
    printf("Enter date to search (dd mm yyyy): ");
    scanf("%d %d %d", &day, &month, &year);
    for (int i = 0; i < count; i++) {
        if (appointments[i].day == day && appointments[i].month == month && appointments[i].year == year) {
            printf("%02d/%02d/%d\t%s\t%s", appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].time, appointments[i].description);
            found = true;
        }
    }
    if (!found) {
        printf("No appointments found on that day.\n");
    }
}

int main() {
    struct Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;
    int choice;
    do {
        printf("Appointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Search appointments\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            if (count < MAX_APPOINTMENTS) {
                addAppointment(appointments, count);
                count++;
            } else {
                printf("Maximum number of appointments reached.\n");
            }
            break;
        case 2:
            printAppointments(appointments, count);
            break;
        case 3:
            searchAppointments(appointments, count);
            break;
        case 4:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}