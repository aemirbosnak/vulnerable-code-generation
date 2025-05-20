//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

struct Appointment {
    int day;
    int month;
    int year;
    char description[50];
};

int menu() {
    int choice;
    printf("\nAppointment Scheduler\n");
    printf("---------------------\n");
    printf("1. Add Appointment\n");
    printf("2. Display All Appointments\n");
    printf("3. Search Appointments\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    return choice;
}

void addAppointment(struct Appointment *appointments, int *count) {
    if (*count < MAX_APPOINTMENTS) {
        printf("\nEnter Date (dd mm yyyy): ");
        scanf("%d %d %d", &appointments[*count].day, &appointments[*count].month, &appointments[*count].year);
        printf("Enter Description: ");
        getchar(); // flush the newline character from the input buffer
        fgets(appointments[*count].description, 50, stdin);
        appointments[*count].description[strcspn(appointments[*count].description, "\n")] = '\0'; // remove the newline character
        (*count)++;
        printf("Appointment added successfully!\n");
    } else {
        printf("\nMax appointments reached!\n");
    }
}

void displayAppointments(struct Appointment *appointments, int count) {
    if (count > 0) {
        printf("\nAll Appointments:\n");
        for (int i = 0; i < count; i++) {
            printf("%d. %02d/%02d/%d - %s\n", i+1, appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].description);
        }
    } else {
        printf("\nNo appointments found!\n");
    }
}

void searchAppointments(struct Appointment *appointments, int count) {
    int day, month, year;
    printf("\nEnter Date to search (dd mm yyyy): ");
    scanf("%d %d %d", &day, &month, &year);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (appointments[i].day == day && appointments[i].month == month && appointments[i].year == year) {
            printf("%d. %02d/%02d/%d - %s\n", i+1, appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].description);
            found = 1;
        }
    }
    if (!found) {
        printf("\nNo appointments found on this date!\n");
    }
}

int main() {
    struct Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;
    int choice;
    do {
        choice = menu();
        switch (choice) {
            case 1:
                addAppointment(appointments, &count);
                break;
            case 2:
                displayAppointments(appointments, count);
                break;
            case 3:
                searchAppointments(appointments, count);
                break;
            case 4:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}