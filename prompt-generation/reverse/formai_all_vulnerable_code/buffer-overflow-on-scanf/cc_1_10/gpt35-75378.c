//FormAI DATASET v1.0 Category: Searching algorithm ; Style: irregular
#include <stdio.h>

// Define the size of the array
#define SIZE 10

// Search function 
int find_number(int arr[], int num)
{
    // Loop through array
    for (int i = 0; i < SIZE; i++) {
        
        // If the element is equal to the number
        if (arr[i] == num) {
            
            // Return the index i
            return i;
        }
        
        // If the element is greater than the number
        else if (arr[i] > num) {
            
            // Return the index i - 1
            if (i > 0) {
                return i - 1;
            }
        }
    }
    
    // If the number is greater than all elements in array
    return SIZE - 1;
}

int main()
{
    // Declare the array
    int arr[SIZE] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    
    // Get input from user
    int num;
    printf("Enter a number to search for: ");
    scanf("%d", &num);
    
    // Call the search function and get the result
    int result = find_number(arr, num);
    
    // Print the result
    printf("The index of the closest number in the array is: %d\n", result);
    
    return 0;
}