//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: irregular
/* Welcome to our unique appointment scheduler program! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Function Prototypes */
void mainMenu();
void viewAppointments();
void addAppointment();
void cancelAppointment();
bool isValidDate(int, int, int);
bool isLeapYear(int);

/* Global Variables */
typedef struct Appointment {
    char name[50];
    char date[20];
    char time[10];
} Appointment;

Appointment appointments[100];
int numOfAppointments = 0;

/* The main function */
int main() {
    printf("Welcome to the Appointment Scheduler!\n");
    mainMenu();

    return 0;
}

/* The main menu */
void mainMenu() {
    int choice;

    printf("\nMAIN MENU\n");
    printf("1. View Appointments\n");
    printf("2. Add Appointment\n");
    printf("3. Cancel Appointment\n");
    printf("4. Exit\n");
    printf("Enter a choice: ");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            viewAppointments();
            break;
        case 2:
            addAppointment();
            break;
        case 3:
            cancelAppointment();
            break;
        case 4:
            printf("Thank you for using the Appointment Scheduler!");
            exit(0);
        default:
            printf("Invalid choice! Please enter a valid choice.\n");
            mainMenu();
            break;
    }
}

/* View Appointments */
void viewAppointments() {
    if (numOfAppointments == 0) {
        printf("You have no appointments!\n");
        mainMenu();
    } else {
        printf("\nVIEW APPOINTMENTS\n");
        printf("NAME\t\tDATE\t\tTIME\n");

        for (int i=0; i<numOfAppointments; i++) {
            printf("%s\t\t%s\t%s\n", appointments[i].name, appointments[i].date, appointments[i].time);
        }

        mainMenu();
    }
}

/* Add Appointment */
void addAppointment() {
    printf("\nADD APPOINTMENT\n");

    printf("Enter your full name: ");
    scanf("%s", &appointments[numOfAppointments].name);

    printf("Enter date of appointment (DD/MM/YYYY): ");
    scanf("%s", &appointments[numOfAppointments].date);

    printf("Enter time of appointment (e.g. 2:30 PM): ");
    scanf("%s", &appointments[numOfAppointments].time);

    int day, month, year;

    sscanf(appointments[numOfAppointments].date, "%d/%d/%d", &day, &month, &year);

    if (isValidDate(day, month, year)) {
        numOfAppointments++;
        printf("Appointment added successfully!\n");
        mainMenu();
    } else {
        printf("Invalid date! Please enter a valid date.\n");
        addAppointment();
    }
}

/* Cancel Appointment */
void cancelAppointment() {
    if (numOfAppointments == 0) {
        printf("You have no appointments to cancel!\n");
        mainMenu();
    } else {
        char name[50];
        printf("\nCANCEL APPOINTMENT\n");
        printf("Enter your full name: ");
        scanf("%s", &name);

        bool found = false;

        for (int i=0; i<numOfAppointments; i++) {
            if (strcmp(name, appointments[i].name) == 0) {
                numOfAppointments--;
                for (int j=i; j<numOfAppointments; j++) {
                    strcpy(appointments[j].name, appointments[j+1].name);
                    strcpy(appointments[j].date, appointments[j+1].date);
                    strcpy(appointments[j].time, appointments[j+1].time);
                }
                found = true;
                break;
            }
        }

        if (found) {
            printf("Appointment cancelled successfully!\n");
        } else {
            printf("Appointment not found! Please enter a valid name.\n");
        }

        mainMenu();
    }
}

/* Check if the date is valid */
bool isValidDate(int day, int month, int year) {
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 2021) {
        return false;
    } else if (month == 2) {
        if (isLeapYear(year)) {
            if (day > 29) {
                return false;
            }
        } else {
            if (day > 28) {
                return false;
            }
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            return false;
        }
    }

    return true;
}

/* Check if the year is a leap year */
bool isLeapYear(int year) {
    if (year % 400 == 0) {
        return true;
    } else if (year % 100 == 0) {
        return false;
    } else if (year % 4 == 0) {
        return true;
    }

    return false;
}