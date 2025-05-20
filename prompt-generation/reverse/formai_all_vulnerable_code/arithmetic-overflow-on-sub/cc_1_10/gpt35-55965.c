//FormAI DATASET v1.0 Category: Sorting ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements of the array
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    srand(time(NULL));
    printf("Let's play a game of sorting!\n");

    int n;
    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &n);

    int arr[n];
    printf("Great! Let's fill up the array\n");

    // Fill the array with random numbers
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
        printf("Element %d: %d\n", i, arr[i]);
    }

    printf("Are you ready to sort the array? (y/n): ");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'n')
    {
        printf("That's okay, maybe next time.\n");
        return 0;
    }

    // Sorting begins
    printf("Okay, let's get down to business.\n");
    printf("I'm thinking of a sorting algorithm, can you guess which one?\n");
    printf("Hint: It's named after a popular card game.\n");

    printf("Enter your guess: ");
    char guess[20];
    scanf("%s", guess);

    if (strcmp(guess, "Go Fish") == 0)
    {
        printf("What?! No, that's not even close.\n");
        return 0;
    }

    printf("Okay, let's sort this array using %s.\n", guess);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                printf("Swapping %d (position %d) with %d (position %d)\n", arr[j], j, arr[j + 1], j + 1);
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }

    printf("\nCongratulations, the array is now sorted!\n");
    printf("Here's the sorted array:\n");
    printArray(arr, n);

    printf("Thanks for playing!\n");

    return 0;
}