//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH "/sys/class/thermal/thermal_zone0/temp"
#define MAX_TEMP 1000
#define MIN_TEMP 0
#define TEMP_SLEEP_SEC 1
#define TEMP_WARN_SEC 5
#define TEMP_CRIT_SEC 10

int read_temp(void) {
    char temp_str[16];
    FILE *temp_file;
    int temp;

    temp_file = fopen(DEVICE_PATH, "r");
    if (temp_file == NULL) {
        printf("Error: Could not open temperature device file.\n");
        return -1;
    }

    fscanf(temp_file, "%s", temp_str);
    temp = atoi(temp_str) / 1000;

    fclose(temp_file);
    return temp;
}

void print_temp(int temp) {
    if (temp >= MAX_TEMP) {
        printf("Temperature critical: %d°C\n", temp);
    } else if (temp >= MIN_TEMP) {
        printf("Temperature: %d°C\n", temp);
    } else {
        printf("Temperature below range: %d°C\n", temp);
    }
}

int main(void) {
    int temp;
    time_t last_warn_time = 0, last_crit_time = 0;

    while (1) {
        temp = read_temp();
        if (temp == -1) {
            sleep(1);
            continue;
        }

        time_t curr_time = time(NULL);
        if (temp >= MIN_TEMP && temp < MAX_TEMP) {
            if (last_warn_time == 0 || curr_time - last_warn_time >= TEMP_WARN_SEC) {
                last_warn_time = curr_time;
                printf("Temperature warning: %d°C\n", temp);
            }
        } else if (temp >= MAX_TEMP) {
            if (last_crit_time == 0 || curr_time - last_crit_time >= TEMP_CRIT_SEC) {
                last_crit_time = curr_time;
                printf("Temperature critical: %d°C\n", temp);
            }
        }

        sleep(TEMP_SLEEP_SEC);
    }

    return 0;
}