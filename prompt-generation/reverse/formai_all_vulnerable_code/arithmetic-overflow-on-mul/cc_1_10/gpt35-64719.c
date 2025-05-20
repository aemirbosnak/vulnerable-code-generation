//FormAI DATASET v1.0 Category: Math exercise ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
  int num1, num2, i, choice, ans, correct=0, incorrect=0;
  float percentage;
  
  printf("Math Exercise Example Program\n");
  printf("============================\n\n");
  
  printf("Enter the number range for the math quiz: ");
  scanf("%d", &num1);
  printf("Enter the number of questions you want to solve: ");
  scanf("%d", &num2);
  
  srand(time(0));
  
  for(i=0; i<num2; i++){
    
    choice=rand()%4+1;
    
    switch(choice){
      case 1:
        printf("\n%d + %d = ", rand()%num1, rand()%num1);
        scanf("%d", &ans);
        if(ans==(num1+num2)){
          printf("Correct Answer!\n");
          correct++;
        }
        else{
          printf("Incorrect Answer!\n");
          incorrect++;
        }
        break;
        
      case 2:
        printf("\n%d - %d = ", rand()%num1, rand()%num1);
        scanf("%d", &ans);
        if(ans==(num1-num2)){
          printf("Correct Answer!\n");
          correct++;
        }
        else{
          printf("Incorrect Answer!\n");
          incorrect++;
        }
        break;
        
      case 3:
        printf("\n%d * %d = ", rand()%num1, rand()%num1);
        scanf("%d", &ans);
        if(ans==(num1*num2)){
          printf("Correct Answer!\n");
          correct++;
        }
        else{
          printf("Incorrect Answer!\n");
          incorrect++;
        }
        break;
        
      case 4:
        printf("\n%d / %d = ", rand()%num1, rand()%num1);
        scanf("%d", &ans);
        if(ans==(num1/num2)){
          printf("Correct Answer!\n");
          correct++;
        }
        else{
          printf("Incorrect Answer!\n");
          incorrect++;
        }
        break;
    }
  }
  
  percentage=((float)correct/num2)*100.0;
  
  printf("\n\n*****Math Quiz Results*****\n");
  printf("Number of Correct Answers: %d\n", correct);
  printf("Number of Incorrect Answers: %d\n", incorrect);
  printf("Percentage: %.2f%%\n", percentage);
  
  return 0;
}