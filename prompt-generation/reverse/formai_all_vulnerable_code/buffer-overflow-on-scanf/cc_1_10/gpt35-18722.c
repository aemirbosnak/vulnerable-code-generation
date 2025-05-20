//FormAI DATASET v1.0 Category: Searching algorithm ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

//Energetic C Searching Algorithm Example

int main()
{
    int arr[] = {1, 4, 5, 8, 9, 11, 14, 15, 19, 25, 31, 33};
    int n = sizeof(arr)/sizeof(arr[0]);
    int search, i, flag = 0;

    printf("Let's energize your search! Enter the number you want to search: ");
    scanf("%d", &search);

    //linear search
    for(i=0; i<n; i++)
    {
        if(arr[i] == search)
        {
            printf("Hurray! The number is found at index %d\n", i);
            flag = 1;
            break;
        }
    }

    //if number is not found through linear search, move on to binary search
    if(flag == 0)
    {
        printf("Sorry, but we couldn't find the number with linear search.\nBut, don't give up! Let's do a binary search now.\n");

        int first = 0, last = n-1, middle;

        //Binary search implementation
        while(first <= last)
        {
            middle = (first + last)/2;
            if(arr[middle] == search)
            {
                printf("Yay! The number is found at index %d\n", middle);
                flag = 1;
                break;
            }
            else if(arr[middle] < search)
            {
                first = middle + 1;
            }
            else if(arr[middle] > search)
            {
                last = middle - 1;
            }
        }
    }

    //if number is not found through binary search as well, display error message
    if(flag == 0)
    {
        printf("Sorry, the number you have searched for does not exist in the given array.\nDon't worry, there will be other opportunities to find your lucky number!\n");
    }

    return 0;
}