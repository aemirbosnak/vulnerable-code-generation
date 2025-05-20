//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TEMP_SENSORS 10
#define MAX_TEMP_DATA 100

typedef struct {
    char name[20];
    float temp;
    time_t timestamp;
} TempData;

TempData tempData[MAX_TEMP_DATA];
int tempDataIndex = 0;

void initTempData() {
    memset(tempData, 0, sizeof(tempData));
    tempDataIndex = 0;
}

void addTempData(char *name, float temp) {
    if (tempDataIndex >= MAX_TEMP_DATA) {
        printf("Error: Temp data buffer is full.\n");
        return;
    }

    strncpy(tempData[tempDataIndex].name, name, 20);
    tempData[tempDataIndex].temp = temp;
    tempData[tempDataIndex].timestamp = time(NULL);
    tempDataIndex++;
}

void printTempData() {
    printf("Temperature data:\n");
    printf("-----------------\n");
    for (int i = 0; i < tempDataIndex; i++) {
        printf("%s %.2f°C %s\n", tempData[i].name, tempData[i].temp, ctime(&tempData[i].timestamp));
    }
}

int main() {
    initTempData();

    char tempSensorName[20];
    float temp;

    while (1) {
        printf("Enter temp sensor name: ");
        scanf("%s", tempSensorName);

        if (strcmp(tempSensorName, "exit") == 0) {
            break;
        }

        printf("Enter temp in °C: ");
        scanf("%f", &temp);

        addTempData(tempSensorName, temp);
    }

    printTempData();

    return 0;
}