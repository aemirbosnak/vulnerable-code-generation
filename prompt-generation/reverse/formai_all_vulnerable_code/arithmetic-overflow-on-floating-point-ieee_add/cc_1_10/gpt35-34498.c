//FormAI DATASET v1.0 Category: Temperature monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100

// function to generate a random temperature value
float random_temperature() {
    return ((float)rand()/(float)(RAND_MAX)) * 100.0; // generates a value between 0 and 100
}

// function to read the temperature values from a file
void read_values_from_file(char *filename, float temperature_values[]) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0;
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        temperature_values[i++] = atof(line);
    }
    
    fclose(fp);
    if (line) {
        free(line);
    }
}

int main(int argc, char *argv[]) {
    float temperature_values[MAX_SIZE];
    int num_values = 0;
    int i;

    // check if the user provided the temperature values as input arguments
    if (argc > 1) {
        for (i = 1; i < argc; i++) {
            temperature_values[num_values++] = atof(argv[i]);
        }
    }
    // if not, generate some random values
    else {
        srand(time(NULL));
        for (i = 0; i < MAX_SIZE; i++) {
            temperature_values[num_values++] = random_temperature();
        }
    }

    // read the temperature values from a file, if provided
    if (num_values == 0) {
        char *filename;
        printf("Enter the filename to read the temperature values from: ");
        scanf("%s", filename);
        read_values_from_file(filename, temperature_values);
        num_values = i; // i has the number of values read from the file in read_values_from_file() function
    }

    // calculate the average temperature
    float sum = 0.0;
    for (i = 0; i < num_values; i++) {
        sum += temperature_values[i];
    }
    float avg_temperature = sum / num_values;

    // display the results
    printf("The temperature values are: \n");
    for (i = 0; i < num_values; i++) {
        printf("%.2f\n", temperature_values[i]);
    }
    printf("The average temperature is: %.2f\n", avg_temperature);

    return 0;
}