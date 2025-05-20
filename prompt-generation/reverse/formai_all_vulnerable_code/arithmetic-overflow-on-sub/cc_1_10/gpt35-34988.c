//FormAI DATASET v1.0 Category: Searching algorithm ; Style: safe
#include <stdio.h>

// Define maximum array length
#define MAX_ARRAY 100

// Define search function
int search(int arr[], int n, int num)
{
    // Initialize left and right pointers
    int left = 0, right = n - 1;
    
    // Iterate until left pointer is less than or equal to right pointer
    while (left <= right)
    {
        // Calculate middle index of the array
        int mid = (left + right) / 2;
        
        // If the middle element is equal to the target number, return mid
        if (arr[mid] == num)
        {
            return mid;
        }
        
        // If the middle element is greater than the target number, update right pointer
        else if (arr[mid] > num)
        {
            right = mid - 1;
        }
        
        // If the middle element is less than the target number, update left pointer
        else
        {
            left = mid + 1;
        }
    }
    
    // If the number is not found, return -1
    return -1;
}

int main()
{
    int arr[MAX_ARRAY];
    int n, num;
    
    // Read the size of the array
    printf("Enter the size of the array (maximum %d): ", MAX_ARRAY);
    scanf("%d", &n);
    
    // Read the elements of the array
    printf("Enter %d elements of the array in ascending order:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    // Read the number to be searched
    printf("Enter the number to be searched: ");
    scanf("%d", &num);
    
    // Call the search function
    int index = search(arr, n, num);
    
    // Print the result
    if (index != -1)
    {
        printf("Number found at index %d\n", index);
    }
    else
    {
        printf("Number not found\n");
    }
    
    return 0;
}