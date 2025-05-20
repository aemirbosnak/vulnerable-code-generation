//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_USERS 100

// Function prototypes
void collectData(int scores[], int *count);
void analyzeData(int scores[], int count);
void displayStatistics(int scores[], int count);
void sortData(int scores[], int count);
float calculateMean(int scores[], int count);
float calculateMedian(int scores[], int count);
int calculateMode(int scores[], int count);

int main() {
    int scores[MAX_USERS];
    int count = 0;

    printf("Welcome to the User Score Data Mining Program!\n");
    
    collectData(scores, &count);
    analyzeData(scores, count);
    
    return 0;
}

// Function to collect user scores
void collectData(int scores[], int *count) {
    int score;

    printf("Please enter user scores between 0 and 100 (enter -1 to finish):\n");
    while (*count < MAX_USERS) {
        scanf("%d", &score);
        if (score == -1) {
            break;
        }
        if (score >= 0 && score <= 100) {
            scores[(*count)++] = score;
        } else {
            printf("Invalid score! Please enter a score between 0 and 100.\n");
        }
    }
}

// Function to analyze collected data
void analyzeData(int scores[], int count) {
    if (count == 0) {
        printf("No data to analyze.\n");
        return;
    }
    
    printf("\nData Analysis Results:\n");
    displayStatistics(scores, count);
}

// Function to display statistics
void displayStatistics(int scores[], int count) {
    float mean = calculateMean(scores, count);
    float median = calculateMedian(scores, count);
    int mode = calculateMode(scores, count);

    printf("Mean Score: %.2f\n", mean);
    printf("Median Score: %.2f\n", median);
    printf("Mode Score: %d\n", mode);
}

// Function to calculate mean
float calculateMean(int scores[], int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += scores[i];
    }
    return (float)sum / count;
}

// Function to calculate median
float calculateMedian(int scores[], int count) {
    sortData(scores, count);
    
    if (count % 2 == 0) {
        return (scores[count / 2 - 1] + scores[count / 2]) / 2.0;
    } else {
        return scores[count / 2];
    }
}

// Function to calculate mode
int calculateMode(int scores[], int count) {
    int maxValue = 0, maxCount = 0;

    for (int i = 0; i < count; i++) {
        int countTemp = 0;

        for (int j = 0; j < count; j++) {
            if (scores[j] == scores[i]) {
                countTemp++;
            }
        }

        if (countTemp > maxCount) {
            maxCount = countTemp;
            maxValue = scores[i];
        }
    }
    return maxValue;
}

// Function to sort data using Bubble Sort
void sortData(int scores[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (scores[j] > scores[j + 1]) {
                int temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }
}