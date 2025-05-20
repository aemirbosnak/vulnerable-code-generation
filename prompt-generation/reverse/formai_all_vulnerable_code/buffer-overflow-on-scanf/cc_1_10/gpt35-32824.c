//FormAI DATASET v1.0 Category: Movie Rating System ; Style: relaxed
#include <stdio.h>

int main(){
  int rating, total, count;
  float average;
  char movieTitle[50];

  //Initializing variables
  total = 0, count = 0;

  //Greeting the user and getting the movie title
  printf("Welcome to the Movie Rating System!\n");
  printf("Please enter the title of the movie you wish to rate:\n");
  scanf("%s", movieTitle);

  //Getting the user ratings and calculating the average
  do{
    printf("Enter a rating between 0 and 10, or -1 to exit:\n");
    scanf("%d", &rating);
    if(rating >= 0 && rating <=10){
      total += rating;
      count++;
    }
    else if(rating != -1){
      printf("Invalid rating! Try again.\n");
    }
  }while(rating != -1);

  //Calculating and displaying the average rating
  if(count > 0){
    average = (float)total / count;
    printf("\nThe average rating for %s is %.2f.\n", movieTitle, average);
  }
  else{
    printf("\nNo valid ratings entered.\n");
  }

  //Displaying a message based on the average rating
  if(average >= 8.0){
    printf("This is an excellent movie! A must-watch!\n");
  }
  else if(average >= 6.0){
    printf("This is a good movie! Definitely worth watching.\n");
  }
  else if(average >= 4.0){
    printf("This movie is okay. You might like it.\n");
  }
  else{
    printf("This movie is not very good. You can skip it.\n");
  }

  return 0;
}