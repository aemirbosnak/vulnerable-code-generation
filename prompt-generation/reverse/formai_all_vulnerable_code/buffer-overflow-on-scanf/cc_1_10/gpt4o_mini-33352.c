//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_COINS 10
#define THREAD_COUNT 10

typedef struct {
    int value; // Value of the coin
    int amount; // Amount to make change for
    int minCoins; // Minimum coins needed for that amount
} ThreadData;

// Function for the greedy algorithm to find minimum coins
void* findMinCoins(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int currentValue = data->value;
    int requiredAmount = data->amount;

    // Greedy approach
    int count = 0;
    while (requiredAmount >= currentValue) {
        requiredAmount -= currentValue;
        count++;
    }
    
    data->minCoins = count;
    return NULL;
}

int main() {
    int amount, denominations[MAX_COINS];
    pthread_t threads[MAX_COINS];
    ThreadData threadData[MAX_COINS];
    int coinCount = 0;

    // Prompt user for the amount
    printf("Enter the amount for which to make change: ");
    scanf("%d", &amount);

    // Input denominations
    printf("Enter number of different denominations: ");
    scanf("%d", &coinCount);

    printf("Enter the denominations:\n");
    for (int i = 0; i < coinCount; i++) {
        scanf("%d", &denominations[i]);
    }

    // Create threads to find minimum coins for each denomination
    for (int i = 0; i < coinCount; i++) {
        threadData[i].value = denominations[i];
        threadData[i].amount = amount;
        threadData[i].minCoins = 0;
        
        if (pthread_create(&threads[i], NULL, findMinCoins, (void*)&threadData[i]) != 0) {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }

    // Wait for all threads to finish and retrieve results
    int totalCoins = 0;
    for (int i = 0; i < coinCount; i++) {
        pthread_join(threads[i], NULL);
        totalCoins += threadData[i].minCoins;
    }

    // Display results
    printf("Minimum number of coins needed: %d\n", totalCoins);

    return 0;
}