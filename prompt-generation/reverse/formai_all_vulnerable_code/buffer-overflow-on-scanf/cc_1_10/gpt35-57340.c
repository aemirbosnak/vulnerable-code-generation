//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct appointment{
    char name[50];
    int day;
    int month;
    int year;
    char time[10];
};

void createAppointment(struct appointment *apt, int size){
    int i;
    printf("Enter the following details for the appointment:\n");
    for(i=0; i<size; i++){
        printf("\nAppointment %d:\n", i+1);
        printf("Name: ");
        scanf("%s", apt[i].name);
        printf("Date (dd-mm-yyyy): ");
        scanf("%d-%d-%d", &apt[i].day, &apt[i].month, &apt[i].year);
        printf("Time (hh:mm am/pm): ");
        scanf("%s", apt[i].time);
        printf("\n");
    }
}

void viewAppointments(struct appointment *apt, int size){
    int i;
    printf("List of Appointments:\n\n");
    for(i=0; i<size; i++){
        printf("Appointment %d:\n", i+1);
        printf("Name: %s\n", apt[i].name);
        printf("Date: %d-%d-%d\n", apt[i].day, apt[i].month, apt[i].year);
        printf("Time: %s\n\n", apt[i].time);
    }
}

void cancelAppointment(struct appointment *apt, int size){
    char name[50];
    int i, found=0;
    printf("Enter the name of the appointment to cancel: ");
    scanf("%s", name);
    for(i=0; i<size; i++){
        if(strcmp(name, apt[i].name)==0){
            printf("Appointment cancelled!\n");
            apt[i].day = 0;
            apt[i].month = 0;
            apt[i].year = 0;
            apt[i].time[0] = '\0';
            found = 1;
            break;
        }
    }
    if(found == 0){
        printf("Appointment not found!\n");
    }
}

int main(){
    int size, choice;
    printf("Appointment Scheduler\n\n");
    printf("Enter the number of appointments to create: ");
    scanf("%d", &size);
    struct appointment apt[size];
    createAppointment(apt, size);
    while(1){
        printf("\nMenu:\n");
        printf("1. View Appointments\n");
        printf("2. Cancel Appointment\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: viewAppointments(apt, size); break;
            case 2: cancelAppointment(apt, size); break;
            case 3: exit(0);
            default: printf("Invalid choice!\n"); break;
        }
    }

    return 0;
}