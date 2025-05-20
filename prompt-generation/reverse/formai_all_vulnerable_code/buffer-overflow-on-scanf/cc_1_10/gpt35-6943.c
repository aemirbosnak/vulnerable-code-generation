//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
typedef struct{
    char name[20],phone[20],email[20],date[20],time[20];
}Appointment;  //Defining a structure for appointment details

void New(int *size,Appointment app[]){
    printf("\nEnter Name: ");
    scanf(" %[^\n]",app[*size].name);
    printf("Enter Phone: ");
    scanf(" %[^\n]",app[*size].phone);
    printf("Enter Email: ");
    scanf(" %[^\n]",app[*size].email);
    printf("Enter Date (dd/mm/yyyy): ");
    scanf(" %[^\n]",app[*size].date);
    printf("Enter Time (hh:mm): ");
    scanf(" %[^\n]",app[*size].time);
    printf("\nAppointment created successfully!\n");
    (*size)++; //Increase the size of appointments array
}

int Search(int size, Appointment app[], char search[20]){
    for(int i=0;i<size;i++){
        if(strcmp(app[i].name,search)==0){
            printf("\nDetails of %s\n",search);
            printf("-----------------------------------------------\n");
            printf("Name: %s\nPhone: %s\nEmail: %s\nDate: %s\nTime: %s\n",app[i].name,app[i].phone,app[i].email,app[i].date,app[i].time);
            return i; //Return the index of the matching appointment
        }
    }
    printf("\nAppointment not found!\n");
    return -1; //If appointment not found, return -1
}

void Update(int size,Appointment app[]){
    char name[20];
    printf("\nEnter the name of the appointment to be updated: ");
    scanf(" %[^\n]",name);
    int index=Search(size,app,name); //Search the appointment by name
    if(index==-1){ //If appointment not found
        return;
    }
    printf("\nEnter new details:\n");
    printf("Enter Phone: ");
    scanf(" %[^\n]",app[index].phone);
    printf("Enter Email: ");
    scanf(" %[^\n]",app[index].email);
    printf("Enter Date (dd/mm/yyyy): ");
    scanf(" %[^\n]",app[index].date);
    printf("Enter Time (hh:mm): ");
    scanf(" %[^\n]",app[index].time);
    printf("\nAppointment updated successfully!\n");
}

void Delete(int *size,Appointment app[]){
    char name[20];
    printf("\nEnter the name of the appointment to be deleted: ");
    scanf(" %[^\n]",name);
    int index=Search(*size,app,name); //Search the appointment by name
    if(index==-1){ //If appointment not found
        return;
    }
    for(int i=index;i<(*size)-1;i++){
        app[i]=app[i+1]; //Shift the appointments to fill the gap
    }
    (*size)--; //Decrease the size of appointments array
    printf("\nAppointment deleted successfully!\n");
}

void Display(int size, Appointment app[]){
    if(size==0){
        printf("\nNo appointments to display\n");
        return;
    }
    printf("\nList of Appointments\n");
    printf("-----------------------------------------------\n");
    for(int i=0;i<size;i++){
        printf("%d. %s (%s) on %s at %s\n",i+1,app[i].name,app[i].phone,app[i].date,app[i].time); //Display the appointments
    }
}

int main(){
    Appointment app[MAXSIZE]; //Array of Appointment structures
    int size=0,choice; //Size variable stores the current number of appointments
    while(1){ //Infinite loop
        printf("\n\nAppointment Scheduler\n");
        printf("-----------------------------------------------\n");
        printf("1. New Appointment\n");
        printf("2. Search Appointment\n");
        printf("3. Update Appointment\n");
        printf("4. Delete Appointment\n");
        printf("5. Display Appointments\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: New(&size,app); break;
            case 2: Search(size,app,"Search"); break;
            case 3: Update(size,app); break;
            case 4: Delete(&size,app); break;
            case 5: Display(size,app); break;
            case 6: exit(0); break;
            default: printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}