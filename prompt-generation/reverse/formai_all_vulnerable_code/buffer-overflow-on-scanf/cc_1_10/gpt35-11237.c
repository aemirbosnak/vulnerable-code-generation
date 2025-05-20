//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This is my unique and funny C Cryptographic hash function!
// It's called the "Silly Hashinator" :)
// I know, it's not the most professional name, but who cares!

int silly_hashinator(char* input_string) {

  int hash = 0;
  int i = 0;

  while(input_string[i] != '\0') { // Loop through each character in the string

    char current_char = input_string[i];

    // Here's the "silly" part: let's add the ASCII value of the character and the index
    // of the character to the hash value. Why? Because I said so!

    int ascii_value = (int) current_char;
    int index_value = i;

    hash += ascii_value + index_value;

    i++;
  }

  // Okay, now we need to do some bit shifting to really make this hash value secure.
  // Because what respectable cryptographer doesn't use bit shifting?

  hash = hash << 5; // Move the bits 5 places to the left
  hash = hash >> 2; // Move the bits 2 places to the right

  return hash;
}

int main() {

  char input_string[50];
  printf("Welcome to the Silly Hashinator! What string do you want to hash? ");
  scanf("%s", &input_string);

  int hash_value = silly_hashinator(input_string);

  printf("The hash value of %s is %d!\n", input_string, hash_value);
  printf("I hope you enjoyed this hilariously unprofessional hash function!\n");

  return 0;
}