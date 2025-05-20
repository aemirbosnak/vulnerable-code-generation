//FormAI DATASET v1.0 Category: Memory Game ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int n, choice1, choice2, temp;
    int i, j, count, ans, p1_score, p2_score;
    char p1_name[20], p2_name[20];
    int arr[16], temp_arr[16], symbol[16];

    srand(time(0));

    printf("Welcome to the Mind-Bending Memory Game!\n\n");
    printf("Player 1, please enter your name: ");
    scanf("%s", p1_name);
    printf("Player 2, please enter your name: ");
    scanf("%s", p2_name);
    printf("\n");

    printf("Instructions:\n");
    printf("1. There are 16 cards arranged in a 4x4 grid.\n");
    printf("2. Each card has a unique symbol.\n");
    printf("3. Players take turns in picking two cards.\n");
    printf("4. If both cards have the same symbol, the player scores a point.\n");
    printf("5. If the symbols are different, the cards are flipped back.\n");
    printf("6. The game ends when all cards have been matched.\n");
    printf("7. The player with the most points at the end wins.\n\n");

    // initializing the cards with unique symbols
    for(i = 0; i < 16; i++)
    {
        arr[i] = rand() % 8;
        symbol[i] = 0;
    }

    // shuffling the cards
    for(i = 0; i < 16; i++)
    {
        j = rand() % 16;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    count = 0;
    ans = 0;
    p1_score = 0;
    p2_score = 0;

    while(count < 16)
    {
        printf("Current board:\n");
        for(i = 0; i < 16; i++)
        {
            if(symbol[i] == 0)
            {
                printf("?");
            }
            else
            {
                printf("%d", arr[i]);
            }

            if((i + 1) % 4 == 0)
            {
                printf("\n");
            }
            else
            {
                printf("\t");
            }
        }
        printf("\n");

        if(ans == 0)
        {
            printf("%s, choose your first card: ", p1_name);
            scanf("%d", &choice1);
            printf("%s, choose your second card: ", p1_name);
            scanf("%d", &choice2);

            if(arr[choice1] == arr[choice2])
            {
                printf("Matched!\n");
                symbol[choice1] = 1;
                symbol[choice2] = 1;
                p1_score++;
                count += 2;
            }
            else
            {
                printf("Not a match.\n");
                ans = 1;
            }
        }
        else
        {
            printf("%s, choose your first card: ", p2_name);
            scanf("%d", &choice1);
            printf("%s, choose your second card: ", p2_name);
            scanf("%d", &choice2);

            if(arr[choice1] == arr[choice2])
            {
                printf("Matched!\n");
                symbol[choice1] = 1;
                symbol[choice2] = 1;
                p2_score++;
                count += 2;
            }
            else
            {
                printf("Not a match.\n");
                ans = 0;
            }
        }

        printf("%s: %d\t%s: %d\n\n", p1_name, p1_score, p2_name, p2_score);
    }

    printf("Final score: %s: %d\t%s: %d\n", p1_name, p1_score, p2_name, p2_score);

    if(p1_score > p2_score)
    {
        printf("%s wins!\n", p1_name);
    }
    else if(p2_score > p1_score)
    {
        printf("%s wins!\n", p2_name);
    }
    else
    {
        printf("It's a tie!\n");
    }

    return 0;
}