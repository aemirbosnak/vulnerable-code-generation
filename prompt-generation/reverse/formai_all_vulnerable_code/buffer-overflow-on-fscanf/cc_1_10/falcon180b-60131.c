//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char* temperature_file = "temperature.txt";
    FILE* temperature_fp;
    int temperature = 0;
    int previous_temperature = 0;
    time_t last_update_time;
    
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("TEMPERATURE MONITOR - POST-APOCALYPTIC EDITION\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    
    temperature_fp = fopen(temperature_file, "r");
    
    if (temperature_fp!= NULL) {
        fscanf(temperature_fp, "%d", &temperature);
        fclose(temperature_fp);
    } else {
        printf("Error: Temperature file not found!\n");
        exit(1);
    }
    
    printf("Current Temperature: %d C\n", temperature);
    
    while (1) {
        time(&last_update_time);
        sleep(10);
        temperature_fp = fopen(temperature_file, "r");
        
        if (temperature_fp!= NULL) {
            fscanf(temperature_fp, "%d", &temperature);
            fclose(temperature_fp);
        } else {
            printf("Error: Temperature file not found!\n");
            exit(1);
        }
        
        if (temperature!= previous_temperature) {
            printf("Temperature Update: %d C\n", temperature);
            printf("Last Updated: %s", ctime(&last_update_time));
        }
        
        previous_temperature = temperature;
    }
    
    return 0;
}