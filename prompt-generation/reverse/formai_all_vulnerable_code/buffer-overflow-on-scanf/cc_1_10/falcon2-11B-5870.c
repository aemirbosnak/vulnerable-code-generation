//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000
#define MIN_NUMBER 1
#define MAX_NUMBER 1000

int main() {
    int num_values;
    int min_value;
    int max_value;
    int sum;
    int i;
    
    printf("Enter the number of values: ");
    scanf("%d", &num_values);
    
    if (num_values < 1 || num_values > MAX_SIZE) {
        printf("Invalid number of values.\n");
        return 1;
    }
    
    int values[num_values];
    
    printf("Enter the values:\n");
    for (i = 0; i < num_values; i++) {
        scanf("%d", &values[i]);
    }
    
    min_value = values[0];
    max_value = values[0];
    
    for (i = 0; i < num_values; i++) {
        if (values[i] < min_value) {
            min_value = values[i];
        }
        if (values[i] > max_value) {
            max_value = values[i];
        }
    }
    
    sum = 0;
    
    for (i = 0; i < num_values; i++) {
        sum += values[i];
    }
    
    printf("Minimum value: %d\n", min_value);
    printf("Maximum value: %d\n", max_value);
    printf("Sum: %d\n", sum);
    
    return 0;
}