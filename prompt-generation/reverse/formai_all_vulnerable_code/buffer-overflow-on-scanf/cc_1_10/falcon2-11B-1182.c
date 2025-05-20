//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Define structures for movie, user and review
struct Movie {
	char title[100];
	int rating;
	char releaseDate[100];
};

struct User {
	char name[100];
	int rating;
};

struct Review {
	struct Movie movie;
	struct User user;
	int rating;
};

// Function prototypes
void printMovie(struct Movie);
void printReview(struct Review);
void getMovieDetails(struct Movie*);
void getUserDetails(struct User*);
void getReviewDetails(struct Review*);

// Main function
int main() {
	struct Movie movie;
	struct User user;
	struct Review review;

	// Get movie details
	printf("Enter movie title:\n");
	scanf("%s", movie.title);

	printf("Enter movie rating (1-5):\n");
	scanf("%d", &movie.rating);

	printf("Enter movie release date (yyyy-mm-dd):\n");
	scanf("%s", movie.releaseDate);

	// Get user details
	printf("Enter your name:\n");
	scanf("%s", user.name);

	printf("Enter your rating (1-5):\n");
	scanf("%d", &user.rating);

	// Create review
	review.movie = movie;
	review.user = user;
	review.rating = movie.rating;

	// Print review
	printReview(review);

	return 0;
}

// Print movie details
void printMovie(struct Movie movie) {
	printf("Movie:\n");
	printf("Title: %s\n", movie.title);
	printf("Rating: %d\n", movie.rating);
	printf("Release date: %s\n", movie.releaseDate);
	printf("\n");
}

// Print review details
void printReview(struct Review review) {
	printf("Review:\n");
	printf("Movie: %s\n", review.movie.title);
	printf("User: %s\n", review.user.name);
	printf("Rating: %d\n", review.rating);
	printf("\n");
}

// Get movie details
void getMovieDetails(struct Movie* movie) {
	printf("Enter movie title:\n");
	scanf("%s", movie->title);

	printf("Enter movie rating (1-5):\n");
	scanf("%d", &movie->rating);

	printf("Enter movie release date (yyyy-mm-dd):\n");
	scanf("%s", movie->releaseDate);
}

// Get user details
void getUserDetails(struct User* user) {
	printf("Enter your name:\n");
	scanf("%s", user->name);

	printf("Enter your rating (1-5):\n");
	scanf("%d", &user->rating);
}

// Get review details
void getReviewDetails(struct Review* review) {
	getMovieDetails(&review->movie);
	getUserDetails(&review->user);
}