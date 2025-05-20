//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a movie rating
typedef struct rating
{
    char name[50];
    int year;
    float score;
} Rating;

// Function to enter a new movie rating into the system
void enter_rating(Rating *ratings, int *count)
{
    printf("Enter the name of the movie: ");
    scanf("%s", ratings[*count].name);
    printf("Enter the year of release: ");
    scanf("%d", &ratings[*count].year);
    printf("Enter the overall score (out of 10): ");
    scanf("%f", &ratings[*count].score);
    (*count)++;
}

// Function to find the average rating across all movies
float find_average(Rating *ratings, int count)
{
    float total = 0.0;
    for (int i = 0; i < count; i++)
    {
        total += ratings[i].score;
    }
    return total / count;
}

// Function to display all movies with a rating above a certain threshold
void display_above_threshold(Rating *ratings, int count, float threshold)
{
    printf("Movies with a rating above %.1f:\n", threshold);
    for (int i = 0; i < count; i++)
    {
        if (ratings[i].score > threshold)
        {
            printf("- %s (%d) - %.1f/10\n", ratings[i].name, ratings[i].year, ratings[i].score);
        }
    }
}

// Function to display the best movie according to user scores
void display_best_movie(Rating *ratings, int count)
{
    char best_name[50];
    float best_score = -1.0;
    for (int i = 0; i < count; i++)
    {
        if (ratings[i].score > best_score)
        {
            strcpy(best_name, ratings[i].name);
            best_score = ratings[i].score;
        }
    }
    printf("The best movie is %s with a score of %.1f/10\n", best_name, best_score);
}

int main()
{
    Rating ratings[100];
    int count = 0;
    int choice = -1;

    while (choice != 4)
    {
        printf("\n\n");
        printf("Welcome to the Unique C Movie Rating System!\n");
        printf("=============================================\n");
        printf("1. Enter a new movie rating\n");
        printf("2. Find the average rating across all movies\n");
        printf("3. Display all movies with a rating above a certain threshold\n");
        printf("4. Display the best movie\n");
        printf("5. Quit\n");

        printf("Please enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            enter_rating(ratings, &count);
        }
        else if (choice == 2)
        {
            float average = find_average(ratings, count);
            printf("The average movie rating is %.1f/10\n", average);
        }
        else if (choice == 3)
        {
            float threshold;
            printf("Enter the rating threshold (out of 10): ");
            scanf("%f", &threshold);
            display_above_threshold(ratings, count, threshold);
        }
        else if (choice == 4)
        {
            display_best_movie(ratings, count);
        }
        else if (choice == 5)
        {
            printf("Thanks for using the Unique C Movie Rating System!\n");
            exit(0);
        }
        else
        {
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}