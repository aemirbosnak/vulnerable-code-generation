//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Alan Touring
//Appointment Scheduler Program using C
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct appointment{
    char name[50];
    char purpose[50];
    int time;
};

struct appointment ap[5];

//Booking Appointment function
void bookAppointment(){
    int i, flag = -1;
    for(i=0; i<5; i++){
        if(ap[i].time == 0){
            flag = 0;
            printf("\nEnter Name: ");
            scanf("%s", ap[i].name);
            printf("Enter Purpose: ");
            scanf("%s", ap[i].purpose);
            printf("Enter Time(in 24 hour format): ");
            scanf("%d", &ap[i].time);
            printf("\nAppointment Booked Successfully!");
            break;
        }
    }
    if(flag == -1){
        printf("\nSorry, Appointment Slots are full!");
    }
}

//Cancel Appointment function
void cancelAppointment(){
    int i, flag = -1, time;
    char name[50];
    printf("\nEnter the Time of your Appointment you want to cancel: ");
    scanf("%d", &time);
    for(i=0; i<5; i++){
        if(ap[i].time == time){
            flag = 0;
            strcpy(name, ap[i].name);
            strcpy(ap[i].name, "");
            strcpy(ap[i].purpose, "");
            ap[i].time = 0;
            break;
        }
    }
    if(flag == -1){
        printf("\nSorry, Appointment for this time does not exist!");
    } else{
        printf("\nAppointment for %s at %d is Cancelled Successfully!", name, time);
    }
}

//View All Appointments function
void viewAppointments(){
    int i, count=0;
    for(i=0; i<5; i++){
        if(ap[i].time != 0){
            count++;
            printf("\nAppointment %d: ", count);
            printf("\nName: %s", ap[i].name);
            printf("\nPurpose: %s", ap[i].purpose);
            printf("\nTime: %d\n", ap[i].time);
        }
    }
    if(count == 0){
        printf("\nThere are no Appointments Scheduled!");
    }
}

int main(){
    int choice;
    do{
        printf("\n\n\t***** Appointment Scheduler *****\n");
        printf("\n1. Book Appointment\n2. Cancel Appointment\n3. View All Appointments\n4. Exit\n\nEnter your Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                bookAppointment();
                break;
            case 2:
                cancelAppointment();
                break;
            case 3:
                viewAppointments();
                break;
            case 4:
                printf("\nThank you for using Appointment Scheduler!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid Choice! Please choose between 1-4\n");
        }
    }while(choice != 4);
    return 0;
}