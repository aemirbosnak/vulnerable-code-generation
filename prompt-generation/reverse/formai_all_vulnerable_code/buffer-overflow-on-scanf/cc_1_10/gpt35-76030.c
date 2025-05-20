//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_APPOINTMENTS 1000
#define MAX_NAME_LEN 50

struct Appointment{
    char name[MAX_NAME_LEN];
    int date;
    int time;
};

void addAppointment(struct Appointment[], int *);
void cancelAppointment(struct Appointment[], int *);
void showAppointments(struct Appointment[], int);

int main(){
    struct Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;
    int choice;

    do{
        printf("\n\nAppointment Scheduler\n");
        printf("========================\n");
        printf("1. Add Appointment\n");
        printf("2. Cancel Appointment\n");
        printf("3. Show Appointments\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addAppointment(appointments, &numAppointments);
                break;
            case 2:
                cancelAppointment(appointments, &numAppointments);
                break;
            case 3:
                showAppointments(appointments, numAppointments);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }while(choice != 4);

    return 0;
}

void addAppointment(struct Appointment appointments[], int *numAppointments){
    if(*numAppointments >= MAX_APPOINTMENTS){
        printf("\nCannot add appointment. Maximum capacity reached.\n");
        return;
    }

    char name[MAX_NAME_LEN];
    int date, time;

    printf("\nEnter name of patient: ");
    scanf("%s", name);
    printf("Enter date of appointment (ddmmyy): ");
    scanf("%d", &date);
    printf("Enter time of appointment (24-Hour Format): ");
    scanf("%d", &time);

    struct Appointment newAppointment;
    strcpy(newAppointment.name, name);
    newAppointment.date = date;
    newAppointment.time = time;

    appointments[*numAppointments] = newAppointment;
    (*numAppointments)++;

    printf("\nAppointment successfully added.\n");
}

void cancelAppointment(struct Appointment appointments[], int *numAppointments){
    if(*numAppointments == 0){
        printf("\nNo appointments to cancel.\n");
        return;
    }

    char name[MAX_NAME_LEN];
    int date, time, valid = 0;

    printf("\nEnter name of patient: ");
    scanf("%s", name);
    printf("Enter date of appointment (ddmmyy): ");
    scanf("%d", &date);
    printf("Enter time of appointment (24-Hour Format): ");
    scanf("%d", &time);

    for(int i = 0; i < *numAppointments; i++){
        if(strcmp(name, appointments[i].name) == 0 && date == appointments[i].date && time == appointments[i].time){
            valid = 1;
            for(int j = i+1; j < *numAppointments; j++){
                appointments[j-1] = appointments[j];
            }
            (*numAppointments)--;
            printf("\nAppointment cancelled.\n");
            break;
        }
    }

    if(!valid){
        printf("\nInvalid input. Appointment not found.\n");
    }
}

void showAppointments(struct Appointment appointments[], int numAppointments){
    if(numAppointments == 0){
        printf("\nNo appointments found.\n");
        return;
    }

    printf("\nAll Appointments\n");
    printf("------------------------\n");
    for(int i = 0; i < numAppointments; i++){
        printf("Patient Name: %s\n", appointments[i].name);
        printf("Date: %d\n", appointments[i].date);
        printf("Time: %d\n\n", appointments[i].time);
    }
}