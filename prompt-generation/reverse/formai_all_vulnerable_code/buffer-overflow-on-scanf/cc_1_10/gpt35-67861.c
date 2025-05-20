//FormAI DATASET v1.0 Category: Movie Rating System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variables
int rating[5] = {0,0,0,0,0};
char movie_name[5][50];

// function prototypes
void add_movie();
void add_rating();
void print_rating();
void print_menu();

// main function
int main()
{
    printf("Welcome to the C Movie Rating System!\n\n");

    // loop for menu options
    int menu_choice;
    do {
        print_menu();
        scanf("%d", &menu_choice);

        switch (menu_choice)
        {
            case 1:
                add_movie();
                break;
            case 2:
                add_rating();
                break;
            case 3:
                print_rating();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid input, please try again.\n");
        }
    } while (menu_choice != 4);

    return 0;
}

// function for adding a movie
void add_movie()
{
    printf("Enter the name of the movie: ");
    for (int i=0; i<5; i++)
    {
        if (!rating[i])
        {
            scanf("%s", movie_name[i]);
            printf("Movie successfully added!\n");
            return;
        }
    }

    printf("Sorry, maximum number of movies reached.\n");
}

// function for adding a rating
void add_rating()
{
    printf("Enter the name of the movie you want to rate: ");
    char movie[50];
    scanf("%s", movie);

    // finding the movie index based on name
    int movie_index = -1;
    for (int i=0; i<5; i++)
    {
        if (!strcmp(movie, movie_name[i]))
        {
            movie_index = i;
            break;
        }
    }

    // checking if movie exists
    if (movie_index == -1)
    {
        printf("Sorry, movie not found.\n");
        return;
    }

    printf("Enter your rating (0-10) for '%s': ", movie_name[movie_index]);
    int r;
    scanf("%d", &r);

    // checking if rating is valid
    if (r < 0 || r > 10)
    {
        printf("Invalid rating, please enter a rating between 0-10.\n");
        return;
    }

    rating[movie_index] += r;
    printf("Your rating of %d for '%s' has been added.\n", r, movie_name[movie_index]);
}

// function for printing all ratings
void print_rating()
{
    printf("\n=================\nMovie Ratings:\n");

    // checking if any movies have been added
    int no_movie_flag = 0;
    for (int i=0; i<5; i++)
    {
        if (rating[i])
        {
            no_movie_flag = 1;
            break;
        }
    }

    if (!no_movie_flag)
    {
        printf("No movies found.\n");
        return;
    }

    // printing ratings
    for (int i=0; i<5; i++)
    {
        if (rating[i])
        {
            double avg = rating[i] / 10.0;
            printf("'%s': %.1f\n", movie_name[i], avg);
        }
    }
    printf("=================\n");
}

// function for printing menu
void print_menu()
{
    printf("\nPlease choose from the following options:\n");
    printf("1 - Add a movie\n");
    printf("2 - Add a rating for a movie\n");
    printf("3 - Print all ratings\n");
    printf("4 - Exit program\n");
    printf("\nEnter your choice: ");
}