//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: puzzling
#include<stdio.h>
#include<string.h>

char english[1000], cat[1000];
int i, j;

void englishToCat(char english[]);
void catToEnglish(char cat[]);

int main() 
{
   int choice;

   printf("\n\n CAT LANGUAGE TRANSLATOR \n");
   printf("--------------------------\n");
   printf("1. English to Cat\n");
   printf("2. Cat to English\n");
   printf("--------------------------\n");
   printf("Enter your choice: ");
   scanf("%d", &choice);

   switch(choice) 
   {
      case 1:
         printf("\nEnter English string: ");
         scanf("%s", english);
         englishToCat(english);
         printf("\nCat language: %s\n",cat);
         break;

      case 2:
         printf("\nEnter Cat language: ");
         scanf("%s", cat);
         catToEnglish(cat);
         printf("\nEnglish string: %s\n",english);
         break;

      default:
         printf("\nInvalid choice! Please try again.\n");
         break;
   }

   return 0;
}

void englishToCat(char english[]) 
{
   int englishLength = strlen(english);
   int catLength = 0;
   for(i=0; i<englishLength; i++) 
   {
      if(english[i] == 'a') 
      {
         strcat(cat, "meow");
         catLength += 4;
      }
      else if(english[i] == 'e') 
      {
         strcat(cat, "purr");
         catLength += 4;
      }
      else if(english[i] == 'i') 
      {
         strcat(cat, "hiss");
         catLength += 4;
      }
      else if(english[i] == 'o') 
      {
         strcat(cat, "yowl");
         catLength += 4;
      }
      else if(english[i] == 'u') 
      {
         strcat(cat, "scratch");
         catLength += 7;
      }
      else 
      {
         cat[catLength] = english[i];
         catLength += 1;
      }
   }

   cat[catLength] = '\0';
}

void catToEnglish(char cat[]) 
{
   int catLength = strlen(cat);
   int englishLength = 0;
   for(i=0; i<catLength; i++) 
   {
      if(cat[i] == 'm' && cat[i+1] == 'e' && cat[i+2] == 'o' && cat[i+3] == 'w') 
      {
         english[englishLength] = 'a';
         englishLength += 1;
         i += 3;
      }
      else if(cat[i] == 'p' && cat[i+1] == 'u' && cat[i+2] == 'r' && cat[i+3] == 'r') 
      {
         english[englishLength] = 'e';
         englishLength += 1;
         i += 3;
      }
      else if(cat[i] == 'h' && cat[i+1] == 'i' && cat[i+2] == 's' && cat[i+3] == 's') 
      {
         english[englishLength] = 'i';
         englishLength += 1;
         i += 3;
      }
      else if(cat[i] == 'y' && cat[i+1] == 'o' && cat[i+2] == 'w' && cat[i+3] == 'l') 
      {
         english[englishLength] = 'o';
         englishLength += 1;
         i += 3;
      }
      else if(cat[i] == 's' && cat[i+1] == 'c' && cat[i+2] == 'r' && cat[i+3] == 'a' && cat[i+4] == 't' && cat[i+5] == 'c' && cat[i+6] == 'h')
      {
         english[englishLength] = 'u';
         englishLength += 1;
         i += 6;
      }
      else 
      {
         english[englishLength] = cat[i];
         englishLength += 1;
      }
   }

   english[englishLength] = '\0';
}