//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_DATE_LENGTH 20
#define MAX_TIME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
} appointment;

int num_appointments = 0;
appointment appointments[MAX_APPOINTMENTS];

void add_appointment() {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter description: ");
    scanf("%s", appointments[num_appointments].description);

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", appointments[num_appointments].date);

    printf("Enter time (HH:MM:SS): ");
    scanf("%s", appointments[num_appointments].time);

    num_appointments++;
}

void display_appointments() {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%d. %s: %s - %s\n", i+1, appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

void delete_appointment() {
    int index;
    printf("Enter appointment number to delete: ");
    scanf("%d", &index);
    if (index >= 0 && index < num_appointments) {
        num_appointments--;
        for (int i = index; i < num_appointments; i++) {
            appointments[i] = appointments[i+1];
        }
    } else {
        printf("Invalid appointment number.\n");
    }
}

int main() {
    srand(time(NULL));

    while (1) {
        printf("1. Add appointment\n");
        printf("2. Display appointments\n");
        printf("3. Delete appointment\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                display_appointments();
                break;
            case 3:
                delete_appointment();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}