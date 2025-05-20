//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

typedef struct date_s
{
    int day;
    int month;
    int year;
}date_t;

typedef struct appointment_s
{
    char name[MAX_SIZE];
    date_t date;
    char time[MAX_SIZE];
}appointment_t;

int num_appointments = 0;
appointment_t appointments[MAX_SIZE];

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void add_appointment()
{
    clear_input_buffer();

    printf("\nEnter name of the appointment: ");
    fgets(appointments[num_appointments].name, MAX_SIZE, stdin);

    printf("\nEnter date of the appointment (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &appointments[num_appointments].date.day, &appointments[num_appointments].date.month, &appointments[num_appointments].date.year);

    clear_input_buffer();

    printf("\nEnter time of the appointment: ");
    fgets(appointments[num_appointments].time, MAX_SIZE, stdin);

    num_appointments++;
    printf("\nAppointment added successfully!\n");
}

void search_appointment_by_date()
{
    int search_day, search_month, search_year;
    int found = 0;
    printf("\nEnter date to search for (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &search_day, &search_month, &search_year);

    for(int i = 0; i < num_appointments; i++)
    {
        if(appointments[i].date.day == search_day && appointments[i].date.month == search_month && appointments[i].date.year == search_year)
        {
            printf("\n");
            printf("Name: %s", appointments[i].name);
            printf("Date: %d/%d/%d\n", appointments[i].date.day, appointments[i].date.month, appointments[i].date.year);
            printf("Time: %s\n", appointments[i].time);
            found = 1;
        }
    }

    if(!found)
    {
        printf("\nNo appointments found on the given date!\n");
    }
}

void print_all_appointments()
{
    if(num_appointments == 0)
    {
        printf("\nNo appointments found!\n");
        return;
    }

    printf("\nAll Appointments:\n");
    for(int i = 0; i < num_appointments; i++)
    {
        printf("Name: %s", appointments[i].name);
        printf("Date: %d/%d/%d\n", appointments[i].date.day, appointments[i].date.month, appointments[i].date.year);
        printf("Time: %s\n", appointments[i].time);
        printf("-------------\n");
    }
}

void print_menu()
{
    printf("\n\n");
    printf("Appointment Scheduler\n");
    printf("------------------------\n");
    printf("1. Add Appointment\n");
    printf("2. Search Appointment by Date\n");
    printf("3. Print All Appointments\n");
    printf("4. Exit\n");
    printf("------------------------\n");
}

int main()
{
    int choice;

    while(1)
    {
        print_menu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                add_appointment();
                break;
            case 2:
                search_appointment_by_date();
                break;
            case 3:
                print_all_appointments();
                break;
            case 4:
                printf("\nExiting the program!\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}