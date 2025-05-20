//FormAI DATASET v1.0 Category: Movie Rating System ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct movie{
    char title[100];
    char director[50];
    int duration;
    char genre[20];
    float rating;
};

void displayMenu(){
    printf("\nWelcome to our C Movie Rating System!");
    printf("\n[1] Add a Movie");
    printf("\n[2] Rate a Movie");
    printf("\n[3] View Movie Details");
    printf("\n[4] View Rated Movie List");
    printf("\n[5] View Top Rated Movies");
    printf("\n[6] Exit");
    printf("\nPlease enter your choice: ");
}

void addMovie(struct movie *movies, int *count){
    printf("\nPlease enter the details of the movie:");
    printf("\nTitle: ");
    scanf(" %[^\n]s", movies[*count].title);
    printf("Director: ");
    scanf(" %[^\n]s", movies[*count].director);
    printf("Duration (in minutes): ");
    scanf("%d", &movies[*count].duration);
    printf("Genre: ");
    scanf(" %[^\n]s", movies[*count].genre);
    movies[*count].rating = 0.0;
    (*count)++;
    printf("\nMovie added successfully!\n");
}

void rateMovie(struct movie *movies, int count){
    char title[100];
    int i, found = 0;
    float rating;
    printf("\nPlease enter the title of the movie you want to rate: ");
    scanf(" %[^\n]s", title);
    for(i=0; i<count; i++){
        if(strcmp(movies[i].title, title) == 0){
            found = 1;
            printf("Please enter your rating (out of 10): ");
            scanf("%f", &rating);
            movies[i].rating = rating;
            printf("\nThank you for rating this movie!\n");
            break;
        }
    }
    if(!found){
        printf("\nMovie not found!\n");
    }
}

void viewMovieDetails(struct movie *movies, int count){
    char title[100];
    int i, found = 0;
    printf("\nPlease enter the title of the movie you want to view: ");
    scanf(" %[^\n]s", title);
    for(i=0; i<count; i++){
        if(strcmp(movies[i].title, title) == 0){
            found = 1;
            printf("\nMovie Details:\n");
            printf("Title: %s\n", movies[i].title);
            printf("Director: %s\n", movies[i].director);
            printf("Duration: %d minutes\n", movies[i].duration);
            printf("Genre: %s\n", movies[i].genre);
            if(movies[i].rating != 0.0){
                printf("Rating: %.2f/10\n", movies[i].rating);
            }
            else{
                printf("This movie has not been rated yet.\n");
            }
            break;
        }
    }
    if(!found){
        printf("\nMovie not found!\n");
    }
}

void viewRatedMovies(struct movie *movies, int count){
    int i, rated_count = 0;
    printf("\nRated Movie List:\n");
    for(i=0; i<count; i++){
        if(movies[i].rating != 0){
            printf("%s\n", movies[i].title);
            rated_count++;
        }
    }
    if(rated_count == 0){
        printf("\nNo movies have been rated yet!\n");
    }
}

void viewTopRatedMovies(struct movie *movies, int count){
    int i, j, max_index;
    struct movie temp;
    printf("\nTop Rated Movies:\n");
    // Bubble sort based on rating
    for (i = 0; i < count-1; i++){
        for (j = 0; j < count-i-1; j++){
            if (movies[j].rating < movies[j+1].rating){
                temp = movies[j];
                movies[j] = movies[j+1];
                movies[j+1] = temp;
            }
        }
    }
    // Print top 3 rated movies
    for(i=0; i<count && i<3; i++){
        printf("%d. %s - %.2f/10\n", i+1, movies[i].title, movies[i].rating);
    }
}

int main(){
    int choice, count = 0;
    struct movie movies[100];
    while(1){
        displayMenu();
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                addMovie(movies, &count);
                break;
            case 2: 
                rateMovie(movies, count);
                break;
            case 3: 
                viewMovieDetails(movies, count);
                break;
            case 4: 
                viewRatedMovies(movies, count);
                break;
            case 5: 
                viewTopRatedMovies(movies, count);
                break;
            case 6: 
                printf("\nThank you for using our C Movie Rating System!\n");
                exit(0);
            default: 
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}