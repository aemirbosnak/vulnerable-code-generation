//FormAI DATASET v1.0 Category: File handling ; Style: brave
//This program demonstrates a unique implementation of file handling in C
//The program reads data from a file into an array, modifies the data and writes it back to the same file
//Author: [Your Name]
#include<stdio.h>

int main()
{
    //open the file in read mode
    FILE *fptr = fopen("data.txt", "r");
    if(fptr == NULL)
    {
        printf("Error opening file!");
        return -1;
    }
    
    //read the data from the file into an array
    int arr[10];
    int i;
    for(i = 0; i < 10; i++)
    {
        fscanf(fptr, "%d", &arr[i]);
    }
    
    //close the file
    fclose(fptr);
    
    //display the array
    printf("Array before modification: ");
    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    //modify the array
    for(i = 0; i < 10; i++)
    {
        arr[i] = arr[i] * 2;
    }
    
    //open the file in write mode
    fptr = fopen("data.txt", "w");
    if(fptr == NULL)
    {
        printf("Error opening file!");
        return -1;
    }
    
    //write the modified data back to the file
    for(i = 0; i < 10; i++)
    {
        fprintf(fptr, "%d ", arr[i]);
    }
    
    //close the file
    fclose(fptr);
    
    //display the array
    printf("Array after modification: ");
    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    //done
    return 0;
}