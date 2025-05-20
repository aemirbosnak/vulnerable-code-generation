//Code Llama-13B DATASET v1.0 Category: Log analysis ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is a letter
int is_letter(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to count the frequency of each letter in a string
void letter_frequency(char *str, int freq[26]) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (is_letter(str[i])) {
      freq[tolower(str[i]) - 'a']++;
    }
  }
}

// Function to print the frequency of each letter in a string
void print_frequency(int freq[26]) {
  for (int i = 0; i < 26; i++) {
    printf("%c: %d\n", i + 'a', freq[i]);
  }
}

// Function to print the most common letter in a string
void most_common_letter(char *str, int freq[26]) {
  int max = 0;
  char letter = 'a';
  for (int i = 0; i < 26; i++) {
    if (freq[i] > max) {
      max = freq[i];
      letter = i + 'a';
    }
  }
  printf("Most common letter: %c\n", letter);
}

int main() {
  char str[100];
  int freq[26] = {0};

  printf("Enter a string: ");
  scanf("%s", str);

  letter_frequency(str, freq);
  print_frequency(freq);
  most_common_letter(str, freq);

  return 0;
}