//FormAI DATASET v1.0 Category: Online Examination System ; Style: Romeo and Juliet
// Romeo and Juliet C Online Examination System

#include <stdio.h>

int main() {
  int score = 0;
  
  // Romeo's first question
  printf("Romeo: My beloved Juliet, what is the output of the following code?\n");
  printf("int num = 3;\n");
  printf("if(num == 3) printf(\"Perfect!\");\n");
  printf("else printf(\"Wrong answer.\");\n");
  printf("A) Perfect!\n");
  printf("B) Wrong answer.\n");
  printf("Answer: ");
  
  char ans1;
  scanf("%c", &ans1);
  if (ans1 == 'A') {
    printf("Romeo: Amazing! You're correct.\n");
    score++;
  } else {
    printf("Romeo: Oh no, my love! The correct answer is A.\n");
  }
  
  // Juliet's first question
  printf("\nJuliet: My sweet Romeo, can you tell me the difference between while and do-while loop?\n");
  printf("A) There is no difference.\n");
  printf("B) while loop runs the code first and then checks the condition, whereas do-while loop checks the condition first and then runs the code.\n");
  printf("Answer: ");
  
  char ans2;
  scanf(" %c", &ans2);
  if (ans2 == 'B') {
    printf("Juliet: Yay! You're so smart!\n");
    score++;
  } else {
    printf("Juliet: Oh dear, you missed that one. The correct answer is B.\n");
  }
  
  // Romeo's second question
  printf("\nRomeo: My love, what is a pointer in C?\n");
  printf("A) A type of variable that stores the memory address of another variable.\n");
  printf("B) An error that occurs when the program runs.\n");
  printf("Answer: ");
  
  char ans3;
  scanf(" %c", &ans3);
  if (ans3 == 'A') {
    printf("Romeo: You are so brilliant, my love!\n");
    score++;
  } else {
    printf("Romeo: Oh no, my heart aches! The correct answer is A.\n");
  }
  
  // Juliet's second question
  printf("\nJuliet: My dear Romeo, what is the difference between a structure and a union in C?\n");
  printf("A) Structures and unions are the same thing.\n");
  printf("B) The main difference is that a structure stores multiple types of data in a single memory unit, while a union stores only one type of data at a time.\n");
  printf("Answer: ");
  
  char ans4;
  scanf(" %c", &ans4);
  if (ans4 == 'B') {
    printf("Juliet: Yes! You are my hero!\n");
    score++;
  } else {
    printf("Juliet: Oh Romeo, my heart is breaking. The correct answer is B.\n");
  }
  
  // Final score
  printf("\nRomeo: My love, you scored %d out of 4! You are a genius!\n", score);
  
  return 0;
}