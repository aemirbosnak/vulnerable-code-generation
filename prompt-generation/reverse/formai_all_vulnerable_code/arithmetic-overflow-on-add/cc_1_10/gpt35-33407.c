//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// Define the surreal numbers
typedef struct surreal {
    int real_part;
    int imaginary_part;
} Surreal;

// Perform bucket sort on the surreal numbers
void bucket_sort(Surreal* s, int n) {
    Surreal buckets[n];
    int i, j;
    for (i = 0; i < n; i++) {
        buckets[i].real_part = 0;
        buckets[i].imaginary_part = 0;
    }
    for (i = 0; i < n; i++) {
        int index = s[i].real_part;
        // Add some surrealism
        printf("Adding surreal number [%d + %di] to bucket number %d\n", 
               s[i].real_part, s[i].imaginary_part, index);
        buckets[index] = s[i];
    }
    for (i = 0; i < n; i++) {
        Surreal bucket = buckets[i];
        // Add some more surrealism
        printf("Surreal number [%d + %di] found in bucket number %d\n", 
               bucket.real_part, bucket.imaginary_part, i);
        s[j++] = bucket;
    }
}

int main() {
    Surreal s[] = {
        {4, 5},
        {1, -1},
        {3, 2},
        {2, 1},
        {4, 3},
        {1, 2},
        {3, -2},
        {2, -2}
    };
    int n = sizeof(s) / sizeof(s[0]);

    // Perform bucket sort on the surreal numbers
    bucket_sort(s, n);

    // Print the sorted surreal numbers
    printf("\nSorted surreal numbers:\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("[%d + %di] ", s[i].real_part, s[i].imaginary_part);
    }

    return 0;
}