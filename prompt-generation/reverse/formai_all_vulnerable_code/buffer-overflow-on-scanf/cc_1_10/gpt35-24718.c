//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct appointment {
    char name[50];
    int day;
    int month;
    int year;
    char time[10];
};

struct appointment cal[100]; //maximum of 100 appointments can be scheduled
int count = 0; //to keep track of number of appointments

void menu();
void display_appointments();
void search_appointment();
void add_appointment();

int main() {

    int choice;

    printf("\t\tWelcome to Appointment Scheduler\n\n");

    while(1) {
        menu(); //display the menu
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                display_appointments();
                break;
            case 2:
                search_appointment();
                break;
            case 3:
                add_appointment();
                break;
            case 4:
                printf("\nThank you for using Appointment Scheduler.\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }

    return 0;
}

void menu() {
    printf("1. Display all appointments\n");
    printf("2. Search for an appointment\n");
    printf("3. Add a new appointment\n");
    printf("4. Exit\n");
}

void display_appointments() {

    if(count == 0) {
        printf("\nNo appointments found.\n");
        return;
    }

    printf("Name\tDate\t\tTime\n");
    printf("--------------------------------------------------------\n");

    int i;

    for(i = 0; i < count; i++) {
        printf("%s\t%d/%d/%d\t%s\n", cal[i].name, cal[i].day, cal[i].month, cal[i].year, cal[i].time);
    }

    printf("\n");
}

void search_appointment() {

    if(count == 0) {
        printf("\nNo appointments found.\n");
        return;
    }

    char search_name[50];
    int i, flag = 0;

    printf("\nEnter the name to search for: ");
    scanf(" %[^\n]s", search_name);

    for(i = 0; i < count; i++) {
        if(strcmp(search_name, cal[i].name) == 0) {
            printf("\nName\tDate\t\tTime\n");
            printf("--------------------------------------------------------\n");
            printf("%s\t%d/%d/%d\t%s\n", cal[i].name, cal[i].day, cal[i].month, cal[i].year, cal[i].time);
            flag = 1;
            break;
        }
    }

    if(flag == 0)
        printf("\nAppointment not found.\n");

    printf("\n");
}

void add_appointment() {

    if(count == 100) {
        printf("\nAppointment Scheduler is full.\n");
        return;
    }

    printf("\nEnter name: ");
    scanf(" %[^\n]s", cal[count].name);

    printf("Enter date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &cal[count].day, &cal[count].month, &cal[count].year);

    printf("Enter time (hh:mm AM/PM): ");
    scanf("%s", cal[count].time);

    printf("\nAppointment added successfully.\n");

    count++;
    printf("\n");
}