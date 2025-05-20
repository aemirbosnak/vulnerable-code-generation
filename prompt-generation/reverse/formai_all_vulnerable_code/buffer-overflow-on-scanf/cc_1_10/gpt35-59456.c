//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct appointment {
    char name[50];
    int month;
    int day;
    int hour;
};

void printAppointment(struct appointment apt) {
    printf("Name: %s\n", apt.name);
    printf("Date: %d/%d\n", apt.month, apt.day);
    printf("Time: %d:00\n\n", apt.hour);
}

int main() {
    struct appointment schedule[5];
    int numAppointments = 0;
    
    printf("Welcome to the Appointment Scheduler!\n");
    printf("You can schedule up to 5 appointments.\n\n");
    
    // loop to add appointments
    int addMore = 1;
    while (addMore) {
        struct appointment apt;
        printf("Enter name for appointment %d: ", numAppointments+1);
        scanf("%s", apt.name);
        printf("Enter month for appointment %d (1-12): ", numAppointments+1);
        scanf("%d", &apt.month);
        printf("Enter day for appointment %d (1-31): ", numAppointments+1);
        scanf("%d", &apt.day);
        printf("Enter time for appointment %d (0-23): ", numAppointments+1);
        scanf("%d", &apt.hour);
        
        // check validity of appointment time
        int validTime = 1;
        for (int i = 0; i < numAppointments; i++) {
            if (strcmp(apt.name, schedule[i].name) == 0) {
                if (apt.month == schedule[i].month && apt.day == schedule[i].day && apt.hour == schedule[i].hour) {
                    printf("Sorry, that time is already booked.\n\n");
                    validTime = 0;
                    break;
                }
            }
        }
        
        // store appointment if time is valid
        if (validTime) {
            schedule[numAppointments] = apt;
            numAppointments++;
            printf("Appointment scheduled for:\n");
            printAppointment(apt);
        }
        
        // check if user wants to add more appointments
        if (numAppointments < 5) {
            int moreInput;
            printf("Do you want to add another appointment? (1/0) ");
            scanf("%d", &moreInput);
            if (moreInput == 0) {
                addMore = 0;
            }
            printf("\n");
        } else {
            addMore = 0;
            printf("You have reached the maximum number of appointments.\n\n");
        }
    }
    
    // print out all appointments
    printf("\nYour appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printAppointment(schedule[i]);
    }
    
    return 0;
}