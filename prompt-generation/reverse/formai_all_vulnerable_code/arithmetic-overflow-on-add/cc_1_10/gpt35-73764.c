//FormAI DATASET v1.0 Category: Memory management ; Style: visionary
#include<stdio.h> 
#include<stdlib.h> 

int main() 
{ 
    //Welcome statement
    printf("Welcome to Innovative Memory Management Program\n\n");
  
    //Declaring variables
    int num, i, *ptr, sum = 0;
  
    //Getting input from user
    printf("Enter number of elements: "); 
    scanf("%d", &num); 
  
    //Dynamic memory allocation using malloc() 
    ptr = (int*) malloc(num * sizeof(int)); 
  
    //Check if memory is allocated successfully or not 
    if(ptr == NULL)                     
    { 
        printf("Memory not allocated.\n"); 
        exit(0); 
    } 
    else 
    {
        //Getting input for array elements from user
        printf("Enter elements of array:\n");
        for(i = 0; i < num; ++i)
        {
            scanf("%d", ptr + i);
            sum += *(ptr + i);
        }
 
        //Printing the array elements with sum
        printf("The elements of array are: ");
        for(i = 0; i < num; ++i)
        {
            printf("%d ", *(ptr + i));
        }
        printf("\nSum of array elements is: %d\n", sum);
        
        //Reallocate memory using realloc()
        printf("\nWant to allocate more memory? Enter number of additional elements you want to add: ");
        int add;
        scanf("%d", &add);
        ptr = realloc(ptr, (num+add)*sizeof(int));
        
        //Getting input for additional elements from user
        printf("\nEnter %d more elements of array:\n", add);
        for(i = num; i < num+add; ++i)
        {
            scanf("%d", ptr+i);
            sum += *(ptr + i);
        }
        
        //Printing the updated array elements with updated sum
        printf("\nThe updated elements of array are: ");
        for(i = 0; i < num+add; ++i)
        {
            printf("%d ", *(ptr + i));
        }
        printf("\nUpdated Sum of array elements is: %d\n", sum);
        free(ptr); //free memory used by program
        return 0; //end program
    } 
}