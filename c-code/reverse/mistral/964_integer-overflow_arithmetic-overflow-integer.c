#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    int bags[10], i, weight, num_bags;
    printf("Enter number of bags: ");
    scanf("%d", &num_bags);

    for(i = 0; i < num_bags; i++) {
        printf("Enter weight of bag %d: ", i+1);
        scanf("%d", &weight);
        bags[i] = weight;
    }

    printf("Enter weight of luggage to check-in: ");
    scanf("%d", &weight);

    for(i = 0; i < num_bags; i++) {
        if(weight < bags[i]) {
            printf("Your luggage is too heavy.\n");
            return 0;
        }
    }

    printf("Your luggage is light enough.\n");

    return 0;
}
