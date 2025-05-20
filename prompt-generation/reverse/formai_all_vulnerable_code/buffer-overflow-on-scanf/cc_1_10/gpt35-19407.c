//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: calm
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

struct Appointment {
    char name[MAX_NAME_LENGTH];
    int day;
    int month;
    int year;
    int hour;
    int minute;
};

struct Appointment appointments[MAX_APPOINTMENTS];
int numAppointments = 0;

void printAppointment(struct Appointment appointment) {
    printf("Appointment Information:\n");
    printf("Name: %s\n", appointment.name);
    printf("Date: %d/%d/%d\n", appointment.day, appointment.month, appointment.year);
    printf("Time: %d:%02d\n", appointment.hour, appointment.minute);
}

int compareAppointments(struct Appointment a, struct Appointment b) {
    if (a.year < b.year) {
        return -1;
    } else if (a.year > b.year) {
        return 1;
    } else {
        if (a.month < b.month) {
            return -1;
        } else if (a.month > b.month) {
            return 1;
        } else {
            if (a.day < b.day) {
                return -1;
            } else if (a.day > b.day) {
                return 1;
            } else {
                if (a.hour < b.hour) {
                    return -1;
                } else if (a.hour > b.hour) {
                    return 1;
                } else {
                    if (a.minute < b.minute) {
                        return -1;
                    } else if (a.minute > b.minute) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        }
    }
}

void sortAppointments() {
    for (int i = 0; i < numAppointments; i++) {
        for (int j = i+1; j < numAppointments; j++) {
            if (compareAppointments(appointments[i], appointments[j]) > 0) {
                struct Appointment temp = appointments[i];
                appointments[i] = appointments[j];
                appointments[j] = temp;
            }
        }
    }
}

void viewAppointments() {
    printf("Appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printAppointment(appointments[i]);
        printf("\n");
    }
}

bool isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

bool isValidDate(int day, int month, int year) {
    if (month < 1 || month > 12) {
        return false;
    }
    if (day < 1 || day > 31) {
        return false;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            return false;
        }
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
    }
    return true;
}

bool isValidTime(int hour, int minute) {
    if (hour < 0 || hour > 23) {
        return false;
    }
    if (minute < 0 || minute > 59) {
        return false;
    }
    return true;
}

void addAppointment() {
    printf("Enter Name: ");
    scanf("%s", appointments[numAppointments].name);
    while(getchar() != '\n');
    printf("Enter Date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &appointments[numAppointments].day, &appointments[numAppointments].month, &appointments[numAppointments].year);
    while(getchar() != '\n');
    if (!isValidDate(appointments[numAppointments].day, appointments[numAppointments].month, appointments[numAppointments].year)) {
        printf("Invalid Date\n");
        return;
    }
    printf("Enter Time (24 hour time hh:mm): ");
    scanf("%d:%d", &appointments[numAppointments].hour, &appointments[numAppointments].minute);
    while(getchar() != '\n');
    if (!isValidTime(appointments[numAppointments].hour, appointments[numAppointments].minute)) {
        printf("Invalid Time\n");
        return;
    }
    numAppointments++;
    sortAppointments();
    printf("Appointment added successfully\n");
}

void removeAppointment() {
    if (numAppointments == 0) {
        printf("No Appointments\n");
        return;
    }
    printf("Enter Name: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    while(getchar() != '\n');
    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            for (int j = i; j < numAppointments-1; j++) {
                appointments[j] = appointments[j+1];
            }
            numAppointments--;
            printf("Appointment removed successfully\n");
            return;
        }
    }
    printf("No appointment with the given name found\n");
}

int main() {
    while (true) {
        printf("\n1. Add Appointment\n");
        printf("2. Remove Appointment\n");
        printf("3. View Appointments\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);
        while(getchar() != '\n');
        switch(choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                removeAppointment();
                break;
            case 3:
                viewAppointments();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}