//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    char name[50];
    int startTime;
    int endTime;
} Appointment;

typedef struct {
    int id;
    char name[50];
    int duration;
} Meeting;

void addAppointment(Appointment *appointments, int numAppointments, Appointment newAppointment) {
    if (numAppointments < 100) {
        appointments[numAppointments].id = newAppointment.id;
        strcpy(appointments[numAppointments].name, newAppointment.name);
        appointments[numAppointments].startTime = newAppointment.startTime;
        appointments[numAppointments].endTime = newAppointment.endTime;
        numAppointments++;
    } else {
        printf("Appointment queue is full. Please try again later.\n");
    }
}

void deleteAppointment(Appointment *appointments, int numAppointments, int appointmentId) {
    if (appointmentId >= 0 && appointmentId < numAppointments) {
        for (int i = appointmentId; i < numAppointments - 1; i++) {
            appointments[i] = appointments[i + 1];
        }
        numAppointments--;
    } else {
        printf("Invalid appointment ID. Please try again.\n");
    }
}

void printAppointments(Appointment *appointments, int numAppointments) {
    printf("Appointment List:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("ID: %d, Name: %s, Start Time: %d, End Time: %d\n",
               appointments[i].id, appointments[i].name, appointments[i].startTime,
               appointments[i].endTime);
    }
}

void addMeeting(Meeting *meetings, int numMeetings, Meeting newMeeting) {
    if (numMeetings < 100) {
        meetings[numMeetings].id = newMeeting.id;
        strcpy(meetings[numMeetings].name, newMeeting.name);
        meetings[numMeetings].duration = newMeeting.duration;
        numMeetings++;
    } else {
        printf("Meeting queue is full. Please try again later.\n");
    }
}

void deleteMeeting(Meeting *meetings, int numMeetings, int meetingId) {
    if (meetingId >= 0 && meetingId < numMeetings) {
        for (int i = meetingId; i < numMeetings - 1; i++) {
            meetings[i] = meetings[i + 1];
        }
        numMeetings--;
    } else {
        printf("Invalid meeting ID. Please try again.\n");
    }
}

void printMeetings(Meeting *meetings, int numMeetings) {
    printf("Meeting List:\n");
    for (int i = 0; i < numMeetings; i++) {
        printf("ID: %d, Name: %s, Duration: %d\n",
               meetings[i].id, meetings[i].name, meetings[i].duration);
    }
}

int main() {
    Appointment appointments[100];
    int numAppointments = 0;
    Meeting meetings[100];
    int numMeetings = 0;

    srand(time(NULL));

    while (1) {
        printf("Enter 'a' to add an appointment or'm' to add a meeting:\n");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'a') {
            printf("Enter appointment ID (0-99):\n");
            int appointmentId;
            scanf(" %d", &appointmentId);

            printf("Enter appointment name:\n");
            char appointmentName[50];
            scanf(" %s", appointmentName);

            printf("Enter appointment start time (HH:MM):\n");
            char appointmentStartTime[10];
            scanf(" %s", appointmentStartTime);

            printf("Enter appointment end time (HH:MM):\n");
            char appointmentEndTime[10];
            scanf(" %s", appointmentEndTime);

            Appointment newAppointment = {
               .id = appointmentId,
               .name = strdup(appointmentName),
               .startTime = atoi(appointmentStartTime),
               .endTime = atoi(appointmentEndTime)
            };

            addAppointment(appointments, numAppointments, newAppointment);
        } else if (choice =='m') {
            printf("Enter meeting ID (0-99):\n");
            int meetingId;
            scanf(" %d", &meetingId);

            printf("Enter meeting name:\n");
            char meetingName[50];
            scanf(" %s", meetingName);

            printf("Enter meeting duration (minutes):\n");
            int meetingDuration;
            scanf(" %d", &meetingDuration);

            Meeting newMeeting = {
               .id = meetingId,
               .name = strdup(meetingName),
               .duration = meetingDuration
            };

            addMeeting(meetings, numMeetings, newMeeting);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printAppointments(appointments, numAppointments);
    printMeetings(meetings, numMeetings);

    return 0;
}