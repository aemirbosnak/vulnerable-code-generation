//Code Llama-13B DATASET v1.0 Category: Syntax parsing ; Style: lively
/*
 * Lively C Syntax Parsing Example Program
 *
 * Written by [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a character is a letter
int is_letter(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to check if a character is a digit
int is_digit(char c) {
  return c >= '0' && c <= '9';
}

// Function to check if a character is a whitespace
int is_whitespace(char c) {
  return c == ' ' || c == '\n' || c == '\t';
}

// Function to check if a character is a punctuation
int is_punctuation(char c) {
  return c == '.' || c == ',' || c == ';' || c == ':' || c == '!' || c == '?';
}

// Function to check if a character is a symbol
int is_symbol(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '<' || c == '>';
}

// Function to check if a character is a keyword
int is_keyword(char *str) {
  if (strcmp(str, "int") == 0) return 1;
  if (strcmp(str, "char") == 0) return 1;
  if (strcmp(str, "float") == 0) return 1;
  if (strcmp(str, "double") == 0) return 1;
  if (strcmp(str, "void") == 0) return 1;
  if (strcmp(str, "if") == 0) return 1;
  if (strcmp(str, "else") == 0) return 1;
  if (strcmp(str, "while") == 0) return 1;
  if (strcmp(str, "for") == 0) return 1;
  if (strcmp(str, "do") == 0) return 1;
  if (strcmp(str, "break") == 0) return 1;
  if (strcmp(str, "continue") == 0) return 1;
  if (strcmp(str, "return") == 0) return 1;
  if (strcmp(str, "switch") == 0) return 1;
  if (strcmp(str, "case") == 0) return 1;
  if (strcmp(str, "default") == 0) return 1;
  return 0;
}

// Function to print the type of a character
void print_type(char c) {
  if (is_letter(c)) printf("Letter");
  else if (is_digit(c)) printf("Digit");
  else if (is_whitespace(c)) printf("Whitespace");
  else if (is_punctuation(c)) printf("Punctuation");
  else if (is_symbol(c)) printf("Symbol");
  else if (is_keyword(c)) printf("Keyword");
  else printf("Unknown");
}

int main() {
  char c;
  while ((c = getchar()) != EOF) {
    print_type(c);
    printf("\n");
  }
  return 0;
}