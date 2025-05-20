//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[50];
    Date date;
    char description[200];
} Appointment;

void printAppointment(Appointment *app);
int getDate(char prompt[], Date *date);
int getAppointment(char prompt[], Appointment *app);
void clearInputBuffer();
void viewAppointments(Appointment *appointments, int count);

int main() {
    Appointment appointments[50];
    int count = 0;
    char choice;

    do {
        printf("\nAppointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf(" %c", &choice);
        clearInputBuffer();

        switch (choice) {
            case '1': {
                Appointment app;
                if (getAppointment("Enter appointment details", &app)) {
                    appointments[count] = app;
                    count++;
                    printf("\nAppointment added successfully!\n");
                } else {
                    printf("\nFailed to add appointment. Please try again.\n");
                }
                break;
            }
            case '2': {
                if (count == 0) {
                    printf("\nThere are no appointments to view.\n");
                } else {
                    printf("\nAppointments:\n");
                    viewAppointments(appointments, count);
                }
                break;
            }
            case '3': {
                printf("\nGoodbye!\n");
                break;
            }
            default: {
                printf("\nInvalid choice. Please enter 1, 2, or 3.\n");
                break;
            }
        }
    } while (choice != '3');

    return 0;
}

void printAppointment(Appointment *app) {
    printf("%d/%d/%d - %s\n", app->date.month, app->date.day, app->date.year, app->name);
    printf("%s\n", app->description);
}

int getDate(char prompt[], Date *date) {
    int valid = 0;
    do {
        printf("%s (MM/DD/YYYY): ", prompt);
        scanf("%d/%d/%d", &date->month, &date->day, &date->year);
        clearInputBuffer();
        if (date->month < 1 || date->month > 12) {
            printf("Invalid month. ");
            continue;
        }
        if (date->day < 1 || date->day > 31) {
            printf("Invalid day. ");
            continue;
        }
        if (date->year < 1900 || date->year > 2200) {
            printf("Invalid year. ");
            continue;
        }
        valid = 1;
    } while (!valid);
    return 1;
}

int getAppointment(char prompt[], Appointment *app) {
    printf("%s\n", prompt);
    printf("Name: ");
    fgets(app->name, sizeof(app->name), stdin);
    app->name[strcspn(app->name, "\n")] = 0;
    if (!getDate("Date", &app->date)) {
        return 0;
    }
    printf("Description: ");
    fgets(app->description, sizeof(app->description), stdin);
    app->description[strcspn(app->description, "\n")] = 0;
    return 1;
}

void clearInputBuffer() {
    while (getchar() != '\n');
}

void viewAppointments(Appointment *appointments, int count) {
    for (int i = 0; i < count; i++) {
        printf("\nAppointment %d:\n", i + 1);
        printAppointment(&appointments[i]);
    }
}