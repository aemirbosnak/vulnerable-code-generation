//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: ultraprecise
// Define the function to solve the fractional knapsack problem using greedy algorithm
int fractionalKnapSack(int W, int wt[], int val[], int n) {
    int i, w;
    float ratio[] = {0.0};

    // Initialize the ratios array with the first element as 1
    ratio[0] = 1.0;

    // Iterate through all items
    for (i = 1; i < n; i++) {
        // Calculate the ratio of the current item
        ratio[i] = (float)val[i] / (float)wt[i];

        // Update the ratios array by comparing the current ratio with the previous ratios
        for (w = W; w >= wt[i]; w--) {
            if ((float)val[i] / (float)wt[i] >= ratio[w - wt[i]]) {
                ratio[w] = (float)val[i] / (float)wt[i];
            }
        }
    }

    // Calculate the maximum value that can be obtained from the given items
    int maxValue = 0;
    for (i = 0; i < n; i++) {
        if (ratio[W] * (float)val[i] > maxValue) {
            maxValue = ratio[W] * (float)val[i];
        }
    }

    // Return the maximum value
    return maxValue;
}

// Define the main function
int main() {
    int W, n, i;
    int wt[] = {10, 20, 30};
    int val[] = {60, 100, 120};
    int capacity = 50;

    // Initialize the number of items
    n = sizeof(val) / sizeof(val[0]);

    // Calculate the maximum value using the fractional knapsack algorithm
    int maxValue = fractionalKnapSack(capacity, wt, val, n);

    // Print the maximum value
    printf("Maximum value: %d\n", maxValue);

    return 0;
}