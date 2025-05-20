//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Sherlock Holmes
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct patient{
char name[50];
int age;
char gender[10];
char illness[100];
char doctor[50];
char appointment_time[30];
};

void schedule_appointment(struct patient p_info[]);
void view_appointments(struct patient p_info[]);
void cancel_appointment(struct patient p_info[]);


int main(){
    int option;
    struct patient p_info[10];
    do{
    printf("\t\t\tSherlock Holmes' Appointment Scheduler \n");
    printf("1. Schedule Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Cancel Appointment\n");
    printf("4. Exit\n");
    printf("Enter your option: ");
    scanf("%d", &option);
    switch(option){
            case 1: schedule_appointment(p_info);
            break;
            case 2: view_appointments(p_info);
            break;
            case 3: cancel_appointment(p_info);
            break;
            case 4: printf("Thank you for using Sherlock Holmes' Appointment Scheduler.\n");
            break;
            default: printf("Invalid option. Please try again.\n");
            break;
        }
    }while(option!=4);

    return 0;
}

void schedule_appointment(struct patient p_info[]){
    int i;
    printf("\nEnter Patient's Name: ");
    getchar();
    fgets(p_info[i].name, 50, stdin);

    printf("Enter Patient's Age: ");
    scanf("%d", &p_info[i].age);

    printf("Enter Patient's Gender: ");
    getchar();
    fgets(p_info[i].gender, 10, stdin);

    printf("Enter Patient's Illness: ");
    fgets(p_info[i].illness, 100, stdin);

    printf("Enter Doctor's Name: ");
    fgets(p_info[i].doctor, 50, stdin);

    printf("Enter Appointment Time: ");
    fgets(p_info[i].appointment_time, 30, stdin);
    i=i+1;
}

void view_appointments(struct patient p_info[]){
    int i;
    for(i=0;i<10;i++){
        if(p_info[i].age==0){
            break;
        }
        else{
            printf("\n\nPatient Name: %s", p_info[i].name);
            printf("Patient Age: %d\n", p_info[i].age);
            printf("Patient Gender: %s", p_info[i].gender);
            printf("Patient Illness: %s", p_info[i].illness);
            printf("Doctor's Name: %s",p_info[i].doctor);
            printf("Appointment Time: %s",p_info[i].appointment_time);
        }
    }
}

void cancel_appointment(struct patient p_info[]){
    int i, cancel_option;
    char name[50];
    printf("\nEnter Patient's Name to Cancel Appointment: ");
    getchar();
    fgets(name, 50, stdin);

    for(i=0;i<10;i++){
        if(strcmp(p_info[i].name, name)==0){
            printf("\nPatient Name: %s", p_info[i].name);
            printf("\nPatient Age: %d", p_info[i].age);
            printf("\nPatient's Illness: %s", p_info[i].illness);
            printf("\nDoctor's Name: %s", p_info[i].doctor);
            printf("\nAppointment Time: %s", p_info[i].appointment_time);

            printf("Do you want to cancel this appointment?\n");
            printf("1. Yes\n2. No\n");
            scanf("%d", &cancel_option);

            if(cancel_option==1){
                p_info[i].age = 0;
                printf("Appointment cancelled successfully.\n");
            }
        }
    }
}