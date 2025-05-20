//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 50

struct Appointment {
    char name[50];
    int age;
    char gender[10];
    char date[20];
    char time[20];
    char issue[100];
}appointments[MAX];

int counter = 0;

void view_appointments() {
    printf("\nAll Appointments\n");
    if(counter == 0)
        printf("\nNo Appointments Scheduled Yet!\n");
    else {
        printf("---------------------------------------------------------------------\n");
        printf("Sr No.  Name                 Age   Gender    Date           Time          Issue\n");
        printf("---------------------------------------------------------------------\n");
        for(int i=0;i<counter;i++){
            printf("%-8d%-21s%-6d%-10s%-15s%-15s%s\n",i+1,appointments[i].name,appointments[i].age,appointments[i].gender,appointments[i].date,appointments[i].time,appointments[i].issue);
        }
    }
}

void schedule_appointment() {
    printf("\nEnter Appointment Details\n");
    printf("Enter Name : ");
    scanf("%s",appointments[counter].name);
    printf("Enter Age : ");
    scanf("%d",&appointments[counter].age);
    printf("Enter Gender : ");
    scanf("%s",appointments[counter].gender);
    printf("Enter Date (dd-mm-yyyy): ");
    scanf("%s",appointments[counter].date);
    printf("Enter Time (hh:mm AM/PM): ");
    scanf("%s",appointments[counter].time);
    printf("Enter Issue : ");
    scanf("%s",appointments[counter].issue);
    counter++;
}

int main() {
    int choice;
    while(1) {
        printf("\n--------------------------------------------------\n");
        printf("\t\t   MENU\n");
        printf("--------------------------------------------------\n");
        printf("1. Schedule Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n");
        printf("Enter Choice : ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: schedule_appointment();
            break;
            case 2: view_appointments();
            break;
            case 3: exit(0);
            default: printf("\nInvalid Choice!\n");
        }
    }
    return 0;
}