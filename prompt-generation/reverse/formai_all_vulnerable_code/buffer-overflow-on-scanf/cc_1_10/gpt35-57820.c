//FormAI DATASET v1.0 Category: Text processing ; Style: excited
#include <stdio.h>

//This sweet program reads a text file and counts the occurrences of each word!
int main(){

  printf("Welcome to the amazing Word Counter 3000!\n");
  printf("Enter the file path to the text file you want to process: ");

  char file_path[100];
  scanf("%s", file_path);

  FILE *fp;
  fp = fopen(file_path, "r");

  if(fp == NULL){
    printf("Sorry, we couldn't open the file. Make sure you typed the path correctly :)\n");
    return 1;
  }

  printf("Processing your file...\n");

  //Create an array to store all the unique words found
  char unique_words[1000][100];
  int unique_count = 0;

  //Create an array to store word counts for each unique word
  int word_counts[1000] = {0};

  //Read each word from the file
  char current_word[100];
  char c = 'a'; //Give an initial value to prevent infinite loop

  while(c != EOF){

    //Read each character until a space or a new line is found
    c = fgetc(fp);
    int i = 0;

    while(c != ' ' && c != '\n' && c != EOF){
      current_word[i] = c;
      c = fgetc(fp);
      i++;
    }

    //Store the current word as a unique word
    int is_new_word = 1;

    for(int j = 0; j < unique_count; j++){
      if(strcmp(unique_words[j], current_word) == 0){
        is_new_word = 0;
        word_counts[j]++; //If the word already exists, add a count to its counter
        break;
      }
    }

    if(is_new_word){
      strcpy(unique_words[unique_count], current_word); //If the word is a new word, add it to the array
      word_counts[unique_count]++; //Add a count to its counter
      unique_count++;
    }
  }

  fclose(fp);

  printf("Words count successfully done!\n");

  //Print the results
  printf("\n------------\n");
  printf("Word Counts:\n");
  printf("------------\n");

  for(int i = 0; i < unique_count; i++){
    printf("%s: %d\n", unique_words[i], word_counts[i]);
  }

  return 0;
}