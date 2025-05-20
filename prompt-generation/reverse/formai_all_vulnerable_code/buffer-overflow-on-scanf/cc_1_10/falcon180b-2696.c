//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t start_time;
    time_t end_time;
} Appointment;

void print_appointment(Appointment* a) {
    printf("Name: %s\n", a->name);
    printf("Description: %s\n", a->description);
    printf("Start time: %s\n", ctime(&a->start_time));
    printf("End time: %s\n", ctime(&a->end_time));
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;
    char input[100];

    printf("Welcome to the appointment scheduler!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an appointment\n");
        printf("2. Delete an appointment\n");
        printf("3. View appointments\n");
        printf("4. Quit\n");

        scanf("%d", &num_appointments);

        switch (num_appointments) {
        case 1:
            printf("Enter name (max %d characters): ", MAX_NAME_LENGTH);
            scanf("%s", appointments[num_appointments].name);

            printf("Enter description (max %d characters): ", MAX_DESCRIPTION_LENGTH);
            scanf("%s", appointments[num_appointments].description);

            printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
            scanf("%s", input);
            appointments[num_appointments].start_time = strptime(input, "%Y-%m-%d %H:%M:%S", NULL);

            printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
            scanf("%s", input);
            appointments[num_appointments].end_time = strptime(input, "%Y-%m-%d %H:%M:%S", NULL);

            printf("Appointment added!\n");
            break;

        case 2:
            printf("Enter appointment ID to delete: ");
            scanf("%d", &num_appointments);

            printf("Appointment deleted!\n");
            break;

        case 3:
            printf("Appointments:\n");
            for (int i = 0; i < num_appointments; i++) {
                print_appointment(&appointments[i]);
            }
            break;

        case 4:
            printf("Goodbye!\n");
            exit(0);

        default:
            printf("Invalid option selected.\n");
        }
    }

    return 0;
}