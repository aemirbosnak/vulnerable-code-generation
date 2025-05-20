//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_TEMP_HISTORY 100

typedef struct {
    time_t timestamp;
    double temperature;
} TempData;

TempData temp_history[MAX_TEMP_HISTORY];
int temp_history_index = 0;

double get_temperature() {
    double temperature = 0.0;
    FILE *fp = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
    if (fp!= NULL) {
        fscanf(fp, "%lf", &temperature);
        fclose(fp);
    }
    return temperature / 1000.0;
}

void add_to_temp_history(double temperature) {
    temp_history[temp_history_index] = (TempData) {.timestamp = time(NULL),.temperature = temperature};
    temp_history_index = (temp_history_index + 1) % MAX_TEMP_HISTORY;
}

void print_temp_history() {
    printf("Temperature history:\n");
    for (int i = 0; i < MAX_TEMP_HISTORY; i++) {
        TempData temp_data = temp_history[(temp_history_index + i) % MAX_TEMP_HISTORY];
        char timestamp_str[32];
        strftime(timestamp_str, sizeof(timestamp_str), "%Y-%m-%d %H:%M:%S", localtime(&temp_data.timestamp));
        printf("%s: %.2lf\n", timestamp_str, temp_data.temperature);
    }
}

int main() {
    srand(time(NULL));
    setvbuf(stdout, NULL, _IONBF, 0);

    printf("Cyberpunk Temperature Monitor\n");
    printf("=============================\n");

    while (true) {
        double temperature = get_temperature();
        add_to_temp_history(temperature);

        printf("\rCurrent temperature: %.2lf°C", temperature);
        fflush(stdout);

        if (rand() % 100 == 0) {
            print_temp_history();
        }

        usleep(1000000); // 1s
    }

    return 0;
}