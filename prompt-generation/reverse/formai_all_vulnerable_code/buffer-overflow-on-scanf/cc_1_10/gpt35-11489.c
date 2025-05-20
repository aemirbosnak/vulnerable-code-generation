//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Ken Thompson
#include<stdio.h>

//function to implement the fractional knapsack algorithm
float fractionalKnapsack(int n, float capacity[], float value[], float weight[]) {
    float frac_value = 0;       //variable to store the final fractional value
    int i;
    float wt = 0;

    //calculate the value to weight ratio
    float ratio[n];
    for(i=0;i<n;i++) {
        ratio[i] = value[i] / weight[i]; 
    }

    //sorting the given items in decreasing order of the value to weight ratio
    for(i=0;i<n-1;i++) {
        int j;
        for(j=i+1;j<n;j++) {
            if(ratio[i] < ratio[j]) {
                float temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = value[i];
                value[i] = value[j];
                value[j] = temp;       
            }
        }
    }

    //calculating the fractional value of the items in the knapsack
    for(i=0;i<n;i++) {
        if(wt + weight[i] <= capacity[0]) {
            wt = wt + weight[i];
            frac_value = frac_value + value[i];
        }
        else {
            frac_value = frac_value + (capacity[0] - wt)*ratio[i];
            break;
        }
    }
    return frac_value;
}

int main() {
    int n,i;

    printf("Enter the number of items : ");
    scanf("%d",&n);

    float capacity[1];      //array to store the capacity of the knapsack
    float value[n],weight[n];

    printf("Enter the capacity of the knapsack : ");
    scanf("%f",&capacity[0]);

    printf("Enter the values and weights of the items : \n");
    for(i=0;i<n;i++) {
        printf("Value of item %d : ",i+1);
        scanf("%f",&value[i]);

        printf("Weight of item %d : ",i+1);
        scanf("%f",&weight[i]);
    }

    //calling the function to implement fractional knapsack algorithm
    float frac_value = fractionalKnapsack(n,capacity,value,weight);

    printf("\nThe maximal value that can be obtained is : %f\n",frac_value);

    return 0;
}