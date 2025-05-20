//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rating;
    char genre;

    printf("Enter the rating (1-5): ");
    scanf("%d", &rating);

    printf("Enter the genre (comedy, drama, thriller): ");
    scanf(" %c", &genre);

    switch (genre)
    {
        case 'c':
            switch (rating)
            {
                case 1:
                    printf("I endured this comedy.\n");
                    break;
                case 2:
                    printf("This comedy made me chuckle.\n");
                    break;
                case 3:
                    printf("This comedy was side-splitting.\n");
                    break;
                case 4:
                    printf("This comedy was a masterpiece.\n");
                    break;
                case 5:
                    printf("I haven't laughed this much in ages.\n");
                    break;
            }
            break;
        case 'd':
            switch (rating)
            {
                case 1:
                    printf("This drama was emotionally draining.\n");
                    break;
                case 2:
                    printf("This drama was well-acted.\n");
                    break;
                case 3:
                    printf("This drama was a tearjerker.\n");
                    break;
                case 4:
                    printf("This drama was a classic.\n");
                    break;
                case 5:
                    printf("This drama was a masterpiece.\n");
                    break;
            }
            break;
        case 't':
            switch (rating)
            {
                case 1:
                    printf("This thriller kept me on the edge of my seat.\n");
                    break;
                case 2:
                    printf("This thriller was suspenseful.\n");
                    break;
                case 3:
                    printf("This thriller was terrifying.\n");
                    break;
                case 4:
                    printf("This thriller was a nail-biter.\n");
                    break;
                case 5:
                    printf("This thriller was a masterpiece.\n");
                    break;
            }
            break;
        default:
            printf("Invalid genre.\n");
    }

    return 0;
}