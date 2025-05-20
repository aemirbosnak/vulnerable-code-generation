//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main()
{
    int n, i, j;
    int arr[MAX_SIZE];
    char choice;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("\nEnter your choice:\n");
        printf("1. Bitwise OR\n");
        printf("2. Bitwise AND\n");
        printf("3. Bitwise XOR\n");
        printf("4. Bitwise NOT\n");
        printf("5. Left Shift\n");
        printf("6. Right Shift\n");
        printf("7. Exit\n");
        scanf(" %c", &choice);

        switch (choice)
        {
            case '1':
                printf("Bitwise OR of the elements:\n");
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < n; j++)
                    {
                        printf("%d ", arr[i] | arr[j]);
                    }
                    printf("\n");
                }
                break;

            case '2':
                printf("Bitwise AND of the elements:\n");
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < n; j++)
                    {
                        printf("%d ", arr[i] & arr[j]);
                    }
                    printf("\n");
                }
                break;

            case '3':
                printf("Bitwise XOR of the elements:\n");
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < n; j++)
                    {
                        printf("%d ", arr[i] ^ arr[j]);
                    }
                    printf("\n");
                }
                break;

            case '4':
                printf("Bitwise NOT of the elements:\n");
                for (i = 0; i < n; i++)
                {
                    printf("%d ", ~arr[i]);
                }
                break;

            case '5':
                printf("Left Shift of the elements:\n");
                for (i = 0; i < n; i++)
                {
                    printf("%d ", arr[i] << 2);
                }
                break;

            case '6':
                printf("Right Shift of the elements:\n");
                for (i = 0; i < n; i++)
                {
                    printf("%d ", arr[i] >> 2);
                }
                break;

            case '7':
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= '7');

    return 0;
}