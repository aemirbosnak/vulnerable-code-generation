//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // Create a list of movie titles
    char* movie_titles[] = {
        "The Road",
        "Mad Max: Fury Road",
        "The Walking Dead",
        "The Book of Eli",
        "12 Monkeys",
        "Zombieland",
        "I Am Legend",
        "28 Days Later",
        "The Mist",
        "Shaun of the Dead",
        "The Last of Us",
        "Resident Evil",
        "World War Z",
        NULL
    };
    
    // Set up a menu
    int menu_choice;
    printf("Welcome to the Post-Apocalyptic Movie Rating System!\n");
    printf("Please select a movie:\n");
    for (int i = 0; movie_titles[i]!= NULL; i++) {
        printf("%d. %s\n", i+1, movie_titles[i]);
    }
    printf("Enter your choice: ");
    scanf("%d", &menu_choice);
    
    // Display the movie's rating
    switch (menu_choice) {
        case 1:
            printf("Rating: 5/5\n");
            break;
        case 2:
            printf("Rating: 4/5\n");
            break;
        case 3:
            printf("Rating: 3/5\n");
            break;
        case 4:
            printf("Rating: 2/5\n");
            break;
        case 5:
            printf("Rating: 1/5\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
    
    // Randomly select a quote from the movie
    srand(time(NULL));
    int quote_choice = rand() % (sizeof(movie_titles) / sizeof(char*)) + 1;
    char* quote = movie_titles[quote_choice];
    
    // Display the quote
    printf("Quote: %s\n", quote);
    
    // Randomly select a character from the movie
    srand(time(NULL));
    int character_choice = rand() % (sizeof(movie_titles) / sizeof(char*)) + 1;
    char* character = movie_titles[character_choice];
    
    // Display the character's name
    printf("Character: %s\n", character);
    
    // Randomly select a plot summary from the movie
    srand(time(NULL));
    int plot_choice = rand() % (sizeof(movie_titles) / sizeof(char*)) + 1;
    char* plot = movie_titles[plot_choice];
    
    // Display the plot summary
    printf("Plot: %s\n", plot);
    
    return 0;
}