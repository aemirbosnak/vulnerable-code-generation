//FormAI DATASET v1.0 Category: Movie Rating System ; Style: creative
#include<stdio.h>
#include<string.h>

struct movie {
    char title[50];
    int year;
    char director[50];
    float rating;
};

int main() {
    struct movie m[10];
    char name[50];
    int i, choice;
    
    printf("Welcome to the Unique C Movie Rating System\n");
    printf("-------------------------------------------\n");
    printf("Please enter details of 10 movies\n\n");
    
    for(i = 0; i < 10; i++) {
        printf("Movie %d:\n", i+1);
        printf("\tTitle: ");
        fgets(m[i].title, 50, stdin);
        printf("\tYear: ");
        scanf("%d", &m[i].year);
        getchar(); // to clear the input buffer
        printf("\tDirector: ");
        fgets(m[i].director, 50, stdin);
        printf("\tRating (out of 10): ");
        scanf("%f", &m[i].rating);
        getchar(); // to clear the input buffer
    }
    
    printf("\n\n");
    printf("What would you like to know?\n");
    printf("1. Movie with highest rating\n");
    printf("2. Movie directed by a specific director\n");
    printf("3. Movies released in a specific year\n");
    printf("4. All movies in the database\n");
    printf("\nEnter choice (1-4): ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            {
                float max_rating = -1;
                int index;
                for(i = 0; i < 10; i++) {
                    if(m[i].rating > max_rating) {
                        max_rating = m[i].rating;
                        index = i;
                    }
                }
                printf("Movie with highest rating: %s\n", m[index].title);
                break;
            }
        case 2:
            {
                printf("Enter name of director: ");
                fgets(name, 50, stdin);
                for(i = 0; i < 10; i++) {
                    if(strcasecmp(m[i].director, name) == 0) {
                        printf("%s\n", m[i].title);
                    }
                }
                break;
            }
        case 3:
            {
                int year;
                printf("Enter year: ");
                scanf("%d", &year);
                for(i = 0; i < 10; i++) {
                    if(m[i].year == year) {
                        printf("%s\n", m[i].title);
                    }
                }
                break;
            }
        case 4:
            {
                printf("All movies in the database:\n");
                for(i = 0; i < 10; i++) {
                    printf("%s (%d) - directed by %s - rating: %.2f/10\n", m[i].title, m[i].year, m[i].director, m[i].rating);
                }
                break;
            }
        default:
            {
                printf("Invalid choice\n");
            }
    }
    
    return 0;
}