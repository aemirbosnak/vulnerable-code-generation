//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Declare global variables
#define max_appts 10
int appt_cnt = 0;

//Declare structure for appointment
struct appt {
    char name[30];
    char date[20];
    int time;
};

//Function to add an appointment
void add_appt(struct appt *appts) {
    //Check if maximum number of appointments have been reached
    if(appt_cnt==max_appts) {
        printf("Maximum number of appointments reached!\n");
        return;
    }

    //Get input from user
    printf("Enter the name: ");
    scanf("%s", appts[appt_cnt].name);
    printf("Enter the date (MM/DD/YYYY): ");
    scanf("%s", appts[appt_cnt].date);

    bool invalid_time = true;
    while(invalid_time) {
        printf("Enter the time (24-hour format, e.g. 13:00): ");
        char input[10];
        scanf("%s", input);
        int hour = atoi(input);
        char *minute_str = strchr(input, ':');
        if(minute_str == NULL) {
            printf("Invalid input!\n");
            continue;
        }
        minute_str++;
        int minute = atoi(minute_str);
        if(hour<0 || hour>=24 || minute<0 || minute>59) {
            printf("Invalid input!\n");
        } else {
            appts[appt_cnt].time = hour*100 + minute;
            invalid_time = false;
        }
    }

    appt_cnt++;
    printf("Appointment added successfully!\n");
}

//Function to search for an appointment
void search_appt(struct appt *appts) {
    //Get input from user
    printf("Enter the name of the appointment to search for: ");
    char search_name[30];
    scanf("%s", search_name);

    //Loop over all appointments and search for the given name
    bool found = false;
    for(int i=0; i<appt_cnt; i++) {
        if(strcmp(appts[i].name, search_name) == 0) {
            char time_str[10];
            int hour = appts[i].time/100;
            int minute = appts[i].time%100;
            sprintf(time_str, "%02d:%02d", hour, minute);
            printf("Appointment found!\n");
            printf("Name: %s\n", appts[i].name);
            printf("Date: %s\n", appts[i].date);
            printf("Time: %s\n", time_str);
            found = true;
            break;
        }
    }
    if(!found) {
        printf("Appointment not found!\n");
    }
}

//Main function
int main() {
    struct appt appts[max_appts];
    bool exit = false;
    while(!exit) {
        //Print menu
        printf("\nAppointment Scheduler\n");
        printf("1. Add an appointment\n");
        printf("2. Search for an appointment\n");
        printf("3. Exit\n");

        //Get input from user
        printf("\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_appt(appts);
                break;
            case 2:
                search_appt(appts);
                break;
            case 3:
                printf("Exiting...\n");
                exit = true;
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}