//FormAI DATASET v1.0 Category: Temperature monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEMP 100.0
#define MIN_TEMP 0.0
#define MAX_HOURS 24

typedef struct TemperatureRecord {
    float temperature;
    int hour;
} TemperatureRecord;

void print_temperature_records(TemperatureRecord* records, int num_records) {
    printf("Temperature Record\n");
    printf("-------------------\n");
    for(int i=0;i<num_records;i++) {
        printf("Hour %d: %.2f degrees Celsius\n", records[i].hour, records[i].temperature);
    }
}

void print_daily_stats(TemperatureRecord* records, int num_records) {
    float max_temp = records[0].temperature;
    float min_temp = records[0].temperature;
    float total_temp = 0.0;
    for(int i=0;i<num_records;i++) {
        float temp = records[i].temperature;
        if(temp > max_temp) {
            max_temp = temp;
        }
        if(temp < min_temp) {
            min_temp = temp;
        }
        total_temp += temp;
    }
    float avg_temp = total_temp/num_records;
    printf("Daily Stats\n");
    printf("-----------\n");
    printf("Max temp: %.2f degrees Celsius\n", max_temp);
    printf("Min temp: %.2f degrees Celsius\n", min_temp);
    printf("Average temp: %.2f degrees Celsius\n", avg_temp);
}

int main() {
    TemperatureRecord* records = (TemperatureRecord*) malloc(MAX_HOURS * sizeof(TemperatureRecord));
    memset(records, 0, MAX_HOURS * sizeof(TemperatureRecord));

    printf("Temperature Monitor\n");
    printf("Enter temperature readings for the day.\n");
    printf("Enter -999 to end and generate stats.\n");
    int count = 0;
    float temperature;
    do {
        printf("Hour %d: ", count+1);
        scanf("%f", &temperature);
        if(temperature!=-999) {
            if(temperature<MIN_TEMP) {
                printf("Temperature cannot be lower than %.2f degrees Celsius.\n", MIN_TEMP);
            } 
            else if(temperature>MAX_TEMP) {
                printf("Temperature cannot be higher than %.2f degrees Celsius.\n", MAX_TEMP);
            }
            else {
                records[count].temperature = temperature;
                records[count].hour = count+1;
                count++;
            }
        }
    } while(temperature!=-999 && count<MAX_HOURS);

    print_temperature_records(records, count);
    print_daily_stats(records, count);
    free(records);
    return 0;
}