//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct appointment{
    char date[MAX];
    char time[MAX];
    char name[MAX];
};

int count = 0;

void addAppointment(struct appointment *appointments);
void viewAppointments(struct appointment *appointments);
void clearInputBuffer();
void printDivider();

int main(){
    struct appointment appointments[MAX];
    char choice;

    do{
        printDivider();
        printf("Please choose an option:\n");
        printf("1. Schedule an appointment.\n2. View appointments.\n3. Exit.\n");
        printDivider();
        printf("Enter your choice: ");
        scanf("%c", &choice);
        clearInputBuffer(); // clearing the input buffer to avoid errors

        switch(choice){
            case '1': 
                addAppointment(appointments);
                break;
            case '2':
                viewAppointments(appointments);
                break;
            case '3':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }while(choice != '3');

    return 0;
}

void addAppointment(struct appointment *appointments){
    char date[MAX], time[MAX], name[MAX];

    printf("Enter the date (DD/MM/YYYY): ");
    fgets(date, MAX, stdin);
    date[strlen(date)-1] = '\0'; //removing the newline character
    fflush(stdin); //flushing the input buffer
    printf("Enter the time (HH:MM): ");
    fgets(time, MAX, stdin);
    time[strlen(time)-1] = '\0'; //removing the newline character
    fflush(stdin); //flushing the input buffer
    printf("Enter the name: ");
    fgets(name, MAX, stdin);
    name[strlen(name)-1] = '\0'; //removing the newline character
    fflush(stdin); //flushing the input buffer

    strcpy(appointments[count].date, date);
    strcpy(appointments[count].time, time);
    strcpy(appointments[count].name, name);
    count++;

    printf("Appointment scheduled successfully!\n");

}

void viewAppointments(struct appointment *appointments){
    int i;

    if(count==0){
        printf("No appointments scheduled.\n");
        return;
    }

    for(i=0; i<count; i++){
        printf("Appointment %d:\nDate: %s\nTime: %s\nName: %s\n", i+1, appointments[i].date, appointments[i].time, appointments[i].name);
        printDivider();
    }
}

void clearInputBuffer(){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

void printDivider(){
    printf("________________________________________\n\n");
}