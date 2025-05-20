//FormAI DATASET v1.0 Category: Temperature monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEMP_RECORDS 10

struct TempRecord {
    float temp;
    char time[25];
};

struct TempMonitor {
    char device_name[20];
    struct TempRecord records[MAX_TEMP_RECORDS];
    int num_records;
};

struct TempMonitor create_monitor(char* name) {
    struct TempMonitor monitor;
    strcpy(monitor.device_name, name);
    monitor.num_records = 0;

    return monitor;
}

void add_record(struct TempMonitor* monitor, float temp, char* time) {
    if(monitor->num_records < MAX_TEMP_RECORDS) {
        struct TempRecord record;
        record.temp = temp;
        strcpy(record.time, time);

        monitor->records[monitor->num_records++] = record;
        printf("Record added successfully.\n");
    } else {
        printf("Maximum number of temperature records reached!\n");
    }
}

void print_records(struct TempMonitor* monitor) {
    printf("Temperature records for monitor %s:\n", monitor->device_name);

    if(monitor->num_records > 0) {
        for(int i = 0; i < monitor->num_records; i++) {
            printf("%s: %.2fC\n", monitor->records[i].time, monitor->records[i].temp);
        }
    } else {
        printf("No temperature records found.\n");
    }
}

int main() {
    struct TempMonitor monitor = create_monitor("Living Room");
    printf("Welcome to temperature monitor %s.\n", monitor.device_name);

    char time[25];
    float temp;
    char choice = 'y';

    while(tolower(choice) == 'y') {
        printf("Enter temperature (in Celsius): ");
        scanf("%f", &temp);
        printf("Enter time (yyyy-mm-dd hh:mm:ss): ");
        scanf("%s", time);

        add_record(&monitor, temp, time);

        printf("Do you want to add another record? (y/n) ");
        scanf(" %c", &choice);
    }

    print_records(&monitor);

    return 0;
}