//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 1000

// Define a struct to hold a single observation
struct obs {
    int age;
    double weight;
    double height;
};

// Define an array to hold N observations
struct obs obs[N];

// Function to generate random observations
void generate_obs(void) {
    int i;
    for (i = 0; i < N; i++) {
        obs[i].age = (int)(100 * rand() / RAND_MAX);
        obs[i].weight = (double)(100 * rand() / RAND_MAX);
        obs[i].height = (double)(100 * rand() / RAND_MAX);
    }
}

// Function to calculate the mean and standard deviation of the observations
void calculate_stats(void) {
    int i;
    double mean, stddev;
    for (i = 0; i < N; i++) {
        mean += obs[i].age;
        mean += obs[i].weight;
        mean += obs[i].height;
        stddev += pow(obs[i].age - mean, 2);
        stddev += pow(obs[i].weight - mean, 2);
        stddev += pow(obs[i].height - mean, 2);
    }
    mean /= N;
    stddev = sqrt(stddev / N);
    printf("Mean age: %f\n", mean);
    printf("Mean weight: %f\n", mean);
    printf("Mean height: %f\n", mean);
    printf("Standard deviation: %f\n", stddev);
}

int main(void) {
    srand(time(NULL));
    generate_obs();
    calculate_stats();
    return 0;
}