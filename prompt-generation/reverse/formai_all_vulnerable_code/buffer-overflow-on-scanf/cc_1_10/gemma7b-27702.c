//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define APPOINTMENT_BOOK_SIZE 10
#define AVAILABLE 0
#define BOOKED 1

typedef struct Appointment {
    char name[50];
    char date[20];
    char time[20];
    int status;
} Appointment;

void initializeAppointmentBook(Appointment *book) {
    for (int i = 0; i < APPOINTMENT_BOOK_SIZE; i++) {
        book[i].status = AVAILABLE;
    }
}

int bookAppointment(Appointment *book, char *name, char *date, char *time) {
    for (int i = 0; i < APPOINTMENT_BOOK_SIZE; i++) {
        if (book[i].status == AVAILABLE) {
            strcpy(book[i].name, name);
            strcpy(book[i].date, date);
            strcpy(book[i].time, time);
            book[i].status = BOOKED;
            return 0;
        }
    }

    return -1;
}

int main() {
    Appointment book[APPOINTMENT_BOOK_SIZE];
    initializeAppointmentBook(book);

    char name[50];
    char date[20];
    char time[20];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the date: ");
    scanf("%s", date);

    printf("Enter the time: ");
    scanf("%s", time);

    int result = bookAppointment(book, name, date, time);

    if (result == 0) {
        printf("Appointment booked successfully!\n");
    } else {
        printf("Error booking appointment.\n");
    }

    return 0;
}