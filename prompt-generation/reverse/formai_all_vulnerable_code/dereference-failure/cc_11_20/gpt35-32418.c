//FormAI DATASET v1.0 Category: Text Summarizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_CHARS 2000000

int main(int argc, char* argv[]) {
  if(argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 0;
  }

  FILE *infile;
  char *buffer;
  char *word;
  char words[MAX_WORDS][MAX_CHARS];
  int word_count = 0;
  off_t file_size, chars_read;
  
  infile = fopen(argv[1], "r");
  if(infile == NULL) {
    printf("Error opening file %s\n", argv[1]);
    return 0;
  }
  
  fseeko(infile, 0, SEEK_END);
  file_size = ftello(infile);
  fseeko(infile, 0, SEEK_SET);
  
  buffer = (char*) malloc(sizeof(char) * file_size);
  chars_read = fread(buffer, sizeof(char), file_size, infile);
  if(chars_read != file_size) {
    printf("Error reading file %s\n", argv[1]);
    return 0;
  }
  fclose(infile);
  
  word = strtok(buffer, " \t\r\n");
  while(word != NULL && word_count < MAX_WORDS) {
    strcpy(words[word_count], word);
    word_count++;
    word = strtok(NULL, " \t\r\n");
  }  

  free(buffer);

  // Algorithm to find the most common words
  int i, j, max_count = 0, common_count = 0;
  char common_words[MAX_WORDS][MAX_CHARS];
  for(i = 0; i < word_count; i++) {
    int count = 1;
    for(j = i + 1; j < word_count; j++) {
      if(strcmp(words[i], words[j]) == 0) {
        count++;
      }
    }
    if(count > max_count) {
      max_count = count;
    }
    if(count > 1) {
      int already_exists = 0;
      for(j = 0; j < common_count; j++) {
        if(strcmp(words[i], common_words[j]) == 0) {
          already_exists = 1;
          break;
        }
      }
      if(!already_exists) {
        strcpy(common_words[common_count], words[i]);
        common_count++;
      }
    }
  }

  // Print the most common words
  printf("The most common words are:\n");
  for(i = 0; i < common_count; i++) {
    printf("%s\n", common_words[i]);
  }
  
  return 0;
}