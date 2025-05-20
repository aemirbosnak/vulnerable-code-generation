//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function to sort the array in non-decreasing order using bubble sort algorithm
void bubbleSort(int arr[], int n){
    int temp, i, j;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int n, i, j, sum=0, maxprofit=0, w;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weight[n], profit[n];

    printf("Enter the weight and profit of each item:\n");
    for(i=0; i<n; i++){
        scanf("%d %d", &weight[i], &profit[i]);
    }

    //calculating the ratio of profit and weight for each item
    float pw[n];
    for(i=0; i<n; i++){
        pw[i] = (float)profit[i]/weight[i];
    }

    //sorting the items based on ratio of profit and weight
    bubbleSort(pw, n);
    for(i=n-1; i>=0; i--){
        //picking the item which gives maximum profit
        if(w+weight[i]<=50){
            w += weight[i];
            maxprofit += profit[i];
        }
        //if the maximum capacity of knapsack gets full, then break the loop
        else{
            break;
        }
    }

    printf("\nMaximum profit that can be obtained is: %d", maxprofit);

    return 0;
}