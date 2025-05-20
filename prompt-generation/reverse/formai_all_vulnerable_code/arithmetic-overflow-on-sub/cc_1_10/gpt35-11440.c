//FormAI DATASET v1.0 Category: Benchmarking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 1000000

void memset_benchmark() {
    char arr[SIZE];
    clock_t t;
    double time_taken;
    
    t = clock();
    memset(arr, 'A', SIZE);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    
    printf("memset took %f seconds.\n", time_taken);
}

void memcpy_benchmark() {
    char arr1[SIZE], arr2[SIZE];
    int i;
    clock_t t;
    double time_taken;
    
    for(i=0; i<SIZE; i++)
        arr1[i] = 'A';
    
    t = clock();
    memcpy(arr2, arr1, SIZE);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    
    printf("memcpy took %f seconds.\n", time_taken);
}

void strcmp_benchmark() {
    int i;
    char str1[SIZE], str2[SIZE];
    clock_t t;
    double time_taken;
    
    for(i=0; i<SIZE; i++) {
        str1[i] = 'A';
        str2[i] = 'A';
    }
    
    t = clock();
    strcmp(str1, str2);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    
    printf("strcmp took %f seconds.\n", time_taken);
}

int main() {
    memset_benchmark();
    memcpy_benchmark();
    strcmp_benchmark();
    return 0;
}