//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: creative
#include <stdio.h>
#include <string.h>

// function to display the menu
void display_menu() {
    printf("********** APPOINTMENT SCHEDULER **********\n");
    printf("1. Schedule an Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Cancel an Appointment\n");
    printf("4. Exit\n");
    printf("*******************************************\n\n");
}

int main() {
    // array to store appointment details
    char appointments[10][100];
    // array to store appointment status (active/inactive)
    int status[10] = {0};
    int choice, count=0;

    printf("Welcome to the Appointment Scheduler\n");
    printf("------------------------------------\n\n");

    while(1) {
        display_menu();

        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(count >= 10) {
                    printf("Sorry! Maximum limit of appointments reached.\n");
                } else {
                    // get appointment details from user
                    char details[100];
                    printf("\nEnter appointment details: ");
                    getchar(); // clear buffer
                    fgets(details, sizeof(details), stdin);
                    // store details in appointments array
                    strcpy(appointments[count], details);
                    // set status as active (1)
                    status[count] = 1;
                    printf("Appointment scheduled successfully!\n\n");
                    count++;
                }
                break;

            case 2:
                if(count == 0) {
                    printf("No appointments scheduled yet.\n\n");
                } else {
                    printf("List of Appointments:\n");
                    printf("---------------------\n");
                    for(int i=0; i<count; i++) {
                        if(status[i] == 1) {
                            printf("%d. %s", i+1, appointments[i]);
                        }
                    }
                    printf("---------------------\n\n");
                }
                break;

            case 3:
                if(count == 0) {
                    printf("No appointments scheduled yet.\n\n");
                } else {
                    printf("Enter the appointment number to cancel: ");
                    int cancel_num;
                    scanf("%d", &cancel_num);
                    if(cancel_num <= 0 || cancel_num > count) {
                        printf("Invalid appointment number!\n\n");
                    } else if(status[cancel_num-1] == 0) {
                        printf("Appointment already cancelled!\n\n");
                    } else {
                        // cancel the appointment
                        status[cancel_num-1] = 0;
                        printf("Appointment cancelled successfully!\n\n");
                    }
                }
                break;

            case 4:
                printf("Thank you for using the Appointment Scheduler\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}