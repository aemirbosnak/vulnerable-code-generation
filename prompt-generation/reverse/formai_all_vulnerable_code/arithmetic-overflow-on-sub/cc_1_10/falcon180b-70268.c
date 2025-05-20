//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TEMPERATURES 100
#define MAX_TEMP_NAME_LENGTH 50

typedef struct {
    char name[MAX_TEMP_NAME_LENGTH];
    int temperature;
    time_t last_checked;
} Temperature;

Temperature temperatures[MAX_TEMPERATURES];
int num_temperatures = 0;

void add_temperature(char* name, int temp) {
    if (num_temperatures >= MAX_TEMPERATURES) {
        printf("Error: maximum number of temperatures reached!\n");
        return;
    }
    strcpy(temperatures[num_temperatures].name, name);
    temperatures[num_temperatures].temperature = temp;
    temperatures[num_temperatures].last_checked = time(NULL);
    num_temperatures++;
}

void check_temperatures() {
    time_t current_time = time(NULL);
    for (int i = 0; i < num_temperatures; i++) {
        Temperature* temp = &temperatures[i];
        if (current_time - temp->last_checked >= 60) {
            int new_temp = rand() % 101;
            temp->temperature = new_temp;
            temp->last_checked = current_time;
        }
        printf("%s: %d degrees\n", temp->name, temp->temperature);
    }
}

int main() {
    srand(time(NULL));
    add_temperature("Core", 50);
    add_temperature("CPU", 60);
    add_temperature("GPU", 70);
    while (1) {
        check_temperatures();
        sleep(60);
    }
    return 0;
}