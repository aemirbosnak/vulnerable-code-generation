//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct appointment {
    char name[50];
    int hour;
    int minute;
};

// Function to display the current date and time
void displayDateTime() {
    time_t current_time = time(NULL);
    printf("Current Date and Time: %s", ctime(&current_time));
}

// Function to get user inputs for name, hour, and minute
void getInputs(struct appointment *a) {
    printf("\nEnter your name: ");
    fgets(a->name, sizeof(a->name), stdin);
    
    printf("Enter hour (0-23): ");
    scanf("%d", &a->hour);
    
    printf("Enter minute (0-59): ");
    scanf("%d", &a->minute);
}

// Function to check if the appointment time is valid
int isValidTime(struct appointment a) {
    if (a.hour < 0 || a.hour > 23) {
        return 0;
    }
    
    if (a.minute < 0 || a.minute > 59) {
        return 0;
    }
    
    return 1;
}

// Function to print the appointment details
void printAppointment(struct appointment a) {
    printf("\nAppointment for %s", a.name);
    printf("Time: %02d:%02d\n", a.hour, a.minute);
}

int main() {
    int choice;
    struct appointment a;
    displayDateTime();
    
    do {
        printf("\n-- Appointment Scheduler --\n");
        printf("1. Set Appointment\n");
        printf("2. Exit\n");
        printf("Enter your choice (1-2): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                getInputs(&a);
                if (isValidTime(a)) {
                    printAppointment(a);
                } else {
                    printf("\nInvalid Time! Try Again..\n");
                }                
                break;
            case 2:
                printf("\nExiting Program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid Choice! Try Again..\n");
        }
    } while (choice != 2);
    
    return 0;
}