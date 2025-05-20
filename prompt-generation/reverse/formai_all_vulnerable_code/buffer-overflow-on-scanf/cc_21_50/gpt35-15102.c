//FormAI DATASET v1.0 Category: Movie Rating System ; Style: energetic
#include <stdio.h>

int main() {
  int rating;
 
  printf("Welcome to the C Movie Rating System!\n");
  printf("Please rate the following movies on a scale of 1-10:\n\n");
  
  // Movie 1
  printf("Movie 1: Avengers: Endgame\n");
  scanf("%d", &rating);
  if (rating >= 8 && rating <= 10) {
    printf("Great choice! Avengers: Endgame is a fantastic movie!\n");
  } else if (rating >= 5 && rating <= 7) {
    printf("Not a bad choice, Avengers: Endgame is a good movie!\n");
  } else {
    printf("Yikes, Avengers: Endgame isn't for everyone I suppose.\n");
  }
  printf("--------------------\n");
  
  // Movie 2
  printf("Movie 2: The Shawshank Redemption\n");
  scanf("%d", &rating);
  if (rating >= 8 && rating <= 10) {
    printf("Excellent choice! The Shawshank Redemption is a masterpiece!\n");
  } else if (rating >= 5 && rating <= 7) {
    printf("Decent choice, The Shawshank Redemption is a well-made movie!\n");
  } else {
    printf("Ah, not everyone appreciates the brilliance of The Shawshank Redemption.\n");
  }
  printf("--------------------\n");
  
  // Movie 3
  printf("Movie 3: Space Jam\n");
  scanf("%d", &rating);
  if (rating >= 8 && rating <= 10) {
    printf("Classic choice! Space Jam is a time-honored favorite!\n");
  } else if (rating >= 5 && rating <= 7) {
    printf("Not too shabby, Space Jam is a fun movie for all ages!\n");
  } else {
    printf("Ah, perhaps Space Jam isn't everyone's cup of tea...\n");
  }
  printf("--------------------\n");
  
  // Movie 4
  printf("Movie 4: The Emoji Movie\n");
  scanf("%d", &rating);
  if (rating >= 8 && rating <= 10) {
    printf("...you're kidding, right? The Emoji Movie was a disaster.\n");
  } else if (rating >= 5 && rating <= 7) {
    printf("Hm, a divisive movie. The Emoji Movie was...fine, I suppose.\n");
  } else {
    printf("Thank you for your honesty. The Emoji Movie was truly terrible.\n");
  }
  printf("--------------------\n");
  
  // Movie 5
  printf("Movie 5: The Godfather\n");
  scanf("%d", &rating);
  if (rating >= 8 && rating <= 10) {
    printf("Bravo! The Godfather is an undisputed classic!\n");
  } else if (rating >= 5 && rating <= 7) {
    printf("A good choice, The Godfather is a brilliant movie.\n");
  } else {
    printf("Ah, not everyone can appreciate the greatness of The Godfather...\n");
  }
  printf("--------------------\n");
  
  return 0;
}