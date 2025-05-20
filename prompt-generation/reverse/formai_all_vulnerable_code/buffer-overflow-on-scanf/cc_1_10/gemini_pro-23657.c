//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: medieval
#include <stdio.h>
#include <string.h>

int main()
{
  // Declare the text to be processed.
  char text[1000];

  // Prompt the user to enter the text.
  printf("Enter thy text, fair maiden: ");
  scanf("%[^\n]", text);

  // Convert the text to all uppercase.
  for (int i = 0; i < strlen(text); i++)
    text[i] = toupper(text[i]);

  // Print the uppercase text.
  printf("\nThy text in all its glory:\n%s\n", text);

  // Convert the text to all lowercase.
  for (int i = 0; i < strlen(text); i++)
    text[i] = tolower(text[i]);

  // Print the lowercase text.
  printf("\nThy text in all its humility:\n%s\n", text);

  // Count the number of characters in the text.
  int char_count = 0;
  for (int i = 0; i < strlen(text); i++)
    char_count++;

  // Print the number of characters in the text.
  printf("\nThe number of characters in thy text: %d\n", char_count);

  // Count the number of words in the text.
  int word_count = 0;
  for (int i = 0; i < strlen(text); i++)
    if (text[i] == ' ')
      word_count++;

  // Print the number of words in the text.
  printf("\nThe number of words in thy text: %d\n", word_count);

  // Count the number of lines in the text.
  int line_count = 0;
  for (int i = 0; i < strlen(text); i++)
    if (text[i] == '\n')
      line_count++;

  // Print the number of lines in the text.
  printf("\nThe number of lines in thy text: %d\n", line_count);

  return 0;
}