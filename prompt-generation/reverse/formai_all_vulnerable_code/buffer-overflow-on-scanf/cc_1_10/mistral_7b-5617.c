//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 256
#define MAX_NUM_TIME_POINTS 100

typedef struct TimePoint {
    int year;
    int month;
    int day;
    char description[MAX_LINE_LENGTH];
} TimePoint;

TimePoint timePoints[MAX_NUM_TIME_POINTS];
int numTimePoints = 0;

void printMenu() {
    printf("1. Add time point\n");
    printf("2. Remove time point\n");
    printf("3. Travel to a time point\n");
    printf("4. List time points\n");
    printf("5. Quit\n");
}

void addTimePoint() {
    TimePoint newTimePoint;
    printf("Enter year, month, day and description (max %d characters):\n", MAX_LINE_LENGTH);
    scanf("%d%d%d%s", &newTimePoint.year, &newTimePoint.month, &newTimePoint.day, newTimePoint.description);

    if (strlen(newTimePoint.description) > MAX_LINE_LENGTH) {
        printf("Description too long. Max length: %d\n", MAX_LINE_LENGTH);
        return;
    }

    timePoints[numTimePoints] = newTimePoint;
    numTimePoints++;
}

void removeTimePoint(int index) {
    if (index < 0 || index >= numTimePoints) {
        printf("Invalid index.\n");
        return;
    }

    memmove(&timePoints[index], &timePoints[index + 1], sizeof(TimePoint) * (numTimePoints - index - 1));
    numTimePoints--;
}

void travelToTimePoint(int index) {
    struct tm time;
    int hours, minutes, seconds;

    if (index < 0 || index >= numTimePoints) {
        printf("Invalid index.\n");
        return;
    }

    time.tm_year = timePoints[index].year - 1900;
    time.tm_mon = timePoints[index].month - 1;
    time.tm_mday = timePoints[index].day;
    time.tm_hour = 0;
    time.tm_min = 0;
    time.tm_sec = 0;

    mktime(&time);

    printf("Traveling to %d-%02d-%02d...\n", timePoints[index].year, timePoints[index].month, timePoints[index].day);
    printf("New time: %s", ctime(&time));
    printf("Description: %s\n", timePoints[index].description);
}

void listTimePoints() {
    int i;

    for (i = 0; i < numTimePoints; i++) {
        printf("%d-%02d-%02d: %s\n", timePoints[i].year, timePoints[i].month, timePoints[i].day, timePoints[i].description);
    }
}

int main() {
    int choice;
    int index;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTimePoint();
                break;
            case 2:
                printf("Enter index to remove: ");
                scanf("%d", &index);
                removeTimePoint(index);
                break;
            case 3:
                printf("Enter index to travel to: ");
                scanf("%d", &index);
                travelToTimePoint(index);
                break;
            case 4:
                listTimePoints();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}