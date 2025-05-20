//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Alan Touring
//Alan Turing's Stock Market Tracker

//header files
#include<stdio.h>
#include<stdlib.h>

//function to get input values from the user and calculate the returns
float stockMarketTracker(int n, int arr[]) 
{
    int i, j, temp;
    float profit = 0;
    for(i = 0; i < n - 1; i++) 
    {
        for(j = i + 1; j < n; j++) 
        {
            if(arr[j] > arr[i]) 
            {
                temp = arr[j] - arr[i];
                if(temp > profit)
                    profit = temp;
            }
        }
    }

    return profit;
}

//main function to test the program
int main() 
{
    int n, i, *arr;
    printf("Enter the number of stocks you want to track: ");
    scanf("%d", &n);
    if(n < 2) 
    {
        printf("Error! You must track at least two stocks!");
        exit(0);
    }

    arr = (int*)malloc(n * sizeof(int));

    for(i = 0; i < n; i++) 
    {
        printf("Enter the value of stock %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    float result = stockMarketTracker(n, arr);
    printf("The maximum return on investment is: %.2f", result);
    free(arr);
    return 0;
}