//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_APPTS 20

typedef struct appointment {
    int month;
    int day;
    int year;
    char description[50];
} Appointment;

Appointment appointments[MAX_APPTS];
int apptCount = 0;

void display_menu() {
    printf("---APPOINTMENT SCHEDULER---\n");
    printf("1. Schedule appointment\n");
    printf("2. View appointments\n");
    printf("3. Cancel appointment\n");
    printf("4. Exit\n");
}

bool is_valid_date(int month, int day, int year) {
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    if (year < 2021)
        return false;
    if (month == 2 && day > 29)
        return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30))
        return false;
    return true;
}

void schedule_appointment() {
    if (apptCount == MAX_APPTS) {
        printf("No more space for appointments!\n");
        return;
    }
    Appointment newAppt;
    printf("Enter month (1-12): ");
    scanf("%d", &newAppt.month);
    printf("Enter day (1-31): ");
    scanf("%d", &newAppt.day);
    printf("Enter year (2021 or later): ");
    scanf("%d", &newAppt.year);
    if (!is_valid_date(newAppt.month, newAppt.day, newAppt.year)) {
        printf("Invalid date!\n");
        return;
    }
    printf("Enter description (50 chars or less): ");
    getchar();
    fgets(newAppt.description, 50, stdin);
    appointments[apptCount++] = newAppt;
    printf("Appointment scheduled successfully!\n");
}

void view_appointments() {
    if (apptCount == 0) {
        printf("No appointments to display!\n");
        return;
    }
    printf("Appointments:\n");
    for (int i = 0; i < apptCount; i++) {
        printf("%d/%d/%d: %s", appointments[i].month, appointments[i].day, appointments[i].year, appointments[i].description);
    }
}

void cancel_appointment() {
    if (apptCount == 0) {
        printf("No appointments to cancel!\n");
        return;
    }
    printf("Enter month of appointment to cancel (1-12): ");
    int month;
    scanf("%d", &month);
    printf("Enter day of appointment to cancel (1-31): ");
    int day;
    scanf("%d", &day);
    printf("Enter year of appointment to cancel (2021 or later): ");
    int year;
    scanf("%d", &year);
    for (int i = 0; i < apptCount; i++) {
        if (appointments[i].month == month && appointments[i].day == day && appointments[i].year == year) {
            for (int j = i; j < apptCount - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            apptCount--;
            printf("Appointment canceled successfully!\n");
            return;
        }
    }
    printf("Appointment not found!\n");
}

int main() {
    int choice;
    while (true) {
        display_menu();
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                schedule_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                cancel_appointment();
                break;
            case 4:
                printf("Exiting. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}