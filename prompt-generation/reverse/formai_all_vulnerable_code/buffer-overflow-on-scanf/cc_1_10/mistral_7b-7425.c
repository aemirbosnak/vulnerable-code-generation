//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#define MAX_N 10005
#define MAX_W 100005

typedef struct{
    int id;
    int weight;
    int value;
}Item;

Item Items[MAX_N];
int n, w;

int main(void){
    int i, j, k, max_value = 0, temp_value;

    scanf("%d%d",&n,&w);
    for(i = 0;i < n;i++){
        scanf("%d%d%d",&Items[i].id,&Items[i].weight,&Items[i].value);
    }

    //Sort items by their weight per value ratio
    for(i = 0;i < n - 1;i++){
        for(j = i + 1;j < n;j++){
            if((float)Items[i].value/Items[i].weight > (float)Items[j].value/Items[j].weight){
                Item temp = Items[i];
                Items[i] = Items[j];
                Items[j] = temp;
            }
        }
    }

    //Fill sack with items
    for(i = 0;i < n;i++){
        k = w - Items[i].weight;
        if(k >= 0){
            temp_value = Items[i].value + max_value;
            if(temp_value > max_value){
                max_value = temp_value;
                printf("Item %d with value %d added to sack.\n",Items[i].id,Items[i].value);
            }
            w -= Items[i].weight;
        }
        else{
            printf("Item %d with weight %d and value %d cannot be added to sack.\n",Items[i].id,Items[i].weight,Items[i].value);
        }
    }

    printf("Total value in sack: %d",max_value);
    return 0;
}