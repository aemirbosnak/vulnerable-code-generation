//FormAI DATASET v1.0 Category: Educational ; Style: thoughtful
/*
  This program is designed to generate and sort a list of randomly generated numbers.

  Firstly, the user is prompted to input the total number of integers to be generated.

  After which, a loop is initiated to generate a random number between 0 to total number of integers.

  These random integers are then stored in an array and printed for user observation.

  The integers are then sorted using the bubble sort algorithm and printed again for user observation.

  The program concludes by displaying the largest and smallest numbers generated.
*/

#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       
 
int main() 
{
    int total_nums, temp, i, j;
    int max = 0, min = 0;
     
    printf("Enter the total numbers to generate: ");
    scanf("%d", &total_nums);
    
    int nums[total_nums];
    
    srand(time(0));
    
    for(i = 0; i < total_nums; i++) 
    {
        nums[i] = rand() % total_nums;
        printf("%d ", nums[i]);
    }
    
    //Bubble Sort Algorithm
    for(i = 0; i < total_nums-1; i++) 
    {
        for(j = i+1; j < total_nums; j++) 
        {
            if(nums[i] > nums[j]) 
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }   
    }

    printf("\n\nSorted List:\n");
    for(i = 0; i < total_nums; i++) 
    {
        printf("%d ", nums[i]);
    }
    
    printf("\n\nLargest Number: %d", nums[total_nums-1]);
    printf("\nSmallest Number: %d", nums[0]);
 
    return 0; 
}