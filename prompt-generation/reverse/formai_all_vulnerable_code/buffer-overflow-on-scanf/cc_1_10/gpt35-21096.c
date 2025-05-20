//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: standalone
#include <stdio.h>

void fibonacciVisualizer(int n)
{
    int i, j;
    int arr[20][20] = {0}; // Declare a 2D array for our visualizer
    
    // Initialize the first two numbers of the sequence
    int num1 = 0, num2 = 1; 
    
    arr[0][0] = 1; // Set the first element of our visualizer to 1
    
    if (n <= 0) // Check if the input is valid
    {
        printf("Invalid input!\n");
        return;
    }
    
    if (n == 1) // Base case when n = 1
    {
        printf("%d\n", num1);
        return;
    }
    
    if (n >= 2) // Base case when n = 2
    {
        printf("%d, %d\n", num1, num2);
        
        arr[1][0] = 1; // Set the second row of our visualizer
        arr[1][1] = 1;
    }
    
    for (i = 3; i <= n; i++) // Loop for generating the Fibonacci Sequence
    {
        int temp = num2;
        num2 = num1 + num2;
        num1 = temp;
        
        printf("%d, ", num2); // Print the current number
        
        // Set the corresponding element in our visualizer to 1
        for (j = 0; j < i; j++) 
        {
            if (j == 0)
            {
                arr[i-1][j] = 1;
            }
            else if (j == i-1)
            {
                arr[i-1][j] = 1;
            }
            else
            {
                arr[i-1][j] = arr[i-2][j-1] + arr[i-2][j];
            }
        }
    }
    
    // Print the completed visualizer
    printf("\nFibonacci Sequence:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    
    printf("Enter the number of terms to be generated: ");
    scanf("%d", &n);
    
    fibonacciVisualizer(n);
    
    return 0;
}