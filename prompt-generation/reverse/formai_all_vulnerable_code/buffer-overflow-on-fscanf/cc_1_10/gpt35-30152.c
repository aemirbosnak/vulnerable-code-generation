//FormAI DATASET v1.0 Category: File handling ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining a structure to hold the details of retro video games
struct retro_game {
    char title[50];
    char platform[20];
    int release_year;
    float rating;
};

// Function to add new game details to the file
void add_game() {
    FILE *file_pointer;
    struct retro_game game;

    // Opening the file in append mode
    file_pointer = fopen("retro_games.txt", "a");

    if (file_pointer == NULL) {
        printf("\nError opening file!\n");
        exit(1);
    }

    printf("\nEnter the title of the game: ");
    fflush(stdin);
    fgets(game.title, 50, stdin);

    printf("\nEnter the platform of the game: ");
    fflush(stdin);
    fgets(game.platform, 20, stdin);

    printf("\nEnter the release year of the game: ");
    scanf("%d", &game.release_year);

    printf("\nEnter the rating of the game (out of 10): ");
    scanf("%f", &game.rating);

    fprintf(file_pointer, "%s%s%d%.1f\n", game.title, game.platform, game.release_year, game.rating);

    printf("\nGame details added successfully!\n");
    fclose(file_pointer);
}

// Function to display all the games in the file
void display_all_games() {
    FILE *file_pointer;
    struct retro_game game;

    // Opening the file in read mode
    file_pointer = fopen("retro_games.txt", "r");

    if (file_pointer == NULL) {
        printf("\nError opening file!\n");
        exit(1);
    }

    printf("\nTitle\tPlatform\tYear\tRating\n");

    // Reading game details from the file and displaying them
    while(fscanf(file_pointer, "%s%s%d%f", game.title, game.platform, &game.release_year, &game.rating) != EOF) {
        printf("%s\t%s\t%d\t%.1f\n", game.title, game.platform, game.release_year, game.rating);
    }

    fclose(file_pointer);
}

// Function to search for games based on their title
void search_game_by_title() {
    FILE *file_pointer;
    struct retro_game game;
    char title[50], found = 0;

    // Opening the file in read mode
    file_pointer = fopen("retro_games.txt", "r");

    if (file_pointer == NULL) {
        printf("\nError opening file!\n");
        exit(1);
    }

    printf("\nEnter the title of the game to search: ");
    fflush(stdin);
    fgets(title, 50, stdin);

    // Reading game details from the file and searching for the given title
    while(fscanf(file_pointer, "%s%s%d%f", game.title, game.platform, &game.release_year, &game.rating) != EOF) {
        if (strstr(game.title, title) != NULL) {
            printf("\nTitle\tPlatform\tYear\tRating\n");
            printf("%s\t%s\t%d\t%.1f\n", game.title, game.platform, game.release_year, game.rating);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nGame not found!\n");
    }

    fclose(file_pointer);
}

int main() {
    int choice;

    // Creating a menu for the user
    do {
        printf("\nRetro games file handling\n");
        printf("1. Add a new game\n");
        printf("2. Display all games\n");
        printf("3. Search for games based on title\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_game();
                break;

            case 2:
                display_all_games();
                break;

            case 3:
                search_game_by_title();
                break;

            case 4:
                printf("\nExiting...\n");
                exit(0);

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}