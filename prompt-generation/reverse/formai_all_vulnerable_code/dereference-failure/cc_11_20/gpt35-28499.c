//FormAI DATASET v1.0 Category: Memory management ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL)); // initialize random seed
    int n = 10000; // number of blocks
    int size = 100; // size of blocks
    int* ptr[n]; // array of pointers to blocks
    int i, j;
    int stat[4] = {0}; // array for statistical data
    int sum = 0;

    // Allocate memory blocks randomly
    for(i=0;i<n;i++){
        ptr[i] = malloc(size);
        if(ptr[i] == NULL){ // failed to allocate memory
            printf("Error: Failed to allocate memory!");
            exit(1);
        }
    }

    // Free memory blocks randomly
    for(i=0;i<n;i++){
        j = rand() % n;
        free(ptr[j]);
        ptr[j] = NULL;

        // Collect and display statistical data
        if(i % 1000 == 0){
            for(j=0;j<n;j++){
                if(ptr[j] != NULL){
                    if(ptr[j] - ptr[0] < size) stat[0]++; // below end of first block
                    else if(ptr[n-1] - ptr[j] < size) stat[1]++; // above end of last block
                    else if(j > 0 && ptr[j] - ptr[j-1] < size) stat[2]++; // adjacent
                    else stat[3]++; // other
                }
            }

            printf("Iteration %d:\n", i);
            printf("Memory blocks below end of first block: %d\n", stat[0]);
            printf("Memory blocks above end of last block: %d\n", stat[1]);
            printf("Adjacent memory blocks: %d\n", stat[2]);
            printf("Other memory blocks: %d\n", stat[3]);
            sum += stat[0] + stat[1] + stat[2] + stat[3];
            printf("Total number of memory blocks: %d\n", sum);

            // reset statistical data for next iteration
            for(j=0;j<4;j++){
                stat[j] = 0;
            }
        }
    }

    return 0;
}