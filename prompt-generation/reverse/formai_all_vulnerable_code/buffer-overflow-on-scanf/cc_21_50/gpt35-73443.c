//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main() {
  char str[100];
  printf("Welcome to the C Alien Language Translator\n");
  printf("Please enter a phrase in the alien language:\n");
  scanf("%[^\n]s", str);
  
  int len = strlen(str);
  char trans_str[len+1];
  
  for (int i = 0; i < len; i++) {
    if (str[i] == 'a') {
      trans_str[i] = 'z';
    } else if (str[i] == 'b') {
      trans_str[i] = 'y';
    } else if (str[i] == 'c') {
      trans_str[i] = 'x';
    } else if (str[i] == 'd') {
      trans_str[i] = 'w';
    } else if (str[i] == 'e') {
      trans_str[i] = 'v';
    } else if (str[i] == 'f') {
      trans_str[i] = 'u';
    } else if (str[i] == 'g') {
      trans_str[i] = 't';
    } else if (str[i] == 'h') {
      trans_str[i] = 's';
    } else if (str[i] == 'i') {
      trans_str[i] = 'r';
    } else if (str[i] == 'j') {
      trans_str[i] = 'q';
    } else if (str[i] == 'k') {
      trans_str[i] = 'p';
    } else if (str[i] == 'l') {
      trans_str[i] = 'o';
    } else if (str[i] == 'm') {
      trans_str[i] = 'n';
    } else if (str[i] == 'n') {
      trans_str[i] = 'm';
    } else if (str[i] == 'o') {
      trans_str[i] = 'l';
    } else if (str[i] == 'p') {
      trans_str[i] = 'k';
    } else if (str[i] == 'q') {
      trans_str[i] = 'j';
    } else if (str[i] == 'r') {
      trans_str[i] = 'i';
    } else if (str[i] == 's') {
      trans_str[i] = 'h';
    } else if (str[i] == 't') {
      trans_str[i] = 'g';
    } else if (str[i] == 'u') {
      trans_str[i] = 'f';
    } else if (str[i] == 'v') {
      trans_str[i] = 'e';
    } else if (str[i] == 'w') {
      trans_str[i] = 'd';
    } else if (str[i] == 'x') {
      trans_str[i] = 'c';
    } else if (str[i] == 'y') {
      trans_str[i] = 'b';
    } else if (str[i] == 'z') {
      trans_str[i] = 'a';
    } else {
      trans_str[i] = str[i];
    }
  }
  
  printf("Translation in English: %s\n", trans_str);
  
  return 0;
}