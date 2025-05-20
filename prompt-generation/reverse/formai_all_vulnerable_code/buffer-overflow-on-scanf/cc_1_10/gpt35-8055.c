//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_APPOINTMENTS 50
#define MAX_NAME_LENGTH 50

// Structure to store the appointment data
struct Appointment {
    int day;
    int month;
    int year;
    char name[MAX_NAME_LENGTH];
};

// Function to check if a given year is a leap year or not
bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}

// Function to get the number of days in a given month
int getDaysInMonth(int month, int year) {
    if (month == 2) {
        if (isLeapYear(year)) {
            return 29;
        } else {
            return 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

// Function to validate a given date
bool isValidDate(int day, int month, int year) {
    if (year < 0) {
        return false;
    }
    if (month < 1 || month > 12) {
        return false;
    }
    int daysInMonth = getDaysInMonth(month, year);
    if (day < 1 || day > daysInMonth) {
        return false;
    }
    return true;
}

// Function to read a valid date from the user
void readDate(int *day, int *month, int *year) {
    char input[20];
    bool valid = false;
    while (!valid) {
        printf("Enter date in format DD/MM/YYYY: ");
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d/%d/%d", day, month, year) == 3) {
            if (isValidDate(*day, *month, *year)) {
                valid = true;
            } else {
                printf("Invalid date, please try again\n");
            }
        } else {
            printf("Invalid input format, please try again\n");
        }
    }
}

// Function to add a new appointment to the appointment list
void addAppointment(struct Appointment *appointments, int *numAppointments) {
    if (*numAppointments == MAX_APPOINTMENTS) {
        printf("Maximum number of appointments reached, cannot add more\n");
        return;
    }
    int day, month, year;
    readDate(&day, &month, &year);
    printf("Enter name of appointment: ");
    fgets(appointments[*numAppointments].name, MAX_NAME_LENGTH, stdin);
    appointments[*numAppointments].name[strcspn(appointments[*numAppointments].name, "\n")] = 0; // remove newline character
    appointments[*numAppointments].day = day;
    appointments[*numAppointments].month = month;
    appointments[*numAppointments].year = year;
    (*numAppointments)++;
}

// Function to print all appointments in a given month
void listAppointments(struct Appointment *appointments, int numAppointments, int month, int year) {
    printf("Appointments for %d/%d:\n", month, year);
    for (int i = 0; i < numAppointments; i++) {
        if (appointments[i].month == month && appointments[i].year == year) {
            printf("%d/%d/%d: %s\n", appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].name);
        }
    }
}

int main() {
    struct Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;
    while (true) {
        printf("\n");
        printf("1. Add appointment\n");
        printf("2. List appointments for month\n");
        printf("3. Exit\n");
        printf("Enter option: ");
        int option;
        scanf("%d", &option);
        getchar(); // consume newline character
        if (option == 1) {
            addAppointment(appointments, &numAppointments);
        } else if (option == 2) {
            int month, year;
            printf("Enter month and year to list appointments for (in format MM/YYYY): ");
            scanf("%d/%d", &month, &year);
            getchar(); // consume newline character
            listAppointments(appointments, numAppointments, month, year);
        } else if (option == 3) {
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid option, please try again\n");
        }
    }
    return 0;
}