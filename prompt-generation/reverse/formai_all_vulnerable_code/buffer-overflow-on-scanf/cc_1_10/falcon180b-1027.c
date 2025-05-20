//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_DATA_POINTS 100
#define MAX_DATA_POINT_SIZE 50

typedef struct {
    char name[MAX_DATA_POINT_SIZE];
    float value;
    time_t timestamp;
} DataPoint;

void logData(DataPoint* data, int dataCount, char* fileName) {
    FILE* file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < dataCount; i++) {
        fprintf(file, "%s,%.2f,%ld\n", data[i].name, data[i].value, data[i].timestamp);
    }

    fclose(file);
}

int main() {
    DataPoint data[MAX_DATA_POINTS];
    int dataCount = 0;
    char fileName[MAX_DATA_POINT_SIZE];

    printf("Enter file name (without extension): ");
    scanf("%s", fileName);
    strcat(fileName, ".csv");

    while (1) {
        printf("\nSelect an option:\n1. Add data\n2. View data\n3. Log data\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (dataCount >= MAX_DATA_POINTS) {
                    printf("Error: Maximum data points reached.\n");
                } else {
                    printf("Enter data name: ");
                    scanf("%s", data[dataCount].name);
                    printf("Enter data value: ");
                    scanf("%f", &data[dataCount].value);
                    data[dataCount].timestamp = time(NULL);
                    dataCount++;
                }
                break;

            case 2:
                if (dataCount == 0) {
                    printf("No data available.\n");
                } else {
                    printf("\nData:\n");
                    for (int i = 0; i < dataCount; i++) {
                        printf("%s, %.2f, %s\n", data[i].name, data[i].value, ctime(&data[i].timestamp));
                    }
                }
                break;

            case 3:
                logData(data, dataCount, fileName);
                printf("Data logged to file.\n");
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}