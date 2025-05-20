//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20

struct appointment {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    time_t start_time;
    time_t end_time;
};

void add_appointment(struct appointment* appointments, int num_appointments) {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter phone number: ");
    scanf("%s", appointments[num_appointments].phone);

    appointments[num_appointments].start_time = time(NULL);
    appointments[num_appointments].end_time = appointments[num_appointments].start_time + 60 * 60; // 1 hour

    printf("Appointment added.\n");
}

void view_appointments(struct appointment* appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s\n", appointments[i].name, appointments[i].phone);
        printf("Start time: %s\n", ctime(&appointments[i].start_time));
        printf("End time: %s\n\n", ctime(&appointments[i].end_time));
    }
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        int choice;
        printf("\n1. Add appointment\n2. View appointments\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_appointment(appointments, num_appointments);
            break;
        case 2:
            view_appointments(appointments, num_appointments);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}