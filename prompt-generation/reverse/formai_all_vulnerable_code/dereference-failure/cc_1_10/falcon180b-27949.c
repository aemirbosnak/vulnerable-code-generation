//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Appointment {
    char *name;
    char *date;
    char *time;
    char *description;
};

void print_appointment(struct Appointment *appointment) {
    printf("Name: %s\n", appointment->name);
    printf("Date: %s\n", appointment->date);
    printf("Time: %s\n", appointment->time);
    printf("Description: %s\n\n", appointment->description);
}

int main() {
    int num_appointments;
    scanf("%d", &num_appointments);

    struct Appointment *appointments = malloc(sizeof(struct Appointment) * num_appointments);

    for (int i = 0; i < num_appointments; i++) {
        appointments[i].name = malloc(50 * sizeof(char));
        appointments[i].date = malloc(50 * sizeof(char));
        appointments[i].time = malloc(50 * sizeof(char));
        appointments[i].description = malloc(200 * sizeof(char));

        printf("Enter name for appointment #%d: ", i+1);
        scanf("%s", appointments[i].name);

        printf("Enter date for appointment #%d (YYYY-MM-DD): ", i+1);
        scanf("%s", appointments[i].date);

        printf("Enter time for appointment #%d (HH:MM AM/PM): ", i+1);
        scanf("%s", appointments[i].time);

        printf("Enter description for appointment #%d:\n", i+1);
        fgets(appointments[i].description, 200, stdin);
        appointments[i].description[strcspn(appointments[i].description, "\n")] = '\0';
    }

    printf("All appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(&appointments[i]);
    }

    return 0;
}