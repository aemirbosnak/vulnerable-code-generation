//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ITEMS 100
#define MAX_THREADS 4

typedef struct {
    int value;
    int weight;
    float ratio; // Value-to-weight ratio
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
    int capacity;
    float totalValue;
} ThreadData;

int threadCount = 0;
pthread_mutex_t mutex;

void* knapsackThread(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int cap = data->capacity;
    float totalValue = 0;
    int i;

    for(i = 0; i < data->itemCount; i++) {
        if(data->items[i].weight <= cap) {
            // If the item can be fully accommodated
            totalValue += data->items[i].value;
            cap -= data->items[i].weight;
        } else {
            // Take the fraction of the item
            totalValue += data->items[i].ratio * cap;
            break;
        }
    }

    pthread_mutex_lock(&mutex);
    data->totalValue += totalValue;
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

void sortItemsByRatio(Item items[], int count) {
    for(int i = 0; i < count; i++) {
        items[i].ratio = (float)items[i].value / (float)items[i].weight;
    }
    // Simple Bubble Sort for the ratios
    for(int i = 0; i < count - 1; i++) {
        for(int j = 0; j < count - i - 1; j++) {
            if(items[j].ratio < items[j + 1].ratio) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main() {
    pthread_t threads[MAX_THREADS];
    ThreadData threadData[MAX_THREADS];
    Item items[MAX_ITEMS];
    int itemCount, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &itemCount);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    
    for(int i = 0; i < itemCount; i++) {
        printf("Enter the value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    // Sort items by value-to-weight ratio
    sortItemsByRatio(items, itemCount);

    // Initialize thread data
    int itemsPerThread = itemCount / MAX_THREADS;
    for(int i = 0; i < MAX_THREADS; i++) {
        threadData[i].capacity = capacity;
        threadData[i].itemCount = (i == MAX_THREADS - 1) ? itemCount - (itemsPerThread * i) : itemsPerThread;
        threadData[i].totalValue = 0;

        for(int j = 0; j < threadData[i].itemCount; j++) {
            threadData[i].items[j] = items[i * itemsPerThread + j];
        }

        // Create threads
        pthread_create(&threads[i], NULL, knapsackThread, &threadData[i]);
    }

    // Wait for threads to finish
    for(int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    float finalValue = 0;
    for(int i = 0; i < MAX_THREADS; i++) {
        finalValue += threadData[i].totalValue;
    }

    printf("Maximum value in Knapsack = %.2f\n", finalValue);
    
    pthread_mutex_destroy(&mutex);  
    return 0;
}