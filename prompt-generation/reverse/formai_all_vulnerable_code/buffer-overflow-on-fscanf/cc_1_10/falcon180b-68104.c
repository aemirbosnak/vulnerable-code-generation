//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP_SENSORS 10
#define TEMP_DATA_SIZE 100

typedef struct {
    char name[20];
    int temp;
    time_t timestamp;
} TempData;

int read_temp_data(TempData temp_data[], int num_sensors) {
    FILE *temp_file;
    int i;

    for (i = 0; i < num_sensors; i++) {
        sprintf(temp_data[i].name, "sensor_%d", i + 1);
        temp_file = fopen(temp_data[i].name, "r");
        if (temp_file == NULL) {
            printf("Error opening temperature file for sensor %s\n", temp_data[i].name);
            return -1;
        }

        if (fscanf(temp_file, "%d %ld", &temp_data[i].temp, &temp_data[i].timestamp)!= 2) {
            printf("Error reading temperature data from file %s\n", temp_file);
            fclose(temp_file);
            return -1;
        }

        fclose(temp_file);
    }

    return 0;
}

void print_temp_data(TempData temp_data[], int num_sensors) {
    int i;

    for (i = 0; i < num_sensors; i++) {
        printf("%s: %d degrees Celsius at ", temp_data[i].name, temp_data[i].temp);
        printf("%.24s", ctime(&temp_data[i].timestamp));
    }
}

int main() {
    char temp_file_name[20];
    int num_sensors;
    TempData temp_data[MAX_TEMP_SENSORS];

    printf("Enter the number of temperature sensors: ");
    scanf("%d", &num_sensors);

    printf("Enter the name of the temperature data file (without extension): ");
    scanf("%s", temp_file_name);

    sprintf(temp_file_name, "%s.txt", temp_file_name);

    if (read_temp_data(temp_data, num_sensors) == -1) {
        return 1;
    }

    printf("\nTemperature data:\n");
    print_temp_data(temp_data, num_sensors);

    return 0;
}