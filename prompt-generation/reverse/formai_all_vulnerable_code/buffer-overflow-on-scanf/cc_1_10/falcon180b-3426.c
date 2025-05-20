//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 20

typedef struct {
    char name[50];
    int date;
    int month;
    int year;
    int hour;
    int minute;
} appointment;

appointment createAppointment(char* name, int date, int month, int year, int hour, int minute) {
    appointment app;
    strcpy(app.name, name);
    app.date = date;
    app.month = month;
    app.year = year;
    app.hour = hour;
    app.minute = minute;
    return app;
}

void printAppointment(appointment app) {
    printf("Name: %s\n", app.name);
    printf("Date: %d/%d/%d\n", app.date, app.month, app.year);
    printf("Time: %02d:%02d\n", app.hour, app.minute);
}

int compareAppointments(const void* a, const void* b) {
    appointment* app1 = (appointment*)a;
    appointment* app2 = (appointment*)b;

    if (app1->date < app2->date) {
        return -1;
    } else if (app1->date > app2->date) {
        return 1;
    } else {
        if (app1->hour < app2->hour) {
            return -1;
        } else if (app1->hour > app2->hour) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main() {
    int choice;
    char name[50];
    int date, month, year, hour, minute;

    appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;

    do {
        printf("\nAppointment Scheduler\n");
        printf("1. Create appointment\n");
        printf("2. Print appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter date (dd/mm/yyyy): ");
            scanf("%d/%d/%d", &date, &month, &year);
            printf("Enter time (hh:mm): ");
            scanf("%d:%d", &hour, &minute);

            if (numAppointments >= MAX_APPOINTMENTS) {
                printf("Sorry, maximum number of appointments reached.\n");
            } else {
                appointments[numAppointments] = createAppointment(name, date, month, year, hour, minute);
                numAppointments++;
            }

            break;

        case 2:
            qsort(appointments, numAppointments, sizeof(appointment), compareAppointments);

            for (int i = 0; i < numAppointments; i++) {
                printAppointment(appointments[i]);
            }

            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }

    } while (1);

    return 0;
}