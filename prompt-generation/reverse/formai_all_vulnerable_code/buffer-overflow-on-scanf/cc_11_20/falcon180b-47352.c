//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 1000
#define MAX_APPOINTMENT_LENGTH 100

typedef struct {
    char name[MAX_APPOINTMENT_LENGTH];
    time_t start_time;
    time_t end_time;
} appointment;

int main() {
    int num_appointments = 0;
    appointment appointments[MAX_APPOINTMENTS];
    char input[MAX_APPOINTMENT_LENGTH];
    int choice;
    time_t current_time;

    srand(time(NULL));
    current_time = time(NULL);

    while (1) {
        system("clear");
        printf("Cyberpunk Appointment Scheduler\n");
        printf("Current time: %s", ctime(&current_time));

        printf("\nChoose an option:\n");
        printf("1. Add appointment\n");
        printf("2. Remove appointment\n");
        printf("3. View appointments\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_appointments >= MAX_APPOINTMENTS) {
                    printf("Maximum number of appointments reached.\n");
                } else {
                    printf("Enter appointment name (up to %d characters): ", MAX_APPOINTMENT_LENGTH - 1);
                    scanf("%s", appointments[num_appointments].name);
                    appointments[num_appointments].start_time = current_time + rand() % 86400; // Random start time within 24 hours
                    appointments[num_appointments].end_time = appointments[num_appointments].start_time + 3600; // 1 hour duration
                    num_appointments++;
                    printf("Appointment added.\n");
                }
                break;
            case 2:
                if (num_appointments == 0) {
                    printf("No appointments to remove.\n");
                } else {
                    printf("Enter appointment name to remove (up to %d characters): ", MAX_APPOINTMENT_LENGTH - 1);
                    scanf("%s", input);
                    int i;
                    for (i = 0; i < num_appointments; i++) {
                        if (strcmp(appointments[i].name, input) == 0) {
                            printf("Appointment removed.\n");
                            num_appointments--;
                            break;
                        }
                    }
                }
                break;
            case 3:
                if (num_appointments == 0) {
                    printf("No appointments.\n");
                } else {
                    printf("Upcoming appointments:\n");
                    for (int i = 0; i < num_appointments; i++) {
                        printf("%s: %s - %s\n", appointments[i].name, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time));
                    }
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}