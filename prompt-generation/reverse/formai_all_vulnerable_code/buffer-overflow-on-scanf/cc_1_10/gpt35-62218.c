//FormAI DATASET v1.0 Category: Math exercise ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle an array
void shuffle(int *arr, int n)
{
    srand(time(NULL));
    for(int i = n-1; i > 0; i--)
    {
        int j = rand() % (i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main()
{
    int a[10], b[10], c[10];
    int i,j,k,n=10;

    printf("Enter 10 integers for array 1:\n");

    // Get values for array a
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Enter 10 integers for array 2:\n");

    // Get values for array b
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }

    // Shuffle array c
    for(i=0; i<n; i++)
    {
        c[i] = i+1;
    }
    shuffle(c, n);

    printf("Unscramble the following equation:\n");

    // Display scrambled equation
    for(i=0; i<n; i++)
    {
        int val = c[i];
        if(val == 1)
        {
            printf("%d * %d ", a[val-1], b[val-1]);
        }
        else if(val == n)
        {
            printf("+ %d = %d\n", b[val-1], a[val-1]*b[val-1]);
        }
        else
        {
            printf("+ %d * %d ", a[val-1], b[val-1]);
        }
    }

    printf("\n");
    printf("Enter your answer:\n");

    // Get user's answer
    int ans;
    scanf("%d", &ans);

    // Calculate correct answer
    int correct_ans = 0;
    for(i=0; i<n; i++)
    {
        int val = c[i];
        if(val == 1)
        {
            correct_ans = a[val-1]*b[val-1];
        }
        else if(val == n)
        {
            correct_ans = correct_ans + b[val-1];
        }
        else
        {
            correct_ans = correct_ans + a[val-1]*b[val-1];
        }
    }

    // Check if the user's answer is correct
    if(ans == correct_ans)
    {
        printf("Congratulations! You are correct!\n");
    }
    else
    {
        printf("Sorry, your answer is incorrect. The correct answer is %d.\n", correct_ans);
    }

    return 0;
}