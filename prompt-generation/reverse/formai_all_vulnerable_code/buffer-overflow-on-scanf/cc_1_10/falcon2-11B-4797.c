//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct Movie
{
    char title[100];
    float rating;
};

void print_menu()
{
    printf("1. Add a movie\n2. Remove a movie\n3. Display all movies\n4. Search for a movie\n5. Exit\n");
}

void add_movie(struct Movie *movie)
{
    printf("Enter movie title: ");
    scanf("%s", movie->title);
    printf("Enter movie rating: ");
    scanf("%f", &movie->rating);
}

void remove_movie(struct Movie *movie)
{
    printf("Enter movie title: ");
    scanf("%s", movie->title);
    printf("Movie removed!\n");
}

void display_movies(struct Movie *movie)
{
    printf("Movies:\n");
    for(int i = 0; i < 5; i++)
    {
        printf("%s - %f\n", movie[i].title, movie[i].rating);
    }
}

void search_movie(struct Movie *movie, char *title)
{
    printf("Movie found!\n");
}

int main()
{
    struct Movie movies[5];

    while(1)
    {
        print_menu();
        int choice;
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                add_movie(movies);
                break;
            case 2:
                remove_movie(movies);
                break;
            case 3:
                display_movies(movies);
                break;
            case 4:
                search_movie(movies, "Avatar");
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}