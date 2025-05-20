//FormAI DATASET v1.0 Category: Movie Rating System ; Style: unmistakable
#include<stdio.h>
#include<string.h>

int rating[20]; //Array to hold movie ratings
char movieName[20][50]; //Array to hold movie names

void clearBuffer() {
    while(getchar() != '\n'); //Clear input buffer
}

void addMovie() {
    char newMovie[50];
    printf("\nEnter the name of the new movie: ");
    scanf("%[^\n]", newMovie);
    clearBuffer();

    int index = 0;
    while(movieName[index][0] != '\0') //Finding empty slot for new movie
        index++;

    strcpy(movieName[index], newMovie); //Adding movie to array
    printf("The movie %s has been added successfully!\n\n", newMovie);
}

int getMovieIndex(char name[50]) {
    for(int i=0; i<20; i++) {
        if(!strcmp(movieName[i], name)) //Comparing strings to find movie index
            return i;
    }
    return -1; //Movie not found
}

void rateMovie() {
    char movie[50];
    printf("\nEnter the name of the movie: ");
    scanf("%[^\n]", movie);
    clearBuffer();

    int index = getMovieIndex(movie);
    if(index == -1) { //Movie not found
        printf("Movie not found. Please try again.\n\n");
        return;
    }

    int ratingVal;
    printf("Enter your rating (1-10): ");
    scanf("%d", &ratingVal);
    clearBuffer();

    if(ratingVal < 1 || ratingVal > 10) { //Invalid rating
        printf("Invalid rating. Please try again.\n\n");
        return;
    }

    rating[index] = (rating[index] + ratingVal)/2; //Calculating new rating
    printf("Thank you for rating %s!\n\n", movie);
}

char getRatingSymbol(int ratingVal) {
    if(ratingVal >= 9)
        return 'A';
    else if(ratingVal >= 7)
        return 'B';
    else if(ratingVal >= 5)
        return 'C';
    else
        return 'D';
}

void showMovies() {
    printf("\nMovie\t\t\tRating\n");
    printf("-------------------------------\n");
    for(int i=0; i<20; i++) {
        if(movieName[i][0] != '\0') {
            char symbol = getRatingSymbol(rating[i]);
            printf("%-20s %c\n", movieName[i], symbol);
        }
    }
    printf("-------------------------------\n\n");
}

int main() {
    int choice;
    while(1) {
        printf("1. Add Movie\n2. Rate Movie\n3. Show Movies\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch(choice) {
            case 1:
                addMovie();
                break;
            case 2:
                rateMovie();
                break;
            case 3:
                showMovies();
                break;
            case 4:
                printf("\nThank you for using the movie rating system.\n");
                return 0; //Exit
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }
    return 0;
}