//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_APPOINTMENTS 50

struct appointment{
    int appointment_id;
    char patient_name[100];
    char doctor_name[100];
    char date[15];
    char time[10];
};

int main(){
    struct appointment appointments[MAX_APPOINTMENTS];
    int appointment_counter = 0;
    int option, i, appointment_id, found;
    char patient_name[100], doctor_name[100], date[15], time[10];
    
    printf("Welcome to the Appointment Scheduler!\n");
    
    do{
        printf("\nWhat would you like to do?\n");
        printf("1. Book an appointment\n");
        printf("2. Cancel an appointment\n");
        printf("3. View appointments\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        fflush(stdin);
        
        switch(option){
            case 1:
                printf("\nEnter patient's name: ");
                fgets(patient_name, sizeof(patient_name), stdin);
                patient_name[strlen(patient_name)-1] = '\0';
                
                printf("Enter doctor's name: ");
                fgets(doctor_name, sizeof(doctor_name), stdin);
                doctor_name[strlen(doctor_name)-1] = '\0';
                
                printf("Enter date: ");
                fgets(date, sizeof(date), stdin);
                date[strlen(date)-1] = '\0';
                
                printf("Enter time (HH:MM): ");
                scanf("%s", time);
                fflush(stdin);
                
                appointments[appointment_counter].appointment_id = appointment_counter+1;
                strcpy(appointments[appointment_counter].patient_name, patient_name);
                strcpy(appointments[appointment_counter].doctor_name, doctor_name);
                strcpy(appointments[appointment_counter].date, date);
                strcpy(appointments[appointment_counter].time, time);
                appointment_counter++;
                printf("\nAppointment booked successfully!\n");
                break;
                
            case 2:
                if(appointment_counter == 0){
                    printf("\nNo appointments to cancel.\n");
                    break;
                }
                printf("\nEnter appointment ID to be cancelled: ");
                scanf("%d", &appointment_id);
                fflush(stdin);
                
                found = 0;
                
                for(i = 0; i < appointment_counter; i++){
                    if(appointments[i].appointment_id == appointment_id){
                        found = 1;
                        break;
                    }
                }
                
                if(found){
                    for(; i < appointment_counter; i++){
                        appointments[i] = appointments[i+1];
                    }
                    appointment_counter--;
                    printf("\nAppointment cancelled successfully!\n");
                }
                else{
                    printf("\nAppointment not found.\n");
                }
                break;
                
            case 3:
                if(appointment_counter == 0){
                    printf("\nNo appointments booked yet.\n");
                    break;
                }
                
                printf("\nAppointments:\n");
                printf("Appointment ID\tPatient Name\tDoctor Name\tDate\tTime\n");
                
                for(i = 0; i < appointment_counter; i++){
                    printf("%d\t\t%s\t\t%s\t\t%s\t%s\n", appointments[i].appointment_id, appointments[i].patient_name, 
                    appointments[i].doctor_name, appointments[i].date, appointments[i].time);
                }
                break;
            case 4:
                printf("\nThank you for using Appointment Scheduler.\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
        
    }while(option != 4);
    
    return 0;
}