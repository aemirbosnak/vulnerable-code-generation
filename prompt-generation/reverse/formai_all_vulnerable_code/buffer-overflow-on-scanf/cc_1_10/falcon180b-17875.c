//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t start_time;
    time_t end_time;
} appointment;

int main() {
    int num_appointments = 0;
    appointment *appointments = (appointment *)malloc(MAX_APPOINTMENTS * sizeof(appointment));
    char input[MAX_DESCRIPTION_LENGTH];
    time_t now;

    time(&now);
    printf("Welcome to the appointment scheduler!\n");
    printf("Enter 'add' to add an appointment, 'list' to view appointments, or 'quit' to exit.\n");

    while (num_appointments < MAX_APPOINTMENTS) {
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            printf("Enter appointment name (max %d characters): ", MAX_NAME_LENGTH);
            scanf("%s", appointments[num_appointments].name);

            printf("Enter appointment description (max %d characters): ", MAX_DESCRIPTION_LENGTH);
            scanf("%s", appointments[num_appointments].description);

            printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
            scanf("%s", input);
            strptime(input, "%Y-%m-%d %H:%M:%S", &appointments[num_appointments].start_time);

            printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
            scanf("%s", input);
            strptime(input, "%Y-%m-%d %H:%M:%S", &appointments[num_appointments].end_time);

            num_appointments++;
            printf("Appointment added!\n");
        }
        else if (strcmp(input, "list") == 0) {
            for (int i = 0; i < num_appointments; i++) {
                printf("%s: %s\n", appointments[i].name, appointments[i].description);
                printf("Start time: %s\n", ctime(&appointments[i].start_time));
                printf("End time: %s\n", ctime(&appointments[i].end_time));
                printf("\n");
            }
        }
        else if (strcmp(input, "quit") == 0) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid input.\n");
        }
    }

    free(appointments);
    return 0;
}