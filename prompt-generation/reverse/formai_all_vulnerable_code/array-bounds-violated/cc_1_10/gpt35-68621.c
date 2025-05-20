//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_ROWS 10
#define MAX_COLS 24

typedef struct CAppointment{
    char appointment_time[10];
    char patient_name[30];
    char patient_contact_no[20];
}CAppointment;

CAppointment schedule[MAX_ROWS][MAX_COLS];

void print_header(){
    printf("******************************************************************************\n");
    printf("*                          C Appointment Scheduler                            *\n");
    printf("******************************************************************************\n");
}

void print_menu(){
    printf("\nMenu:\n");
    printf("1. Schedule an Appointment\n");
    printf("2. Cancel an Appointment\n");
    printf("3. Print Today's Schedule\n");
    printf("4. Exit\n");
    printf("\nEnter your choice: ");
}

void get_appointment_details(CAppointment *appointment){
    printf("\nEnter appointment time (hh:mm AM/PM): ");
    scanf("%s", appointment->appointment_time);
    printf("\nEnter patient name: ");
    scanf("%s", appointment->patient_name);
    printf("\nEnter patient contact number: ");
    scanf("%s", appointment->patient_contact_no);
}

void schedule_appointment(){
    CAppointment *appointment = (CAppointment*)malloc(sizeof(CAppointment));
    get_appointment_details(appointment);

    // split appointment_time into hours, minutes and period
    char *token;
    token = strtok(appointment->appointment_time,":"); // first time calling strtok
    int hours = atoi(token);
    token = strtok(NULL, ":"); // second time calling strtok
    int minutes = atoi(token);
    token = strtok(NULL, " ");
    char period[3];
    strcpy(period, token);

    // convert hours to military time
    if(strcmp(period, "PM")==0 && hours!=12){
        hours += 12;
    }

    // set the appointment in the schedule
    schedule[hours-8][minutes/30] = *appointment;

    printf("\nAppointment scheduled successfully.\n");

    free(appointment);
}

void cancel_appointment(){
    char appointment_time[10];
    printf("\nEnter appointment time to cancel (hh:mm AM/PM): ");
    scanf("%s", appointment_time);

    // split appointment_time into hours, minutes and period
    char *token;
    token = strtok(appointment_time,":"); // first time calling strtok
    int hours = atoi(token);
    token = strtok(NULL, ":"); // second time calling strtok
    int minutes = atoi(token);
    token = strtok(NULL, " ");
    char period[3];
    strcpy(period, token);

    // convert hours to military time
    if(strcmp(period, "PM")==0 && hours!=12){
        hours += 12;
    }

    // cancel the appointment
    strcpy(schedule[hours-8][minutes/30].appointment_time, "");
    strcpy(schedule[hours-8][minutes/30].patient_name, "");
    strcpy(schedule[hours-8][minutes/30].patient_contact_no, "");

    printf("\nAppointment cancelled successfully.\n");
}

void print_schedule(){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    char week_day[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    printf("\nSchedule for %02d/%02d/%d (%s)\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, week_day[tm.tm_wday]);

    printf("  | 08:00 - 08:30 |  08:30 - 09:00 |  09:00 - 09:30 |  09:30 - 10:00 |  10:00 - 10:30 |  10:30 - 11:00 |  11:00 - 11:30 |  11:30 - 12:00 |  12:00 - 12:30 |  12:30 - 01:00 |  01:00 - 01:30 |  01:30 - 02:00 |  02:00 - 02:30 |  02:30 - 03:00 |  03:00 - 03:30 |  03:30 - 04:00 |  04:00 - 04:30 |  04:30 - 05:00 |  05:00 - 05:30 |  05:30 - 06:00 |  06:00 - 06:30 |  06:30 - 07:00 |\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for(int i=0; i<MAX_ROWS; i++){
        printf("%02d| ", i+8);
        for(int j=0; j<MAX_COLS; j++){
            printf("%-15s| ", schedule[i][j].appointment_time);
        }
        printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    }
}

int main(){
    int choice;

    while(1){
        print_header();
        print_menu();
        scanf("%d", &choice);

        switch(choice){
            case 1:
                schedule_appointment();
                break;

            case 2:
                cancel_appointment();
                break;

            case 3:
                print_schedule();
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

        printf("\nPress Enter key to continue...");
        getchar();
        getchar();

        system("clear");
    }

    return 0;
}