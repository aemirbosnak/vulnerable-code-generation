//FormAI DATASET v1.0 Category: Scientific ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n, i, j, count;
    float data[100], mean, var, std_deviation, sum = 0, sum1 = 0;

    //Get number of elements as input
    printf("Enter number of elements:");
    scanf("%d",&n);

    //Input the data
    printf("Enter %d data:\n",n);
    for(i = 0; i < n; ++i)
    {
        scanf("%f", &data[i]);
    }

    //Calculate mean
    for(i = 0; i < n; ++i)
    {
        sum = sum + data[i];
    }
    mean = sum/n;

    //Calculate Standard Deviation
    for(i = 0; i < n; ++i)
    {
        sum1 = sum1 + pow((data[i]-mean), 2);
    }
    var = sum1/(n-1);
    std_deviation = sqrt(var);

    //Display the results
    printf("Mean = %.2f\n", mean);
    printf("Standard Deviation = %.2f\n", std_deviation);

    //Count number of elements outside of mean range
    count = 0;
    for(i = 0; i < n; ++i)
    {
        if(data[i] > mean+std_deviation || data[i] < mean-std_deviation)
        {
            ++count;
        }
    }

    //Display number of elements outside range
    printf("\nNumber of elements outside mean range: %d", count);

    return 0;
}