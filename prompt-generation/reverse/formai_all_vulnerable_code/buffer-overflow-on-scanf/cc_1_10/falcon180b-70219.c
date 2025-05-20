//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

struct appointment {
    char name[50];
    char date[20];
    char time[20];
};

int add_appointment(struct appointment* app, int count) {
    printf("Enter name: ");
    scanf("%s", app[count].name);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", app[count].date);
    printf("Enter time (HH:MM): ");
    scanf("%s", app[count].time);
    return 1;
}

int view_appointments(struct appointment* app, int count) {
    system("clear");
    printf("Appointments:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s on %s at %s\n", i+1, app[i].name, app[i].date, app[i].time);
    }
    return 1;
}

int main() {
    struct appointment app[MAX_APPOINTMENTS];
    int count = 0;
    char choice;

    do {
        system("clear");
        printf("Appointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (count >= MAX_APPOINTMENTS) {
                    printf("Sorry, you can only add up to %d appointments.\n", MAX_APPOINTMENTS);
                } else {
                    add_appointment(app, count);
                    count++;
                }
                break;
            case '2':
                if (count == 0) {
                    printf("No appointments added yet.\n");
                } else {
                    view_appointments(app, count);
                }
                break;
            case '3':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '3');

    return 0;
}