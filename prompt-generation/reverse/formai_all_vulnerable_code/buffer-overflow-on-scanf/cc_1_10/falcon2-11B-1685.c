//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: genius
#include <stdio.h>
#include <string.h>

void scheduleAppointment(int numOfSlots, char* clientNames[], char* timeSlots[]) {
    int i;
    int j;
    int k;
    char clientName[50];

    printf("Enter the number of clients: ");
    scanf("%d", &numOfSlots);

    printf("Enter the names of the clients: ");
    for (i = 0; i < numOfSlots; i++) {
        scanf("%s", clientName);
        clientNames[i] = clientName;
    }

    printf("Enter the available time slots: ");
    for (i = 0; i < numOfSlots; i++) {
        scanf("%s", timeSlots[i]);
    }

    for (i = 0; i < numOfSlots; i++) {
        for (j = i + 1; j < numOfSlots; j++) {
            for (k = j + 1; k < numOfSlots; k++) {
                if (strcmp(clientNames[i], clientNames[j])!= 0 && strcmp(clientNames[i], clientNames[k])!= 0) {
                    if (strcmp(timeSlots[i], timeSlots[j])!= 0 && strcmp(timeSlots[i], timeSlots[k])!= 0) {
                        if (strcmp(timeSlots[j], timeSlots[k])!= 0) {
                            printf("Conflict between client %s and client %s at time slot %s\n", clientNames[i], clientNames[j], timeSlots[i]);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    char timeSlots[100][50];
    char clientNames[100][50];
    int numOfSlots;

    printf("Enter the number of clients: ");
    scanf("%d", &numOfSlots);

    printf("Enter the names of the clients: ");
    for (int i = 0; i < numOfSlots; i++) {
        scanf("%s", clientNames[i]);
    }

    printf("Enter the available time slots: ");
    for (int i = 0; i < numOfSlots; i++) {
        scanf("%s", timeSlots[i]);
    }

    scheduleAppointment(numOfSlots, clientNames, timeSlots);

    return 0;
}