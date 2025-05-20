//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: random
#include <stdio.h>

// function to print the menu
void print_menu() {
    printf("\n");
    printf("Movie Rating System\n");
    printf("-------------------\n");
    printf("1. Add a movie\n");
    printf("2. Rate a movie\n");
    printf("3. View ratings\n");
    printf("4. Exit\n");
    printf("\n");
}

// function to add a movie
void add_movie() {
    char name[50];
    printf("Enter the movie name: ");
    scanf("%s", name);
    printf("Movie added: %s\n", name);
}

// function to rate a movie
void rate_movie() {
    char name[50];
    int rating;
    printf("Enter the movie name: ");
    scanf("%s", name);
    printf("Enter the rating (1-5): ");
    scanf("%d", &rating);
    printf("Movie rated: %s with %d stars\n", name, rating);
}

// function to view ratings
void view_ratings() {
    FILE *fp;
    char ch;
    fp = fopen("ratings.txt", "r");
    if (fp == NULL) {
        printf("No ratings found.\n");
        return;
    }
    printf("Movie Ratings\n");
    while ((ch = fgetc(fp))!= EOF) {
        printf("%c", ch);
    }
    fclose(fp);
}

// main function
int main() {
    int choice;
    char filename[20] = "ratings.txt";
    FILE *fp;

    // create the ratings file
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating ratings file.\n");
        return 1;
    }
    fclose(fp);

    // loop until user chooses to exit
    while (1) {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_movie();
                break;
            case 2:
                rate_movie();
                break;
            case 3:
                view_ratings();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}