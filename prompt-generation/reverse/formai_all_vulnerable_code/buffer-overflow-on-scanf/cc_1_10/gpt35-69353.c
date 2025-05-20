//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function declaration */
void shuffle(int array[], int n);

int main()
{
    int score = 0, choice, answer;
    int atomic_numbers[10] = {54, 28, 8, 33, 79, 17, 15, 45, 72, 2};
    char element_symbols[10] = {'Xe', 'Ni', 'O', 'As', 'Au', 'Cl', 'P', 'Rh', 'Hf', 'He'};

    /* Randomize the atomic number array */
    srand(time(0));
    shuffle(atomic_numbers, 10);

    printf("\nWelcome to the Periodic Table Quiz!\n\n");
    printf("You will be given 10 questions to answer in this quiz.\n");
    printf("Each question will display the element symbol and a description of the element.\n");
    printf("You must choose the correct atomic number of the element.\n");

    /* Loop through the quiz */
    for(int i = 0; i < 10; i++)
    {
        printf("\nQuestion %d:\n", i+1);
        printf("Element: %c\n", element_symbols[i]);

        switch(atomic_numbers[i])
        {
            case 54:
                printf("Description: A colorless, odorless noble gas.\n");
                break;
            case 28:
                printf("Description: A silver-white metal that is used extensively in coins, plumbing, and electrical wiring.\n");
                break;
            case 8:
                printf("Description: A highly reactive nonmetal that is found in water and many rocks.\n");
                break;
            case 33:
                printf("Description: A brittle, silvery-white metalloid. It has many uses in the electronics industry.\n");
                break;
            case 79:
                printf("Description: A soft, dense, yellow metal that is highly valued for its beauty and rarity.\n");
                break;
            case 17:
                printf("Description: A greenish-yellow gas that is highly reactive and forms compounds with nearly all other elements.\n");
                break;
            case 15:
                printf("Description: A nonmetal that is an essential component of all living organisms.\n");
                break;
            case 45:
                printf("Description: A hard, silvery-white metal that is used to make jewelry and is also used in catalytic converters.\n");
                break;
            case 72:
                printf("Description: A dense, silvery-white metal that is used extensively in the aerospace industry.\n");
                break;
            case 2:
                printf("Description: A colorless, odorless gas that is the lightest element on the periodic table.\n");
                break;
            default:
                printf("Error: Invalid atomic number.\n");
        }

        printf("\nPlease enter your answer: ");
        scanf("%d", &choice);

        /* Check the answer */
        if(choice == atomic_numbers[i])
        {
            printf("Congratulations! You are correct.\n");
            score++;
        }
        else
        {
            printf("Sorry, the correct answer is %d.\n", atomic_numbers[i]);
        }
    }

    printf("\nQuiz complete!\n");
    printf("You scored %d out of 10.\n", score);

    return 0;
}

/* Function to shuffle an array */
void shuffle(int array[], int n)
{
    if(n > 1)
    {
        for(int i = 0; i < n - 1; i++)
        {
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
}