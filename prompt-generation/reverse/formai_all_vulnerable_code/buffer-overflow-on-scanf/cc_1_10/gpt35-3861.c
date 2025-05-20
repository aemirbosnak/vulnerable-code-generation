//FormAI DATASET v1.0 Category: Memory management ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Artistic C Memory Management Program
// This program lets you create your own art using dynamic array memory allocation

int main()
{
    int rows, cols, i, j, k;
    char choice;

    printf("Welcome to Artistic C Memory Management Program!\n\n");

    do
    {
        printf("Enter number of rows: ");
        scanf("%d", &rows);

        printf("Enter number of columns: ");
        scanf("%d", &cols);

        // Allocate memory for array
        char **arr = (char**)malloc(rows * sizeof(char*));
        for (i = 0; i < rows; i++)
        {
            arr[i] = (char*)malloc(cols * sizeof(char));
        }

        // Get user input for each character in array
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < cols; j++)
            {
                printf("Enter character for row %d, column %d: ", i+1, j+1);
                scanf(" %c", &arr[i][j]);
            }
        }

        // Print array
        printf("\nHere is your art:\n");
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < cols; j++)
            {
                printf("%c", arr[i][j]);
            }
            printf("\n");
        }
        
        // Ask user if they want to continue
        printf("\nDo you want to create another art piece? (y/n): ");
        scanf(" %c", &choice);

        // Free memory allocated for array
        for (i = 0; i < rows; i++)
        {
            free(arr[i]);
        }
        free(arr);
    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for using Artistic C Memory Management Program!");

    return 0;
}