//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: creative
#include <stdio.h>
#define MAX_SIZE 1000

int main() {
    int num_items, i, curr_weight = 0, max_weight, total_value = 0;
    int item_weights[MAX_SIZE], item_values[MAX_SIZE];
    float value_per_weight[MAX_SIZE] = {0}, temp;

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    printf("Enter the weight and value of each item:\n");
    for(i=0; i<num_items; i++) {
        printf("Item %d - weight: ", i+1);
        scanf("%d", &item_weights[i]);
        printf("Item %d - value : ", i+1);
        scanf("%d", &item_values[i]);
        value_per_weight[i] = (float)item_values[i] / item_weights[i];
    }

    printf("Enter the maximum weight for the bag: ");
    scanf("%d", &max_weight);

    //sort items based on value per weight in descending order
    for(i=0; i<num_items; i++) {
        for(int j=i+1; j<num_items; j++) {
            if(value_per_weight[j]>value_per_weight[i]) {
                temp = value_per_weight[i];
                value_per_weight[i] = value_per_weight[j];
                value_per_weight[j] = temp;

                temp = item_weights[i];
                item_weights[i] = item_weights[j];
                item_weights[j] = temp;

                temp = item_values[i];
                item_values[i] = item_values[j];
                item_values[j] = temp;
            }
        }
    }

    //fill the bag with items in descending order until it reaches maximum weight
    for(i=0; i<num_items; i++) {
        if(curr_weight + item_weights[i] <= max_weight) {
            curr_weight += item_weights[i];
            total_value += item_values[i];
            printf("Item %d with weight %d and value %d is included\n", i+1, item_weights[i], item_values[i]);
        }
        else {
            int remaining_weight = max_weight - curr_weight;
            float fraction = (float) remaining_weight / item_weights[i];
            curr_weight += remaining_weight;
            total_value += fraction * item_values[i];
            printf("Item %d with weight %d and value %d is included partially with fraction %.2f\n", i+1, item_weights[i], item_values[i], fraction);
            break;
        }
    }

    printf("Total value of items in the bag: %d\n", total_value);

    return 0;
}