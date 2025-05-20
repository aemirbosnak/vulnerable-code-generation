//FormAI DATASET v1.0 Category: Data mining ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// A Data Mining Example Program //

int main(){

    // Inputting the number of data points
    int n;
    printf("Enter the number of data points: ");
    scanf("%d",&n);

    // Defining the data set as an array
    double dataset[n];
    printf("Enter the data set: ");
    for(int i=0;i<n;i++){
        scanf("%lf",&dataset[i]);
    }

    // Calculating the mean
    double mean=0;
    for(int i=0;i<n;i++){
        mean+=dataset[i];
    }
    mean/=n;
    printf("The mean of the data set is: %lf\n",mean);

    // Calculating the standard deviation
    double std_dev=0;
    for(int i=0;i<n;i++){
        std_dev+=pow(dataset[i]-mean,2);
    }
    std_dev=sqrt(std_dev/n);
    printf("The standard deviation of the data set is: %lf\n",std_dev);

    // Determining if the data set contains outliers
    double threshold=2*std_dev;
    int outliers=0;
    for(int i=0;i<n;i++){
        if(fabs(dataset[i]-mean)>=threshold){
            outliers++;
        }
    }
    if(outliers>0){
        printf("The data set contains %d outliers.\n",outliers);
    }
    else{
        printf("The data set does not contain any outliers.\n");
    }

    return 0;
}