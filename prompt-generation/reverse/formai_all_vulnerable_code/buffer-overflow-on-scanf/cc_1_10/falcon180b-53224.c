//Falcon-180B DATASET v1.0 Category: Error handling ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 100
#define ERROR_CODE -1

int main()
{
    int array[MAX_SIZE];
    int size = 0;
    int choice, element;
    bool error = false;

    do
    {
        printf("\n1. Add element to array\n2. Display array\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(size == MAX_SIZE)
                {
                    printf("Error: Array is full.\n");
                }
                else
                {
                    printf("Enter element to add: ");
                    scanf("%d", &element);
                    array[size++] = element;
                }
                break;

            case 2:
                if(size == 0)
                {
                    printf("Error: Array is empty.\n");
                }
                else
                {
                    printf("Array elements: ");
                    for(int i=0; i<size; i++)
                    {
                        printf("%d ", array[i]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Error: Invalid choice.\n");
                error = true;
        }

    }while(error);

    return 0;
}