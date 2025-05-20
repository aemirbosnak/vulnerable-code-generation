//FormAI DATASET v1.0 Category: Online Examination System ; Style: puzzling
#include <stdio.h>

int main()
{
  int score = 0;
  printf("Welcome to the C Online Examination System!\n");
  printf("Please answer all questions without peeking at external resources.\n\n");

  printf("Question 1: What is the output of the following code?\n\n");
  printf("int x = 7, y = 2;\n");
  printf("x += y *= 3;\n");
  printf("printf(\"%d %d\", x, y);\n\n");

  int answer1;
  scanf("%d", &answer1);
  if(answer1 == 25)
  {
    printf("Congratulations! You got Question 1 right!\n");
    score++;
  }
  else
  {
    printf("Sorry, that is incorrect.\n");
  }

  printf("\nQuestion 2: What is the output of the following code?\n\n");
  printf("int a = 7, b = 3, c = 2;\n");
  printf("if(a > b || a > c && c > b)\n");
  printf("{\n");
  printf("  printf(\"%d\", a);\n");
  printf("}\n");
  printf("else if(b > c || c > a && a > b)\n");
  printf("{\n");
  printf("  printf(\"%d\", b);\n");
  printf("}\n");
  printf("else\n");
  printf("{\n");
  printf("  printf(\"%d\", c);\n");
  printf("}\n\n");

  int answer2;
  scanf("%d", &answer2);
  if(answer2 == 7)
  {
    printf("Congratulations! You got Question 2 right!\n");
    score++;
  }
  else
  {
    printf("Sorry, that is incorrect.\n");
  }

  printf("\nQuestion 3: What is the output of the following code?\n\n");
  printf("int i;\n");
  printf("for(i = 0; i < 5; --i)\n");
  printf("{\n");
  printf("  printf(\"%d\", i);\n");
  printf("}\n\n");
  
  int answer3;
  scanf("%d", &answer3);
  if(answer3 == 0)
  {
    printf("Congratulations! You got Question 3 right!\n");
    score++;
  }
  else
  {
    printf("Sorry, that is incorrect.\n");
  }

  printf("\nThank you for taking the C Online Examination System. Your score is %d out of 3.\n", score);

  return 0;
}