//FormAI DATASET v1.0 Category: Memory management ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
 
int main()
{
    int *ptr[MAX], i, n, option, size, total;
    total = 0;
    printf("\nWelcome to Memory Management System");
    while (1)
    {
        printf("\n\nSelect your option:\n");
        printf("1. Allocate memory\n");
        printf("2. Free memory\n");
        printf("3. Exit\n");
        printf("Enter Option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\nEnter number of blocks to allocate: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("\nEnter the size of memory block %d: ", i + 1);
                scanf("%d", &size);
                ptr[i] = (int *)malloc(size * sizeof(int));
                if (ptr[i] == NULL)
                {
                    printf("\nMemory Allocation failed for block %d", i + 1);
                    break;
                }
                else
                {
                    total += size;
                    printf("\nMemory allocated successfully for block %d", i + 1);
                }
            }
            printf("\nTotal memory allocated: %d bytes", total);
            break;
 
        case 2:
            printf("\nEnter block number to free: ");
            scanf("%d", &i);
            if (i < 0 || i > n)
            {
                printf("\nInvalid block number entered");
            }
            else if (ptr[i - 1] == NULL)
            {
                printf("\nMemory has already been freed for block %d", i);
            }
            else
            {
                free(ptr[i - 1]);
                ptr[i - 1] = NULL;
                printf("\nMemory for block %d has been freed", i);
            }
            break;
 
        case 3:
            printf("\nExiting Memory Management System!\n");
            exit(0);
 
        default:
            printf("\nInvalid Option Selected.");
            break;
        }
    }
    return 0;
}