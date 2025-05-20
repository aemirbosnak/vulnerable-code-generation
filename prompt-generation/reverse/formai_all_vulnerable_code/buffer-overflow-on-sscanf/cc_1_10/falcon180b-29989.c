//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char *movie_title = argv[1];
    char *rating_str = argv[2];
    int rating = 0;

    if (argc!= 3)
    {
        printf("Usage: %s <movie_title> <rating>\n", argv[0]);
        exit(1);
    }

    // Convert rating string to integer
    if (sscanf(rating_str, "%d", &rating)!= 1)
    {
        printf("Invalid rating. Please enter a number.\n");
        exit(1);
    }

    // Convert movie title to uppercase
    for (int i = 0; movie_title[i]!= '\0'; i++)
    {
        movie_title[i] = toupper(movie_title[i]);
    }

    // Get movie rating
    int movie_rating = 0;
    FILE *movie_file = fopen("movies.txt", "r");
    if (movie_file == NULL)
    {
        printf("Error opening movies.txt\n");
        exit(1);
    }
    while (fscanf(movie_file, "%s %d", movie_title, &movie_rating)!= EOF)
    {
        if (strcmp(movie_title, argv[1]) == 0)
        {
            printf("Movie already rated.\n");
            exit(1);
        }
    }
    fclose(movie_file);

    // Add movie rating to file
    movie_file = fopen("movies.txt", "a");
    if (movie_file == NULL)
    {
        printf("Error opening movies.txt\n");
        exit(1);
    }
    fprintf(movie_file, "%s %d\n", movie_title, rating);
    fclose(movie_file);

    // Print movie rating
    printf("Movie rated %d/5\n", rating);
    return 0;
}