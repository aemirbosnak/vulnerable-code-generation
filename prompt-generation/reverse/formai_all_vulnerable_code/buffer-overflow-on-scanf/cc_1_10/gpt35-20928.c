//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Structure to store the appointment details
struct appointment{
    char date[20];
    char time[10];
    char name[50];
    char contact[15];
    char email[50];
};

//Function to validate the appointment date
int validateDate(char date[]){
    int dateLength=strlen(date);
    if(dateLength!=10) return 0;
    if(date[2]!='-' || date[5]!='-') return 0;
    for(int i=0;i<dateLength;i++){
        if(i==2 || i==5) continue;
        if(!isdigit(date[i])) return 0;
    }
    return 1;
}

//Function to validate the appointment time
int validateTime(char time[]){
    if(strlen(time)!=5 || time[2]!=':') return 0;
    if(!isdigit(time[0]) || !isdigit(time[1]) || !isdigit(time[3]) || !isdigit(time[4])) return 0;
    int hour=atoi(time);
    int minute=atoi(time+3);
    if(hour<0 || hour>=24 || minute<0 || minute>=60) return 0;
    return 1;
}

int main(){
    int choice=0,appointmentCount=0;
    struct appointment appointments[50];
    printf("Welcome to the Appointment Scheduler!\n");
    do{
        printf("\n1. Schedule an appointment\n2. View all appointments\n3. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter the appointment date (DD-MM-YYYY): ");
                char date[20],time[10],name[50],contact[15],email[50];
                scanf("%s",date);
                while(!validateDate(date)){
                    printf("Invalid date format! Enter the appointment date again (DD-MM-YYYY): ");
                    scanf("%s",date);
                }
                printf("Enter the appointment time (HH:MM): ");
                scanf("%s",time);
                while(!validateTime(time)){
                    printf("Invalid time format! Enter the appointment time again (HH:MM): ");
                    scanf("%s",time);
                }
                printf("Enter the customer name: ");
                scanf("%s",name);
                printf("Enter the contact number: ");
                scanf("%s",contact);
                printf("Enter the email address: ");
                scanf("%s",email);
                struct appointment newAppointment={.date=date,.time=time,.name=name,.contact=contact,.email=email};
                appointments[appointmentCount++]=newAppointment;
                printf("\nAppointment created successfully!");
                break;
            case 2:
                printf("\nAll Appointments:\n");
                for(int i=0;i<appointmentCount;i++){
                    printf("\nAppointment %d\n",i+1);
                    printf("Date: %s\nTime: %s\nName: %s\nContact: %s\nEmail: %s\n",appointments[i].date,appointments[i].time,appointments[i].name,appointments[i].contact,appointments[i].email);
                }
                break;
            case 3:
                printf("\nExiting the program...");
                break;
            default:
                printf("\nInvalid choice!");
        }
    }while(choice!=3);
    return 0;
}