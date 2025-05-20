//Falcon-180B DATASET v1.0 Category: Error handling ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include<math.h>
#include<time.h>
#include<limits.h>

#define MAX_SIZE 1000

int main()
{
  char input[MAX_SIZE];
  int i,j,k,l;
  int count=0;
  int count_error=0;
  int count_warning=0;
  int count_info=0;
  int count_debug=0;

  printf("Welcome to the Retro Error Handling Program!\n");
  printf("Please enter a string:\n");
  scanf("%[^\n]",input);

  for(i=0;input[i]!='\0';i++)
  {
    if(isalpha(input[i]))
    {
      count++;
    }
    else if(isdigit(input[i]))
    {
      count++;
    }
    else if(isspace(input[i]))
    {
      count++;
    }
    else
    {
      count_error++;
      printf("Error: Invalid character found at position %d\n",i+1);
    }
  }

  if(count_error==0)
  {
    printf("No errors found!\n");
  }
  else
  {
    printf("Total number of errors: %d\n",count_error);
  }

  printf("\n");
  return 0;
}