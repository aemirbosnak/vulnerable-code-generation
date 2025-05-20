//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to shuffle array of elements
void shuffle(int arr[], int n)
{
    srand(time(NULL));
    for (int i = n - 1; i >= 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main()
{
    // declare variables and arrays
    int score = 0;
    int total = 0;
    int answer;
    int elements[] = {3, 11, 19, 35, 54, 94};
    char symbols[] = {'Li', 'Na', 'K', 'Br', 'Xe', 'Pu'};
    char names[] = {'Lithium', 'Sodium', 'Potassium', 'Bromine', 'Xenon', 'Plutonium'};

    // shuffle the array of elements
    shuffle(elements, 6);

    // loop through each element
    for (int i = 0; i < 6; i++)
    {
        printf("What is the symbol for %s?\n", names[elements[i]-1]);
        scanf("%s", &answer);

        // check if answer is correct
        if (answer == symbols[elements[i]-1])
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect. The correct symbol is %s.\n", symbols[elements[i]-1]);
        }

        total++;
    }

    // give final score
    printf("You scored %d out of %d.\n", score, total);

    return 0;
}