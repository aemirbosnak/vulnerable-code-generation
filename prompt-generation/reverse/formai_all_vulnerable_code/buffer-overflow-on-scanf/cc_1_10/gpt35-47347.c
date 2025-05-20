//FormAI DATASET v1.0 Category: Movie Rating System ; Style: creative
#include <stdio.h>

int main() {
    // Welcome message
    printf("Welcome to C Movie Rating System!\n");

    // Prompt for user's name
    printf("Please enter your name: ");
    char name[20];
    scanf("%s", name);

    // Prompt for user's age
    printf("Please enter your age: ");
    int age;
    scanf("%d", &age);

    // Check if user is above 18 years old
    if (age < 18) {
        printf("Sorry %s, you are not allowed to use this program as you are underage.\n", name);
        return 0;
    }

    // Prompt for movie title
    printf("Please enter the movie title: ");
    char title[50];
    scanf("%s", title);

    // Prompt for movie genre
    printf("Please enter the movie genre: ");
    char genre[20];
    scanf("%s", genre);

    // Prompt for movie rating
    printf("Please rate the movie (out of 10): ");
    double rating;
    scanf("%lf", &rating);

    // Print rating message based on rating
    if (rating >= 9.0) {
        printf("Wow, %s! You think that %s (%s) deserves an AMAZING rating of %.1lf! We will definitely recommend this movie to other viewers.\n", name, title, genre, rating);
    } else if (rating >= 7.0) {
        printf("Great job, %s! You think that %s (%s) is an excellent movie with a rating of %.1lf. This movie will definitely be popular among many viewers.\n", name, title, genre, rating);
    } else if (rating >= 5.0) {
        printf("Not bad, %s! You think that %s (%s) is a decent movie, with a rating of %.1lf. This movie has room for improvement, but it is still worth watching.\n", name, title, genre, rating);
    } else {
        printf("Hmm, %s. You think that %s (%s) is not a very good movie, with a rating of %.1lf. We suggest you choose a different movie, or perhaps give this one another chance!\n", name, title, genre, rating);
    }

    return 0;
}