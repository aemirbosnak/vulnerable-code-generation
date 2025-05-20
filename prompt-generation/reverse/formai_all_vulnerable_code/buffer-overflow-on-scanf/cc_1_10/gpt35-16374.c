//FormAI DATASET v1.0 Category: String manipulation ; Style: innovative
#include<stdio.h>
#include<string.h>

int main()
{
  char str1[50];
  char str2[50];
  char str3[50];

  printf("Enter the first string: ");
  scanf("%s", str1);

  printf("Enter the second string: ");
  scanf("%s", str2);

  printf("Enter the third string: ");
  scanf("%s", str3);

  // Concatenating strings
  strcat(str1, str2);
  strcat(str1, str3);

  printf("Concatenated string is: %s \n", str1);

  // Reversing the string
  int length = strlen(str1);
  for(int i = 0; i < length / 2; i++)
  {
    char temp = str1[i];
    str1[i] = str1[length - i - 1];
    str1[length - i - 1] = temp;
  }

  printf("Reversed string is: %s \n", str1);

  // Searching for a substring
  char subStr[10] = "unique";
  char * p = strstr(str1, subStr);
  if(p)
  {
    printf("Given substring found in the string.\n");
  }
  else
  {
    printf("Given substring not found in the string.\n");
  }

  // Converting string to uppercase
  for(int i = 0; str1[i]; i++)
  {
    if(str1[i] >= 'a' && str1[i] <= 'z')
    {
      str1[i] = str1[i] - 32;
    }
  }

  printf("String in uppercase: %s \n", str1);

  // Splitting the string
  char * token = strtok(str1, " ");
  while(token)
  {
    printf("%s\n", token);
    token = strtok(NULL, " ");
  }

  return 0;
}