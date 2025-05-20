//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
    char profession[50];
    int appointment_time;
} appointment;

void create_appointment(appointment* app) {
    printf("Enter the name of the person: ");
    scanf("%s", app->name);
    printf("Enter the age of the person: ");
    scanf("%d", &app->age);
    printf("Enter the profession of the person: ");
    scanf("%s", app->profession);
    printf("Enter the appointment time (in minutes): ");
    scanf("%d", &app->appointment_time);
}

void display_appointment(appointment app) {
    printf("\nName: %s\n", app.name);
    printf("Age: %d\n", app.age);
    printf("Profession: %s\n", app.profession);
    printf("Appointment Time: %d minutes\n", app.appointment_time);
}

int compare_appointments(const void* a, const void* b) {
    appointment* app1 = (appointment*)a;
    appointment* app2 = (appointment*)b;

    if(app1->appointment_time < app2->appointment_time)
        return -1;
    else if(app1->appointment_time > app2->appointment_time)
        return 1;
    else
        return 0;
}

void schedule_appointments(appointment arr[], int size) {
    qsort(arr, size, sizeof(appointment), compare_appointments);

    for(int i=0; i<size; i++) {
        printf("\nAppointment %d:\n", i+1);
        display_appointment(arr[i]);
    }
}

int main() {
    int size;
    printf("Enter the number of appointments: ");
    scanf("%d", &size);

    appointment arr[size];

    for(int i=0; i<size; i++) {
        create_appointment(&arr[i]);
    }

    schedule_appointments(arr, size);

    return 0;
}