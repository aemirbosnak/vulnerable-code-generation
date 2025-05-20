//Code Llama-13B DATASET v1.0 Category: Spell checking ; Style: sophisticated
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  #define MAX_WORD_LENGTH 100

  struct Node {
    char word[MAX_WORD_LENGTH];
    struct Node* next;
  };

  void insert_word(struct Node** head, char* word) {
    struct Node* new_node = malloc(sizeof(struct Node));
    strcpy(new_node->word, word);
    new_node->next = *head;
    *head = new_node;
  }

  void print_list(struct Node* head) {
    while (head != NULL) {
      printf("%s ", head->word);
      head = head->next;
    }
  }

  int is_word_correct(char* word) {
    int word_length = strlen(word);
    if (word_length == 0) return 0;

    int i;
    for (i = 0; i < word_length; i++) {
      if (word[i] >= 'a' && word[i] <= 'z') continue;
      if (word[i] >= 'A' && word[i] <= 'Z') continue;
      return 0;
    }

    return 1;
  }

  int main() {
    struct Node* head = NULL;
    char word[MAX_WORD_LENGTH];

    while (scanf("%s", word) != EOF) {
      if (is_word_correct(word)) {
        insert_word(&head, word);
      }
    }

    print_list(head);
    return 0;
  }