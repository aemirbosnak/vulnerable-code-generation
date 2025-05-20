//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[20];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} appointment;

void add_appointment(appointment* appts, int num_appts) {
    printf("Enter name: ");
    scanf("%s", appts[num_appts].name);

    printf("Enter phone number: ");
    scanf("%s", appts[num_appts].phone);

    printf("Enter day (1-31): ");
    scanf("%d", &appts[num_appts].day);

    printf("Enter month (1-12): ");
    scanf("%d", &appts[num_appts].month);

    printf("Enter year (e.g. 2022): ");
    scanf("%d", &appts[num_appts].year);

    printf("Enter hour (0-23): ");
    scanf("%d", &appts[num_appts].hour);

    printf("Enter minute (0-59): ");
    scanf("%d", &appts[num_appts].minute);

    num_appts++;
}

void display_appointments(appointment* appts, int num_appts) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appts; i++) {
        printf("%s - %s - %02d/%02d/%04d %02d:%02d\n", appts[i].name, appts[i].phone, appts[i].day, appts[i].month, appts[i].year, appts[i].hour, appts[i].minute);
    }
}

int main() {
    appointment appts[MAX_APPOINTMENTS];
    int num_appts = 0;

    while (num_appts < MAX_APPOINTMENTS) {
        printf("\nEnter 1 to add an appointment, 0 to exit:\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_appointment(appts, num_appts);
        } else if (choice == 0) {
            break;
        } else {
            printf("Invalid choice, try again.\n");
        }
    }

    display_appointments(appts, num_appts);

    return 0;
}