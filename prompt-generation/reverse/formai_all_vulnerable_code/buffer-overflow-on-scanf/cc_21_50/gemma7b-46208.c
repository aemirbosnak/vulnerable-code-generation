//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rating;
    char genre;
    printf("Welcome to the CineSavant Rating System!\n");
    printf("Please enter the rating (1-5): ");
    scanf("%d", &rating);
    printf("Please enter the genre (A, C, F, H): ");
    scanf(" %c", &genre);

    switch (genre)
    {
        case 'A':
            printf("For action-adventure, the rating is: ");
            switch (rating)
            {
                case 1:
                    printf("Meh.\n");
                    break;
                case 2:
                    printf("Not bad.\n");
                    break;
                case 3:
                    printf("Good.\n");
                    break;
                case 4:
                    printf("Great!\n");
                    break;
                case 5:
                    printf("Epic!\n");
                    break;
            }
            break;
        case 'C':
            printf("For comedy, the rating is: ");
            switch (rating)
            {
                case 1:
                    printf("Ha! Ha!\n");
                    break;
                case 2:
                    printf("Haha! Haha!\n");
                    break;
                case 3:
                    printf("Lol! Lol! Lol!\n");
                    break;
                case 4:
                    printf("Side-splitting!\n");
                    break;
                case 5:
                    printf("Classic!\n");
                    break;
            }
            break;
        case 'F':
            printf("For fantasy, the rating is: ");
            switch (rating)
            {
                case 1:
                    printf("Meh.\n");
                    break;
                case 2:
                    printf("Not bad.\n");
                    break;
                case 3:
                    printf("Good.\n");
                    break;
                case 4:
                    printf("Epic!\n");
                    break;
                case 5:
                    printf("Legendary!\n");
                    break;
            }
            break;
        case 'H':
            printf("For horror, the rating is: ");
            switch (rating)
            {
                case 1:
                    printf("Boo hoo!\n");
                    break;
                case 2:
                    printf("Mwahahaha! \n");
                    break;
                case 3:
                    printf("Scared the crap out of me!\n");
                    break;
                case 4:
                    printf("Bloodcurdling!\n");
                    break;
                case 5:
                    printf("Classic scare!\n");
                    break;
            }
            break;
    }

    return 0;
}