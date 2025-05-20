//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Define the cat language keywords
#define MEOW "meow"
#define PURR "purr"
#define HISS "hiss"
#define SCRATCH "scratch"

// Define the cat language grammar
struct cat_sentence {
  char *subject;
  char *verb;
  char *object;
};

// Define the cat language parser
struct cat_sentence *parse_cat_sentence(char *sentence) {
  struct cat_sentence *parsed_sentence = malloc(sizeof(struct cat_sentence));

  // Split the sentence into subject, verb, and object
  char *subject = strtok(sentence, " ");
  char *verb = strtok(NULL, " ");
  char *object = strtok(NULL, " ");

  // Assign the subject, verb, and object to the parsed sentence
  parsed_sentence->subject = subject;
  parsed_sentence->verb = verb;
  parsed_sentence->object = object;

  // Return the parsed sentence
  return parsed_sentence;
}

// Define the cat language interpreter
void interpret_cat_sentence(struct cat_sentence *sentence) {
  // Get the subject, verb, and object of the sentence
  char *subject = sentence->subject;
  char *verb = sentence->verb;
  char *object = sentence->object;

  // Interpret the sentence based on the verb
  if (strcmp(verb, MEOW) == 0) {
    printf("%s meows at %s.\n", subject, object);
  } else if (strcmp(verb, PURR) == 0) {
    printf("%s purrs at %s.\n", subject, object);
  } else if (strcmp(verb, HISS) == 0) {
    printf("%s hisses at %s.\n", subject, object);
  } else if (strcmp(verb, SCRATCH) == 0) {
    printf("%s scratches %s.\n", subject, object);
  } else {
    printf("Invalid cat language verb: %s.\n", verb);
  }
}

// Get a cat language sentence from the user
char *get_cat_sentence() {
  char *sentence = malloc(100);

  printf("Enter a cat language sentence: ");
  scanf("%s", sentence);

  return sentence;
}

// Main function
int main() {
  // Get a cat language sentence from the user
  char *sentence = get_cat_sentence();

  // Parse the cat language sentence
  struct cat_sentence *parsed_sentence = parse_cat_sentence(sentence);

  // Interpret the cat language sentence
  interpret_cat_sentence(parsed_sentence);

  // Free the memory allocated for the parsed sentence
  free(parsed_sentence);

  // Free the memory allocated for the sentence
  free(sentence);

  return 0;
}