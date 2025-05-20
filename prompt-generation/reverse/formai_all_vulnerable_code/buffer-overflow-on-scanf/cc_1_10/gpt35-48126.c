//FormAI DATASET v1.0 Category: String manipulation ; Style: satisfied
#include <stdio.h>
#include <string.h>

int main()
{
   char original_str[100], reverse_str[100] = {0};
   int i, j, len;

   printf("Enter a string: ");
   scanf("%s", original_str);

   len = strlen(original_str);

   j = len - 1;

   for(i = 0; i < len; i++) {
      reverse_str[i] = original_str[j];
      j--;
   }

   printf("Reverse string is: %s\n", reverse_str);

   if (strcmp(original_str, reverse_str) == 0)
      printf("%s is a palindrome.\n", original_str);
   else
      printf("%s is not a palindrome.\n", original_str);

   printf("Enter a character to search: ");
   char ch;
   scanf(" %c", &ch);

   int index = -1;
   for(i = 0; i < len; i++) {
      if(original_str[i] == ch) {
         index = i;
         break;
      }
   }

   if(index == -1)
      printf("The character '%c' is not found.\n", ch);
   else
      printf("The character '%c' is found at index %d.\n", ch, index);

   printf("Enter a word to replace: ");
   char old_word[20], new_word[20];
   scanf("%s", old_word);
   printf("Enter a new word to replace '%s': ", old_word);
   scanf("%s", new_word);

   char *pos = strstr(original_str, old_word);
   if(pos != NULL) {
      int i, j;
      int len1 = strlen(original_str);
      int len2 = strlen(new_word);
      int len3 = strlen(old_word);
      int diff = len2 - len3;
      
      // move the rest of the string to the right
      for(int i = len1; i > pos-original_str+len3; i--)
         original_str[i+diff] = original_str[i];

      // replace old with new
      for(int i = 0; i < len2; i++)
         original_str[pos-original_str+i] = new_word[i];

      printf("New string after replacement: '%s'\n", original_str);
   }
   else {
      printf("'%s' not found in '%s'", old_word, original_str);
   }

   return 0;
}