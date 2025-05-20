//FormAI DATASET v1.0 Category: String manipulation ; Style: irregular
#include<stdio.h>
#include<string.h>

char p[]="This is a String";
int k=0;
char m[]="mageedpshaker";
char t[20]="xyz123";
int count=0;

void replace(char s[],char w1[],char w2[]){

   char* temp=NULL;
   temp=strstr(s,w1);
   if(temp){
      strncpy(temp,w2,strlen(w2));
   }
   printf("%s",s);
}

void reverses(char s[])
{
   int i,j;
   char temp;
   i=0;
   j=strlen(s)-1;
   while(i<j){
      temp=s[i];
      s[i]=s[j];
      s[j]=temp;
      i++;
      j--;
   }
   printf("%s",s);
}

int searchString(char s[],char ch)
{
   while(s[k]){
      if(s[k]==ch)
         count++;
      k++;
   }
   return count;
}

void strCapitalize(char s[])
{
   int i=0;
   while(s[i]){
      if(s[i]>=97 && s[i]<=122)
         s[i]-=32;
      i++;
   }
   printf("%s",s);
}

int main(){
   printf("Original String: %s\n",p);
   printf("Enter words to Replace: ");
   char word1[20],word2[20];
   scanf("%s%s",word1,word2);
   replace(p,word1,word2);

   printf("\nOriginal String: %s\n",m);
   reverses(m);

   printf("\nEnter a character to search: ");
   char search=' ';
   scanf("%c",&search);
   int result=searchString(t,search);
   printf("Character '%c' found %d times\n",search,result);

   printf("\nOriginal String: %s\n",m);
   printf("Capitalized String: ");
   strCapitalize(m);
   return 0;
}