//FormAI DATASET v1.0 Category: Image Steganography ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  char message[100], hide_msg[100], c;
  int len, i, j, k=0;

  printf("Enter the message you want to hide: ");
  scanf("%[^\n]", message);
  fflush(stdin);

  len = strlen(message);

  printf("Enter the message you want to hide it in: ");
  scanf("%[^\n]", hide_msg);

  FILE *fptr1, *fptr2, *fptr3;

  fptr1 = fopen("msg.txt", "w");

  if(fptr1==NULL)
  {
    printf("Error opening file!");
    exit(1);
  }

  fprintf(fptr1, "%s", message);
  fclose(fptr1);

  fptr1 = fopen("msg.txt", "r");
  fptr2 = fopen("hidden.txt", "w");

  if(fptr1==NULL || fptr2==NULL)
  {
    printf("Error opening file!");
    exit(1);
  }

  for(i=0; i<len; i++)
  {
    c = fgetc(fptr1);

    for(j=7; j>=0; j--)
    {
      if((c>>j)&1)
      {
        fputc(hide_msg[k]|(1<<j), fptr2);
      }
      else
      {
        fputc(hide_msg[k]&(~(1<<j)), fptr2);
      }
      k++;
    }
  }

  while((c=fgetc(fptr1))!=EOF)
  {
    fputc(c, fptr2);
  }

  fclose(fptr1);
  fclose(fptr2);

  fptr2 = fopen("hidden.txt", "r");

  if(fptr2==NULL)
  {
    printf("Error opening file!");
    exit(1);
  }

  fptr3 = fopen("output.txt", "w");

  if(fptr3==NULL)
  {
    printf("Error opening file!");
    exit(1);
  }

  k = 0;

  while(fscanf(fptr2, "%c", &c)!=EOF && k<len*8)
  {
    for(j=7; j>=0; j--)
    {
      if((c>>j)&1)
      {
        fprintf(fptr3, "%c", '1');
      }
      else
      {
        fprintf(fptr3, "%c", '0');
      }
      k++;
    }
  }

  fclose(fptr2);
  fclose(fptr3);

  printf("Encoding message is complete.\n");

  return 0;
}