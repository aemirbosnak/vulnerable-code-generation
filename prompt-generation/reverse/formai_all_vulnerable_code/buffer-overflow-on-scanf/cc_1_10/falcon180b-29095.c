//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    time_t date;
    int duration;
} appointment;

int main() {
    appointment* appointments = (appointment*)malloc(MAX_APPOINTMENTS * sizeof(appointment));
    int num_appointments = 0;
    char input[MAX_NAME_LENGTH + MAX_PHONE_LENGTH + 10];
    time_t current_time = time(NULL);

    while (1) {
        system("clear");
        printf("Appointment Scheduler\n");
        printf("------------------------\n");

        if (num_appointments == 0) {
            printf("No appointments scheduled.\n");
        } else {
            printf("Appointments scheduled:\n");
            for (int i = 0; i < num_appointments; i++) {
                printf("%s (%s) - %s\n", appointments[i].name, appointments[i].phone, ctime(&appointments[i].date));
            }
        }

        printf("\nEnter A to add an appointment, D to delete an appointment, or Q to quit.\n");
        scanf("%s", input);

        if (strcmp(input, "A") == 0) {
            printf("Enter name (max %d characters): ", MAX_NAME_LENGTH - 1);
            scanf("%s", appointments[num_appointments].name);

            printf("Enter phone number (max %d characters): ", MAX_PHONE_LENGTH - 1);
            scanf("%s", appointments[num_appointments].phone);

            printf("Enter appointment date (YYYY-MM-DD HH:MM:SS): ");
            scanf("%s", input);
            strptime(input, "%Y-%m-%d %H:%M:%S", &appointments[num_appointments].date);

            printf("Enter appointment duration in minutes: ");
            scanf("%d", &appointments[num_appointments].duration);

            num_appointments++;
        } else if (strcmp(input, "D") == 0) {
            printf("Enter appointment ID to delete: ");
            int id;
            scanf("%d", &id);

            for (int i = 0; i < num_appointments; i++) {
                if (appointments[i].date == id) {
                    memmove(&appointments[i], &appointments[i+1], (num_appointments - i - 1) * sizeof(appointment));
                    num_appointments--;
                    break;
                }
            }
        } else if (strcmp(input, "Q") == 0) {
            free(appointments);
            exit(0);
        } else {
            printf("Invalid input.\n");
        }
    }

    return 0;
}