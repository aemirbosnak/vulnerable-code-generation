//FormAI DATASET v1.0 Category: Online Examination System ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main() {
   int questions[10][5] = {{1,1,4,2,3},
                          {2,2,3,2,3},
                          {3,1,1,3,4},
                          {4,2,1,4,1},
                          {5,3,2,1,3},
                          {6,2,2,3,4},
                          {7,4,2,1,4},
                          {8,3,1,2,3},
                          {9,1,3,2,1},
                          {10,2,4,1,3}};
   int answers[10][5] = {{1,1,4,2,3},
                        {2,2,3,2,3},
                        {3,1,1,3,4},
                        {4,2,1,4,1},
                        {5,3,2,1,3},
                        {6,2,2,3,4},
                        {7,4,2,1,4},
                        {8,3,1,2,3},
                        {9,1,3,2,1},
                        {10,2,4,1,3}};
   int score = 0;
   char answer[5];
   printf("Welcome to the C Online Examination System!\n\n");
   for(int i=0; i<10; i++) {
      printf("Question %d: ", questions[i][0]);
      printf("\n%s\n", "What will be the output of the following C code?");
      printf("%s", "printf(\"%d\\n\", 5+3*8/4-2);");
      printf("\n%s\n", "a) 12 b) 14 c) 16 d) 18");
      printf("Enter your choice (a/b/c/d): ");
      scanf("%s", answer);
      if(answers[i][1] == 1 && *answer == 'a') {
         printf("Correct\n");
         score++;
      } else if(answers[i][2] == 1 && *answer == 'b') {
         printf("Correct\n");
         score++;
      } else if(answers[i][3] == 1 && *answer == 'c') {
         printf("Correct\n");
         score++;
      } else if(answers[i][4] == 1 && *answer == 'd') {
         printf("Correct\n");
         score++;
      } else {
         printf("Incorrect\n");
      }
   }
   printf("\nYour score is %d out of 10", score);
   if(score >= 7) {
      printf(", Congratulations!\n");
   } else {
      printf(", Please try again.\n");
   }
   return 0;
}