#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MIN_WEIGHT 0
#define MAX_WEIGHT 100
#define TIME_FRAME 60

typedef struct {
    int weight;
    int status; // 0: not processed, 1: processed
} Bag;

int main() {
    srand(time(NULL));
    Bag bags[MAX_BAGS];
    int num_bags = 0;

    printf("Enter the number of bags: ");
    scanf("%d", &num_bags);

    for (int i = 0; i < num_bags; ++i) {
        bags[i].weight = rand() % (MAX_WEIGHT - MIN_WEIGHT + 1) + MIN_WEIGHT;
    }

    for (int second = 0; second < TIME_FRAME; ++second) {
        printf("\nSecond %d:\n", second);
        for (int i = 0; i < num_bags; ++i) {
            if (bags[i].status == 0) {
                if (bags[i].weight <= (second + 1)) {
                    bags[i].status = 1;
                    printf("Bag %d (weight: %d) processed\n", i + 1, bags[i].weight);
                } else {
                    printf("Bag %d (weight: %d) not processed yet\n", i + 1, bags[i].weight);
                }
            } else {
                printf("Bag %d (weight: %d) already processed\n", i + 1, bags[i].weight);
            }
        }
    }

    return 0;
}
