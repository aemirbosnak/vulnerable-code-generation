//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Claude Shannon
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100

struct Appointment{
    int id;
    char name[20];
    char date[20];
    char time[20];
};

struct Appointment appointments[MAX];
int num_of_appointments = 0;

void viewAppointments(){
    if(num_of_appointments == 0){
        printf("No Appointments\n");
        return;
    }
    printf("ID\tName\t\tDate\t\tTime\n");
    for(int i=0; i<num_of_appointments; i++){
        printf("%d\t%s\t\t%s\t%s\n", appointments[i].id, appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

void addAppointments(){
    if(num_of_appointments == MAX){
        printf("Maximum limit reached\n");
        return;
    }
    printf("Enter Name:");
    scanf("%s", appointments[num_of_appointments].name);
    printf("Enter Date:");
    scanf("%s", appointments[num_of_appointments].date);
    printf("Enter Time:");
    scanf("%s", appointments[num_of_appointments].time);
    appointments[num_of_appointments].id = time(0);
    num_of_appointments++;
}

void deleteAppointments(){
    int id;
    printf("Enter ID of Appointment to delete:");
    scanf("%d", &id);
    for(int i=0; i<num_of_appointments; i++){
        if(appointments[i].id == id){
            appointments[i] = appointments[num_of_appointments-1];
            num_of_appointments--;
            printf("Appointment with ID %d deleted\n", id);
            return;
        }
    }
    printf("Invalid ID\n");
}

void generateCode(){
    int i, j;
    char message[MAX];
    printf("Enter Message:");
    scanf(" %[^\n]s", message);
    int message_len = strlen(message);
    char binary[8*message_len+1];
    for(i=0; i<message_len; i++){
        int ascii = (int)message[i];
        for(j=7; j>=0; j--){
            if(ascii%2 == 0){
                binary[i*8+j] = '0';
            }
            else{
                binary[i*8+j] = '1';
            }
            ascii = ascii/2;
        }
    }
    binary[i*8] = '\0';
    printf("Binary Code: %s\n", binary);
}

int main(){
    int choice;
    do{
        printf("\n-------------------\n");
        printf("Appointment Scheduler:\n");
        printf("-------------------\n");
        printf("1. View Appointments\n");
        printf("2. Add Appointments\n");
        printf("3. Delete Appointments\n");
        printf("4. Generate Binary Code\n");
        printf("-------------------\n");
        printf("Enter Choice:");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                viewAppointments();
                break;
            case 2:
                addAppointments();
                break;
            case 3:
                deleteAppointments();
                break;
            case 4:
                generateCode();
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }while(1);
    return 0;
}