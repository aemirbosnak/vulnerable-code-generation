//FormAI DATASET v1.0 Category: Memory management ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

#define SIZE 1000000

int main()
{
    void *ptr[10];
    int i, j, size, choice;

    while(1)
    {
        printf("Enter your choice:\n1. Allocate memory\n2. Free memory\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the size of memory you want to allocate (in bytes): ");
                scanf("%d", &size);

                for(i=0; i<10; i++)
                {
                    if(ptr[i]==NULL)
                    {
                        ptr[i]=malloc(size);

                        if(ptr[i]==NULL)
                        {
                            printf("Memory allocation failed\n");
                            break;
                        }
                        else
                        {
                            printf("Memory allocated at address: %p\n", ptr[i]);
                            break;
                        }
                    }
                }

                if(i==10)
                    printf("Memory is already full. Please free some memory to perform allocation\n");

                break;

            case 2:
                printf("Enter the index of the memory block you want to free (1-10): ");
                scanf("%d", &j);

                if(j<1 || j>10)
                {
                    printf("Invalid index entered. Please enter between 1 and 10\n");
                    break;
                }

                if(ptr[j-1]==NULL)
                {
                    printf("Memory block is already empty\n");
                    break;
                }

                free(ptr[j-1]);
                ptr[j-1]=NULL;
                printf("Memory block %d freed successfully\n", j);

                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice entered. Please enter 1, 2 or 3\n");
                break;
        }
    }

    return 0;
}