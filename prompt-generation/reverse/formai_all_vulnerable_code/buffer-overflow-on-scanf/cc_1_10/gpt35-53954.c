//FormAI DATASET v1.0 Category: Audio processing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function to calculate mean
double mean(double data[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}

//Function to calculate standard deviation
double sd(double data[], int size) {
    double m = mean(data, size);
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += pow((data[i] - m), 2);
    }
    return sqrt(sum / size);
}

int main() {
    //Initialize variables
    double input[1000];
    double output[1000];
    int size;
    
    //Get input from user
    printf("Enter the size of the input data: ");
    scanf("%d", &size);
    printf("Enter the values of the input data:\n");
    for (int i = 0; i < size; i++) {
        scanf("%lf", &input[i]);
    }
    
    //Normalize the input data
    double m = mean(input, size);
    double s = sd(input, size);
    for (int i = 0; i < size; i++) {
        input[i] = (input[i] - m) / s;
    }
    
    //Apply audio processing algorithm
    for (int i = 0; i < size; i++) {
        //TODO: Add your audio processing algorithm here
        //Example algorithm: output[i] = input[i] * 2.0;
        output[i] = input[i] * 2.0;
    }
    
    //Denormalize the output data
    for (int i = 0; i < size; i++) {
        output[i] = output[i] * s + m;
    }
    
    //Print the output data
    printf("The processed data is:\n");
    for (int i = 0; i < size; i++) {
        printf("%lf\n", output[i]);
    }
    
    return 0;
}