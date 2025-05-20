//FormAI DATASET v1.0 Category: Movie Rating System ; Style: protected
#include <stdio.h>

void display_menu()
{
    printf("C Movie Rating System\n");
    printf("---------------------\n");
    printf("\t1. Add a movie\n");
    printf("\t2. View all movies\n");
    printf("\t3. Rate a movie\n");
    printf("\t4. View movie ratings\n");
    printf("\t5. Exit\n\n");
    printf("Enter an option: ");
}

int main()
{
    int choice, num_movies = 0;
    char movie_name[50][100];
    float movie_rating[50] = {0};
    int movie_ratings[50][5] = {0};

    display_menu();
    scanf("%d", &choice);

    while (choice != 5)
    {
        switch (choice)
        {
            case 1:
                // add a movie
                printf("\nEnter movie name: ");
                scanf("%s", movie_name[num_movies]);
                printf("Movie '%s' added successfully!\n", movie_name[num_movies]);
                num_movies++;
                break;

            case 2:
                // view all movies
                if (num_movies == 0)
                {
                    printf("\nNo movies found. Please add a movie first.\n");
                }
                else
                {
                    printf("\nAll movies:\n");
                    for (int i = 0; i < num_movies; i++)
                    {
                        printf("%d. %s\n", i+1, movie_name[i]);
                    }
                }
                break;

            case 3:
                // rate a movie
                if (num_movies == 0)
                {
                    printf("\nNo movies found. Please add a movie first.\n");
                }
                else
                {
                    printf("\nEnter movie number: ");
                    int movie_num;
                    scanf("%d", &movie_num);
                    if (movie_num <= 0 || movie_num > num_movies)
                    {
                        printf("\nInvalid movie number. Please try again.\n");
                        break;
                    }
                    printf("\nEnter rating (1 to 5): ");
                    int rating;
                    scanf("%d", &rating);
                    if (rating < 1 || rating > 5)
                    {
                        printf("\nInvalid rating. Please try again.\n");
                        break;
                    }
                    movie_rating[movie_num-1] = (movie_rating[movie_num-1] * movie_ratings[movie_num-1][rating-1] + rating) / (movie_ratings[movie_num-1][rating-1] + 1);
                    movie_ratings[movie_num-1][rating-1]++;
                    printf("\nRating '%d' added for movie '%s' successfully!\n", rating, movie_name[movie_num-1]);
                }
                break;

            case 4:
                // view movie ratings
                if (num_movies == 0)
                {
                    printf("\nNo movies found. Please add a movie first.\n");
                }
                else
                {
                    printf("\nEnter movie number: ");
                    int movie_num;
                    scanf("%d", &movie_num);
                    if (movie_num <= 0 || movie_num > num_movies)
                    {
                        printf("\nInvalid movie number. Please try again.\n");
                        break;
                    }
                    printf("\nRatings for '%s' movie:\n", movie_name[movie_num-1]);
                    for (int i = 0; i < 5; i++)
                    {
                        printf("%d star: %d\n", i+1, movie_ratings[movie_num-1][i]);
                    }
                    printf("Average rating: %.2f\n", movie_rating[movie_num-1]);
                }
                break;

            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }

        printf("\n");
        display_menu();
        scanf("%d", &choice);
    }

    printf("\nThank you for using C Movie Rating System!\n");

    return 0;
}