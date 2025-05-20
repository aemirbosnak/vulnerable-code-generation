//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: detailed
#include<stdio.h>

int main() {
    int num_elements;
    printf("Enter the number of elements: ");
    scanf("%d", &num_elements);

    float values[num_elements], weights[num_elements];
    for(int i=0; i<num_elements; i++) {
        printf("Enter the weight and value of item %d: ",i+1);
        scanf("%f %f", &weights[i], &values[i]);
    }

    float max_weight;
    printf("Enter the maximum weight that can be carried: ");
    scanf("%f", &max_weight);

    float value_per_weight[num_elements];
    for(int i=0; i<num_elements; i++) {
        value_per_weight[i] = values[i]/weights[i];
    }

    for(int i = 0; i < num_elements; i++) {
        for(int j = 0; j < num_elements-i-1; j++) {
            if(value_per_weight[j] < value_per_weight[j+1]) {
                float temp = value_per_weight[j];
                value_per_weight[j] = value_per_weight[j+1];
                value_per_weight[j+1] = temp;

                temp = weights[j];
                weights[j] = weights[j+1];
                weights[j+1] = temp;

                temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
            }
        }
    }

    float current_weight = 0;
    float current_value = 0;
    int index = 0;
    while(current_weight < max_weight && index < num_elements) {
        if(current_weight + weights[index] <= max_weight) {
            current_weight += weights[index];
            current_value += values[index];
        }
        else {
            float remaining_weight = max_weight - current_weight;
            current_value += remaining_weight * value_per_weight[index];
            current_weight = max_weight;
        }
        index++;
    }

    printf("Maximum value that can be carried is: $%.2f", current_value);

    return 0;
}