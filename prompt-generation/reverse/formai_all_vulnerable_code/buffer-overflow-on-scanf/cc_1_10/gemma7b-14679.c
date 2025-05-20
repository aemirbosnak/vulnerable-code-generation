//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rating = 0;
    char genre = ' ';

    printf("Welcome to the Sherlock Holmes Movie Rating System!\n");
    printf("Please enter the genre of the movie: ");
    scanf("%c", &genre);

    printf("Please enter the rating of the movie (1-10): ");
    scanf("%d", &rating);

    switch (genre)
    {
        case 'c':
            if (rating >= 8)
            {
                printf("A fine film, worthy of a bow to the detective.\n");
            }
            else
            {
                printf("A disappointing outing, even for a detective of your caliber.\n");
            }
            break;
        case 'a':
            if (rating >= 6)
            {
                printf("A gripping tale, with a strong performance from the detective.\n");
            }
            else
            {
                printf("A dull and uninspired mystery, even a novice detective could crack.\n");
            }
            break;
        case 'f':
            if (rating >= 7)
            {
                printf("A masterfully crafted film, worthy of a standing ovation.\n");
            }
            else
            {
                printf("A poorly paced and unoriginal mystery, even a seasoned detective would find tiresome.\n");
            }
            break;
        default:
            printf("Invalid genre selection.\n");
    }

    return 0;
}