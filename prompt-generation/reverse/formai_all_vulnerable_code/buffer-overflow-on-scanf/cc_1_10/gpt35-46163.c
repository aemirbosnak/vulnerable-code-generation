//FormAI DATASET v1.0 Category: Stock market tracker ; Style: active
#include<stdio.h>
#define MAX 100

// function to find the maximum amongst two values
int max(int a, int b) {
    return (a > b) ? a : b;
}

// function to find the minimum amongst two values
int min(int a, int b) {
    return (a < b) ? a : b;
}

// function to print the stock values for a given day
void printDayValues(int day, int stockValues[MAX]) {
    int i;
    printf("Values for Day %d: ", day);
    for (i = 0; i < day; i++) {
        printf("%d ", stockValues[i]);
    }
    printf("\n");
}

int main() {
    int stockValues[MAX], diff[MAX], maxDiff = 0, minVal, N, i, j;
    printf("Enter the number of days: ");
    scanf("%d", &N);

    printf("Enter the stock values: ");
    for (i = 0; i < N; i++) {
        scanf("%d", &stockValues[i]);
    }

    minVal = stockValues[0];

    // calculating differences between stock values and keeping track of the minimum values
    for (i = 1; i < N; i++) {
        diff[i] = stockValues[i] - minVal;
        minVal = min(minVal, stockValues[i]);
    }

    // finding the maximum difference between two days' stock values
    for (i = 1; i < N; i++) {
        maxDiff = max(maxDiff, diff[i]);
    }

    if (maxDiff == 0) {
        printf("No profits can be made.\n");
        return 0;
    }

    // printing the days and stock values where maximum profit can be made
    for (i = 0; i < N; i++) {
        if (diff[i] == maxDiff) {
            printf("Buy on Day %d (Value: %d) ", i, stockValues[i]);
            for (j = i+1; j < N; j++) {
                if (diff[j] == maxDiff || stockValues[j] - stockValues[i] == maxDiff) {
                    printf("Sell on Day %d (Value: %d)\n", j, stockValues[j]);
                    break;
                }
            }
            break;
        }
    }

    // printing the stock values for each day
    for (i = 1; i <= N; i++) {
        printDayValues(i, stockValues);
    }

    return 0;
}