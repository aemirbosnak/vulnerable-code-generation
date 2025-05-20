//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i, j, k, l, count = 0;
    char arr[10][10];
    char temp[10];
    int flag = 0;
    int m = 0;
    int p = 0;
    int q = 0;
    int r = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("\nEnter the elements:\n");

    for(i=0; i<n; i++)
    {
        scanf("%s", arr[i]);
    }

    srand(time(0));
    int rand_index;
    for(k=0; k<n; k++)
    {
        rand_index = rand()%n;
        temp[0] = arr[k][0];
        arr[k][0] = arr[rand_index][0];
        arr[rand_index][0] = temp[0];

        for(l=1; l<10; l++)
        {
            temp[l] = arr[k][l];
            arr[k][l] = arr[rand_index][l];
            arr[rand_index][l] = temp[l];
        }
    }

    printf("\nShuffled array:\n");

    for(i=0; i<n; i++)
    {
        printf("%s\n", arr[i]);
    }

    return 0;
}