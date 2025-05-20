//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char name[20];
    int temp;
    time_t timestamp;
} SensorData;

int read_sensor_data(SensorData *sensor_data) {
    printf("Enter sensor name: ");
    scanf("%s", sensor_data->name);

    printf("Enter temperature: ");
    scanf("%d", &sensor_data->temp);

    time(&sensor_data->timestamp);

    return 0;
}

int write_to_file(SensorData *sensor_data) {
    FILE *file;
    file = fopen("sensor_data.txt", "a");

    if (file == NULL) {
        printf("Error opening file");
        return -1;
    }

    fprintf(file, "Sensor name: %s\n", sensor_data->name);
    fprintf(file, "Temperature: %d\n", sensor_data->temp);
    fprintf(file, "Timestamp: %s\n", ctime(&sensor_data->timestamp));

    fclose(file);
    return 0;
}

int main() {
    SensorData sensor_data;
    char choice;

    do {
        printf("1. Read sensor data\n");
        printf("2. Write to file\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                read_sensor_data(&sensor_data);
                break;
            case '2':
                write_to_file(&sensor_data);
                break;
            case '3':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= '3');

    return 0;
}