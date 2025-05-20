//FormAI DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

//Binary search function
int binarySearch(int array[], int left, int right, int key)
{
    int center;

    while(left <= right)
    {
        center = left + (right-left)/2;

        //Key found
        if(array[center] == key)
        {
            return center;
        }

        //Key is in the left half
        if(key < array[center])
        {
            right = center - 1;
        }

        //Key is in the right half
        else
        {
            left = center + 1;
        }
    }

    //Key not found
    return -1;
}

//Main function to execute program
int main()
{
    //Welcome message
    printf("Greetings, noble knights! I am thy trusty searching algorithm, here to aid thee in thy battles!\n");

    //Declare and initialize variables
    int array[SIZE] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int key, position;

    printf("Enter the number thou seeketh: ");
    scanf("%d", &key);

    //Search for key using our algorithm
    position = binarySearch(array, 0, SIZE - 1, key);

    //If key is found
    if(position != -1)
    {
        printf("Thee hath found %d at position %d in the array!\n", key, position + 1);
    }

    //If key is not found
    else
    {
        printf("Apologies, noble knights. %d is not present in the array.\n", key);
    }

    //Farewell message
    printf("Until we meet again, my dear knights!\n");
    return 0;
}