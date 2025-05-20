//FormAI DATASET v1.0 Category: HTML beautifier ; Style: surprised
#include<stdio.h>
#include<string.h>

int main()
{
   char html[1000], ch;
   int i, j, len, indent;
   
   printf("Enter your unformatted HTML code: \n");
   scanf("%[^~]s", html);
   printf("\nEnter the desired indentation level: ");
   scanf("%d", &indent);
   
   len = strlen(html);
   i = 0;
  
   while(i<len)
   {
      ch = html[i];
      if(ch=='<')
      {
         i++;
         if(html[i]!='/')
         {
            for(j=1;j<=indent;j++)
               printf(" ");
            while(html[i]!=' ' && html[i]!='>' && html[i]!='\n')
            {
               printf("%c", html[i]);
               i++;
            }
            printf("\n");
            i--; 
         }
         else
         {
            for(j=1;j<=indent;j++)
               printf(" ");
            while(html[i]!='>' && html[i]!='\n')
            {
               printf("%c", html[i]);
               i++;
            }
            printf("\n");
         }
      }
      else
         printf("%c", ch);   
      i++;
   }
   return 0;
}