//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int id;
    float resource_value;
} Resource;

void fill_resources(Resource *resources, int count) {
    for (int i = 0; i < count; i++) {
        resources[i].id = i + 1;  // Assign a unique ID
        resources[i].resource_value = rand() % 1000 + (float)(rand() % 100) / 100; // Random resource value
    }
}

void quicksort(Resource resources[], int left, int right) {
    int i = left, j = right;
    Resource tmp;
    Resource pivot = resources[(left + right) / 2];

    while (i <= j) {
        while (resources[i].resource_value < pivot.resource_value)
            i++;
        while (resources[j].resource_value > pivot.resource_value)
            j--;
        if (i <= j) {
            tmp = resources[i];
            resources[i] = resources[j];
            resources[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j)
        quicksort(resources, left, j);
    if (i < right)
        quicksort(resources, i, right);
}

void benchmark_sort(int size) {
    Resource resources[MAX_SIZE];
    fill_resources(resources, size);
    
    clock_t start = clock();
    
    quicksort(resources, 0, size - 1);
    
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("Benchmark complete: Sorted %d resources in %f seconds.\n", size, time_spent);
}

void apocalypse_mode() {
    printf("=== Wasteland Resource Loader ===\n");
  
    int resource_count;
    printf("Enter the number of resources to sort (1 to %d): ", MAX_SIZE);
    scanf("%d", &resource_count);
    
    if (resource_count < 1 || resource_count > MAX_SIZE) {
        printf("Invalid resource count! Please enter a number between 1 and %d.\n", MAX_SIZE);
        return;
    }
    
    benchmark_sort(resource_count);
  
    printf("Resources sorted. Trust in the survival of the fittest!\n");
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    apocalypse_mode();  // Enter the bleak world of resource management
    return 0;
}