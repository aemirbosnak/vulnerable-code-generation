//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 100
#define MAX_DESCRIPTION_LENGTH 500

struct appointment {
    int id;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int start_time;
    int end_time;
};

void add_appointment(struct appointment *appointments, int num_appointments) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Cannot add more appointments.\n");
        return;
    }

    printf("Enter appointment name (up to %d characters): ", MAX_NAME_LENGTH);
    scanf("%s", appointments[num_appointments].name);

    printf("Enter appointment description (up to %d characters): ", MAX_DESCRIPTION_LENGTH);
    scanf("%s", appointments[num_appointments].description);

    printf("Enter appointment start time (in minutes): ");
    scanf("%d", &appointments[num_appointments].start_time);

    printf("Enter appointment end time (in minutes): ");
    scanf("%d", &appointments[num_appointments].end_time);

    num_appointments++;
}

void print_appointments(struct appointment *appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("ID: %d\nName: %s\nDescription: %s\nStart time: %d minutes\nEnd time: %d minutes\n\n",
                appointments[i].id, appointments[i].name, appointments[i].description,
                appointments[i].start_time, appointments[i].end_time);
    }
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter 1 to add an appointment or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        } else if (choice == 1) {
            add_appointment(appointments, num_appointments);
        } else {
            printf("Invalid choice.\n");
        }
    }

    print_appointments(appointments, num_appointments);

    return 0;
}