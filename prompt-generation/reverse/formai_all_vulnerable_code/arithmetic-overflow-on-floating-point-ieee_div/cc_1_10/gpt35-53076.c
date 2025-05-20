//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 100

typedef struct{
    float value;
    int weight;
    float ratio;
} item;

int compare(const void *a, const void *b){
    item *i1 = (item *) a;
    item *i2 = (item *) b;
    return (i2->ratio - i1->ratio) > 0 ? 1 : -1; 
}

int main(){
    int n, w, i;
    float maxProfit = 0.0;
    item itemList[MAX_ITEMS];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the maximum weight: ");
    scanf("%d", &w);

    printf("Enter the value and weight for each item\n");

    for(i = 0; i < n; i++){
        printf("Item %d: ", i+1);
        scanf("%f %d", &itemList[i].value, &itemList[i].weight);
        itemList[i].ratio = itemList[i].value / itemList[i].weight;
    }

    qsort(itemList, n, sizeof(item), compare);

    printf("\nSorted items by value/weight ratio:\n");
    for(i = 0; i < n; i++){
        printf("Item %d: Value = %.2f, Weight = %d, Ratio = %.2f\n", i+1, itemList[i].value, itemList[i].weight, itemList[i].ratio);
    }

    printf("\n");

    i = 0;
    while(w > 0 && i < n){
        if(itemList[i].weight <= w){
            maxProfit += itemList[i].value;
            w -= itemList[i].weight;
            printf("Item %d added to the knapsack\n", i+1);
        }
        else{
            maxProfit += (float) itemList[i].value * w / itemList[i].weight;
            w = 0;
            printf("Fractional item %d added to the knapsack\n", i+1);
        }
        i++;
    }

    printf("\nMaximum profit possible = %.2f\n", maxProfit);

    return 0;
}