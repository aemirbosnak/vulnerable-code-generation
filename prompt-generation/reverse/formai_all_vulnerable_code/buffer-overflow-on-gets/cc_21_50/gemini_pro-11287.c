//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 1024

int main() {
  char str[MAX_STR_LEN];
  int len, i, j, k;

  printf("Enter a string: ");
  gets(str);

  // Calculate the length of the string
  len = strlen(str);

  // Reverse the string using the two-pointer approach
  for (i = 0, j = len - 1; i < j; i++, j--) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }

  // Print the reversed string
  printf("Reversed string: %s\n", str);

  // Convert the string to uppercase using the toupper() function
  for (i = 0; i < len; i++) {
    str[i] = toupper(str[i]);
  }

  // Print the uppercase string
  printf("Uppercase string: %s\n", str);

  // Convert the string to lowercase using the tolower() function
  for (i = 0; i < len; i++) {
    str[i] = tolower(str[i]);
  }

  // Print the lowercase string
  printf("Lowercase string: %s\n", str);

  // Remove all spaces from the string using the strtok() function
  char *token = strtok(str, " ");
  while (token != NULL) {
    printf("%s", token);
    token = strtok(NULL, " ");
  }
  printf("\n");

  // Count the number of words in the string using the strtok() function
  int word_count = 0;
  token = strtok(str, " ");
  while (token != NULL) {
    word_count++;
    token = strtok(NULL, " ");
  }
  printf("Number of words in the string: %d\n", word_count);

  // Find the longest word in the string using the strtok() function
  int max_len = 0;
  char *max_word = NULL;
  token = strtok(str, " ");
  while (token != NULL) {
    int len = strlen(token);
    if (len > max_len) {
      max_len = len;
      max_word = token;
    }
    token = strtok(NULL, " ");
  }
  printf("Longest word in the string: %s\n", max_word);

  // Find the shortest word in the string using the strtok() function
  int min_len = MAX_STR_LEN;
  char *min_word = NULL;
  token = strtok(str, " ");
  while (token != NULL) {
    int len = strlen(token);
    if (len < min_len) {
      min_len = len;
      min_word = token;
    }
    token = strtok(NULL, " ");
  }
  printf("Shortest word in the string: %s\n", min_word);

  // Find the most frequent character in the string using the strchr() function
  int char_freq[256] = {0};
  for (i = 0; i < len; i++) {
    char_freq[str[i]]++;
  }
  int max_freq = 0;
  char max_char;
  for (i = 0; i < 256; i++) {
    if (char_freq[i] > max_freq) {
      max_freq = char_freq[i];
      max_char = (char)i;
    }
  }
  printf("Most frequent character in the string: %c (%d occurrences)\n", max_char, max_freq);

  // Find the least frequent character in the string using the strchr() function
  int min_freq = MAX_STR_LEN;
  char min_char;
  for (i = 0; i < 256; i++) {
    if (char_freq[i] < min_freq && char_freq[i] > 0) {
      min_freq = char_freq[i];
      min_char = (char)i;
    }
  }
  printf("Least frequent character in the string: %c (%d occurrences)\n", min_char, min_freq);

  // Find all the palindromes in the string using the strstr() function
  for (i = 0; i < len; i++) {
    for (j = i + 1; j < len; j++) {
      char *palindrome = strstr(str + j, str + i);
      if (palindrome != NULL) {
        printf("Palindrome found: %s\n", palindrome);
      }
    }
  }

  // Find all the anagrams of a given word in the string using the strstr() function
  char word[MAX_STR_LEN];
  printf("Enter a word to find anagrams for: ");
  gets(word);

  int word_len = strlen(word);
  int anagram_count = 0;
  for (i = 0; i < len - word_len + 1; i++) {
    char *anagram = strstr(str + i, word);
    if (anagram != NULL) {
      int anagram_len = strlen(anagram);
      int anagram_freq[256] = {0};
      for (j = 0; j < anagram_len; j++) {
        anagram_freq[anagram[j]]++;
      }
      int match_count = 0;
      for (k = 0; k < word_len; k++) {
        if (anagram_freq[word[k]] > 0) {
          match_count++;
        }
      }
      if (match_count == word_len) {
        printf("Anagram found: %s\n", anagram);
        anagram_count++;
      }
    }
  }
  printf("Number of anagrams found: %d\n", anagram_count);

  return 0;
}