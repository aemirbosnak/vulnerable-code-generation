//FormAI DATASET v1.0 Category: File handling ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    // Declare Variables
    FILE *fp;
    int arr[10];
    int sum = 0;
    int n = 0;
    float mean, sd;

    // Open file for reading
    fp = fopen("data.txt", "r");

    // Check if file exists
    if(fp == NULL){
        printf("Error Opening File.\n");
        exit(0);
    }

    // Read data from file into array
    while(!feof(fp) && n < 10){
        fscanf(fp, "%d", &arr[n]);
        n++;
    }

    // Close file
    fclose(fp);

    // Calculate Mean
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    mean = (float)sum / n;

    // Calculate Standard Deviation
    sum = 0;
    for(int i = 0; i < n; i++){
        sum += pow(arr[i] - mean, 2);
    }
    sd = sqrt((float)sum / n);

    // Display Results
    printf("Data from File:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    printf("\nMean: %.2f\nStandard Deviation: %.2f\n", mean, sd);

    return 0; 
}