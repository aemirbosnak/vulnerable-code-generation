//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct appointment {
    int hour;
    int minutes;
    char description[100];
};

void add_appointment(struct appointment *appt) {
    printf("Enter the appointment time (hh:mm): ");
    scanf("%d:%d", &appt->hour, &appt->minutes);
    printf("Enter the appointment description: ");
    getchar(); // clear input buffer
    fgets(appt->description, 100, stdin);
    appt->description[strcspn(appt->description, "\n")] = 0; // remove newline character
}

void view_appointments(struct appointment *appts, int num_appts) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appts; i++) {
        printf("%d:%02d - %s\n", appts[i].hour, appts[i].minutes, appts[i].description);
    }
}

int main() {
    struct appointment appointments[100];
    int num_appointments = 0;
    char choice;

    printf("Welcome to the Appointment Scheduler!\n\n");

    do {
        printf("Enter 'a' to add an appointment, 'v' to view appointments, or 'q' to quit: ");
        scanf(" %c", &choice);
        switch (choice) {
            case 'a':
                if (num_appointments == 100) {
                    printf("Appointment list is full!\n");
                } else {
                    add_appointment(&appointments[num_appointments]);
                    num_appointments++;
                }
                break;
            case 'v':
                view_appointments(appointments, num_appointments);
                break;
            case 'q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 'q');

    return 0;
}