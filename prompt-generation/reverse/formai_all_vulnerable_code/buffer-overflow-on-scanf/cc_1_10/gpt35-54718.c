//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: invasive
/*Welcome to the powerful and innovative C Cat Language Translator!*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the dictionary for Cat language */
char cat_dict[10][20] = {"meow", "purr", "hiss", "chirp", "scratch",
                         "lick", "yowl", "pounce", "play", "nap"};

/* Define the dictionary for English language */
char eng_dict[10][20] = {"hello", "happy", "angry", "bird", "claw",
                         "tongue", "noise", "jump", "fun", "sleep"};

/* Cat language to English language translator function*/
void cat_to_eng() {
  char input_word[20];
  printf("Enter a word in cat language: ");
  scanf("%s", input_word);

  for (int i = 0; i < 10; i++) {
    if (strcmp(input_word, cat_dict[i]) == 0) {
      printf("The English translation is: %s\n", eng_dict[i]);
      return;    // Exit the function if we found the translation
    }
  }
  printf("Sorry, I don't know that word yet.\n");
}

/* English language to Cat language translator function*/
void eng_to_cat() {
  char input_word[20];
  printf("Enter a word in English: ");
  scanf("%s", input_word);

  for (int i = 0; i < 10; i++) {
    if (strcmp(input_word, eng_dict[i]) == 0) {
      printf("The cat translation is: %s\n", cat_dict[i]);
      return;    // Exit the function if we found the translation
    }
  }
  printf("Sorry, I don't know that word yet.\n");
}

/* Main function to run the translator program */
int main() {
  int choice;
  printf("Welcome to the C Cat Language Translator! Please select an option:\n");
  printf("1. Cat to English language translation\n");
  printf("2. English to Cat language translation\n");
  printf("3. Quit\n");
  while (1) {
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        cat_to_eng();
        break;
      case 2:
        eng_to_cat();
        break;
      case 3:
        printf("Thank you for using the C Cat Language Translator! Goodbye!\n");
        exit(0);    // Exit the program when user enters 3
      default:
        printf("Please enter a valid choice!\n");
    }
  }
  return 0;
}