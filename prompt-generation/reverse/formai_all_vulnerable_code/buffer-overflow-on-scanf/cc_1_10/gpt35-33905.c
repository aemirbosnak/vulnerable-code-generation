//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: post-apocalyptic
#include<stdio.h>
#include<string.h>

void print_slowly(char *str) {
  int i = 0;
  while(str[i] != '\0') {
    printf("%c", str[i]);
    fflush(stdout);
    usleep(15000); // add delay for the atmosphere
    i++;
  }
}

int main() {
  char word[100];
  printf("Enter a word to check if it is a palindrome: ");
  fflush(stdout);
  scanf("%s", word);
  
  // reverse the word
  int length = strlen(word);
  char reverse_word[100];
  int i;
  for(i = 0; i < length; i++) {
    reverse_word[i] = word[length-i-1];
  }
  reverse_word[length] = '\0';
  
  // check if the word is a palindrome
  if(strcmp(word,reverse_word) == 0) {
    printf("\n");
    print_slowly("It seems...\n");
    usleep(500000);
    print_slowly("This word is a palindrome!\n");
    usleep(500000);
    print_slowly("We have found a rare treasure in these dark times.\n");
    usleep(500000);
    print_slowly("May it bring us some joy in the midst of all this chaos.\n");
    usleep(500000);
    return 0;
  } else {
    printf("\n");
    print_slowly("It seems...\n");
    usleep(500000);
    print_slowly("This word is not a palindrome.\n");
    usleep(500000);
    print_slowly("Oh well, it was worth a shot.\n");
    usleep(500000);
    return 1;
  }
}