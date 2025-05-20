//FormAI DATASET v1.0 Category: Movie Rating System ; Style: automated
#include <stdio.h>

struct movie {
   char title[50];
   char director[50];
   int year;
   float rating;
};

void displayMenu() {
    printf("\n---- C MOVIE RATING SYSTEM ----\n");
    printf("\nSelect an option:\n");
    printf("1. Add a movie\n");
    printf("2. Edit a movie\n");
    printf("3. Rate a movie\n");
    printf("4. Display all movies\n");
    printf("5. Exit\n");
}

int main() {
    int choice, count = 0, i;
    struct movie movies[10];

    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Add a movie
                if(count < 10) {
                    printf("\nEnter movie title: ");
                    scanf("%s", movies[count].title);

                    printf("Enter director name: ");
                    scanf("%s", movies[count].director);

                    printf("Enter release year: ");
                    scanf("%d", &movies[count].year);

                    printf("Movie added successfully!\n");
                    count++;
                } else {
                    printf("\nSorry, you can't add any more movies.\n");
                }
                break;

            case 2:
                // Edit a movie
                if(count > 0) {
                    char title[50];
                    printf("\nEnter the movie title: ");
                    scanf("%s", title);

                    for(i=0; i<count; i++) {
                        if(strcmp(title, movies[i].title) == 0) {
                            printf("Enter new rating: ");
                            scanf("%f", &movies[i].rating);
                            printf("Movie rating updated successfully!\n");
                            break;
                        }
                    }

                    if(i == count) {
                        printf("Movie not found.\n");
                    }
                } else {
                    printf("\nNo movies in the database.\n");
                }
                break;

            case 3:
                // Rate a movie
                if(count > 0) {
                    char title[50];
                    printf("\nEnter the movie title: ");
                    scanf("%s", title);

                    for(i=0; i<count; i++) {
                        if(strcmp(title, movies[i].title) == 0) {
                            printf("\nThe current rating for %s is %.2f\n", movies[i].title, movies[i].rating);
                            printf("Enter new rating: ");
                            scanf("%f", &movies[i].rating);
                            printf("Movie rating updated successfully!\n");
                            break;
                        }
                    }

                    if(i == count) {
                        printf("\nMovie not found.\n");
                    }
                } else {
                    printf("\nNo movies in the database.\n");
                }
                break;

            case 4:
                // Display all movies
                if(count > 0) {
                    printf("\nAll movies:\n");
                    for(i=0; i<count; i++) {
                        printf("\nTitle: %s\n", movies[i].title);
                        printf("Director: %s\n", movies[i].director);
                        printf("Year: %d\n", movies[i].year);
                        printf("Rating: %.2f\n", movies[i].rating);
                    }
                } else {
                    printf("\nNo movies in the database.\n");
                }
                break;

            case 5:
                // Exit
                printf("\nGoodbye!\n");
                break;

            default:
                // Invalid choice
                printf("\nInvalid choice.\n");
                break;
        }

    } while(choice != 5);

    return 0;
}