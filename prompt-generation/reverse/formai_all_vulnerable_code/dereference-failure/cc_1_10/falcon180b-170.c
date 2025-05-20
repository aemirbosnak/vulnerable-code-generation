//Falcon-180B DATASET v1.0 Category: File handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_DATA 1000000
#define MAX_STATS 10

struct data {
    int value;
    time_t timestamp;
};

struct stats {
    double mean;
    double deviation;
    double min;
    double max;
};

FILE *data_file;
FILE *stats_file;

void init() {
    data_file = fopen("data.txt", "wb");
    stats_file = fopen("stats.txt", "wb");
    if (data_file == NULL || stats_file == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }
}

void write_data(int value) {
    struct data data;
    data.value = value;
    data.timestamp = time(NULL);
    fwrite(&data, sizeof(struct data), 1, data_file);
}

void close_files() {
    fclose(data_file);
    fclose(stats_file);
}

void print_stats() {
    struct stats stats;
    int num_data = 0;
    double sum = 0;
    double squared_sum = 0;
    double mean;
    double deviation;
    double min;
    double max;
    FILE *stats_file_read = fopen("stats.txt", "rb");
    if (stats_file_read == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }
    fread(&stats, sizeof(struct stats), 1, stats_file_read);
    fclose(stats_file_read);
    mean = stats.mean;
    deviation = stats.deviation;
    min = stats.min;
    max = stats.max;
    printf("Mean: %.2f\n", mean);
    printf("Deviation: %.2f\n", deviation);
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
}

int main() {
    init();
    srand(time(NULL));
    for (int i = 0; i < MAX_DATA; i++) {
        write_data(rand() % 100);
    }
    close_files();
    print_stats();
    return 0;
}