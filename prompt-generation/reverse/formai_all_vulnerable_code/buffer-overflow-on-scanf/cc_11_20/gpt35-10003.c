//FormAI DATASET v1.0 Category: Text processing ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  char text[1000];
  char new_text[1000];
  int option;
  int i, j, k = 0, count = 0;
  printf("Enter the text:");
  fgets(text, sizeof(text), stdin);
  
  printf("Select an option:\n");
  printf("1. Remove vowels\n");
  printf("2. Reverse the text\n");
  printf("3. Count words\n");
  printf("Enter an option:");
  scanf("%d", &option);
  
  switch(option)
  {
    case 1: // Remove vowels
      for(i=0; text[i]!='\0'; i++)
      {
        if(text[i]=='a' || text[i]=='e' || text[i]=='i' || text[i]=='o' || text[i]=='u' || text[i]=='A' || text[i]=='E' || text[i]=='I' || text[i]=='O' || text[i]=='U')
        {
          continue;
        }
        new_text[k] = text[i];
        k++;
      }
      new_text[k] = '\0';
      printf("Modified text:%s\n", new_text);
      break;
    
    case 2: // Reverse the text
      j = strlen(text) - 2; // -2 to remove \n
      for(i=0; i<strlen(text)-1; i++)
      {
        new_text[i] = text[j];
        j--;
      }
      new_text[i] = '\0';
      printf("Modified text:%s\n", new_text);
      break;
    
    case 3: // Count words
      for(i=0; text[i]!='\0'; i++)
      {
        if(text[i]==' ')
        {
          count++;
        }
      }
      printf("Number of words:%d\n", count+1); // +1 to account for last word
      break;
    
    default:
      printf("Invalid option!");
  }
  return 0;
}