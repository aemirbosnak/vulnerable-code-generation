//FormAI DATASET v1.0 Category: Syntax parsing ; Style: surprised
#include<stdio.h>

int main()
{
  char expression[50];
  int i, error_flag = 0;
  
  printf("Please enter a C syntax statement: ");
  scanf("%s", expression);
  
  for(i=0; i<strlen(expression); i++)
  {
    if(expression[i] == '(')
    {
      int j;
      int found_match = 0;
      for(j=i+1; j<strlen(expression); j++)
      {
        if(expression[j] == ')')
        {
          found_match = 1;
          break;
        }
        else if(expression[j] == '(')
        {
          error_flag = 1;
          printf("\nUnexpected symbol '(' found within parenthesis");
          break;
        }
      }
      if(found_match == 0)
      {
        error_flag = 1;
        printf("\nMismatched parenthesis found");
        break;
      }
      else
      {
        i = j; // skip to end of current parenthesis
      }
    }
    else if(expression[i] == ')')
    {
      error_flag = 1;
      printf("\nUnexpected closing parenthesis found");
      break;
    }
    else if(expression[i] == ';')
    {
      if(i != strlen(expression)-1)
      {
        error_flag = 1;
        printf("\nUnexpected symbol found after semicolon");
        break;
      }
    }
  }
  if(error_flag == 0)
  {
    printf("\nProgram successfully parsed");
  }
  return 0;
}