//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct appointment {
    char name[50];
    char description[100];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} appointment;

int compare_appointments(const void *a, const void *b) {
    const appointment *appt1 = (const appointment *)a;
    const appointment *appt2 = (const appointment *)b;

    if (appt1->year != appt2->year) {
        return appt1->year - appt2->year;
    } else if (appt1->month != appt2->month) {
        return appt1->month - appt2->month;
    } else if (appt1->day != appt2->day) {
        return appt1->day - appt2->day;
    } else if (appt1->hour != appt2->hour) {
        return appt1->hour - appt2->hour;
    } else {
        return appt1->minute - appt2->minute;
    }
}

void print_appointment(const appointment *appt) {
    printf("%s: %s (%02d/%02d/%04d %02d:%02d)\n",
           appt->name, appt->description,
           appt->day, appt->month, appt->year,
           appt->hour, appt->minute);
}

int main() {
    // Wow! Check out this awesome array of appointments!
    appointment appointments[] = {
        {"Dentist", "Checkup", 15, 3, 2023, 10, 30},
        {"Doctor", "Physical", 20, 4, 2023, 14, 0},
        {"Haircut", "Trim", 1, 5, 2023, 16, 30},
        {"Movie", "The Godfather", 10, 6, 2023, 19, 0},
        {"Dinner", "Anniversary", 24, 6, 2023, 18, 30}
    };

    // Whoa, there are so many appointments!
    int num_appointments = sizeof(appointments) / sizeof(appointment);

    // Let's sort them out so we can see them clearly!
    qsort(appointments, num_appointments, sizeof(appointment), compare_appointments);

    // Ta-da! Here's your sorted list of appointments!
    puts("Upcoming Appointments:");
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(&appointments[i]);
    }

    puts("");

    // Wait, what's this? A new appointment just popped up!
    appointment new_appointment;
    strcpy(new_appointment.name, "Urgent Meeting");
    strcpy(new_appointment.description, "Discuss important project");
    new_appointment.day = 12;
    new_appointment.month = 5;
    new_appointment.year = 2023;
    new_appointment.hour = 11;
    new_appointment.minute = 0;

    // Oh no! We need to add it to the sorted list!
    appointments[num_appointments] = new_appointment;
    num_appointments++;

    // Phew! Got it!
    qsort(appointments, num_appointments, sizeof(appointment), compare_appointments);

    puts("Updated Appointments:");
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(&appointments[i]);
    }

    return 0;
}