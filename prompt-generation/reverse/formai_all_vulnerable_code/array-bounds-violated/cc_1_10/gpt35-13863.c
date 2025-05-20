//FormAI DATASET v1.0 Category: Compression algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1024
#define MAX_CODE  4096
#define CODE_SIZE 12

/* Definition of the symbol dictionary */
typedef struct {
  unsigned char *string;
  int length;
  int code;
} DictionaryEntry;

/* Function to find the index of a dictionary entry based on its string representation */
int findIndex(DictionaryEntry *dictionary, int dictSize, unsigned char *symbol, int symLength) {
  for (int i = 0; i < dictSize; i++) {
    if (dictionary[i].length == symLength && memcmp(dictionary[i].string, symbol, symLength) == 0) {
      return i;
    }
  }
  return -1;
}

/* Function to encode input string using Lempel-Ziv-Welch algorithm */
int encodeLZW(unsigned char *input, int inputLen, int *output) {
  int numBits = 9, dictSize = 256, outputLen = 0, currIndex = 0;
  unsigned char currSymbol[MAX_INPUT], nextChar = 0;
  DictionaryEntry dictionary[MAX_CODE];

  /* Initialize symbol dictionary with single-byte entries */
  for (int i = 0; i < dictSize; i++) {
    dictionary[i].string = (unsigned char *)malloc(1 * sizeof(unsigned char));
    dictionary[i].string[0] = (unsigned char)i;
    dictionary[i].length = 1;
    dictionary[i].code = i;
  }

  /* Loop over input string, encoding symbols as we go */
  for (int i = 0; i < inputLen; i++) {
    currSymbol[currIndex++] = input[i];
    if (i == inputLen - 1) {  /* case where we are at end of input string */
      nextChar = '\0';
    } else {
      nextChar = input[i+1];
    }
    /* Check if symbol + next char is in dictionary */
    int index = findIndex(dictionary, dictSize, currSymbol, currIndex);
    if (index != -1 && i != inputLen - 1) {  /* extend current symbol */
      continue;
    } else {  /* add symbol to dictionary and output code for current symbol */
      dictionary[dictSize].string = (unsigned char *)malloc(currIndex * sizeof(unsigned char));
      memcpy(dictionary[dictSize].string, currSymbol, currIndex);
      dictionary[dictSize].length = currIndex;
      dictionary[dictSize].code = dictSize;
      dictSize++;
      /* output the code for the previous symbol (if it exists) */
      if (currIndex == 1) {  /* special case where the previous symbol is just a single byte */
        *output++ = currSymbol[0];
        outputLen++;
      } else {
        int prevIndex = findIndex(dictionary, dictSize-1, currSymbol, currIndex-1);
        *output++ = dictionary[prevIndex].code;
        outputLen++;
      }
      /* update current symbol and current index */
      currSymbol[0] = nextChar;
      currIndex = 1;
      /* check if it's time to increase the number of bits allocated for codes */
      if (dictSize >= 1<<numBits) {
        numBits++;
      }
    }
  }

  /* free memory */
  for (int i = 0; i < dictSize; i++) {
    free(dictionary[i].string);
  }

  return outputLen;
}

/* Driver program for LZW encoding example */
int main(int argc, char *argv[]) {
  /* read input string from command line */
  unsigned char input[MAX_INPUT];
  printf("Enter a string (max length = %d): ", MAX_INPUT);
  fgets(input, MAX_INPUT, stdin);
  int inputLen = strlen(input);
  if (input[inputLen-1] == '\n') {
    input[inputLen-1] = '\0';
    inputLen--;
  }
  printf("Input string: %s\n", input);

  /* encode the input string using LZW algorithm */
  int output[MAX_CODE];
  int outputLen = encodeLZW(input, inputLen, output);

  /* output the encoded string */
  printf("Encoded string: ");
  for (int i = 0; i < outputLen; i++) {
    printf("%d ", output[i]);
  }
  printf("\n");

  return 0;
}