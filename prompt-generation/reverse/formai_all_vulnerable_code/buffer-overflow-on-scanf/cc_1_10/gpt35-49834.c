//FormAI DATASET v1.0 Category: Movie Rating System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct movie {
    char title[50];
    int year;
    float rating;
};

void addMovie();
void rateMovie();
void displayMovies();

int main() {
    int choice;
    printf("Welcome to the Unique C Movie Rating System!\n");
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a movie\n");
        printf("2. Rate a movie\n");
        printf("3. Display movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addMovie();
                break;
            case 2:
                rateMovie();
                break;
            case 3:
                displayMovies();
                break;
            case 4:
                printf("Thank you for using our Unique C Movie Rating System!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while(choice != 4);
    return 0;
}

void addMovie() {
    struct movie m;
    printf("Enter the title of the movie: ");
    scanf("%s", m.title);
    printf("Enter the year the movie was released: ");
    scanf("%d", &m.year);
    m.rating = 0;
    FILE *fp = fopen("movies.dat", "ab");
    if(fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    fwrite(&m, sizeof(struct movie), 1, fp);
    fclose(fp);
    printf("%s added to the database!\n", m.title);
}

void rateMovie() {
    FILE *fp = fopen("movies.dat", "rb+");
    if(fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    int pos, found=0;
    struct movie m;

    printf("Enter the title of the movie: ");
    char title[50];
    scanf("%s", title);

    while(fread(&m, sizeof(struct movie), 1, fp)) {
        pos = ftell(fp) - sizeof(struct movie);
        if(strcmp(title, m.title) == 0) {
            found = 1;
            printf("Enter your rating (0-10): ");
            scanf("%f", &m.rating);
            fseek(fp, pos, SEEK_SET);
            fwrite(&m, sizeof(struct movie), 1, fp);
            break;
        }
    }
    fclose(fp);
    if(found == 0) {
        printf("%s was not found in the database!\n", title);
    } else {
        printf("Rating added for %s!\n", title);
    }
}

void displayMovies() {
    FILE *fp = fopen("movies.dat", "rb");
    if(fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    struct movie m;
    int count = 0;
    while(fread(&m, sizeof(struct movie), 1, fp)) {
        printf("Title: %s\n", m.title);
        printf("Released: %d\n", m.year);
        if(m.rating == 0) {
            printf("No rating yet!\n");
        } else {
            printf("Rating: %.2f\n", m.rating);
        }
        printf("\n");
        count++;
    }
    if(count == 0) {
        printf("No movies in the database!\n");
    }
    fclose(fp);
}