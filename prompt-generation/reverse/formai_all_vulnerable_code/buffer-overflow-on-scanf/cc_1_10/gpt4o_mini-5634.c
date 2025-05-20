//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 100
#define NUM_BUCKETS 10

// Define a fairy structure
typedef struct Fairy {
    int *magicalNumbers;
    int count;
} Fairy;

// Function to create a bucket for the fairy
Fairy* create_bucket() {
    Fairy *newFairy = (Fairy*)malloc(sizeof(Fairy));
    newFairy->magicalNumbers = (int*)malloc(MAX_NUM * sizeof(int));
    newFairy->count = 0;
    return newFairy;
}

// Function to free the memory used by the fairy bucket
void free_bucket(Fairy *fairy) {
    free(fairy->magicalNumbers);
    free(fairy);
}

// The sorting fairy dance with bucket sort
void magic_sort(int *arr, int n) {
    // Create an array of fairies (buckets)
    Fairy **buckets = (Fairy**)malloc(NUM_BUCKETS * sizeof(Fairy*));
    for (int i = 0; i < NUM_BUCKETS; i++) {
        buckets[i] = create_bucket();
    }

    // Place each number into the appropriate fairy bucket
    for (int i = 0; i < n; i++) {
        int index = arr[i] / (MAX_NUM / NUM_BUCKETS);
        if (index >= NUM_BUCKETS) {
            index = NUM_BUCKETS - 1;
        }
        buckets[index]->magicalNumbers[buckets[index]->count++] = arr[i];
    }

    // Collect and sort each fairy's numbers
    int currentIndex = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        if (buckets[i]->count > 0) {
            // Sort the magical numbers in current fairy bucket
            for (int j = 0; j < buckets[i]->count - 1; j++) {
                for (int k = 0; k < buckets[i]->count - j - 1; k++) {
                    if (buckets[i]->magicalNumbers[k] > buckets[i]->magicalNumbers[k + 1]) {
                        // Swap using a magic move
                        int temp = buckets[i]->magicalNumbers[k];
                        buckets[i]->magicalNumbers[k] = buckets[i]->magicalNumbers[k + 1];
                        buckets[i]->magicalNumbers[k + 1] = temp;
                    }
                }
            }
            // Collect the sorted numbers back from the fairy
            for (int j = 0; j < buckets[i]->count; j++) {
                arr[currentIndex++] = buckets[i]->magicalNumbers[j];
            }
        }
    }

    // Free the fairies after the magic is done
    for (int i = 0; i < NUM_BUCKETS; i++) {
        free_bucket(buckets[i]);
    }
    free(buckets);
}

// Main function where the journey begins
int main() {
    int n;
    printf("Welcome to the Magical Forest of Sorting!\n");
    printf("How many mystical numbers would you like to sort? ");
    scanf("%d", &n);

    int *mysticalNumbers = (int*)malloc(n * sizeof(int));
    printf("Enter the mystical numbers (between 0 and %d):\n", MAX_NUM-1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &mysticalNumbers[i]);
    }

    printf("Your mystical numbers before the magic (Bucket Sort):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", mysticalNumbers[i]);
    }
    printf("\n");

    // The magic begins!
    magic_sort(mysticalNumbers, n);
    
    printf("Your mystical numbers sorted by the magic fairies:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", mysticalNumbers[i]);
    }
    printf("\n");

    free(mysticalNumbers);
    return 0;
}