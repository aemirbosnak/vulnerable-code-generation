//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: high level of detail
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_STRING_LENGTH 50
#define MAX_APPOINTMENTS 5

typedef struct {
    char name[MAX_STRING_LENGTH];
    char date[MAX_STRING_LENGTH];
    char time[MAX_STRING_LENGTH];
} Appointment;

void displayMenu() {
    printf("\n========== APPOINTMENT SCHEDULER ==========\n");
    printf("1. Schedule Appointment\n");
    printf("2. View Schedule\n");
    printf("3. Cancel Appointment\n");
    printf("4. Exit\n");
    printf("============================================\n");
    printf("Enter your choice: ");
}

void clearInputBuffer() {
    while(getchar()!='\n');
}

int isScheduleAvailable(Appointment schedule[MAX_APPOINTMENTS], char date[MAX_STRING_LENGTH], char time[MAX_STRING_LENGTH]) {
    for(int i=0; i<MAX_APPOINTMENTS; i++) {
        if(strcmp(schedule[i].date, date)==0 && strcmp(schedule[i].time, time)==0) {
            return 0;
        }
    }
    return 1;
}

void scheduleAppointment(Appointment schedule[MAX_APPOINTMENTS]) {
    char name[MAX_STRING_LENGTH];
    char date[MAX_STRING_LENGTH];
    char time[MAX_STRING_LENGTH];
    int appointmentNumber = -1;

    printf("\nEnter your name: ");
    fgets(name, MAX_STRING_LENGTH, stdin);
    strtok(name, "\n");

    printf("Enter date of appointment (DD/MM/YYYY): ");
    fgets(date, MAX_STRING_LENGTH, stdin);
    strtok(date, "\n");

    printf("Enter time of appointment (HH:MM AM/PM): ");
    fgets(time, MAX_STRING_LENGTH, stdin);
    strtok(time, "\n");

    if(isScheduleAvailable(schedule, date, time)) {
        for(int i=0; i<MAX_APPOINTMENTS; i++) {
            if(schedule[i].name[0]=='\0') {
                appointmentNumber = i;
                break;
            }
        }

        if(appointmentNumber==-1) {
            printf("\nSorry, appointment slots are full.");
        } else {
            strcpy(schedule[appointmentNumber].name, name);
            strcpy(schedule[appointmentNumber].date, date);
            strcpy(schedule[appointmentNumber].time, time);

            printf("\nAppointment scheduled successfully!");
        }
    } else {
        printf("\nSorry, that appointment slot is already booked.");
    }
}

void viewSchedule(Appointment schedule[MAX_APPOINTMENTS]) {
    printf("\n=============== SCHEDULE ===============\n");
    printf("No.  NAME   DATE          TIME       \n");
    for(int i=0; i<MAX_APPOINTMENTS; i++) {
        if(schedule[i].name[0]!='\0') {
            printf("%d.   %-5s  %-12s  %-8s\n", i+1, schedule[i].name, schedule[i].date, schedule[i].time);
        }
    }
    printf("========================================\n");
}

void cancelAppointment(Appointment schedule[MAX_APPOINTMENTS]) {
    int appointmentNumber;

    printf("\nEnter appointment number to cancel: ");
    scanf("%d", &appointmentNumber);

    if(appointmentNumber>=1 && appointmentNumber<=MAX_APPOINTMENTS && schedule[appointmentNumber-1].name[0]!='\0') {
        memset(&schedule[appointmentNumber-1], 0, sizeof(Appointment));
        printf("\nAppointment cancelled successfully!");
    } else {
        printf("\nInvalid appointment number.");
    }
}

int main() {
    Appointment schedule[MAX_APPOINTMENTS];
    memset(schedule, 0, sizeof(schedule));

    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                scheduleAppointment(schedule);
                break;
            case 2:
                viewSchedule(schedule);
                break;
            case 3:
                cancelAppointment(schedule);
                break;
            case 4:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid choice. Please try again.");
                break;
        }

        clearInputBuffer(); // Clear the input buffer after each input
    } while(choice!=4);

    return 0;
}