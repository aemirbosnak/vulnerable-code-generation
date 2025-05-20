//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

struct schedule {
    int day, month, year;
    char name[30];
    char venue[50];
    int time; //to store time in hours 
};

struct schedule appt[100];
int count = 0; //to count number of appointments

void addAppointment() {
    printf("\nEnter appointment details:\n");
    printf("Name: ");
    scanf("%s", appt[count].name);
    printf("Venue: ");
    scanf("%s", appt[count].venue);
    printf("Date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &appt[count].day, &appt[count].month, &appt[count].year);
    printf("Time (in hours): ");
    scanf("%d", &appt[count].time);
    count++;
    printf("\nAppointment added successfully.\n");
}

void viewAppointments() {
    printf("\nScheduled Appointments\n");
    printf("------------------------\n");
    printf("Name\tVenue\tDate\tTime\n");
    for(int i=0; i<count; i++) {
        printf("%s\t%s\t%d/%d/%d\t%d\n", appt[i].name, appt[i].venue, appt[i].day, appt[i].month, appt[i].year, appt[i].time);
    }
}

void deleteAppointment() {
    printf("\nEnter the date (dd/mm/yyyy) of the appointment you want to delete: ");
    int temp_day, temp_month, temp_year;
    scanf("%d/%d/%d", &temp_day, &temp_month, &temp_year);
    int found = 0;
    for(int i=0; i<count; i++) {
        if(appt[i].day==temp_day && appt[i].month==temp_month && appt[i].year==temp_year) {
            for(int j=i; j<count; j++) {
                appt[j] = appt[j+1];
            }
            found = 1;
            count--;
            printf("\nAppointment deleted successfully.\n");
            break;
        }
    }
    if(found==0) printf("\nAppointment not found.\n");
}

int main() {
    int ch;
    while(1) {
        printf("\nAppointment Scheduler\n");
        printf("------------------------\n");
        printf("1. Add Appointment\n2. View Appointments\n3. Delete Appointment\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: addAppointment(); break;
            case 2: viewAppointments(); break;
            case 3: deleteAppointment(); break;
            case 4: exit(0);
            default: printf("\nInvalid choice.\n");
        }
    }
    return 0;
}