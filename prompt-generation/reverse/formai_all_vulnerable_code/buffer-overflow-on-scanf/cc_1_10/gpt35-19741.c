//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

struct item{
    int value;
    int weight;
} items[100];

int compare(const void *a, const void *b){
    struct item *x = (struct item *)a;
    struct item *y = (struct item *)b;
    return ((y->value/y->weight) - (x->value/x->weight));
}

int main(){
    int numItems, capacity, i;
    float totalValue = 0;

    printf("Enter the number of items: ");
    scanf("%d",&numItems);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d",&capacity);

    printf("Enter the values and weights of the %d items:\n",numItems);
    for(i=0;i<numItems;i++){
        printf("Item %d: ",i+1);
        scanf("%d%d",&items[i].value,&items[i].weight);
    }

    qsort(items,numItems,sizeof(struct item),compare);

    printf("\nItems in the Knapsack:\n");

    for(i=0;i<numItems;i++){
        if(items[i].weight > capacity){
            break;
        }
        printf("Item %d: Quantity 1, Value %d, Weight %d\n",i+1,items[i].value,items[i].weight);
        capacity -= items[i].weight;
        totalValue += items[i].value;
    }
    if(i<numItems){
        printf("Item %d: Quantity %.2f, Value %.2f, Weight %.2f\n",i+1,(float)capacity/items[i].weight*items[i].value,capacity,items[i].weight);
        totalValue += (float)capacity/items[i].weight*items[i].value;
    }

    printf("\nThe maximum value that can be put in a knapsack of capacity %d is %.2f\n",capacity,totalValue);

    return 0;
}