//FormAI DATASET v1.0 Category: Movie Rating System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int get_choice();
void add_rating(int *ratings);
void print_ratings(int *ratings);
double calculate_average(int *ratings);

int main() {
  int ratings[5] = {0, 0, 0, 0, 0};
  int choice;
  
  do {
    printf("Welcome to the C Movie Rating System!\n\n");
    printf("1) Add rating\n");
    printf("2) Print ratings\n");
    printf("3) Calculate average rating\n");
    printf("4) Exit\n\n");
    printf("Please enter your choice: ");
    
    choice = get_choice();
    
    switch(choice) {
      case 1:
        add_rating(ratings);
        break;
      case 2:
        print_ratings(ratings);
        break;
      case 3:
        printf("The average rating is %.2f\n\n", calculate_average(ratings));
        break;
      case 4:
        printf("Thank you for using the C Movie Rating System!\n\n");
        exit(0);
      default:
        printf("\nInvalid choice. Please try again.\n\n");
        break;
    }
  } while(choice != 4);
  
  return 0;
}

int get_choice() {
  int choice;
  scanf("%d", &choice);
  printf("\n");
  return choice;
}

void add_rating(int *ratings) {
  int movie_number, rating;
  printf("Please enter the movie number (1-5): ");
  scanf("%d", &movie_number);
  printf("Please enter the rating (1-10): ");
  scanf("%d", &rating);
  if(movie_number > 0 && movie_number <= 5 && rating > 0 && rating <= 10) {
    ratings[movie_number - 1] = rating;
    printf("\nRating added.\n\n");
  }
  else {
    printf("\nInvalid input. Please try again.\n\n");
  }
}

void print_ratings(int *ratings) {
  for(int i = 0; i < 5; i++) {
    printf("Movie %d: %d\n", i + 1, ratings[i]);
  }
  printf("\n");
}

double calculate_average(int *ratings) {
  int total = 0, count = 0;
  for(int i = 0; i < 5; i++) {
    if(ratings[i] != 0) {
      total += ratings[i];
      count++;
    }
  }
  return (double) total / count;
}