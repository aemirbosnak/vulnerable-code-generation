//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100

// structure for each appointment 
struct app{
    char date[20];
    char time[10];
    char desc[100];
};

// global array to store the appointments
struct app apptArr[MAXSIZE];

// global counter to keep track of number appointments
int counter = 0;

// function to add an appointment
void addAppointment(){
    printf("\n----Add Appointment----\n");

    // input the date
    printf("Enter date of appointment (dd/mm/yyyy): ");
    scanf("%s", apptArr[counter].date);

    // input the time of appointment
    printf("Enter time of appointment (hh:mm AM/PM): ");
    scanf("%s", apptArr[counter].time);

    // input the description of the appointment
    printf("Enter description of appointment: ");
    scanf(" %[^\n]", apptArr[counter].desc);

    // increment counter 
    counter++;

    // confirmation message
    printf("Appointment added successfully!\n");
}

//function to delete an appointment
void deleteAppointment(){
    printf("\n----Delete Appointment----\n");

    // input the date to be deleted
    char delDate[20];
    printf("Enter date of appointment to be deleted (dd/mm/yyyy): ");
    scanf("%s", delDate);

    // input the time to be deleted
    char delTime[10];
    printf("Enter time of appointment to be deleted (hh:mm AM/PM): ");
    scanf("%s", delTime);

    // find the index of the appointment to be deleted
    int index = -1;
    for(int i=0;i<counter;i++){
        if(strcmp(apptArr[i].date, delDate) == 0 && strcmp(apptArr[i].time, delTime) == 0){
            index = i;
            break;
        }
    }

    // if appointment found, delete it and shift the appointments after it up by 1
    if(index != -1){
        for(int i=index;i<counter-1;i++){
            strcpy(apptArr[i].date, apptArr[i+1].date);
            strcpy(apptArr[i].time, apptArr[i+1].time);
            strcpy(apptArr[i].desc, apptArr[i+1].desc);
        }
        counter--;
        printf("Appointment deleted successfully!\n");
    }
    else{
        printf("Appointment not found!\n");
    }
}

// function to search for appointments on a given date
void searchAppointment(){
    printf("\n----Search Appointment----\n");

    // input the date to search for
    char searchDate[20];
    printf("Enter date of appointment to be searched (dd/mm/yyyy): ");
    scanf("%s", searchDate);

    // find and print all appointments on the given date
    int flag = 0;
    for(int i=0;i<counter;i++){
        if(strcmp(apptArr[i].date, searchDate) == 0){
            flag = 1;
            printf("\nAppointment %d: \n", i+1);
            printf("Date: %s\n", apptArr[i].date);
            printf("Time: %s\n", apptArr[i].time);
            printf("Description: %s\n", apptArr[i].desc);
        }
    }

    // if no appointments on given date are found
    if(flag == 0){
        printf("No appointments found for the given date!\n");
    }
}

// main function
int main(){
    // main menu loop
    int choice = 1;
    while(choice!=0){
        printf("\n---Appointment Scheduler---\n");
        printf("1. Add Appointment\n2. Delete Appointment\n3. Search Appointment\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        // perform the selected operation
        switch(choice){
            case 1: 
                addAppointment();
                break;
            case 2:
                deleteAppointment();
                break;
            case 3:
                searchAppointment();
                break;
            case 0:
                printf("\nThank you for using Appointment Scheduler!\n");
                break;
            default:
                printf("\nInvalid choice! Please enter a valid choice.\n");
        }
    }

    return 0;
}