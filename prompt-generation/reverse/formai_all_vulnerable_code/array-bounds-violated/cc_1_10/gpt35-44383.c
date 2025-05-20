//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: enthusiastic
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
  printf("Welcome to the Ultimate Typing Speed Test!\n");
  printf("Get ready to type like the wind!\n");
  printf("Instructions:\n");
  printf("Type the words on the screen as fast as you can.\n");
  printf("Accuracy counts too, so be careful!\n");
  printf("You have 60 seconds to complete as many words as possible.\n");
  printf("Press Enter to start the timer.\n");
  getchar();
  system("clear"); //clears the screen
  printf("3\n");
  sleep(1);
  printf("2\n");
  sleep(1);
  printf("1\n");
  sleep(1);
  printf("GO!\n\n");

  //word bank
  char *words[] = {"hello","world","programming","language","computer","science","keyboard","mouse","code","debug","algorithm","data","structure","memory","pointer","numeric","variable","function","syntax","compiler","binary","file","database","network","server","client","program","loop","conditional","statement","operator","iteration","argument","parameter","string","library","header","pointer","scope","operator","bitwise","boolean","floating","point","integer","character","constant","enumeration","union","structure","typedef","volatile","register","extern"};
  int numWords = 60;
  int score = 0, mistakes = 0;
  time_t start, end;
  double timeTaken;

  time(&start);

  //loop for 60 seconds
  while(difftime(time(NULL),start) < 60){
    //randomly selects a word from the word bank
    int randomIndex = rand() % numWords;
    char *word = words[randomIndex];

    //prints the word for the user to type
    printf("%s ", word);
    char *input = malloc(50 * sizeof(char));
    scanf("%s", input);

    //compares the user's input to the correct word
    if(strcmp(input,word) == 0){
      score++;
    }else{
      mistakes++;
    }
    free(input);
    system("clear"); //clears the screen
  }
  time(&end);

  //calculates time taken and final score
  timeTaken = difftime(end,start);
  printf("\nTime taken: %.2f seconds\n", timeTaken);
  printf("Words per minute: %.2f\n", (score/timeTaken)*60);
  printf("Mistakes: %d\n", mistakes);

  return 0;
}