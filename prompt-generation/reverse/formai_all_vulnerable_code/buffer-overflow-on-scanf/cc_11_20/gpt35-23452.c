//FormAI DATASET v1.0 Category: Data mining ; Style: real-life
#include <stdio.h> 
#include <stdlib.h> 

#define MAX_SIZE 100 
#define MAX_ATTRIBUTES 10 

int main() 
{ 
    int num_instances, num_attributes; 
    float dataset[MAX_SIZE][MAX_ATTRIBUTES]; 

    printf("Enter number of instances: "); 
    scanf("%d", &num_instances); 

    printf("Enter number of attributes: "); 
    scanf("%d", &num_attributes); 

    /* Input dataset */ 
    printf("Enter dataset:\n"); 
    for(int i = 0; i < num_instances; i++) 
    { 
        for(int j = 0; j < num_attributes; j++) 
        { 
            scanf("%f", &dataset[i][j]); 
        } 
    } 

    /* Find means of each attribute */ 
    float attribute_means[MAX_ATTRIBUTES]; 
    for(int j = 0; j < num_attributes; j++) 
    { 
        float sum = 0; 
        for(int i = 0; i < num_instances; i++) 
        { 
            sum += dataset[i][j]; 
        } 
        attribute_means[j] = sum / num_instances; 
    } 

    /* Normalize data */ 
    for(int i = 0; i < num_instances; i++) 
    { 
        for(int j = 0; j < num_attributes; j++) 
        { 
            dataset[i][j] = (dataset[i][j] - attribute_means[j]); 
        } 
    } 

    /* Calculate covariance matrix */ 
    float covariance_matrix[MAX_ATTRIBUTES][MAX_ATTRIBUTES]; 
    for(int i = 0; i < num_attributes; i++) 
    { 
        for(int j = 0; j < num_attributes; j++) 
        { 
            float sum = 0; 
            for(int k = 0; k < num_instances; k++) 
            { 
                sum += (dataset[k][i] * dataset[k][j]); 
            } 
            covariance_matrix[i][j] = sum / (num_instances - 1); 
        } 
    } 

    /* Print covariance matrix */ 
    printf("Covariance Matrix:\n"); 
    for(int i = 0; i < num_attributes; i++) 
    { 
        for(int j = 0; j < num_attributes; j++) 
        { 
            printf("%f ", covariance_matrix[i][j]); 
        } 
        printf("\n"); 
    } 

    return 0; 
}