//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[1000];
  
  // Welcome message
  printf("Welcome to the C Cat Language Translator!\n\n");

  // Ask for user input
  printf("Enter a sentence in English:\n");
  scanf("%[^\n]s", input);

  // Define cat vocabulary
  char* catVocab[10][2] = {
    {"meow", "hello"},
    {"purr", "thank you"},
    {"hiss", "goodbye"},
    {"scratch", "please"},
    {"catnip", "food"},
    {"hairball", "problem"},
    {"paw", "hand"},
    {"whisker", "finger"},
    {"tail", "backside"},
    {"feline", "cat"}
  };

  // Split input into words
  char* token;
  token = strtok(input, " ");

  // Translate each word
  while (token != NULL) {
    for (int i = 0; i < 10; i++) {
      if (strcmp(token, catVocab[i][0]) == 0) {
        printf("%s ", catVocab[i][1]);
        break;
      } else if (i == 9) {
        printf("%s ", token);
      }
    }
    token = strtok(NULL, " ");
  }

  // Goodbye message
  printf("\n\nThank you for using the C Cat Language Translator!\n");

  return 0;
}