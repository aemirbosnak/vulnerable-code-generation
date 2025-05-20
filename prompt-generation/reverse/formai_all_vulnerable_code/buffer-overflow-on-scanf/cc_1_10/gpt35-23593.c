//FormAI DATASET v1.0 Category: Movie Rating System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

struct movie {
    char title[100];
    char director[100];
    int year;
    float rating;
};

int main() {
    int num_movies;
    printf("Enter the number of movies you want to rate: ");
    scanf("%d", &num_movies);
    
    struct movie movies[num_movies];
    for(int i = 0; i < num_movies; i++) {
        printf("\nEnter the details for movie %d:\n", i+1);
        printf("Title: ");
        scanf(" %[^\n]s", movies[i].title);
        printf("Director: ");
        scanf(" %[^\n]s", movies[i].director);
        printf("Year: ");
        scanf("%d", &movies[i].year);
        printf("Rating (out of 10): ");
        scanf("%f", &movies[i].rating);
    }
    
    printf("\n~~~~CURRENT RATINGS~~~~\n");
    printf("#  | Movie Title  | Director  | Year  | Rating\n");
    printf("==========================================================\n");
    for(int i = 0; i < num_movies; i++) {
        printf("%2d | %-12.12s | %-9.9s | %d | %.2f\n", i+1, movies[i].title, movies[i].director, movies[i].year, movies[i].rating);
    }
    
    int choice;
    do {
        printf("\nEnter the number of the movie you want to rate (0 to quit): ");
        scanf("%d", &choice);
        if(choice == 0) {
            printf("Exiting...");
            break;
        } else if(choice > num_movies || choice < 0) {
            printf("Invalid choice. Try again.\n");
            continue;
        } else {
            float new_rating;
            printf("Enter the new rating (out of 10): ");
            scanf("%f", &new_rating);
            movies[choice-1].rating = new_rating;
            printf("\n~~~~UPDATED RATINGS~~~~\n");
            printf("#  | Movie Title  | Director  | Year  | Rating\n");
            printf("==========================================================\n");
            for(int i = 0; i < num_movies; i++) {
                printf("%2d | %-12.12s | %-9.9s | %d | %.2f\n", i+1, movies[i].title, movies[i].director, movies[i].year, movies[i].rating);
            }
        }
    } while(1);
    return 0;
}