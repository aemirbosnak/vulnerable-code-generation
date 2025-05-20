//FormAI DATASET v1.0 Category: Word Count Tool ; Style: funny
#include<stdio.h>
#include<string.h>

int main()
{
   int i, space=0, word=1;
   char str[1000];

   printf("Welcome to the C Word Count Tool!\n\n");

   printf("Enter any sentence or paragraph:\n");
   gets(str);

   for(i=0; str[i]!='\0'; i++)
   {
       if(str[i]==' ')
       {
           space++;
           word++;
       }
       else
       {
           space=0;
       }
   }

   printf("\n");

   if(word==1)
   {
       printf("You didn't enter any words! You must be a mime\n");
   }
   else
   {
       printf("Your sentence has %d words in it!\n", word);
   }

   if(space==1)
   {
       printf("You only entered one space! That's not enough to separate words...\n");
   }
   else if(space==0)
   {
       printf("You didn't enter any spaces! How do you expect me to count your words?\n");
   }
   else if(space>1)
   {
       printf("You entered %d spaces in your sentence. You should work on your punctuation...\n", space);
   }

   return 0;
}