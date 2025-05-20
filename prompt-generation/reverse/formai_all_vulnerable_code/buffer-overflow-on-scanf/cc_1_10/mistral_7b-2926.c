//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#define MAX_APPOINTMENTS 10

typedef struct {
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

typedef struct {
    Appointment data[MAX_APPOINTMENTS];
    int head;
    int tail;
} CircularBuffer;

CircularBuffer cb;

void initCircularBuffer() {
    cb.head = 0;
    cb.tail = 0;
}

int isFull() {
    if ((cb.tail + 1) % MAX_APPOINTMENTS == cb.head) {
        return 1;
    }
    return 0;
}

void addAppointment(Appointment appt) {
    if (isFull()) {
        printf("Calendar is full. Cannot add appointment.\n");
        return;
    }

    cb.data[cb.tail] = appt;
    cb.tail = (cb.tail + 1) % MAX_APPOINTMENTS;
}

void printAppointments() {
    int i;

    if (cb.head == cb.tail) {
        printf("Calendar is empty.\n");
        return;
    }

    printf("Appointments:\n");
    for (i = cb.head; i != cb.tail; i = (i + 1) % MAX_APPOINTMENTS) {
        printf("%02d/%02d/%d %d:%02d -\n", cb.data[i].month, cb.data[i].day, cb.data[i].year, cb.data[i].hour, cb.data[i].minute);
    }
}

int main() {
    Appointment appt;
    initCircularBuffer();

    printf("Enter appointments (format: day month year hour minute):\n");
    while (1) {
        scanf("%d%d%d%d%d", &appt.day, &appt.month, &appt.year, &appt.hour, &appt.minute);

        if (appt.month == 0 || appt.day == 0) {
            break;
        }

        addAppointment(appt);
    }

    printAppointments();

    return 0;
}