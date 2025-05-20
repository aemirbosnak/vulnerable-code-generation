//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: scientific
#include <stdio.h>

int main() {
    int n, m, i, j, temp, swap;
    int weight[50], profit[50], ratio[50];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the maximum weight of the bag: ");
    scanf("%d", &m);

    for(i=0; i<n; i++){
        printf("Enter the weight and profit of item %d: ", i+1);
        scanf("%d %d", &weight[i], &profit[i]);
        ratio[i] = profit[i]/weight[i];
    }

    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(ratio[i] < ratio[j]){
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                swap = profit[j];
                profit[j] = profit[i];
                profit[i] = swap;

                swap = weight[j];
                weight[j] = weight[i];
                weight[i] = swap;
            }
        }
    }

    int currentWeight = 0, currentProfit = 0, remainingWeight, maxProfit;

    for(i=0; i<n; i++){
        if(currentWeight + weight[i] <= m){
            currentWeight += weight[i];
            currentProfit += profit[i];
        }
        else{
            remainingWeight = m - currentWeight;
            maxProfit = remainingWeight * ratio[i];
            currentProfit += maxProfit;
            break;
        }
    }

    printf("The maximum profit is: %d", currentProfit);

    return 0;
}