//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DATA_POINTS 100
#define TRUE 1
#define FALSE 0

typedef struct {
    double data[MAX_DATA_POINTS];
    int count;
} Statistics;

// Function prototypes
void addDataPoint(Statistics* stats, double value);
double calculateMean(Statistics* stats);
double calculateMedian(Statistics* stats);
double calculateVariance(Statistics* stats);
double calculateStandardDeviation(Statistics* stats);
void sortData(Statistics* stats);
void displayMenu();
void clearBuffer();

int main() {
    Statistics stats = {{0}, 0};
    int choice;
    double input;

    while (TRUE) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter a data point: ");
                scanf("%lf", &input);
                addDataPoint(&stats, input);
                printf("Data point %lf added.\n", input);
                break;
                
            case 2:
                if (stats.count > 0) {
                    printf("Mean: %lf\n", calculateMean(&stats));
                } else {
                    printf("No data points available.\n");
                }
                break;

            case 3:
                if (stats.count > 0) {
                    printf("Median: %lf\n", calculateMedian(&stats));
                } else {
                    printf("No data points available.\n");
                }
                break;

            case 4:
                if (stats.count > 0) {
                    printf("Variance: %lf\n", calculateVariance(&stats));
                } else {
                    printf("No data points available.\n");
                }
                break;

            case 5:
                if (stats.count > 0) {
                    printf("Standard Deviation: %lf\n", calculateStandardDeviation(&stats));
                } else {
                    printf("No data points available.\n");
                }
                break;

            case 6:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
        clearBuffer();
    }
}

void addDataPoint(Statistics* stats, double value) {
    if (stats->count < MAX_DATA_POINTS) {
        stats->data[stats->count] = value;
        stats->count++;
    } else {
        printf("Data array full, cannot add more data points.\n");
    }
}

double calculateMean(Statistics* stats) {
    double sum = 0.0;
    for (int i = 0; i < stats->count; i++) {
        sum += stats->data[i];
    }
    return sum / stats->count;
}

void sortData(Statistics* stats) {
    for (int i = 0; i < stats->count - 1; i++) {
        for (int j = 0; j < stats->count - i - 1; j++) {
            if (stats->data[j] > stats->data[j + 1]) {
                double temp = stats->data[j];
                stats->data[j] = stats->data[j + 1];
                stats->data[j + 1] = temp;
            }
        }
    }
}

double calculateMedian(Statistics* stats) {
    sortData(stats);
    if (stats->count % 2 == 0) {
        return (stats->data[stats->count / 2 - 1] + stats->data[stats->count / 2]) / 2;
    } else {
        return stats->data[stats->count / 2];
    }
}

double calculateVariance(Statistics* stats) {
    double mean = calculateMean(stats);
    double variance = 0.0;
    
    for (int i = 0; i < stats->count; i++) {
        variance += pow(stats->data[i] - mean, 2);
    }
    return variance / stats->count;
}

double calculateStandardDeviation(Statistics* stats) {
    return sqrt(calculateVariance(stats));
}

void displayMenu() {
    printf("\nStatistics Calculator Menu:\n");
    printf("1. Add Data Point\n");
    printf("2. Calculate Mean\n");
    printf("3. Calculate Median\n");
    printf("4. Calculate Variance\n");
    printf("5. Calculate Standard Deviation\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void clearBuffer() {
    // Flush stdin for unwanted input (in case of invalid input)
    while (getchar() != '\n');
}