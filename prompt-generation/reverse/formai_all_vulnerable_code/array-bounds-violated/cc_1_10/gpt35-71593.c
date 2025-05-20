//FormAI DATASET v1.0 Category: String manipulation ; Style: minimalist
#include <stdio.h>
#include <string.h>

int main() {
  char str1[50], str2[50], concat_str[100];
  int len1, len2, i, j;

  // Get input strings from user
  printf("Enter string one: ");
  fgets(str1, 50, stdin);
  printf("Enter string two: ");
  fgets(str2, 50, stdin);

  // Remove \n character from input strings
  len1 = strlen(str1);
  if (str1[len1-1] == '\n') 
    str1[len1-1] = '\0';
  len2 = strlen(str2);
  if (str2[len2-1] == '\n') 
    str2[len2-1] = '\0';

  // Find length of each string
  len1 = strlen(str1);
  len2 = strlen(str2);

  // Concatenate the two strings
  for (i = 0; i < len1; i++) 
    concat_str[i] = str1[i];
  for (j = 0; j < len2; j++) 
    concat_str[len1+j] = str2[j];
  
  // Add null terminator to concatenated string
  concat_str[len1+len2] = '\0';

  // Print the original strings and the concatenated string
  printf("First string: %s\n", str1);
  printf("Second string: %s\n", str2);
  printf("Concatenated string: %s\n", concat_str);

  // Search for a substring in the concatenated string
  char search_str[50];
  printf("Enter a substring to search for in the concatenated string: ");
  fgets(search_str, 50, stdin);

  // Remove \n character from search string
  int search_len = strlen(search_str);
  if (search_str[search_len-1] == '\n') 
    search_str[search_len-1] = '\0';

  char *found_str;
  found_str = strstr(concat_str, search_str);

  if (found_str != NULL)
    printf("'%s' found in concatenated string at position %ld.\n", search_str, found_str-concat_str);
  else 
    printf("Substring not found in concatenated string.\n");

  return 0;
}