//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

char* translate_to_cat_language(char* english_input) {
  char* cat_output;
  int english_length, cat_length, i, j, k, counter;
  english_length = strlen(english_input);
  cat_length = english_length * 3; // cats like to talk a lot

  cat_output = (char*) malloc(cat_length * sizeof(char));

  for (i = 0, j = 0; i < english_length; i++) {
    // check each letter and translate to cat language
    switch(english_input[i]) {
      case 'a': strcat(cat_output + j, "meow"); j += 4; break;
      case 'b': strcat(cat_output + j, "purr"); j += 4; break;
      case 'c': strcat(cat_output + j, "hiss"); j += 4; break;
      case 'd': strcat(cat_output + j, "sniff"); j += 5; break;
      case 'e': strcat(cat_output + j, "paw"); j += 3; break;
      case 'f': strcat(cat_output + j, "lick"); j += 4; break;
      case 'g': strcat(cat_output + j, "nip"); j += 3; break;
      case 'h': strcat(cat_output + j, "scratch"); j += 8; break;
      case 'i': strcat(cat_output + j, "meow-meow"); j += 8; break;
      case 'j': strcat(cat_output + j, "chase"); j += 5; break;
      case 'k': strcat(cat_output + j, "cuddle"); j += 7; break;
      case 'l': strcat(cat_output + j, "pounce"); j += 7; break;
      case 'm': strcat(cat_output + j, "stare"); j += 5; break;
      case 'n': strcat(cat_output + j, "purr-purr"); j += 9; break;
      case 'o': strcat(cat_output + j, "sneak"); j += 5; break;
      case 'p': strcat(cat_output + j, "hug"); j += 4; break;
      case 'q': strcat(cat_output + j, "swat"); j += 5; break;
      case 'r': strcat(cat_output + j, "nap"); j += 3; break;
      case 's': strcat(cat_output + j, "roll"); j += 4; break;
      case 't': strcat(cat_output + j, "chirp"); j += 5; break;
      case 'u': strcat(cat_output + j, "yawn"); j += 4; break;
      case 'v': strcat(cat_output + j, "curl"); j += 4; break;
      case 'w': strcat(cat_output + j, "twitch"); j += 6; break;
      case 'x': strcat(cat_output + j, "paw-lick"); j += 9; break;
      case 'y': strcat(cat_output + j, "play"); j += 4; break;
      case 'z': strcat(cat_output + j, "stretch"); j += 7; break;
      case ' ': strcat(cat_output + j, "purrr"); j += 5; break;
      case '.': strcat(cat_output + j, "hunt"); j += 4; break;
      case ',': strcat(cat_output + j, "flick"); j += 5; break;
      case '?': strcat(cat_output + j, "paws-up"); j += 7; break;
      case '!': strcat(cat_output + j, "meow-out-loud"); j += 14; break;
      default: strcat(cat_output + j, "meow"); j += 4; break;
    }
    strcat(cat_output + j, " ");
    j += 1;
  }

  return cat_output;
}

int main() {
  char input[100];
  char* output;
  printf("Enter a sentence in English: ");
  scanf("%[^\n]s", input);
  output = translate_to_cat_language(input);
  printf("Your sentence translated into Cat Language is:\n%s\n", output);
  free(output);
  return 0;
}