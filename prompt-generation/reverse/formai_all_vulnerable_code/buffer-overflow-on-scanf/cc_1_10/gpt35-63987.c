//FormAI DATASET v1.0 Category: Error handling ; Style: statistical
#include <stdio.h>

double find_mean(int arr[], int n) {
    double sum = 0.0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }
    return sum/n;
}

double find_standard_deviation(int arr[], int n, double mean) {
    double sum = 0.0;
    for(int i=0; i<n; i++) {
        sum += (arr[i] - mean) * (arr[i] - mean);
    }
    double variance = sum/n;
    return sqrt(variance);
}

void handle_error(int err_code) {
    if(err_code == 1) {
        printf("Error: Array size should be at least 10\n");
    } else if(err_code == 2) {
        printf("Error: Array elements should be between 0 and 100\n");
    } else if(err_code == 3) {
        printf("Error: Invalid input, please enter a number\n");
    } else if(err_code == 4) {
        printf("Error: Invalid choice, please enter 1 or 2\n");
    } else if(err_code == 5) {
        printf("Error: Unexpected error occurred, please try again later\n");
    } else {
        printf("Error: Unknown error occurred\n");
    }
}

int main() {
    int arr[100];
    int n;

    printf("Enter the size of the array (at least 10): ");
    if(scanf("%d", &n) != 1) {
        handle_error(3);
        return 1;
    }
    if(n < 10) {
        handle_error(1);
        return 1;
    }

    printf("Enter the elements of the array (between 0 and 100):\n");
    for(int i=0; i<n; i++) {
        if(scanf("%d", &arr[i]) != 1) {
            handle_error(3);
            return 1;
        }
        if(arr[i] < 0 || arr[i] > 100) {
            handle_error(2);
            return 1;
        }
    }

    printf("Choose an option:\n");
    printf("1. Find mean\n");
    printf("2. Find standard deviation\n");
    int choice;
    if(scanf("%d", &choice) != 1) {
        handle_error(3);
        return 1;
    }
    if(choice != 1 && choice != 2) {
        handle_error(4);
        return 1;
    }

    double result;
    if(choice == 1) {
        result = find_mean(arr, n);
    } else {
        double mean = find_mean(arr, n);
        result = find_standard_deviation(arr, n, mean);
    }
    printf("Result: %.2f\n", result);
    return 0;
}