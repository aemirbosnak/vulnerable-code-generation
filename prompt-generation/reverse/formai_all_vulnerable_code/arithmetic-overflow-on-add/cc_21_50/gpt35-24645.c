//FormAI DATASET v1.0 Category: Memory Game ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i, j, k, n, temp, count = 0, index1, index2;
    int *a;  // array to store randomly generated numbers
    printf("Enter the number of cards:");
    scanf("%d", &n);

    if(n%2==1)   //if the number of cards is odd, turn it into an even number
    {
        printf("The number of cards has been changed to %d in order to start with pairs.\n", n+1);
        n++;
    }

    a = (int *) malloc(sizeof(int)*n);  //dynamically allocate memory for the array

    for(i = 0; i < n; i+=2) //generate pairs of random numbers
    {
        a[i] = rand()%100 + 1;
        a[i+1] = a[i];
    }

    srand((unsigned) time(NULL));   // seed the random number generator with the current time

    for(i = 0; i < n; i++)  //shuffle the array to mix up the pairs
    {
        j = rand()%(n-i)+i; //pick a random index
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    int table[n/2][2];  //2D array to represent the memory game table
    for(i = 0; i < n/2; i++) //populate the table with the generated pairs of numbers
    {
        table[i][0] = a[i*2];
        table[i][1] = a[i*2+1];
    }

    int shownTable[n/2][2]; //2D array to keep track of which cards have been shown and matched
    for(i = 0; i < n/2; i++) //initialize all values to 0 (not shown, not matched)
    {
        for(j = 0; j < 2; j++)
        {
            shownTable[i][j] = 0;
        }
    }

    while(count < n/2) //keep playing until all pairs have been matched
    {
        printf("\nMemory game - Match pairs by entering row and column of cards\n\n");
        printf("       ");
        for(k = 0; k < n/2; k++) //print the column numbers
        {
            printf(" %2d", k+1);
        }
        printf("\n");
        for(i = 0; i < n/2; i++) //print the table with values hidden or shown
        {
            printf(" Row %d ", i+1);
            for(j = 0; j < 2; j++)
            {
                if(shownTable[i][j]==1)
                {
                    printf(" %2d", table[i][j]);
                }
                else
                {
                    printf(" xx");
                }
            }
            printf("\n");
        }
        printf("\nEnter the row and column of the first card to reveal:\n");
        scanf("%d %d", &index1, &index2);
        index1--; //decrease by 1 to match 0-based array indexing
        index2--;
        shownTable[index1][index2] = 1; //mark the card as shown
        printf("\n       ");
        for(k = 0; k < n/2; k++)
        {
            printf(" %2d", k+1);
        }
        printf("\n");
        for(i = 0; i < n/2; i++)
        {
            printf(" Row %d ", i+1);
            for(j = 0; j < 2; j++)
            {
                if(shownTable[i][j]==1)
                {
                    printf(" %2d", table[i][j]);
                }
                else
                {
                    printf(" xx");
                }
            }
            printf("\n");
        }
        printf("\nEnter the row and column of the second card to reveal:\n");
        scanf("%d %d", &index1, &index2);
        index1--;
        index2--;
        shownTable[index1][index2] = 1;
        printf("\n       ");
        for(k = 0; k < n/2; k++)
        {
            printf(" %2d", k+1);
        }
        printf("\n");
        for(i = 0; i < n/2; i++)
        {
            printf(" Row %d ", i+1);
            for(j = 0; j < 2; j++)
            {
                if(shownTable[i][j]==1)
                {
                    printf(" %2d", table[i][j]);
                }
                else
                {
                    printf(" xx");
                }
            }
            printf("\n");
        }
        if(table[index1][index2]==table[index1][index2-1]) //if a pair has been found
        {
            printf("\nCongratulations! You found a pair of %d's!\n", table[index1][index2]);
            shownTable[index1][index2-1] = 1; //mark both cards as matched
            count++;
        }
        else
        {
            printf("\nSorry, the selected cards are not a pair. Better luck next time!\n");
            shownTable[index1][index2] = 0; //hide both cards again
            shownTable[index1][index2-1] = 0;
        }
    }
    printf("\nYou have matched all pairs! Well done!\n");
    return 0;
}