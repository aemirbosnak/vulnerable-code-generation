//FormAI DATASET v1.0 Category: Online Examination System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

struct Question {
  char ques[100];
  char opA[50], opB[50], opC[50], opD[50];
  char corrOp;
};

int main(){
  int i, score = 0;
  struct Question questions[5];
  questions[0] = (struct Question){"What is the capital of India?", "Kolkata", "Mumbai", "Delhi", "Chennai", 'c'};
  questions[1] = (struct Question){"What is the closest planet to the Sun?", "Mars", "Mercury", "Venus", "Earth", 'b'};
  questions[2] = (struct Question){"What is the smallest country in the world by land area?", "San Marino", "Vatican City", "Monaco", "Maldives", 'b'};
  questions[3] = (struct Question){"What is the largest mammal in the world?", "Killer Whale", "Hippo", "Elephant", "Blue Whale", 'd'};
  questions[4] = (struct Question){"Who wrote the book 'To Kill a Mockingbird'?", "Harper Lee", "J.K Rowling", "Charles Dickens", "Agatha Christie", 'a'};

  printf("--- Welcome to the Online Examination System ---\n");
  printf("--- This exam consists of 5 multiple choice questions ---\n\n");

  for(i = 0; i < 5; i++){
    printf("Q%d. %s\n", i+1, questions[i].ques);
    printf("A. %s\n", questions[i].opA);
    printf("B. %s\n", questions[i].opB);
    printf("C. %s\n", questions[i].opC);
    printf("D. %s\n", questions[i].opD);
    printf("Enter your answer (A/B/C/D): ");
    char ans;
    scanf(" %c", &ans);
    if(ans == questions[i].corrOp){
      printf("Correct answer! You get 1 point.\n\n");
      score++;
    }else{
      printf("Wrong answer! Correct answer: %c\n\n", questions[i].corrOp);
    }
  }

  printf("--- Your final score is %d/5 ---\n\n", score);

  if(score == 5){
    printf("** Congratulations! You scored 100% **\n");
  }else if(score >= 3){
    printf("** Well done! You passed the exam **\n");
  }else{
    printf("** Sorry! You failed the exam **\n");
  }

  return 0;
}