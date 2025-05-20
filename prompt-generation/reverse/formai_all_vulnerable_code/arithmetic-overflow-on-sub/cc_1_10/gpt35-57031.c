//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: automated
#include<stdio.h>
#include<stdlib.h>

//function to sort the array in descending order
void sort(float arr[], int n){
    int i, j;
    float temp;

    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(arr[i]<arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int i, n, m;
    float sum=0.0f;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    //dynamic allocation of memory for weight and value arrays
    int *w = (int *) malloc(sizeof(int)*n);
    float *v = (float *) malloc(sizeof(float)*n);
    float *ratio = (float *) malloc(sizeof(float)*n);

    printf("Enter the weight and corresponding value of each item:\n");
    for(i = 0; i < n; i++){
        scanf("%d %f", &w[i], &v[i]);
    }

    //calculating the ratio of value and weight for each item
    for(i = 0; i < n; i++){
        ratio[i] = v[i]/(float)w[i];
    }

    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &m);
    
    //sorting the items in descending order of their value to weight ratio using bubble sort
    sort(ratio, n);

    for (i = 0; i < n; i++)
    {
        if (w[i] <= m) //if item fits in the knapsack
        {
            sum += v[i]; //add its value to the sum
            m -= w[i]; //decrease the capacity of the knapsack
        } 
        else //if item does not fit in the knapsack
        {
            sum += ratio[i] * m; //add the value of the remaining fraction of the item
            break;
        }
    }

    printf("The maximum value of items that can be put into knapsack is: %f", sum);

    free(w);
    free(v);
    free(ratio);
    return 0;
}