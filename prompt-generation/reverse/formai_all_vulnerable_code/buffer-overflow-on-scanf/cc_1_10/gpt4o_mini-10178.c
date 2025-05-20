//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
    double numbers[MAX_SIZE];
    int count;
} NumberSeries;

void initializeSeries(NumberSeries *series) {
    series->count = 0;
}

void addNumber(NumberSeries *series, double number) {
    if (series->count < MAX_SIZE) {
        series->numbers[series->count] = number;
        series->count++;
    } else {
        printf("Cannot add more numbers, series is full.\n");
    }
}

double calculateMean(NumberSeries *series) {
    if (series->count == 0) return 0.0;

    double sum = 0.0;
    for (int i = 0; i < series->count; i++) {
        sum += series->numbers[i];
    }
    return sum / series->count;
}

double calculateVariance(NumberSeries *series, double mean) {
    double variance = 0.0;
    for (int i = 0; i < series->count; i++) {
        variance += pow(series->numbers[i] - mean, 2);
    }
    return variance / series->count;
}

double calculateStandardDeviation(double variance) {
    return sqrt(variance);
}

void displayNumbers(NumberSeries *series) {
    printf("Numbers in the series:\n");
    for (int i = 0; i < series->count; i++) {
        printf("%lf ", series->numbers[i]);
    }
    printf("\n");
}

void displayResults(NumberSeries *series) {
    double mean = calculateMean(series);
    double variance = calculateVariance(series, mean);
    double stddev = calculateStandardDeviation(variance);

    printf("Results:\n");
    printf("Mean: %lf\n", mean);
    printf("Variance: %lf\n", variance);
    printf("Standard Deviation: %lf\n", stddev);
}

int main() {
    NumberSeries series;
    initializeSeries(&series);

    printf("Welcome to the Arithmetic Series Calculator!\n");
    printf("Enter numbers to add to the series (enter -1 to stop):\n");

    double input;
    while (1) {
        printf("Enter a number: ");
        scanf("%lf", &input);
        if (input == -1) break;

        addNumber(&series, input);
    }

    if (series.count > 0) {
        displayNumbers(&series);
        displayResults(&series);
    } else {
        printf("No numbers were entered!\n");
    }

    return 0;
}