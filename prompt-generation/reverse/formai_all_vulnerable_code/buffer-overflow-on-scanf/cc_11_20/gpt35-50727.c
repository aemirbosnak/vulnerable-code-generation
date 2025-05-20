//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Romeo and Juliet
#include<stdio.h>

int main()
{
    int rating;
    printf("O Romeo, what rating shall thou give this movie?\n");
    printf("I, Juliet, shall give it a score out of ten.\n");
    printf("Enter your rating, my love: \n");
    scanf("%d",&rating);

    if(rating>10)
    {
        printf("Oh Romeo, thy score is too high, please enter a number less than ten\n");
        scanf("%d",&rating);
    }
    else if(rating<1)
    {
        printf("Dearest Romeo, thy score is too low, please enter a number greater than zero.\n");
        scanf("%d",&rating);
    }
    else
    {
        printf("Thou hath given %d out of ten, my dear Romeo.\n", rating);
    }

    printf("Now let us compare our opinions on this movie, my love.\n");
    printf("What is thy opinion, dear Romeo?\n");
    char opinion[20];
    scanf("%s",opinion);

    printf("Thou art %s, oh Romeo? Interesting...\n", opinion);
    printf("My opinion of this movie is that it dost be:\n");

    switch(rating)
    {
        case 10:
        case 9:
            printf("A Masterpiece!\n");
            break;

        case 8:
        case 7:
            printf("Very Good, Indeed!\n");
            break;

        case 6:
        case 5:
            printf("Fair at Best.\n");
            break;

        case 4:
        case 3:
            printf("A downright Flop!\n");
            break;

        case 2:
        case 1:
            printf("Unwatchable Trash!\n");
            break;

        default:
            printf("I shall not give an opinion on this rating.\n");
            break;
    }
    return 0;
}