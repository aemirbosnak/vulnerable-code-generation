//FormAI DATASET v1.0 Category: Movie Rating System ; Style: complete
#include <stdio.h>

void showMenu() {
    printf("\n---------------- C Movie Rating System ----------------\n");
    printf("Choose an option:\n");
    printf("1. Add a new movie\n");
    printf("2. Rate a movie\n");
    printf("3. View ratings of a movie\n");
    printf("4. View all movies\n");
    printf("5. Exit\n");
    printf("-------------------------------------------------------\n");
    printf("Option: ");
}

struct Movie {
    char title[100];
    int year;
    float rating;
};

void addMovie(struct Movie movies[], int *count) {
    char c;
    do {
        printf("\nEnter the title of the movie: ");
        fflush(stdin);
        gets(movies[*count].title);

        printf("Enter the release year of the movie: ");
        scanf("%d", &movies[*count].year);

        movies[*count].rating = -1;

        printf("\nMovie added successfully!\n");

        (*count)++;

        printf("\nAdd another movie? (Y/N): ");
        fflush(stdin);
        scanf("%c", &c);
    } while(c == 'y' || c == 'Y');
}

void rateMovie(struct Movie movies[], int count) {
    char title[100];
    float rating;

    printf("\nEnter the title of the movie: ");
    fflush(stdin);
    gets(title);

    int found = 0;

    for(int i = 0; i < count; i++) {
        if(strcmp(movies[i].title, title) == 0) {
            printf("Enter your rating (out of 10): ");
            scanf("%f", &movies[i].rating);

            printf("\nMovie rated successfully!\n");

            found = 1;
            break;
        }
    }

    if(!found) {
        printf("\nMovie not found!\n");
    }
}

void viewRatings(struct Movie movies[], int count) {
    char title[100];

    printf("\nEnter the title of the movie: ");
    fflush(stdin);
    gets(title);

    int found = 0;

    for(int i = 0; i < count; i++) {
        if(strcmp(movies[i].title, title) == 0) {
            if(movies[i].rating >= 0) {
                printf("\n%s (%d) - %.1f\n", movies[i].title, movies[i].year, movies[i].rating);
            } else {
                printf("\n%s (%d) - Not rated yet\n", movies[i].title, movies[i].year);
            }

            found = 1;
            break;
        }
    }

    if(!found) {
        printf("\nMovie not found!\n");
    }
}

void viewMovies(struct Movie movies[], int count) {
    printf("\n-----------------------\n");
    printf("Title\tYear\tRating\n");
    printf("-----------------------\n");

    for(int i = 0; i < count; i++) {
        if(movies[i].rating >= 0) {
            printf("%s\t%d\t%.1f\n", movies[i].title, movies[i].year, movies[i].rating);
        } else {
            printf("%s\t%d\tNot rated yet\n", movies[i].title, movies[i].year);
        }
    }

    printf("-----------------------\n");
}

int main() {
    struct Movie movies[100];
    int count = 0;

    int choice;

    do {
        showMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                rateMovie(movies, count);
                break;
            case 3:
                viewRatings(movies, count);
                break;
            case 4:
                viewMovies(movies, count);
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid option, try again!\n");
        }
    } while(choice != 5);

    return 0;
}