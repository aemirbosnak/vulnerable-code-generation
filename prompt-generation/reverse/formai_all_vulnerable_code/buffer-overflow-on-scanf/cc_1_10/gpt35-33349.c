//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: peaceful
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50

char* translate(char* word) {
  char* translation;

  if (strcmp(word, "greetings") == 0) {
    translation = "narakth";
  } else if (strcmp(word, "peace") == 0) {
    translation = "zelx";
  } else if (strcmp(word, "friend") == 0) {
    translation = "vrek";
  } else if (strcmp(word, "hello") == 0) {
    translation = "tharalt";
  } else if (strcmp(word, "goodbye") == 0) {
    translation = "zarnax";
  } else if (strcmp(word, "love") == 0) {
    translation = "hulnax";
  } else if (strcmp(word, "life") == 0) {
    translation = "tharran";
  } else if (strcmp(word, "world") == 0) {
    translation = "vrenox";
  } else if (strcmp(word, "home") == 0) {
    translation = "galrk";
  } else if (strcmp(word, "food") == 0) {
    translation = "draltix";
  } else if (strcmp(word, "water") == 0) {
    translation = "marwee";
  } else if (strcmp(word, "thank you") == 0) {
    translation = "vrenzax";
  } else if (strcmp(word, "please") == 0) {
    translation = "krelth";
  } else if (strcmp(word, "knowledge") == 0) {
    translation = "kelnax";
  } else {
    translation = "Invalid word";
  }

  return translation;
}

int main() {
  char input[MAX_LENGTH];
  char* output;

  printf("Enter a word in C Alien Language: ");
  scanf("%s", input);

  output = translate(input);

  printf("The translation of '%s' is '%s'.\n", input, output);

  return 0;
}