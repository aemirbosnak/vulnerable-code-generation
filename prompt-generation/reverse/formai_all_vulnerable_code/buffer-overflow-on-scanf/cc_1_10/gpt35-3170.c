//FormAI DATASET v1.0 Category: Movie Rating System ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct movie {
    char name[50];
    char genre[20];
    int year;
    float rating;
};

void display_menu() {
    printf("\n\n");
    printf("Welcome to the C Movie Rating System\n");
    printf("------------------------------------\n\n");
    printf("1. View All Movies\n");
    printf("2. Rate a Movie\n");
    printf("3. Add a Movie\n");
    printf("4. Exit\n\n");
}

void display_movies(struct movie* movies, int count) {
    printf("All Movies:\n\n");
    for(int i=0; i<count; i++) {
        printf("%s, %s, %d, %.1f\n", movies[i].name, movies[i].genre, movies[i].year, movies[i].rating);
    }
}

void rate_movie(struct movie* movies, int count) {
    char name[50];
    int index = -1;
    printf("Enter the name of the movie: ");
    scanf("%s", name);
    for(int i=0; i<count; i++) {
        if(strcmp(movies[i].name, name)==0) {
            index = i;
            break;
        }
    }
    if(index!=-1) {
        float rating;
        printf("Enter your rating (out of 10): ");
        scanf("%f", &rating);
        movies[index].rating = (movies[index].rating + rating)/2;
        printf("Thank you for rating!\n\n");
    }
    else {
        printf("Movie not found.\n\n");
    }
}

void add_movie(struct movie* movies, int count) {
    char name[50];
    char genre[20];
    int year;
    float rating;
    printf("Enter the name of the movie: ");
    scanf("%s", name);
    printf("Enter the genre: ");
    scanf("%s", genre);
    printf("Enter the year of release: ");
    scanf("%d", &year);
    printf("Enter the rating (out of 10): ");
    scanf("%f", &rating);
    strcpy(movies[count].name, name);
    strcpy(movies[count].genre, genre);
    movies[count].year = year;
    movies[count].rating = rating;
    printf("Movie added successfully.\n\n");
}

int main() {
    struct movie movies[100];
    int count = 0;
    int choice = 0;
    
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice) {
            case 1:
                display_movies(movies, count);
                break;
            case 2:
                rate_movie(movies, count);
                break;
            case 3:
                add_movie(movies, count);
                count++;
                break;
            case 4:
                printf("Goodbye!\n\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    } while(choice!=4);
    
    return 0;
}