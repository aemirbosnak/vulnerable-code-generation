//FormAI DATASET v1.0 Category: Weather simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sunnyWeather();
void cloudyWeather();
void rainyWeather();
void snowyWeather();

int main() {
  int weather = -1;
  srand(time(NULL));

  printf("What's the weather like today?\n\n");
  printf("1. Sunny\n");
  printf("2. Cloudy\n");
  printf("3. Rainy\n");
  printf("4. Snowy\n\n");

  printf("Please enter a number between 1-4: ");
  scanf("%d", &weather);

  switch(weather) {
    case 1:
      sunnyWeather();
      break;
    case 2:
      cloudyWeather();
      break;
    case 3:
      rainyWeather();
      break;
    case 4:
      snowyWeather();
      break;
    default:
      printf("Invalid input! Please enter a number between 1-4.\n");
      break;
  }

  return 0;
}

void sunnyWeather() {
  printf("\nIt's a beautiful day in the neighborhood!\n");
  printf("The sun is shining and the birds are singing.\n");
  printf("You feel energized and ready to tackle anything.\n");
}

void cloudyWeather() {
  printf("\nIt's a bit gloomy today, but don't let that get you down.\n");
  printf("The soft clouds overhead make for a great day to stay indoors.\n");
  printf("You might even feel a bit nostalgic as memories of childhood rainy days come flooding back.\n");
}

void rainyWeather() {
  printf("\nIt's a little soggy out there!\n");
  printf("But that doesn't mean you can't have a great day.\n");
  printf("Put on your rain boots and go for a puddle-jumping adventure or cozy up with a book.\n");
}

void snowyWeather() {
  printf("\nIt's a winter wonderland out there!\n");
  printf("Everything is covered in white and the snow is still falling.\n");
  printf("You feel like a kid again as you frolic through the powdery flakes.\n");
}