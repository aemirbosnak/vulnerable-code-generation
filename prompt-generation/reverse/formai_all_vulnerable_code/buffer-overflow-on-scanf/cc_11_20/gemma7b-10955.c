//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rating = 0;
    char side = 'a';

    printf("Enter your side (a/b): ");
    scanf("%c", &side);

    printf("Enter your rating (1-10): ");
    scanf("%d", &rating);

    switch (side)
    {
        case 'a':
            switch (rating)
            {
                case 1:
                    printf("Your rating is a disgrace. Go back to the cave.\n");
                    break;
                case 2:
                    printf("Your rating is better than a drunken sailor's, but not enough.\n");
                    break;
                case 3:
                    printf("Your rating is respectable, but you could do better.\n");
                    break;
                case 4:
                    printf("Your rating is worthy of a sonnet.\n");
                    break;
                case 5:
                    printf("Your rating is excellent. You are a master of the art.\n");
                    break;
                default:
                    printf("Invalid rating.\n");
            }
            break;
        case 'b':
            switch (rating)
            {
                case 1:
                    printf("Your rating is an insult to our family. We will not forget.\n");
                    break;
                case 2:
                    printf("Your rating is pathetic. We will drown you in our hate.\n");
                    break;
                case 3:
                    printf("Your rating is disgraceful. We will cast you out of our society.\n");
                    break;
                case 4:
                    printf("Your rating is cowardly. We will never forget your shame.\n");
                    break;
                case 5:
                    printf("Your rating is terrible. We will destroy you.\n");
                    break;
                default:
                    printf("Invalid rating.\n");
            }
            break;
        default:
            printf("Invalid side.\n");
    }

    return 0;
}