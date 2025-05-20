//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: curious
#include<stdio.h>
#include<string.h>

int main()
{
  char filename[20];
  char signature[20] = "virus";
  char ch;
  int i=0, flag=0;
  
  printf("Enter the file name to be scanned: ");
  scanf("%s", filename);
  
  FILE *fp = fopen(filename, "r");
  
  if(fp == NULL)
  {
    printf("File not found!\n");
    return 0;
  }
  
  while((ch = fgetc(fp))!= EOF)
  {
    if(ch == signature[i])
    {
      i++;
      if(i == strlen(signature))
      {
        flag=1;
        break;
      }
    }
    else
    {
      i=0;
    }
  }
  
  if(flag == 1)
  {
    printf("Virus Found!\n");
  }
  else
  {
    printf("The file is safe!\n");
  }
  
  fclose(fp);
  return 0;
}