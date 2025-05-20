//Falcon-180B DATASET v1.0 Category: Error handling ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

int main()
{
    int arr[MAX_SIZE];
    int size = 0;
    int choice = 0;
    int element = 0;
    int searchElement = 0;
    int found = 0;
    int insertPosition = 0;
    int deletePosition = 0;
    int i = 0;
    char input[50];
    char *token = NULL;

    do
    {
        printf("Enter your choice:\n");
        printf("1. Add an element\n");
        printf("2. Delete an element\n");
        printf("3. Search for an element\n");
        printf("4. Display the array\n");
        printf("5. Exit\n");
        scanf("%s", input);
        token = strtok(input, " ");
        choice = atoi(token);

        switch(choice)
        {
            case 1:
                printf("Enter the element to be added:\n");
                scanf("%d", &element);
                if(size >= MAX_SIZE)
                {
                    printf("Error: Array is full\n");
                }
                else
                {
                    arr[size] = element;
                    size++;
                }
                break;

            case 2:
                printf("Enter the element to be deleted:\n");
                scanf("%d", &searchElement);
                found = 0;
                for(i = 0; i < size; i++)
                {
                    if(arr[i] == searchElement)
                    {
                        found = 1;
                        deletePosition = i;
                        break;
                    }
                }
                if(!found)
                {
                    printf("Error: Element not found\n");
                }
                else
                {
                    for(i = deletePosition; i < size - 1; i++)
                    {
                        arr[i] = arr[i + 1];
                    }
                    size--;
                }
                break;

            case 3:
                printf("Enter the element to be searched:\n");
                scanf("%d", &searchElement);
                found = 0;
                for(i = 0; i < size; i++)
                {
                    if(arr[i] == searchElement)
                    {
                        found = 1;
                        break;
                    }
                }
                if(found)
                {
                    printf("Element found at position %d\n", i);
                }
                else
                {
                    printf("Element not found\n");
                }
                break;

            case 4:
                printf("Array:\n");
                for(i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while(choice!= 5);

    return 0;
}