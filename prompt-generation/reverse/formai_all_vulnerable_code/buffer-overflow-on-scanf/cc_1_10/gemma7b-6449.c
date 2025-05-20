//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 1000

struct word_node {
  char word[MAX_WORDS];
  struct word_node* next;
};

void insert_word(struct word_node** head, char* word) {
  struct word_node* new_node = malloc(sizeof(struct word_node));
  strcpy(new_node->word, word);
  new_node->next = NULL;

  if (*head == NULL) {
    *head = new_node;
  } else {
    (*head)->next = new_node;
  }
}

int main() {
  struct word_node* head = NULL;
  char word[MAX_WORDS];

  // Multiplayer game loop
  while (1) {
    // Get the word from the player
    printf("Enter a word: ");
    scanf("%s", word);

    // Insert the word into the list
    insert_word(&head, word);

    // Print the list of words
    struct word_node* current = head;
    while (current) {
      printf("%s ", current->word);
    }

    // Check if the player wants to continue
    char continue_yn;
    printf("Do you want to continue? (Y/N): ");
    scanf("%c", &continue_yn);

    // Break out of the loop if the player does not want to continue
    if (continue_yn != 'Y') {
      break;
    }
  }

  return 0;
}