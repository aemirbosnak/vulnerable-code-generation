//FormAI DATASET v1.0 Category: Movie Rating System ; Style: decentralized
#include <stdio.h>

// Movie rating structure
struct movie_rating {
    int id;
    char title[100];
    float rating;
};

// Function declarations
void add_movie_rating(struct movie_rating *mr, int size);
void view_movie_ratings(struct movie_rating *mr, int size);
void search_movie_rating(struct movie_rating *mr, int size);

int main() {
    int choice, size = 0;
    struct movie_rating mr[100];
    
    do {
        printf("\nC Movie Rating System\n");
        printf("---------------------\n");
        printf("1. Add Movie Rating\n");
        printf("2. View Movie Ratings\n");
        printf("3. Search Movie Rating\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_movie_rating(mr, size);
                size++;
                break;
            case 2:
                view_movie_ratings(mr, size);
                break;
            case 3:
                search_movie_rating(mr, size);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}

void add_movie_rating(struct movie_rating *mr, int size) {
    printf("Enter movie title: ");
    scanf("%s", mr[size].title);
    
    printf("Enter movie rating: ");
    scanf("%f", &mr[size].rating);
    
    mr[size].id = size + 1;
    
    printf("Movie rating added successfully.\n");
}

void view_movie_ratings(struct movie_rating *mr, int size) {
    if (size == 0) {
        printf("No movie ratings found.\n");
        return;
    }
    
    printf("ID\tTitle\t\tRating\n");
    printf("----------------------------------\n");
    
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t\t%.2f\n", mr[i].id, mr[i].title, mr[i].rating);
    }
}

void search_movie_rating(struct movie_rating *mr, int size) {
    char query[100];
    int count = 0;
    
    printf("Enter movie title to search: ");
    scanf("%s", query);
    
    printf("Search Results\n");
    printf("ID\tTitle\t\tRating\n");
    printf("----------------------------------\n");
    
    for (int i = 0; i < size; i++) {
        if (strcmp(mr[i].title, query) == 0) {
            printf("%d\t%s\t\t%.2f\n", mr[i].id, mr[i].title, mr[i].rating);
            count++;
        }
    }
    
    if (count == 0) {
        printf("No movie ratings found.\n");
    }
}