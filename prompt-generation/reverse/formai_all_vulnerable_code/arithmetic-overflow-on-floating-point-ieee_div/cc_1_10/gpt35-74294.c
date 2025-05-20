//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: rigorous
#include<stdio.h>

int main(){
    int n, i, j;
    float wt[50], val[50], ratio[50], temp, max_weight, profit=0;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%f", &max_weight);

    printf("Enter the weight and value of each item: \n");
    for(i=0; i<n; i++){
        printf("Weight of item %d: ", i+1);
        scanf("%f", &wt[i]);
        printf("Value of item %d: ", i+1);
        scanf("%f", &val[i]);
        ratio[i] = val[i]/wt[i];
    }

    //sorting the items based on the ratio of value to weight in descending order
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(ratio[i]<ratio[j]){
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = wt[i];
                wt[i] = wt[j];
                wt[j] = temp;

                temp = val[i];
                val[i] = val[j];
                val[j] = temp;
            }
        }
    }

    //applying the greedy approach
    for(i=0; i<n; i++){
        if(wt[i]<=max_weight){
            profit += val[i];
            max_weight -= wt[i];
        }
        else{
            profit += max_weight*ratio[i];
            break;
        }
    }

    printf("The maximum profit that can be obtained is: %f", profit);

    return 0;
}