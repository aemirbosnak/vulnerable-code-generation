//FormAI DATASET v1.0 Category: Stock market tracker ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

int main()
{
    float stocks[5][5] = {   //initializing stocks of 5 companies
        {95.10, 24.55, 45.33, 106.60, 37.20},
        {121.90, 80.33, 154.65, 110.45, 75.10},
        {55.90, 70.60, 82.40, 99.20, 67.30},
        {33.50, 44.20, 50.10, 60.40, 82.50},
        {78.06, 92.10, 66.70, 45.80, 99.99}
    };
    float high[5], low[5], sum = 0, average, difference;
    int i, j, choice;

    //Printing the available stocks
    printf("List of available stocks:\n");
    for(i=0;i<5;i++){
        printf("Stock %d: ", i+1);
        for(j=0;j<5;j++){
            printf("%.2f ", stocks[i][j]);
        }
        printf("\n");
    }

    //Calculating the high and low value of each stock
    for(i=0;i<5;i++){
        high[i] = stocks[i][0];
        low[i] = stocks[i][0];
        for(j=0;j<5;j++){
            if(stocks[i][j] > high[i]) high[i] = stocks[i][j];
            if(stocks[i][j] < low[i]) low[i] = stocks[i][j];
        }
    }

    //Printing the high and low values
    printf("\n\nList of highest and lowest value on each stock: \n");
    for(i=0;i<5;i++){
        printf("Stock %d: High = %.2f, Low = %.2f\n", i+1, high[i], low[i]);
    }

    //Calculating the average value of all stocks
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            sum += stocks[i][j];
        }
    }
    average = sum / 25;

    //Calculating and printing the difference from the average value
    printf("\n\nDifference from the average value: \n");
    for(i=0;i<5;i++){
        difference = high[i] - low[i];
        printf("Stock %d: %.2f\n", i+1, difference-average);
    }

    //Asking for the specific stock choice
    printf("\n\nEnter the choice of stock (1-5): ");
    scanf("%d", &choice);

    //Printing the indices where the specific value is greater than average
    printf("\nIndices where the value of Stock %d is greater than average value: \n", choice);
    for(i=0;i<5;i++){
        if(stocks[choice-1][i] > average){
            printf("%d ", i);
        }
    }

    //Exit statement
    printf("\n\nThank you for using our program!\n");
    return 0;
}