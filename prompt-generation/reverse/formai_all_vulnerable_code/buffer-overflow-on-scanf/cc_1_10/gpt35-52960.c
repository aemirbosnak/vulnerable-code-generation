//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>

struct appointment {
    char name[30];
    char date[20];
    char time[20];
    int duration;
};

void scheduleAppointment(struct appointment appt[], int *numAppts);
void displayAppointments(struct appointment appt[], int numAppts);

int main() {
    struct appointment appt[50];
    int numAppts = 0;
    int choice;

    printf("Appointment Scheduler\n\n");

    do {
        printf("1. Schedule Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                scheduleAppointment(appt, &numAppts);
                break;
            case 2:
                displayAppointments(appt, numAppts);
                break;
            case 3:
                printf("Exiting program.\n\n");
                break;
            default:
                printf("Invalid choice. Try again.\n\n");
        }
    } while(choice != 3);

    return 0;
}

void scheduleAppointment(struct appointment appt[], int *numAppts) {
    if(*numAppts >= 50) {
        printf("Appointment scheduler is full. Cannot schedule any more appointments.\n\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", appt[*numAppts].name);

    printf("Enter date (mm/dd/yyyy): ");
    scanf("%s", appt[*numAppts].date);

    printf("Enter time (hh:mm AM/PM): ");
    scanf("%s", appt[*numAppts].time);

    printf("Enter duration (in minutes): ");
    scanf("%d", &appt[*numAppts].duration);

    printf("Appointment scheduled!\n\n");

    (*numAppts)++;
}

void displayAppointments(struct appointment appt[], int numAppts) {
    if(numAppts == 0) {
        printf("There are no appointments scheduled.\n\n");
        return;
    }

    printf("Appointments\n");
    for(int i = 0; i < numAppts; i++) {
        printf("Name: %s\n", appt[i].name);
        printf("Date: %s\n", appt[i].date);
        printf("Time: %s\n", appt[i].time);
        printf("Duration: %d minutes\n\n", appt[i].duration);
    }
}