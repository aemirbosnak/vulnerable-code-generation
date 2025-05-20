//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_MONTHS 12
#define MAX_TEMP 100

typedef struct {
    char name[20];
    int temperature[MAX_MONTHS];
} city_data_t;

city_data_t cities[5];

void read_data(void);
void calculate_means(void);
void print_results(void);

int main(void) {
    read_data();
    calculate_means();
    print_results();
    return 0;
}

void read_data(void) {
    int i, j;
    char filename[20];

    // Read temperature data from file
    for (i = 0; i < 5; i++) {
        sprintf(filename, "temperature_%d.txt", i + 1);
        FILE *file = fopen(filename, "r");
        if (file == NULL) {
            perror("Error opening file");
            exit(1);
        }
        for (j = 0; j < MAX_MONTHS; j++) {
            fscanf(file, "%d", &cities[i].temperature[j]);
        }
        fclose(file);
    }
}

void calculate_means(void) {
    int i, j;
    double total_temp = 0;
    double mean_temp = 0;

    // Calculate the total temperature for each city
    for (i = 0; i < 5; i++) {
        for (j = 0; j < MAX_MONTHS; j++) {
            total_temp += cities[i].temperature[j];
        }
    }

    // Calculate the mean temperature for each city
    for (i = 0; i < 5; i++) {
        mean_temp = total_temp / MAX_MONTHS;
        printf("City %d: mean temperature = %f\n", i + 1, mean_temp);
    }
}

void print_results(void) {
    int i;

    // Print the results for each city
    for (i = 0; i < 5; i++) {
        printf("City %d:", i + 1);
        for (int j = 0; j < MAX_MONTHS; j++) {
            printf(" %d", cities[i].temperature[j]);
        }
        printf("\n");
    }
}