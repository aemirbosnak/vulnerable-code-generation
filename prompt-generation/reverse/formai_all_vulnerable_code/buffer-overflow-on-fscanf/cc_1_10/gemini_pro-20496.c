//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: Donald Knuth
// Donald Knuth-style C Spam Detection System
// Written by [Your Name] on [Date]

// Header Files

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Constants

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define MAX_PATTERNS 100

// Data Structures

typedef struct word_node {
  char* word;
  int count;
  struct word_node* next;
} word_node;

typedef struct pattern_node {
  char* pattern;
  int count;
  struct pattern_node* next;
} pattern_node;

// Functions

word_node* create_word_node(char* word) {
  word_node* node = (word_node*)malloc(sizeof(word_node));
  node->word = strdup(word);
  node->count = 1;
  node->next = NULL;
  return node;
}

void insert_word(word_node** head, char* word) {
  word_node* new_node = create_word_node(word);
  if (*head == NULL) {
    *head = new_node;
  } else {
    word_node* curr = *head;
    word_node* prev = NULL;
    while (curr != NULL && strcmp(curr->word, word) < 0) {
      prev = curr;
      curr = curr->next;
    }
    if (curr == NULL) {
      prev->next = new_node;
    } else if (strcmp(curr->word, word) == 0) {
      curr->count++;
    } else {
      new_node->next = curr;
      prev->next = new_node;
    }
  }
}

void free_word_list(word_node* head) {
  while (head != NULL) {
    word_node* next = head->next;
    free(head->word);
    free(head);
    head = next;
  }
}

pattern_node* create_pattern_node(char* pattern) {
  pattern_node* node = (pattern_node*)malloc(sizeof(pattern_node));
  node->pattern = strdup(pattern);
  node->count = 1;
  node->next = NULL;
  return node;
}

void insert_pattern(pattern_node** head, char* pattern) {
  pattern_node* new_node = create_pattern_node(pattern);
  if (*head == NULL) {
    *head = new_node;
  } else {
    pattern_node* curr = *head;
    pattern_node* prev = NULL;
    while (curr != NULL && strcmp(curr->pattern, pattern) < 0) {
      prev = curr;
      curr = curr->next;
    }
    if (curr == NULL) {
      prev->next = new_node;
    } else if (strcmp(curr->pattern, pattern) == 0) {
      curr->count++;
    } else {
      new_node->next = curr;
      prev->next = new_node;
    }
  }
}

void free_pattern_list(pattern_node* head) {
  while (head != NULL) {
    pattern_node* next = head->next;
    free(head->pattern);
    free(head);
    head = next;
  }
}

double calculate_score(word_node* words, pattern_node* patterns) {
  double score = 0.0;
  word_node* curr_word = words;
  pattern_node* curr_pattern = patterns;
  while (curr_word != NULL && curr_pattern != NULL) {
    if (strcmp(curr_word->word, curr_pattern->pattern) < 0) {
      curr_word = curr_word->next;
    } else if (strcmp(curr_word->word, curr_pattern->pattern) > 0) {
      curr_pattern = curr_pattern->next;
    } else {
      score += log(curr_word->count + 1) * log(curr_pattern->count + 1);
      curr_word = curr_word->next;
      curr_pattern = curr_pattern->next;
    }
  }
  return score;
}

int main(int argc, char** argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <words file> <patterns file>\n", argv[0]);
    exit(1);
  }

  // Read words from file

  FILE* words_file = fopen(argv[1], "r");
  if (words_file == NULL) {
    fprintf(stderr, "Error opening words file: %s\n", argv[1]);
    exit(1);
  }

  word_node* words = NULL;
  char word[MAX_WORD_LENGTH + 1];
  while (fscanf(words_file, "%s", word) == 1) {
    for (int i = 0; word[i] != '\0'; i++) {
      word[i] = tolower(word[i]);
    }
    insert_word(&words, word);
  }
  fclose(words_file);

  // Read patterns from file

  FILE* patterns_file = fopen(argv[2], "r");
  if (patterns_file == NULL) {
    fprintf(stderr, "Error opening patterns file: %s\n", argv[2]);
    exit(1);
  }

  pattern_node* patterns = NULL;
  char pattern[MAX_WORD_LENGTH + 1];
  while (fscanf(patterns_file, "%s", pattern) == 1) {
    for (int i = 0; pattern[i] != '\0'; i++) {
      pattern[i] = tolower(pattern[i]);
    }
    insert_pattern(&patterns, pattern);
  }
  fclose(patterns_file);

  // Calculate spam score

  double score = calculate_score(words, patterns);

  // Print spam score

  printf("Spam score: %.2f\n", score);

  // Free memory

  free_word_list(words);
  free_pattern_list(patterns);

  return 0;
}