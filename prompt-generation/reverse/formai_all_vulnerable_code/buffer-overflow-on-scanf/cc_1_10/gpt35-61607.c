//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//Structure to store appointment details
struct appointment{
    int day;
    int month;
    int year;
    char time[6];
    char name[50];
    char purpose[100];
};

//Function to display available time slots on a given date
void displayTimeSlots(int day, int month, int year){
    printf("\nAvailable time slots on %d/%d/%d:\n", day, month, year);
    printf("1. 09:00 AM\n");
    printf("2. 11:00 AM\n");
    printf("3. 02:00 PM\n");
    printf("4. 04:00 PM\n");
}

//Function to check if a given time slot is available
int isSlotAvailable(int day, int month, int year, char* time){
    //Open the data file
    FILE *fp = fopen("appointments.dat", "rb");
    if(fp == NULL){
        return 1;
    }
    //Loop through all appointments and check if the given time slot is not available
    struct appointment apt;
    while(fread(&apt, sizeof(struct appointment), 1, fp) == 1){
        if(apt.day == day && apt.month == month && apt.year == year && strcmp(apt.time, time) == 0){
            fclose(fp);
            return 0;
        }
    }
    fclose(fp);
    return 1;
}

//Function to schedule a new appointment
void scheduleAppointment(){
    printf("\n\n*** Schedule Appointment ***\n\n");
    //Get the date
    int day, month, year;
    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);
    //Check if the date is valid
    if(day < 1 || day > 31 || month < 1 || month > 12){
        printf("Invalid date\n");
        return;
    }
    //Check if the year is a leap year
    int isLeapYear = 0;
    if(year % 4 == 0){
        if(year % 100 == 0){
            if(year % 400 == 0){
                isLeapYear = 1;
            }
        }else{
            isLeapYear = 1;
        }
    }
    if((day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)) ||
    (day == 30 && month == 2) ||
    (day == 29 && month == 2 && !isLeapYear) ||
    day > 29){
        printf("Invalid date\n");
        return;
    }
    //Get the time
    int choice;
    printf("\nEnter the time slot:\n");
    displayTimeSlots(day, month, year);
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    char time[6];
    switch(choice){
        case 1:
            strcpy(time, "09:00");
            break;
        case 2:
            strcpy(time, "11:00");
            break;
        case 3:
            strcpy(time, "02:00");
            break;
        case 4:
            strcpy(time, "04:00");
            break;
        default:
            printf("Invalid choice\n");
            return;
    }
    //Check if the time slot is available
    if(!isSlotAvailable(day, month, year, time)){
        printf("Sorry, the selected time slot is not available\n");
        return;
    }
    //Get the name
    char name[50];
    printf("Enter your name: ");
    getchar();
    fgets(name, 50, stdin);
    name[strlen(name) - 1] = '\0';
    //Get the purpose
    char purpose[100];
    printf("Enter the purpose of the appointment: ");
    fgets(purpose, 100, stdin);
    purpose[strlen(purpose) - 1] = '\0';
    //Save the details to a file
    FILE *fp = fopen("appointments.dat", "ab");
    if(fp == NULL){
        printf("Error writing to file\n");
        return;
    }
    struct appointment apt;
    apt.day = day;
    apt.month = month;
    apt.year = year;
    strcpy(apt.time, time);
    strcpy(apt.name, name);
    strcpy(apt.purpose, purpose);
    fwrite(&apt, sizeof(struct appointment), 1, fp);
    fclose(fp);
    printf("\nAppointment scheduled successfully!:\n");
    printf("Date: %d/%d/%d\n", day, month, year);
    printf("Time: %s\n", time);
    printf("Name: %s\n", name);
    printf("Purpose: %s\n", purpose);
}

//Function to view all appointments
void viewAppointments(){
    printf("\n\n*** View Appointments ***\n\n");
    //Open the data file
    FILE *fp = fopen("appointments.dat", "rb");
    if(fp == NULL){
        printf("No appointments found\n");
        return;
    }
    //Loop through all appointments and display them
    struct appointment apt;
    printf("Day\tMonth\tYear\tTime\tName\t\tPurpose\n");
    while(fread(&apt, sizeof(struct appointment), 1, fp) == 1){
        printf("%d\t%d\t%d\t%s\t%s\t\t%s\n", apt.day, apt.month, apt.year, apt.time, apt.name, apt.purpose);
    }
    fclose(fp);
}

int main(){
    //Seed the random number generator with current time
    srand(time(NULL));
    //Display welcome message
    printf("***************************************************\n");
    printf("*                                                 *\n");
    printf("*            Appointment Scheduler                *\n");
    printf("*                                                 *\n");
    printf("***************************************************\n\n\n");
    //Menu loop
    int choice;
    do{
        printf("\n\n*** Main Menu ***\n\n");
        printf("1. Schedule Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                scheduleAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }while(choice != 3);
    return 0;
}