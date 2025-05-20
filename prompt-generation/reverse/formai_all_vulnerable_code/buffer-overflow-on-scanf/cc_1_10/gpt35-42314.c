//FormAI DATASET v1.0 Category: Arithmetic ; Style: statistical
/* 
This program analyzes a set of integer data and calculates various statistical measures.

Instructions:
1. Enter the size of the data set.
2. Enter the data values.
3. Select the statistical measure to calculate.

Statistical measures available:
1. Mean
2. Median
3. Mode
4. Variance
5. Standard deviation
*/

#include <stdio.h>
#include <stdlib.h>

// Function to calculate the mean
float calculate_mean(int data[], int size){
    float sum = 0;
    
    for(int i=0; i<size; i++){
        sum += data[i];
    }
    
    return sum/size;
}

// Function to calculate the median
float calculate_median(int data[], int size){
    int middle = size/2;
    float median;
    
    if(size % 2 == 0){
        median = (data[middle-1] + data[middle])/2.0;
    }
    else{
        median = data[middle];
    }
    
    return median;
}

// Function to calculate the mode
int calculate_mode(int data[], int size){
    int mode = -1;
    int max_count = 0;
    
    for(int i=0; i<size; i++){
        int count = 0;
        
        for(int j=0; j<size; j++){
            if(data[j] == data[i]){
                count++;
            }
        }
        
        if(count > max_count){
            max_count = count;
            mode = data[i];
        }
    }
    
    return mode;
}

// Function to calculate the variance
float calculate_variance(int data[], int size){
    float mean = calculate_mean(data, size);
    float variance = 0;
    
    for(int i=0; i<size; i++){
        variance += (data[i]-mean)*(data[i]-mean);
    }
    
    return variance/size;
}

// Function to calculate the standard deviation
float calculate_sd(int data[], int size){
    float variance = calculate_variance(data, size);
    return sqrt(variance);
}

int main(){
    int size;
    printf("Enter the size of the data set: ");
    scanf("%d", &size);
    
    int data[size];
    printf("Enter the data values: ");
    for(int i=0; i<size; i++){
        scanf("%d", &data[i]);
    }
    
    int option;
    printf("Select the statistical measure to calculate:\n");
    printf("1. Mean\n2. Median\n3. Mode\n4. Variance\n5. Standard deviation\n");
    scanf("%d", &option);
    
    switch(option){
        case 1:
            printf("Mean: %.2f\n", calculate_mean(data, size));
            break;
        case 2:
            printf("Median: %.2f\n", calculate_median(data, size));
            break;
        case 3:
            printf("Mode: %d\n", calculate_mode(data, size));
            break;
        case 4:
            printf("Variance: %.2f\n", calculate_variance(data, size));
            break;
        case 5:
            printf("Standard deviation: %.2f\n", calculate_sd(data, size));
            break;
        default:
            printf("Invalid option!\n");
    }
    
    return 0;
}