//FormAI DATASET v1.0 Category: Spell checking ; Style: Ada Lovelace
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

// A struct to hold the dictionary words and their counts
typedef struct dict_word {
  char word[100];
  int count;
} Dict_word;

// Function to read dictionary file and store words
void read_dict(char file_name[], Dict_word dict[]) {
  FILE *fp = fopen(file_name, "r");
  char buffer[100];
  int i = 0;
  
  while(fscanf(fp, "%s", buffer) != EOF) {
    // Convert word to lowercase
    for(int j=0; j<strlen(buffer); j++) {
      buffer[j] = tolower(buffer[j]);
    }
    // Copy word to dictionary struct and initialize count
    strcpy(dict[i].word, buffer);
    dict[i].count = 0;
    i++;
  }
  fclose(fp);
}

// Function to check if the word is in the dictionary
int check_dict(char word[], Dict_word dict[], int num_words) {
  int found = 0;
  for(int i=0; i<num_words; i++) {
    if(strcmp(word, dict[i].word) == 0) {
      found = 1;
      dict[i].count++;
      break;
    }
  }
  return found;
}

int main() {
  // Define dictionary file and input file names
  char dict_file[] = "dictionary.txt";
  char input_file[] = "input.txt";

  Dict_word dictionary[10000];
  int num_words = 0;

  // Read dictionary file and store words
  read_dict(dict_file, dictionary);
  num_words = sizeof(dictionary)/sizeof(dictionary[0]);

  // Open input file for reading
  FILE* fp = fopen(input_file, "r");
  if (fp == NULL) {
    printf("Could not open file %s\n", input_file);
    exit(1);
  }

  // Loop through each word in input file and check if in dictionary
  char buffer[100];
  while(fscanf(fp, "%s", buffer) != EOF) {
    // Convert word to lowercase
    for(int j=0; j<strlen(buffer); j++) {
      buffer[j] = tolower(buffer[j]);
    }
      
    // Check if word is in dictionary and output result
    if(check_dict(buffer, dictionary, num_words)) {
      printf("%s ", buffer);
    }
    else {
      printf("*%s* ", buffer);
    }
  }

  // Output statistics for each word in dictionary
  printf("\n\nDictionary word statistics:\n");
  for(int i=0; i<num_words; i++) {
    printf("%s: %d\n", dictionary[i].word, dictionary[i].count);
  }

  fclose(fp);

  return 0;
}