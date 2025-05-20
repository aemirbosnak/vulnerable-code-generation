//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPTS 100
#define MAX_NAME 50
#define MAX_DATE 11

/* Struct for each appointment */
typedef struct {
    char name[MAX_NAME];
    char date[MAX_DATE];
    int time;
    int duration;
} Appointment;

/* Function to print out a single appointment */
void print_appt(Appointment a) {
    printf("Name: %s\n", a.name);
    printf("Date: %s\n", a.date);
    printf("Time: %d:00\n", a.time);
    printf("Duration: %d hour(s)\n", a.duration);
}

/* Function to print out the list of appointments */
void print_appts(Appointment appts[], int num_appts) {
    int i;
    for (i = 0; i < num_appts; i++) {
        printf("Appointment %d:\n", i+1);
        print_appt(appts[i]);
        printf("\n");
    }
}

/* Function to add a new appointment */
void add_appt(Appointment appts[], int *num_appts) {
    char name[MAX_NAME];
    char date[MAX_DATE];
    int time, duration;

    printf("Enter the name of the appointment: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter the date of the appointment (MM/DD/YYYY): ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = '\0';

    printf("Enter the time of the appointment (in hours, 0-23): ");
    scanf("%d", &time);

    printf("Enter the duration of the appointment (in hours): ");
    scanf("%d", &duration);

    getchar();  // consume newline character left in buffer after scanf()

    appts[*num_appts].time = time;
    appts[*num_appts].duration = duration;
    strcpy(appts[*num_appts].name, name);
    strcpy(appts[*num_appts].date, date);

    *num_appts += 1;
}

/* Function to remove an appointment */
void remove_appt(Appointment appts[], int *num_appts) {
    int i, appt_num;
    printf("Enter the number of the appointment to remove: ");
    scanf("%d", &appt_num);

    if (appt_num < 1 || appt_num > *num_appts) {
        printf("Invalid appointment number.\n");
        return;
    }

    for (i = appt_num - 1; i < *num_appts - 1; i++) {
        appts[i] = appts[i+1];  // shift appointments over to fill gap
    }

    *num_appts -= 1;
    printf("Appointment %d has been removed.\n", appt_num);
}

/* Main function */
int main() {
    Appointment appts[MAX_APPTS];
    int num_appts = 0;
    int menu_choice = 0;

    printf("*** Appointment Scheduler ***\n");

    while (menu_choice != 4) {
        printf("\n");
        printf("*** Menu ***\n");
        printf("1. View all appointments\n");
        printf("2. Add a new appointment\n");
        printf("3. Remove an appointment\n");
        printf("4. Exit\n");

        printf("\nEnter your choice (1-4): ");
        scanf("%d", &menu_choice);
        getchar();  // consume newline character left in buffer after scanf()

        printf("\n");

        switch (menu_choice) {
            case 1:
                if (num_appts == 0) {
                    printf("There are no appointments yet.\n");
                } else {
                    print_appts(appts, num_appts);
                }
                break;

            case 2:
                if (num_appts == MAX_APPTS) {
                    printf("The maximum number of appointments has been reached.\n");
                } else {
                    add_appt(appts, &num_appts);
                    printf("The appointment has been added.\n");
                }
                break;

            case 3:
                if (num_appts == 0) {
                    printf("There are no appointments to remove.\n");
                } else {
                    remove_appt(appts, &num_appts);
                }
                break;

            case 4:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid menu choice.\n");
                break;
        }
    }

    return 0;
}