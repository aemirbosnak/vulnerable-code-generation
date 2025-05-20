//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BLOCKS 20 // Maximum number of blocks
#define MIN_TRAFFIC  1 // Minimum traffic amount
#define MAX_TRAFFIC 10 // Maximum traffic amount

void init_blocks(int blocks[], int num_blocks) {
    // Initialize each block with some random amount of traffic
    srand(time(NULL));
    int i;
    for(i = 0; i < num_blocks; i++) {
        blocks[i] = MIN_TRAFFIC + rand() % (MAX_TRAFFIC - MIN_TRAFFIC + 1);    
    }
}

void print_blocks(int blocks[], int num_blocks) {
    // Print the current traffic amount of each block
    int i;
    for(i = 0; i < num_blocks; i++) {
        printf("Block %d: %d cars\n", i+1, blocks[i]);
    }
    printf("\n");
}

void simulate_traffic(int blocks[], int num_blocks) {
    int i;
    for(i = 0; i < num_blocks - 1; i++) {
        // Cars on this block start moving to the next block
        int num_cars = blocks[i] / 2;
        blocks[i] -= num_cars;
        blocks[i+1] += num_cars;
        
        // If the number of cars exceeds the max traffic amount for a block, move some cars to the next block
        if(blocks[i+1] > MAX_TRAFFIC) {
            int excess_cars = blocks[i+1] - MAX_TRAFFIC;
            blocks[i+1] = MAX_TRAFFIC;
            blocks[i+2] += excess_cars;
        }
    }
}

int main() {
    int blocks[MAX_BLOCKS];
    int num_blocks;
    
    printf("Enter the number of blocks: ");
    scanf("%d", &num_blocks);
    
    init_blocks(blocks, num_blocks);
    
    while(1) {
        system("cls");
        printf("Traffic Simulation\n");
        printf("========================\n");
        simulate_traffic(blocks, num_blocks);
        print_blocks(blocks, num_blocks);
        printf("Press any key to continue...");
        getchar();
    }
    
    return 0;
}