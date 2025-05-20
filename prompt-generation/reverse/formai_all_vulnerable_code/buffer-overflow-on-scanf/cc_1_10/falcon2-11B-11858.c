//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 5
#define DAYS_OF_WEEK 7

typedef struct {
    int day;
    int time;
    char title[50];
} Appointment;

typedef struct {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments;
} AppointmentBook;

void add_appointment(AppointmentBook *book, int day, int time, const char *title) {
    if (book->num_appointments >= MAX_APPOINTMENTS) {
        printf("Appointment book is full.\n");
        return;
    }

    Appointment new_appointment;
    new_appointment.day = day;
    new_appointment.time = time;
    strcpy(new_appointment.title, title);

    book->appointments[book->num_appointments] = new_appointment;
    book->num_appointments++;

    printf("Added appointment: %s at %02d:%02d on %d.\n", title, time / 100, time % 100, day);
}

void delete_appointment(AppointmentBook *book, int index) {
    if (index < 0 || index >= book->num_appointments) {
        printf("Invalid appointment index.\n");
        return;
    }

    memmove(&book->appointments[index], &book->appointments[index + 1], sizeof(Appointment) * (book->num_appointments - index - 1));
    book->num_appointments--;

    printf("Deleted appointment: %s at %02d:%02d on %d.\n", book->appointments[index].title, book->appointments[index].time / 100, book->appointments[index].time % 100, book->appointments[index].day);
}

void print_appointments(const AppointmentBook *book) {
    if (book->num_appointments == 0) {
        printf("No appointments.\n");
        return;
    }

    printf("Appointments:\n");
    for (int i = 0; i < book->num_appointments; i++) {
        printf("(%02d:%02d) %s\n", book->appointments[i].time / 100, book->appointments[i].time % 100, book->appointments[i].title);
    }
}

void main() {
    srand(time(NULL));

    AppointmentBook book;
    book.num_appointments = 0;

    while (1) {
        printf("Appointment scheduler\n");
        printf("1. Add appointment\n");
        printf("2. Delete appointment\n");
        printf("3. Print appointments\n");
        printf("4. Exit\n");
        printf("> ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter appointment day (1-7): ");
                int day;
                scanf("%d", &day);

                printf("Enter appointment time (00-23): ");
                int time;
                scanf("%d", &time);

                printf("Enter appointment title: ");
                char title[50];
                fgets(title, sizeof(title), stdin);

                add_appointment(&book, day, time, title);
                break;

            case 2:
                printf("Enter appointment index to delete (0-%d): ", book.num_appointments);
                int index;
                scanf("%d", &index);

                delete_appointment(&book, index);
                break;

            case 3:
                print_appointments(&book);
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid choice.\n");
        }
    }
}