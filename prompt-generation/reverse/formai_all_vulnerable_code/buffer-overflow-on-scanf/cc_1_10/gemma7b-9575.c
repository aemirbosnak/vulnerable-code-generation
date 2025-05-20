//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rating;
    char genre;
    float budget;

    printf("Enter the movie rating (1-5): ");
    scanf("%d", &rating);

    printf("Enter the movie genre (A-C): ");
    scanf(" %c", &genre);

    printf("Enter the movie budget (in millions): ");
    scanf("%f", &budget);

    switch (genre)
    {
        case 'A':
            if (rating >= 3 && budget >= 50)
            {
                printf("You will enjoy this romantic comedy.\n");
            }
            else
            {
                printf("This romantic comedy may not be your cup of tea.\n");
            }
            break;
        case 'B':
            if (rating >= 4 && budget >= 75)
            {
                printf("You will love this action-adventure film.\n");
            }
            else
            {
                printf("This action-adventure film may not be your cup of tea.\n");
            }
            break;
        case 'C':
            if (rating >= 2 && budget >= 30)
            {
                printf("You will enjoy this drama.\n");
            }
            else
            {
                printf("This drama may not be your cup of tea.\n");
            }
            break;
    }

    return 0;
}