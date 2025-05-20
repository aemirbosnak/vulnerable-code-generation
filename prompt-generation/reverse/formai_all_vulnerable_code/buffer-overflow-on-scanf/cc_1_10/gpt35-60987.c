//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
    int day;
    int month;
    int year;
} Date;

struct Appointment{
    char name[50];
    Date date;
    char time[10];
    char location[50];
};

void addAppointment(struct Appointment *appointments, int *numAppointments);
void printAppointment(struct Appointment apt);
void printAppointments(struct Appointment *appointments, int numAppointments);

int main(){
    int numAppointments = 0;
    struct Appointment appointments[50];

    while(1){
        printf("\n======= Appointment Scheduler =======\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n");
        printf("Enter option: ");
        int option;
        scanf("%d", &option);

        switch(option){
            case 1:
                addAppointment(appointments, &numAppointments);
                break;
            case 2:
                printAppointments(appointments, numAppointments);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}

void addAppointment(struct Appointment *appointments, int *numAppointments){
    // Get name
    printf("Enter name for appointment: ");
    scanf("%s", appointments[*numAppointments].name);

    // Get date
    printf("Enter date for appointment (dd-mm-yyyy): ");
    scanf("%d-%d-%d", &appointments[*numAppointments].date.day, &appointments[*numAppointments].date.month, &appointments[*numAppointments].date.year);

    // Get time
    printf("Enter time for appointment (hh:mm am/pm): ");
    scanf("%s", appointments[*numAppointments].time);

    // Get location
    printf("Enter location for appointment: ");
    scanf("%s", appointments[*numAppointments].location);

    (*numAppointments)++;
}

void printAppointment(struct Appointment apt){
    printf("\nName: %s\n", apt.name);
    printf("Date: %02d-%02d-%04d\n", apt.date.day, apt.date.month, apt.date.year);
    printf("Time: %s\n", apt.time);
    printf("Location: %s\n", apt.location);
}

void printAppointments(struct Appointment *appointments, int numAppointments){
    if(numAppointments == 0){
        printf("No appointments scheduled.\n");
    }
    else{
        printf("\n======= Scheduled Appointments =======\n");
        for(int i=0;i<numAppointments;i++){
            printAppointment(appointments[i]);
            printf("\n");
        }
    }
}