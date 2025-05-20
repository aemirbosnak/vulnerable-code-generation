//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LOG_FILE_SIZE 1000000

struct ocean_data {
    float temperature;
    float salinity;
    float depth;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <log_file_path>\n", argv[0]);
        return 1;
    }

    char *log_file_path = argv[1];
    FILE *log_file = fopen(log_file_path, "r");
    if (!log_file) {
        perror("Error opening log file");
        return 2;
    }

    int line_count = 0;
    struct ocean_data data;

    while (fscanf(log_file, "%f %f %f", &data.temperature, &data.salinity, &data.depth) == 3) {
        line_count++;
    }

    double mean_temperature = 0;
    double mean_salinity = 0;
    double mean_depth = 0;

    for (int i = 0; i < line_count; i++) {
        mean_temperature += data.temperature;
        mean_salinity += data.salinity;
        mean_depth += data.depth;
    }

    mean_temperature /= line_count;
    mean_salinity /= line_count;
    mean_depth /= line_count;

    double standard_deviation_temperature = 0;
    double standard_deviation_salinity = 0;
    double standard_deviation_depth = 0;

    for (int i = 0; i < line_count; i++) {
        double diff_temperature = data.temperature - mean_temperature;
        double diff_salinity = data.salinity - mean_salinity;
        double diff_depth = data.depth - mean_depth;

        standard_deviation_temperature += diff_temperature * diff_temperature;
        standard_deviation_salinity += diff_salinity * diff_salinity;
        standard_deviation_depth += diff_depth * diff_depth;
    }

    standard_deviation_temperature /= line_count;
    standard_deviation_salinity /= line_count;
    standard_deviation_depth /= line_count;

    double skewness_temperature = 0;
    double skewness_salinity = 0;
    double skewness_depth = 0;

    for (int i = 0; i < line_count; i++) {
        double diff_temperature = data.temperature - mean_temperature;
        double diff_salinity = data.salinity - mean_salinity;
        double diff_depth = data.depth - mean_depth;

        skewness_temperature += (diff_temperature * diff_temperature * diff_temperature) / (3 * standard_deviation_temperature * standard_deviation_temperature);
        skewness_salinity += (diff_salinity * diff_salinity * diff_salinity) / (3 * standard_deviation_salinity * standard_deviation_salinity);
        skewness_depth += (diff_depth * diff_depth * diff_depth) / (3 * standard_deviation_depth * standard_deviation_depth);
    }

    skewness_temperature /= line_count;
    skewness_salinity /= line_count;
    skewness_depth /= line_count;

    printf("Mean temperature: %f\n", mean_temperature);
    printf("Standard deviation temperature: %f\n", standard_deviation_temperature);
    printf("Skewness temperature: %f\n", skewness_temperature);

    printf("Mean salinity: %f\n", mean_salinity);
    printf("Standard deviation salinity: %f\n", standard_deviation_salinity);
    printf("Skewness salinity: %f\n", skewness_salinity);

    printf("Mean depth: %f\n", mean_depth);
    printf("Standard deviation depth: %f\n", standard_deviation_depth);
    printf("Skewness depth: %f\n", skewness_depth);

    fclose(log_file);
    return 0;
}