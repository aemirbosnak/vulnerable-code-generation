//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TEMP_SAMPLES 1000
#define TEMP_FILE "temperature.txt"

struct temp_data {
    time_t timestamp;
    double temperature;
};

void read_temp_data(FILE *fp, struct temp_data *data, int *count) {
    char line[50];
    while (fgets(line, sizeof(line), fp)) {
        if (*count >= MAX_TEMP_SAMPLES) {
            break;
        }
        sscanf(line, "%ld %lf", &data[*count].timestamp, &data[*count].temperature);
        (*count)++;
    }
}

void write_temp_data(FILE *fp, struct temp_data data) {
    time_t now = time(NULL);
    fprintf(fp, "%ld %lf\n", now, data.temperature);
}

int main() {
    FILE *fp;
    struct temp_data data[MAX_TEMP_SAMPLES];
    int count = 0;
    double avg_temp = 0;

    if ((fp = fopen(TEMP_FILE, "r"))!= NULL) {
        read_temp_data(fp, data, &count);
        fclose(fp);
    }

    while (1) {
        time_t now = time(NULL);
        double current_temp = (double)now / 1000; // assuming temperature changes every second

        if (count >= MAX_TEMP_SAMPLES) {
            data[count - 1].timestamp = now;
            data[count - 1].temperature = current_temp;
            write_temp_data(fp, data[count - 1]);
            count--;
        } else {
            data[count].timestamp = now;
            data[count].temperature = current_temp;
            write_temp_data(fp, data[count]);
            count++;
        }

        avg_temp = 0;
        for (int i = 0; i < count; i++) {
            avg_temp += data[i].temperature;
        }
        avg_temp /= count;

        printf("Current temperature: %.2lf\n", current_temp);
        printf("Average temperature: %.2lf\n", avg_temp);
        printf("Minimum temperature: %.2lf\n", data[0].temperature);
        printf("Maximum temperature: %.2lf\n", data[count - 1].temperature);

        sleep(1);
    }

    return 0;
}