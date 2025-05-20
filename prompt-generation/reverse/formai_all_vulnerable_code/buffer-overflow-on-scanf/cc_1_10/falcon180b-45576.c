//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    time_t start_time;
    time_t end_time;
} Appointment;

int main() {
    int num_appointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];
    char input[100];
    time_t current_time;
    int choice;
    int id;

    time(&current_time);
    srand(current_time);

    do {
        printf("\nWelcome to the Appointment Scheduler!\n");
        printf("1. Add an appointment\n");
        printf("2. View appointments\n");
        printf("3. Remove an appointment\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_appointments >= MAX_APPOINTMENTS) {
                    printf("Sorry, the schedule is full.\n");
                } else {
                    printf("Enter the name of the appointment: ");
                    scanf("%s", appointments[num_appointments].name);
                    appointments[num_appointments].id = rand() % 1000;
                    printf("Enter the start time (YYYY-MM-DD HH:MM:SS): ");
                    scanf("%s", input);
                    strptime(input, "%Y-%m-%d %H:%M:%S", &appointments[num_appointments].start_time);
                    printf("Enter the end time (YYYY-MM-DD HH:MM:SS): ");
                    scanf("%s", input);
                    strptime(input, "%Y-%m-%d %H:%M:%S", &appointments[num_appointments].end_time);
                    num_appointments++;
                }
                break;
            case 2:
                printf("Appointments:\n");
                for (int i = 0; i < num_appointments; i++) {
                    printf("%d. %s - %s to %s\n", i+1, appointments[i].name, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time));
                }
                break;
            case 3:
                printf("Enter the ID of the appointment to remove: ");
                scanf("%d", &id);
                for (int i = 0; i < num_appointments; i++) {
                    if (appointments[i].id == id) {
                        memmove(&appointments[i], &appointments[i+1], sizeof(Appointment) * (num_appointments - i - 1));
                        num_appointments--;
                        printf("Appointment removed.\n");
                        break;
                    }
                }
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}