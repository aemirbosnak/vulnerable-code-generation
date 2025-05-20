//FormAI DATASET v1.0 Category: Text processing ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
  char input[1000], output[1000];
  int i, j, k;

  printf("Please type in a sentence or paragraph:\n");
  fgets(input, 1000, stdin); //fgets to take input from user

  char key[50];
  printf("Please enter the keyword for encoding:\n");
  scanf("%s", key); //take keyword from the user
  
  int len_key = strlen(key);
  int len_input = strlen(input);

  if(len_key > len_input){ //if keyword length is greater than input character length
    printf("Invalid input, keyword has to be shorter than input.\n");
    exit(0);
  }

  for (i = 0; i < len_input; i++){
    k = i % len_key;
    output[i] = ((input[i] - 'a' + key[k] - 'a') % 26) + 'a';
  }
  output[i] = '\0';

  printf("Encoded text using keyword '%s':\n", key);
  printf("%s\n", output);

  char decode_key[50];
  printf("Please enter the keyword for decoding:\n");
  scanf("%s", decode_key); //take the decoding keyword from the user

  if(strcmp(decode_key, key) != 0){ //if the decoding key doesn't match encoding key
    printf("Invalid decoding keyword. Decoding failed.\n");
    exit(0);
  }

  char decoded[1000];
  for(j = 0; j < len_input; j++){
    k = j % len_key;
    decoded[j] = ((output[j] - 'a' - key[k] + 'a') % 26) + 'a';
  }
  decoded[j] = '\0';

  printf("Decoded text:\n");
  printf("%s", decoded);

  return 0;
}