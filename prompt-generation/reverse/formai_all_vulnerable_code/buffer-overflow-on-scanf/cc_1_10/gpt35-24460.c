//FormAI DATASET v1.0 Category: Image Steganography ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void hide(const char *s1,const char *s2);
void search(const char *s);

void main()
{
  char msg[50], msg1[50];
  
  printf("Enter the message to hide: ");
  scanf("%[^\n]",&msg);
  
  printf("Enter the message to be hidden: ");
  scanf("%s",&msg1);

  printf("\n\nOriginal Message: %s\n",msg);
  
  hide(msg,msg1);
  
  printf("The Secret Message is hidden successfully\n\n");
  printf("Encrypted Message: %s\n",msg);
  
  search(msg);
  
}

void hide(const char *s1,const char *s2)
{
  int i,j=0,k=0,len1,len2;
  char temp[50] = {'\0'}, test[10] = {'\0'};

   len1 = strlen(s1);
   len2 = strlen(s2);
   for(i=0; i<=len1; i++)
   {
        if(isspace(s1[i]))
            continue;
        else
            strcat(temp,&s1[i]);
    }
    for(i=0; i<=len2; i++)
    {
        sprintf(test,"%d",s2[i]);
        strcat(temp,&test[1]);
    }
    strcat(temp,"\0");
    strcpy(s1,temp);
}

void search(const char *s)
{
    int i,j=0,len1,ress;
    char temp[10] = {'\0'};

    len1 = strlen(s);
    for(i=0; i<=len1; i++)
    {
        if(isdigit(s[i]))
        {
            temp[j] = s[i];
            j++;
        }
        else
        {
            ress = atoi(temp);
            printf("%c",(char)ress);
            j=0;
            memset(temp,'\0',strlen(temp));
        
        }
    }
}