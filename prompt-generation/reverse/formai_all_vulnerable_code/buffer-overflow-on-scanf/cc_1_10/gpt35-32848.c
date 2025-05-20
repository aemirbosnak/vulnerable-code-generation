//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: systematic
#include<stdio.h> 

void bucketSort(float arr[], int n) 
{ 
    // Create n empty buckets 
    int i, j; 
    int count[n]; 
    for (i = 0; i < n; i++) 
        count[i] = 0; 
        
    // Add elements into the respective buckets
    for (i = 0; i < n; i++) 
    { 
       int bucket = n*arr[i];  
       count[bucket]++; 
    } 

    //Sort each bucket using insertion sort 
    for (i = 0; i < n; i++) 
    { 
        int k = 0; 
        float bucket[n]; 

        for (j = 0; j < n; j++) 
            bucket[j] = 0; 
            
        for (j = 0; j < count[i]; j++) 
            bucket[k++] = arr[j]; 
            
        for (j = 1; j < k; j++) 
        { 
            float temp = bucket[j]; 
            int l = j - 1;  
            while (l >= 0 && bucket[l] > temp) 
            { 
                bucket[l+1] = bucket[l]; 
                l--; 
            } 
            bucket[l+1] = temp; 
        } 

        // Copy the sorted elements of bucket back into the original array 
        for (j = 0; j < k; j++) 
            arr[j] = bucket[j]; 
    } 
} 

// Driver program to test above function 
int main() 
{ 
    int n; 
    printf("Enter the size of the array to be sorted: "); 
    scanf("%d", &n); 
    
    float arr[n]; 
    printf("\nEnter the elements of the array:\n"); 
    for (int i = 0; i < n; i++) 
        scanf("%f", &arr[i]); 
        
    printf("\nUnsorted array: "); 
    for(int i=0; i<n; i++)
        printf("%f ", arr[i]); 

    //Sort the given array using Bucket Sort 
    bucketSort(arr, n); 
    
    printf("\n\nBucket sorted array: "); 
    for(int i=0; i<n; i++)
        printf("%f ", arr[i]); 
        
    return 0; 
}