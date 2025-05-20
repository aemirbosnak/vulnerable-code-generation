//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: scalable
#include <stdio.h>

/* Function to sort the items according to their value */
void sort(float value[], float weight[], int n){

    /* Insertion sort algorithm */
    int i,j;
    float temp;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if((value[j]/weight[j]) > (value[i]/weight[i])){ // Computing the value/weight ratio and sorting the items accordingly
                temp = value[i];
                value[i] = value[j];
                value[j] = temp;
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
            }
        }
    }
}

/* Function to find the maximum profit we can get by using greedy approach */
float getMaxProfit(int n, float value[], float weight[], float max_weight){

    sort(value, weight, n); // Sorting the items

    float profit = 0; // The final profit we will get
    int i=0; // Index to access the items

    while(max_weight > 0 && i<n){
        if(weight[i] <= max_weight){ // If the item can be fully added to the knapsack
            profit += value[i];
            max_weight -= weight[i];
        }else{ // If the item cannot be fully added to the knapsack
            profit += (max_weight/weight[i])*value[i];
            max_weight = 0;
        }
        i++; // Moving to the next item
    }

    return profit; // Returning the maximum profit
}

int main(){

    int n; // Number of items
    float max_weight; // Maximum weight the knapsack can hold

    printf("Enter the number of items: ");
    scanf("%d",&n);

    float value[n], weight[n];
    printf("Enter the value and weight of each item:\n");
    for(int i=0;i<n;i++){
        scanf("%f%f",&value[i],&weight[i]);
    }

    printf("Enter the maximum weight the knapsack can hold: ");
    scanf("%f",&max_weight);

    printf("The maximum profit we can get is: %f", getMaxProfit(n, value, weight, max_weight)); 

    return 0;
}