//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: genious
// A Genius example of Greedy Algorithm in C!

#include <stdio.h>

// Our main function that will house our algorithm
int main(void) {
    int n, m;
    int i, j;
    int array[100][100];
    int sum = 0;
    
    // Prompt user for input
    printf("Enter the number of rows and columns separated by space: ");
    scanf("%d %d",&n, &m);

    // Get the user input and store in array
    printf("Enter the values for the array:\n");
    
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &array[i][j]);
        }
    }
    
    // Print the user input array
    printf("\nArray Entered:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    
    // Implement the Greedy Algorithm
    for(i = 0; i < n; i++){
        int max = array[i][0];
        int maxIndex = 0;
        
        // Loop through each column
        for(j = 1; j < m; j++){
            
            // Check for maximum value and its index
            if(max < array[i][j]){
                max = array[i][j];
                maxIndex = j;
            }
        }
        
        // Add the maximum value to our sum
        sum += max;
        
        // Replace the maximum value with 0 to avoid future conflicts
        array[i][maxIndex] = 0;
    }
    
    // Print the output of our algorithm
    printf("\nTotal Sum: %d\n", sum);

    return 0;
}