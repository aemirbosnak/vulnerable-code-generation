//FormAI DATASET v1.0 Category: String manipulation ; Style: creative
#include <stdio.h>
#include <string.h>

int main() {

  printf("Welcome to the String Manipulation program!\n");
  
  // Initializing the string 
  char string[100];
  printf("Enter a string (max of 100 characters):\n");
  scanf("%s", string);
  
  // Reversing the string
  printf("Original string: %s\n", string);
  int length = strlen(string);
  for(int i=0; i<length/2; i++) {
      char temp = string[i];
      string[i] = string[length-i-1];
      string[length-i-1] = temp;
  }
  printf("Reversed string: %s\n", string);
  
  // Counting the number of vowels and consonants
  int vowels=0, consonants=0;
  for(int i=0; i<length; i++) {
      char c = string[i];
      if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
          vowels++;
      }
      else if((c>='a' && c<='z') || (c>='A' && c<='Z')) {
          consonants++;
      }
  }
  printf("Number of vowels: %d\n", vowels);
  printf("Number of consonants: %d\n", consonants);
  
  // Capitalizing the words
  char words[100][100];
  int word_count=0, word_length=0;
  for(int i=0; i<=length; i++) {
      char c = string[i];
      if(c==' ' || c=='\0') {
          words[word_count][word_length] = '\0';
          word_count++;
          word_length=0;
      }
      else {
          words[word_count][word_length] = c;
          word_length++;
      }
  }
  for(int i=0; i<word_count; i++) {
      words[i][0] = toupper(words[i][0]);
  }
  printf("Capitalized string:");
  for(int i=0; i<word_count; i++) {
      printf(" %s", words[i]);
  }
  
  return 0;
}