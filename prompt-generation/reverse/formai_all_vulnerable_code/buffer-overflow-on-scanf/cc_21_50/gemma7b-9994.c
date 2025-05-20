//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: secure
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rating;
    char genre;
    printf("Enter the rating (1-5): ");
    scanf("%d", &rating);
    printf("Enter the genre (A, B, C, D, E): ");
    scanf(" %c", &genre);

    switch (genre)
    {
        case 'A':
            printf("The movie is an action film. The rating is: ");
            switch (rating)
            {
                case 1:
                    printf("1/5\n");
                    break;
                case 2:
                    printf("2/5\n");
                    break;
                case 3:
                    printf("3/5\n");
                    break;
                case 4:
                    printf("4/5\n");
                    break;
                case 5:
                    printf("5/5\n");
                    break;
            }
            break;
        case 'B':
            printf("The movie is a drama film. The rating is: ");
            switch (rating)
            {
                case 1:
                    printf("1/5\n");
                    break;
                case 2:
                    printf("2/5\n");
                    break;
                case 3:
                    printf("3/5\n");
                    break;
                case 4:
                    printf("4/5\n");
                    break;
                case 5:
                    printf("5/5\n");
                    break;
            }
            break;
        case 'C':
            printf("The movie is a comedy film. The rating is: ");
            switch (rating)
            {
                case 1:
                    printf("1/5\n");
                    break;
                case 2:
                    printf("2/5\n");
                    break;
                case 3:
                    printf("3/5\n");
                    break;
                case 4:
                    printf("4/5\n");
                    break;
                case 5:
                    printf("5/5\n");
                    break;
            }
            break;
        case 'D':
            printf("The movie is a thriller film. The rating is: ");
            switch (rating)
            {
                case 1:
                    printf("1/5\n");
                    break;
                case 2:
                    printf("2/5\n");
                    break;
                case 3:
                    printf("3/5\n");
                    break;
                case 4:
                    printf("4/5\n");
                    break;
                case 5:
                    printf("5/5\n");
                    break;
            }
            break;
        case 'E':
            printf("The movie is an horror film. The rating is: ");
            switch (rating)
            {
                case 1:
                    printf("1/5\n");
                    break;
                case 2:
                    printf("2/5\n");
                    break;
                case 3:
                    printf("3/5\n");
                    break;
                case 4:
                    printf("4/5\n");
                    break;
                case 5:
                    printf("5/5\n");
                    break;
            }
            break;
    }

    return 0;
}