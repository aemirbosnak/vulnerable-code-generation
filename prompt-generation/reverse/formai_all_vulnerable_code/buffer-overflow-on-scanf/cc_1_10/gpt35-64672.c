//FormAI DATASET v1.0 Category: Math exercise ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to calculate the absolute value
int abs_val(int num)
{
  if(num < 0)
  {
    return -num;
  }
  else
  {
    return num;
  }
}

int main()
{
  //Seed the random number generator
  srand(time(0));
  
  int num1, num2, result, user_ans, ans;
  
  //Generate the numbers to be added
  num1 = rand() % 101;    //Generate numbers between 0 and 100
  num2 = rand() % 101;
  
  //Calculate the answer
  ans = num1 + num2;
  
  //Prompt the user to answer the question
  printf("What is the result of %d + %d ?\n", num1, num2);
  scanf("%d", &user_ans);
  
  //Check the answer
  result = abs_val(user_ans - ans);
  if(result == 0)
  {
    printf("Correct!\n");
  }
  else if(result == 1)
  {
    printf("You were close, but be careful, I'm watching you...\n");
  }
  else if(result > 1 && result <= 5)
  {
    printf("Incorrect, but not too far off...Or are you?\n");
  }
  else if(result > 5 && result <= 10)
  {
    printf("You're not even in the ballpark! Did you make an honest mistake or are you trying to throw me off?\n");
  }
  else if(result > 10 && result <= 20)
  {
    printf("You're way off, but you're not fooling anyone. Are you playing dumb on purpose?\n");
  }
  else
  {
    printf("What in the world were you thinking?! Did you forget how to add? Are you trying to sabotage me?\n");
  }
  
  return 0;
}