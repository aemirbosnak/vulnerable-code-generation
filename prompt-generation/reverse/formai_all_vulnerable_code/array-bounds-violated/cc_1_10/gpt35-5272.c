//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>

int main(){
    int num_items, capacity, profit = 0;
    printf("Enter the number of items: ");
    scanf("%d", &num_items);
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    int weights[num_items], values[num_items];

    for(int i=0; i<num_items; i++){
        printf("Enter the weight of item %d: ", i+1);
        scanf("%d", &weights[i]);
        printf("Enter the value of item %d: ", i+1);
        scanf("%d", &values[i]);
    }

    float ratio[num_items];
    for(int i=0; i<num_items; i++){
        ratio[i] = (float)values[i] / (float)weights[i];
    }

    //sorting items based on their ratio
    for(int i=0; i<num_items-1; i++){
        for(int j=0; j<num_items-i-1; j++){
            if(ratio[j] < ratio[j+1]){
                float temp = ratio[j];
                ratio[j] = ratio[j+1];
                ratio[j+1] = temp;

                int temp1 = weights[j];
                weights[j] = weights[j+1];
                weights[j+1] = temp1;

                int temp2 = values[j];
                values[j] = values[j+1];
                values[j+1] = temp2;
            }
        }
    }

    printf("\nItems to be selected:\n");
    for(int i=0; i<num_items; i++){
        if(capacity == 0){
            break;
        }
        else if(weights[i] <= capacity){
            printf("item %d weight=%d value=%d\n", i+1, weights[i], values[i]);
            profit += values[i];
            capacity -= weights[i];
        }
        else{
            float fraction = (float)capacity / (float)weights[i];
            printf("item %d weight=%d value=%d (fraction)\n", i+1, weights[i], (int)(values[i]*fraction));
            profit += (int)(values[i]*fraction);
            capacity = 0;
        }
    }

    printf("\nTotal profit: $%d", profit);
    return 0;
}