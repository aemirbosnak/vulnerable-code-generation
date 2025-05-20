//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char rating;
    int score;

    printf("Welcome to the Sherlock Holmes C Movie Rating System!\n");
    printf("Please enter the letter of your rating (A, B, C, D, E): ");
    scanf("%c", &rating);

    printf("Please enter your score (0-10): ");
    scanf("%d", &score);

    switch (rating)
    {
        case 'A':
            if (score >= 8)
            {
                printf("Excellent! You have the mind of Sherlock Holmes himself.\n");
            }
            else
            {
                printf("A good start, but you could do better. Perhaps you need to consult the detective's handbook.\n");
            }
            break;
        case 'B':
            if (score >= 6)
            {
                printf("Very good. You have the deductive abilities of a master detective.\n");
            }
            else
            {
                printf("You have a keen eye for detail, but your reasoning is a bit weak. Try to sharpen your mind.\n");
            }
            break;
        case 'C':
            if (score >= 4)
            {
                printf("Acceptable. You have the ability to see the obvious, but you could improve your detective work.\n");
            }
            else
            {
                printf("Your detective work is poor. You need to re-examine the case and try again.\n");
            }
            break;
        case 'D':
            if (score >= 2)
            {
                printf("Below average. You have a limited understanding of detective work. Perhaps you should take a break.\n");
            }
            else
            {
                printf("Your detective work is terrible. You should go back to school.\n");
            }
            break;
        case 'E':
            printf("I'm sorry, but I cannot rate your movie. You have not provided me with enough information.\n");
            break;
    }

    return 0;
}