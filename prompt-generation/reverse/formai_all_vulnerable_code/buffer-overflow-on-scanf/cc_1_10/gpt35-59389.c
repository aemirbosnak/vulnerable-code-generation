//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_APPOINTMENTS 50
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int numAppointments = 0;

bool isDuplicate(Appointment newApp) {
    for(int i = 0; i < numAppointments; i++) {
        if(strcmp(appointments[i].name, newApp.name) == 0 
            && appointments[i].day == newApp.day
            && appointments[i].month == newApp.month
            && appointments[i].year == newApp.year
            && appointments[i].hour == newApp.hour
            && appointments[i].minute == newApp.minute) {
            return true;
        }
    }
    return false;
}

void addAppointment() {
    Appointment newApp;
    printf("\nEnter name: ");
    scanf("%29s", newApp.name);
    printf("Enter day (1-31): ");
    scanf("%d", &newApp.day);
    printf("Enter month (1-12): ");
    scanf("%d", &newApp.month);
    printf("Enter year: ");
    scanf("%d", &newApp.year);
    printf("Enter hour (0-23): ");
    scanf("%d", &newApp.hour);
    printf("Enter minute (0-59): ");
    scanf("%d", &newApp.minute);

    if(isDuplicate(newApp)) {
        printf("\nSorry, there is already an appointment booked for that time.\n");
    } else {
        appointments[numAppointments] = newApp;
        numAppointments++;
        printf("\nAppointment added successfully.\n");
    }
}

void viewAppointments() {
    if(numAppointments == 0) {
        printf("\nNo appointments scheduled.\n");
    } else {
        printf("\nAppointments:\n");
        for(int i = 0; i < numAppointments; i++) {
            printf("%s on %d/%d/%d at %02d:%02d\n",
                appointments[i].name,
                appointments[i].day,
                appointments[i].month,
                appointments[i].year,
                appointments[i].hour,
                appointments[i].minute
            );
        }
    }
}

void deleteAppointment() {
    if(numAppointments == 0) {
        printf("\nNo appointments scheduled.\n");
    } else {
        char name[MAX_NAME_LENGTH];
        int deleteIndex = -1;
        printf("\nEnter name of the appointment to delete: ");
        scanf("%29s", name);
        for(int i = 0; i < numAppointments; i++) {
            if(strcmp(name, appointments[i].name) == 0) {
                deleteIndex = i;
                break;
            }
        }
        if(deleteIndex == -1) {
            printf("\nSorry, no appointment found with that name.\n");
        } else {
            for(int i = deleteIndex + 1; i < numAppointments; i++) {
                appointments[i-1] = appointments[i];
            }
            numAppointments--;
            printf("\nAppointment deleted successfully.\n");
        }
    }
}

int main() {
    int choice = 0;
    printf("***********************************\n");
    printf("****Welcome to Appointment App****\n");
    printf("***********************************\n");
    while(true) {
        printf("\nPlease choose an option:\n");
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Delete appointment\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}