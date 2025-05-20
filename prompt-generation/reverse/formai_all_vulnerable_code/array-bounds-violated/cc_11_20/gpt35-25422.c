//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//Struct for appointment
struct Appointment {
    char task[50];
    char date[20];
    char time[20];
    bool cancel;
};

int main() {
    //Display current date and time
    time_t now;
    time(&now);
    printf("Current date and time: %s", ctime(&now));

    //Declare variables
    int choice, count = 0;
    struct Appointment appt[50];
    char input[50];

    //Loop until user chooses to exit
    while (true) {
        //Display menu options
        printf("\nChoose an option:\n");
        printf("1. Schedule an appointment\n");
        printf("2. View scheduled appointments\n");
        printf("3. Edit or cancel an appointment\n");
        printf("4. Exit\n");

        //Get user choice
        fgets(input, 50, stdin);
        choice = atoi(input);

        //Process user choice
        switch (choice) {
            case 1:
                printf("\nEnter task description: ");
                fgets(appt[count].task, 50, stdin);
                printf("Enter date (mm/dd/yyyy): ");
                fgets(appt[count].date, 20, stdin);
                printf("Enter time (hh:mm AM/PM): ");
                fgets(appt[count].time, 20, stdin);
                appt[count].cancel = false;
                count++;
                printf("\nAppointment scheduled!\n");
                break;
            case 2:
                if (count == 0) {
                    printf("\nNo scheduled appointments\n");
                }
                else {
                    printf("\nScheduled appointments:\n");
                    for (int i = 0; i < count; i++) {
                        if (!appt[i].cancel) {
                            printf("%d. Task: %sDate: %sTime: %s\n", i+1, appt[i].task, appt[i].date, appt[i].time);
                        }
                    }
                }
                break;
            case 3:
                printf("\nEnter number of appointment to edit/cancel: ");
                fgets(input, 50, stdin);
                int index = atoi(input) - 1;
                if (!appt[index].cancel) {
                    printf("1. Edit task\n");
                    printf("2. Edit date\n");
                    printf("3. Edit time\n");
                    printf("4. Cancel appointment\n");
                    fgets(input, 50, stdin);
                    int edit_choice = atoi(input);
                    switch (edit_choice) {
                        case 1:
                            printf("Enter new task description: ");
                            fgets(appt[index].task, 50, stdin);
                            printf("\nTask description updated!\n");
                            break;
                        case 2:
                            printf("Enter new date (mm/dd/yyyy): ");
                            fgets(appt[index].date, 20, stdin);
                            printf("\nDate updated!\n");
                            break;
                        case 3:
                            printf("Enter new time (hh:mm AM/PM): ");
                            fgets(appt[index].time, 20, stdin);
                            printf("\nTime updated!\n");
                            break;
                        case 4:
                            appt[index].cancel = true;
                            printf("\nAppointment cancelled!\n");
                            break;
                        default:
                            printf("\nInvalid choice\n");
                            break;
                    }
                }
                else {
                    printf("\nInvalid appointment number\n");
                }
                break;
            case 4:
                printf("\nThank you for using the Appointment Scheduler program!\n");
                exit(0);
            default:
                printf("\nInvalid choice\n");
                break;
        }
    }

    return 0;
}