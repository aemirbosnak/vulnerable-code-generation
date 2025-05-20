//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

struct appointment{
    char date[10];
    char time[10];
    char name[50];
};

int findEmptyIndex(struct appointment aptList[]);
void printScheduledAppointments(struct appointment aptList[]);
void scheduleAppointment(struct appointment aptList[]);

int main(){
    int choice;
    struct appointment aptList[MAX] = {0};

    do{
        printf("1. Schedule Appointment\n");
        printf("2. View Scheduled Appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                scheduleAppointment(aptList);
                break;
            case 2:
                printScheduledAppointments(aptList);
                break;
            case 3:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice. Please try again.");
        }
        printf("\n\n");

    }while(choice != 3);

    return 0;
}

int findEmptyIndex(struct appointment aptList[]){
    int i;
    for(i=0;i<MAX;i++){
        if(strcmp(aptList[i].date,"")==0){
            return i;
        }
    }
    printf("\nAppointment slots are full for today. Please try again tomorrow.\n");
    exit(0);
}

void printScheduledAppointments(struct appointment aptList[]){
    int i, j;
    struct appointment temp;

    for(i=0;i<MAX-1;i++){
        for(j=i+1;j<MAX;j++){
            if(strcmp(aptList[i].date,"")==0 || strcmp(aptList[j].date,"")==0 || strcmp(aptList[i].date,aptList[j].date)>0){
                temp = aptList[i];
                aptList[i] = aptList[j];
                aptList[j] = temp;
            }
        }
    }

    printf("\nScheduled Appointments:\n");
    for(i=0;i<MAX;i++){
        if(strcmp(aptList[i].date,"")!=0){
            printf("%s at %s with %s\n",aptList[i].date,aptList[i].time,aptList[i].name);
        }
    }
}

void scheduleAppointment(struct appointment aptList[]){
    int index;
    char date[10], time[10], name[50];
    printf("\nEnter desired appointment date (MM/DD/YY): ");
    scanf("%s",date);
    printf("Enter desired appointment time (HH:MM AM/PM): ");
    scanf("%s",time);
    printf("Enter patient name: ");
    scanf("%s",name);

    index = findEmptyIndex(aptList);
    strcpy(aptList[index].date,date);
    strcpy(aptList[index].time,time);
    strcpy(aptList[index].name,name);

    printf("\nAppointment scheduled successfully on %s at %s with %s.\n",date,time,name);
}