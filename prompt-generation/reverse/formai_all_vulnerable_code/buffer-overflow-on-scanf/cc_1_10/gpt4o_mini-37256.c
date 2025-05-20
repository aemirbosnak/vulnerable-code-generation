//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LEN 100
#define MAX_NAME_LEN 100

typedef struct Movie {
    char title[MAX_TITLE_LEN];
    char reviewer_name[MAX_NAME_LEN];
    int rating; // 0 to 10
} Movie;

void display(Movie movies[], int count) {
    printf("Oh! What light through yonder window breaks?\n");
    printf("Let us list the films and the ratings bestowed upon them!\n\n");
    for (int i = 0; i < count; i++) {
        printf("Title: '%s' | Reviewer: '%s' | Rating: %d\n",
                movies[i].title, movies[i].reviewer_name, movies[i].rating);
    }
    printf("\n");
}

int add_movie(Movie movies[], int count) {
    if (count >= MAX_MOVIES) {
        printf("Alas! We cannot add more movies!\n");
        return count;
    }

    printf("Enter the title of the movie, sweet love:\n");
    scanf(" %[^\n]%*c", movies[count].title);
    
    printf("What is thine name, dear reviewer?\n");
    scanf(" %[^\n]%*c", movies[count].reviewer_name);
    
    printf("How dost thou rate this fair production? (0 to 10): ");
    scanf("%d", &movies[count].rating);
    
    if (movies[count].rating < 0 || movies[count].rating > 10) {
        printf("A rating must be of fair measure! Cursed be those ill ratings!\n");
        return count;
    }
    
    printf("The movie hath been added, with a score most noble!\n");
    return count + 1;
}

void search_movie(Movie movies[], int count) {
    char title_to_find[MAX_TITLE_LEN];
    printf("Which film dost thou seek? Enter the title:\n");
    scanf(" %[^\n]%*c", title_to_find);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, title_to_find) == 0) {
            printf("Aha! The film '%s' hath been found!\n", movies[i].title);
            printf("Reviewer: '%s' | Rating: %d\n", 
                    movies[i].reviewer_name, movies[i].rating);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Alack! The film '%s' hath not been found in our scrolls!\n", title_to_find);
    }
}

void display_average_rating(Movie movies[], int count) {
    if (count == 0) {
        printf("Nay! There are no ratings to calculate! Pray, add some first!\n");
        return;
    }

    int total_rating = 0;
    for (int i = 0; i < count; i++) {
        total_rating += movies[i].rating;
    }
    float average = (float)total_rating / count;
    printf("The average rating of all movies is: %.2f\n", average);
}

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;
    
    printf("Welcome to the enchanted Movie Rating System!\n");
    
    while (1) {
        printf("1. Add a movie\n");
        printf("2. Display all movies\n");
        printf("3. Search for a movie\n");
        printf("4. Display average rating\n");
        printf("5. Exit\n");
        printf("What dost thou desire? (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                count = add_movie(movies, count);
                break;
            case 2:
                display(movies, count);
                break;
            case 3:
                search_movie(movies, count);
                break;
            case 4:
                display_average_rating(movies, count);
                break;
            case 5:
                printf("Farewell, dear user! To thine own heart be true!\n");
                return 0;
            default:
                printf("That choice is naught but a shadow!\n");
                break;
        }
    }
}