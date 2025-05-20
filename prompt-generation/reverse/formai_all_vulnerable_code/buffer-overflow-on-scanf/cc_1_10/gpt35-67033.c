//FormAI DATASET v1.0 Category: Movie Rating System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

struct Movie
{
    char title[50];
    char director[50];
    char genre[20];
    float duration;
    int year;
    int rating;
};

void addMovie(struct Movie m[], int *count);
void displayMovies(struct Movie m[], int count);
void updateRating(struct Movie m[], int count);
void deleteMovie(struct Movie m[], int *count);

int main()
{
    struct Movie movies[100];
    int choice, count = 0;

    while(1)
    {
        printf("\n\n--- C Movie Rating System---\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Update Rating\n");
        printf("4. Delete Movie\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: addMovie(movies, &count);
                    break;

            case 2: displayMovies(movies, count);
                    break;

            case 3: updateRating(movies, count);
                    break;

            case 4: deleteMovie(movies, &count);
                    break;

            case 5: exit(0);

            default: printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addMovie(struct Movie m[], int *count)
{
    printf("\n\n--- Add Movie ---\n\n");

    printf("Title: ");
    scanf("%s", m[*count].title);

    printf("Director: ");
    scanf("%s", m[*count].director);

    printf("Genre: ");
    scanf("%s", m[*count].genre);

    printf("Duration (in minutes): ");
    scanf("%f", &m[*count].duration);

    printf("Year: ");
    scanf("%d", &m[*count].year);

    printf("Rating (out of 10.0): ");
    scanf("%d", &m[*count].rating);

    printf("\n--- Movie Added Successfully ---\n");

    *count += 1;
}

void displayMovies(struct Movie m[], int count)
{
    if(count == 0)
    {
        printf("\nNo movies found!\n");
        return;
    }

    printf("\n\n--- Displaying Movies ---\n\n");

    for(int i = 0; i < count; i++)
    {
        printf("Movie %d:\n", i+1);
        printf("Title: %s\n", m[i].title);
        printf("Director: %s\n", m[i].director);
        printf("Genre: %s\n", m[i].genre);
        printf("Duration: %f minutes\n", m[i].duration);
        printf("Year: %d\n", m[i].year);
        printf("Rating: %d/10.0\n\n", m[i].rating);
    }
}

void updateRating(struct Movie m[], int count)
{
    char title[50];
    int found = 0;

    printf("\n\n--- Update Rating ---\n\n");

    printf("Enter the title of the movie: ");
    scanf("%s", title);

    for(int i = 0; i < count; i++)
    {
        if(strcmp(m[i].title, title) == 0)
        {
            printf("Enter the new rating (out of 10.0): ");
            scanf("%d", &m[i].rating);
            found = 1;
            printf("\n--- Rating updated successfully ---\n");
            break;
        }
    }

    if(found == 0)
    {
        printf("\nMovie not found!\n");
    }
}

void deleteMovie(struct Movie m[], int *count)
{
    char title[50];
    int found = 0;

    printf("\n\n--- Delete Movie ---\n\n");

    printf("Enter the title of the movie: ");
    scanf("%s", title);

    for(int i = 0; i < *count; i++)
    {
        if(strcmp(m[i].title, title) == 0)
        {
            // Shift all movies to the left
            for(int j = i; j < *count-1; j++)
            {
                m[j] = m[j+1];
            }

            *count -= 1;
            found = 1;
            printf("\n--- Movie deleted successfully ---\n");
            break;
        }
    }

    if(found == 0)
    {
        printf("\nMovie not found!\n");
    }
}