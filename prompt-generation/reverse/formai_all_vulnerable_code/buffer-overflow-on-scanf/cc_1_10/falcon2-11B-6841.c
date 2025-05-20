//Falcon2-11B DATASET v1.0 Category: Mortgage Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed random number generator

    // Declare variables and arrays
    const int MAX_BOOKS = 10;
    const int MAX_NAME_LENGTH = 20;
    const int MAX_AGE = 120;
    const int MAX_PRICE = 1000;
    char names[MAX_BOOKS][MAX_NAME_LENGTH];
    int ages[MAX_BOOKS];
    int num_books[MAX_BOOKS];
    float prices[MAX_BOOKS];

    // Prompt user for input
    printf("Enter book name: ");
    scanf("%s", names[0]);
    ages[0] = rand() % MAX_AGE;
    num_books[0] = rand() % MAX_BOOKS;
    prices[0] = rand() % MAX_PRICE;

    for (int i = 1; i < MAX_BOOKS; i++)
    {
        printf("Enter book name: ");
        scanf("%s", names[i]);
        ages[i] = rand() % MAX_AGE;
        num_books[i] = rand() % MAX_BOOKS;
        prices[i] = rand() % MAX_PRICE;
    }

    // Calculate average price
    float total_price = 0;
    for (int i = 0; i < MAX_BOOKS; i++)
    {
        total_price += prices[i];
    }

    float average_price = total_price / MAX_BOOKS;

    // Display results
    printf("Book Name\tAge\tNumber of Books\tAverage Price\n");
    for (int i = 0; i < MAX_BOOKS; i++)
    {
        printf("%s\t%d\t%d\t%.2f\n", names[i], ages[i], num_books[i], average_price);
    }

    return 0;
}