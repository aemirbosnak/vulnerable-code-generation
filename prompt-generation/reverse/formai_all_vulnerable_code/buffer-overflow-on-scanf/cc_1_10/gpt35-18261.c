//FormAI DATASET v1.0 Category: Compression algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

char compression[MAX_SIZE]; // store the compressed string
char decompression[MAX_SIZE]; // store the decompressed string

// function to perform run-length encoding compression
void compress(char *input) {
  char current = input[0];
  int count = 1, i, len = strlen(input);

  for(i = 1; i < len; i++) {
    if (input[i] == current) {
      count++;
    }
    else {
      sprintf(compression + strlen(compression), "%c%d", current, count);
      current = input[i];
      count = 1;
    }
  }

  sprintf(compression + strlen(compression), "%c%d", current, count);
}

// function to perform run-length encoding decompression
void decompress(char *input) {
  int i, len = strlen(input), j = 0, count = 0;

  for(i = 0; i < len; i++) {
    if(input[i] >= '0' && input[i] <= '9') {
      count = count * 10 + (input[i] - '0');
    }
    else {
      while(count--) {
        decompression[j++] = input[i];
      }
      count = 0;
    }
  }
}


int main() {
  char input[MAX_SIZE], choice;

  printf("Enter the string to be compressed: ");
  fgets(input, MAX_SIZE, stdin);
  input[strcspn(input, "\n")] = 0;

  printf("Performing run-length encoding compression...\n");
  compress(input);
  printf("Compressed string: %s\n", compression);

  printf("Do you want to decompress (Y/N)? ");
  scanf("%c", &choice);

  if(choice == 'Y' || choice == 'y') {
    printf("Performing run-length encoding decompression...\n");
    decompress(compression);
    printf("Decompressed string: %s\n", decompression);
  }

  return 0;
}