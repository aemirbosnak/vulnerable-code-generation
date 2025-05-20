//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

//defining the structure of each item
struct item {
    int weight;
    int value;
};

//comparison function used for sorting by value/weight ratio
int compare(const void *a, const void *b){
    double r1 = ((struct item*)a)->value / (double)((struct item*)a)->weight;
    double r2 = ((struct item*)b)->value / (double)((struct item*)b)->weight;

    if(r1 > r2)
        return -1;
    else if(r1 < r2)
        return 1;
    else
        return 0;
}

int main(){

    int numItems, capacity, i;
    double totalValue = 0.0;
    struct item* items;

    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    items = (struct item*)malloc(sizeof(struct item) * numItems);

    for(i=0; i<numItems; i++){
        printf("\nEnter the weight of item %d: ", i+1);
        scanf("%d", &items[i].weight);
        printf("Enter the value of item %d: ", i+1);
        scanf("%d", &items[i].value);
    }

    printf("\nEnter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    qsort(items, numItems, sizeof(struct item), compare);

    for(i=0; i<numItems; i++){
        if(items[i].weight <= capacity){
            totalValue += items[i].value;
            capacity -= items[i].weight;
        }
        else{
            totalValue += (capacity/(double)items[i].weight) * items[i].value;
            break;
        }
    }

    printf("\nMaximum value that can be carried: %.2f\n", totalValue);

    return 0;
}