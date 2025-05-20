//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define ARRAY_SIZE 20

void paranoid_search(int arr[], int size, int target) {
    int found = 0;
    
    printf("Commencing paranoia-driven search...\n");
    for (int i = 0; i < size; i++) {
        printf("Checking index %d, value: %d...\n", i, arr[i]);
        if (arr[i] == target) {
            printf("Danger! Value %d located at index %d!\n", target, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Whew! Value %d is not here! We can breathe... for now...\n", target);
    }
}

void fill_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random values between 0-99
    }
}

void display_array(int arr[], int size) {
    printf("Current array contents:\n");
    for (int i = 0; i < size; i++) {
        printf("Index %d: %d\n", i, arr[i]);
    }
}

int main() {
    int arr[ARRAY_SIZE];
    int target;
    
    srand(time(NULL)); // Seed for randomness
    fill_array(arr, ARRAY_SIZE);
    display_array(arr, ARRAY_SIZE);
    
    printf("Enter the value you are paranoid about (0-99): ");
    scanf("%d", &target);

    // Input validation
    if (target < 0 || target >= 100) {
        printf("Invalid input! Stay vigilant; the range is 0-99!\n");
        return 1; // Exit if input is out of bounds
    }
    
    paranoid_search(arr, ARRAY_SIZE, target);
    
    // Additional paranoia
    printf("Searching for anything unusual in the array...\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (arr[i] > 90) {
            printf("Alert! Suspiciously high value detected at index %d: %d!\n", i, arr[i]);
        }
    }

    printf("Search completed. Trust but verify!\n");
    return 0;
}