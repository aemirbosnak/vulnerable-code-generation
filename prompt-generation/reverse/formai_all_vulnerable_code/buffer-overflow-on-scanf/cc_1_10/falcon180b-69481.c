//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TEMP_HISTORY 100

struct TempHistory {
    int temp;
    time_t timestamp;
};

void printTempHistory(struct TempHistory *history, int count) {
    printf("Temperature history (%d entries):\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d degrees at %s", history[i].temp, ctime(&history[i].timestamp));
    }
}

void addTempToHistory(struct TempHistory *history, int temp) {
    if (history == NULL) {
        printf("Error: Temperature history is empty.\n");
        return;
    }
    if (history->temp == temp) {
        printf("Temperature has not changed.\n");
        return;
    }
    history->temp = temp;
    history->timestamp = time(NULL);
    printf("Temperature changed to %d degrees at %s.\n", temp, ctime(&history->timestamp));
}

int getTempFromUser() {
    int temp;
    printf("Enter current temperature: ");
    scanf("%d", &temp);
    return temp;
}

void main() {
    struct TempHistory tempHistory[MAX_TEMP_HISTORY];
    int tempHistoryCount = 0;
    int currentTemp = getTempFromUser();
    addTempToHistory(tempHistory, currentTemp);
    while (1) {
        int newTemp = getTempFromUser();
        if (newTemp!= currentTemp) {
            addTempToHistory(tempHistory, newTemp);
            currentTemp = newTemp;
        }
        if (tempHistoryCount >= MAX_TEMP_HISTORY) {
            tempHistoryCount--;
        }
        tempHistory[tempHistoryCount] = tempHistory[tempHistoryCount - 1];
    }
}