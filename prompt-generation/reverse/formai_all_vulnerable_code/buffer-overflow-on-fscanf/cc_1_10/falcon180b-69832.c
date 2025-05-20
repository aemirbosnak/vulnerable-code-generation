//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DATA_SIZE 100
#define MAX_NUM_DATA 10

typedef struct {
    int data[MAX_DATA_SIZE];
    int num_data;
} Data;

void read_data(Data *data) {
    char filename[20];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%d", &data->data[i])!= EOF) {
        i++;
    }
    data->num_data = i;

    fclose(file);
}

void print_data(Data *data) {
    for (int i = 0; i < data->num_data; i++) {
        printf("%d ", data->data[i]);
    }
    printf("\n");
}

void calculate_mean(Data *data, double *mean) {
    *mean = 0.0;
    for (int i = 0; i < data->num_data; i++) {
        *mean += data->data[i];
    }
    *mean /= data->num_data;
}

void calculate_std_dev(Data *data, double *std_dev) {
    *std_dev = 0.0;
    double mean;
    calculate_mean(data, &mean);

    for (int i = 0; i < data->num_data; i++) {
        *std_dev += pow(data->data[i] - mean, 2.0);
    }
    *std_dev = sqrt(*std_dev / data->num_data);
}

int main() {
    Data data;
    read_data(&data);
    print_data(&data);

    double mean, std_dev;
    calculate_mean(&data, &mean);
    printf("Mean: %.2lf\n", mean);

    calculate_std_dev(&data, &std_dev);
    printf("Standard deviation: %.2lf\n", std_dev);

    return 0;
}