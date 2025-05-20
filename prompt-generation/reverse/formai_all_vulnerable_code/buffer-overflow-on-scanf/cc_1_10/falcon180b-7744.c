//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define a structure to hold appointment information
typedef struct {
    char name[50];
    char description[100];
    time_t date;
    time_t duration;
} appointment;

// define a function to sort appointments by date and time
int compare_appointments(const void *a, const void *b) {
    const appointment *appointment1 = a;
    const appointment *appointment2 = b;
    return difftime(appointment1->date, appointment2->date);
}

// define a function to print the appointments
void print_appointments(appointment *appointments, int count) {
    printf("name\tdescription\tdate\ttime\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t%s\t%s\n", appointments[i].name, appointments[i].description, ctime(&appointments[i].date), ctime(&appointments[i].date + appointments[i].duration));
    }
}

// define a function to add an appointment
void add_appointment(appointment *appointments, int *count) {
    char name[50];
    char description[100];
    time_t date;
    time_t duration;

    printf("enter name: ");
    scanf("%s", name);
    printf("enter description: ");
    scanf("%s", description);
    printf("enter date (yyyy-mm-dd hh:mm:ss): ");
    scanf("%s", ctime(&date));
    printf("enter duration (in seconds): ");
    scanf("%d", &duration);

    strcpy(appointments[*count].name, name);
    strcpy(appointments[*count].description, description);
    appointments[*count].date = date;
    appointments[*count].duration = duration;

    (*count)++;
}

int main() {
    // initialize appointment array
    appointment appointments[100];
    int count = 0;

    // add some appointments
    add_appointment(appointments, &count);
    add_appointment(appointments, &count);
    add_appointment(appointments, &count);

    // sort appointments by date and time
    qsort(appointments, count, sizeof(appointment), compare_appointments);

    // print appointments
    print_appointments(appointments, count);

    return 0;
}