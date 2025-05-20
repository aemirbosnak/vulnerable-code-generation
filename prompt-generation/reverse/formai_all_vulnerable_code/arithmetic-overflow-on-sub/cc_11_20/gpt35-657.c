//FormAI DATASET v1.0 Category: System administration ; Style: statistical
#include <stdio.h>
#include <math.h>

int main()
{
    int num, i, j, flag;
    printf("Enter the number of elements: ");
    scanf("%d", &num);
    
    int arr[num];
    printf("Enter %d integers: ", num);
    for (i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("\nThe prime numbers in the array are: ");
    for (i = 0; i < num; i++)
    {
        flag = 0;
        for (j = 2; j <= sqrt(arr[i]); j++)
        {
            if (arr[i] % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0 && arr[i] > 1)
        {
            printf("%d ", arr[i]);
        }
    }
    
    int sum = 0;
    for (i = 0; i < num; i++)
    {
        sum += arr[i];
    }
    float avg = (float)sum / (float)num;
    printf("\n\nThe sum of the array is: %d", sum);
    printf("\nThe average of the array is: %.2f", avg);
    
    int temp;
    for (i = 0; i < num; i++)
    {
        for (j = i+1; j < num; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("\n\nThe sorted array is: ");
    for (i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }
    
    printf("\n\nThe maximum element in the array is: %d", arr[num-1]);
    printf("\nThe minimum element in the array is: %d", arr[0]);
    
    return 0;
}