//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 20
#define MAX_TIME_LENGTH 20
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Cannot add more than %d appointments\n", MAX_APPOINTMENTS);
        return;
    }

    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter date (MM/DD/YYYY): ");
    scanf("%s", appointments[num_appointments].date);

    printf("Enter time (HH:MM AM/PM): ");
    scanf("%s", appointments[num_appointments].time);

    printf("Enter description: ");
    scanf("%s", appointments[num_appointments].description);

    num_appointments++;
}

void view_appointments() {
    if (num_appointments == 0) {
        printf("No appointments\n");
        return;
    }

    printf("Name\tDate\tTime\tDescription\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s\t%s\t%s\t%s\n", appointments[i].name, appointments[i].date, appointments[i].time, appointments[i].description);
    }
}

void delete_appointment() {
    if (num_appointments == 0) {
        printf("No appointments\n");
        return;
    }

    printf("Enter appointment number to delete: ");
    int appointment_number;
    scanf("%d", &appointment_number);

    if (appointment_number < 0 || appointment_number >= num_appointments) {
        printf("Invalid appointment number\n");
        return;
    }

    for (int i = appointment_number; i < num_appointments - 1; i++) {
        appointments[i] = appointments[i + 1];
    }

    num_appointments--;
}

int main() {
    srand(time(NULL));

    printf("Welcome to the appointment scheduler\n");

    while (1) {
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Delete appointment\n");
        printf("4. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                delete_appointment();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}