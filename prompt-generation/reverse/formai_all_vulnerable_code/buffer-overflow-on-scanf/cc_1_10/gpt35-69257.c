//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
  char answer[50];
  char correct_answer[] = "tungsten";
  int score = 0;

  printf("\nWelcome to the C periodic table quiz! Are you ready to test your knowledge?\n");
  printf("Let's begin!\n");

  printf("\nQuestion 1: What element has the symbol W?\n");
  scanf("%s", answer);
  if(strcmp(answer, correct_answer) == 0){
    printf("Correct!\n");
    score++;
  }else{
    printf("Incorrect!\n");
  }

  printf("\nQuestion 2: What element has the symbol C?\n");
  scanf("%s", answer);
  if(strcmp(answer, "carbon") == 0){
    printf("Correct!\n");
    score++;
  }else{
    printf("Incorrect!\n");
  }

  printf("\nQuestion 3: What element has the symbol Fe?\n");
  scanf("%s", answer);
  if(strcmp(answer, "iron") == 0){
    printf("Correct!\n");
    score++;
  }else{
    printf("Incorrect!\n");
  }

  printf("\nQuestion 4: What element has the symbol Na?\n");
  scanf("%s", answer);
  if(strcmp(answer, "sodium") == 0){
    printf("Correct!\n");
    score++;
  }else{
    printf("Incorrect!\n");
  }

  printf("\nQuestion 5: What element has the symbol Ne?\n");
  scanf("%s", answer);
  if(strcmp(answer, "neon") == 0){
    printf("Correct!\n");
    score++;
  }else{
    printf("Incorrect!\n");
  }

  printf("\nThat's the end of the quiz! Let's see how you did.\n");
  printf("You scored %d out of 5.\n", score);

  if(score == 5){
    printf("Wow, you really know your stuff! Great job!\n");
  }else if(score == 4){
    printf("Excellent job, you just missed one!\n");
  }else if(score == 3){
    printf("Not bad, but you can do better!\n");
  }else{
    printf("Looks like you need to study some more.\n");
  }

  return 0;
}