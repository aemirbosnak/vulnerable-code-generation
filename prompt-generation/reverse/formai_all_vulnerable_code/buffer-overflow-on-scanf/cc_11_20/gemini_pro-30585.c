//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a string to ASCII art
void stringToASCII(char *str) {
  // Get the length of the string
  int len = strlen(str);

  // Create a 2D array to store the ASCII art
  char **art = (char **)malloc(len * sizeof(char *));
  for (int i = 0; i < len; i++) {
    art[i] = (char *)malloc(8 * sizeof(char));
  }

  // Convert each character to ASCII art
  for (int i = 0; i < len; i++) {
    char c = str[i];
    switch (c) {
      case 'A':
        strcpy(art[i], "███████\n███░░░░░███\n█████░░█████\n███░░░░░███\n███░░░░░███");
        break;
      case 'B':
        strcpy(art[i], "███████\n███░░███\n███████\n███░░███\n███████");
        break;
      case 'C':
        strcpy(art[i], "████████\n███░░░░░░\n███░░░░░░\n███░░░░░░\n████████");
        break;
      case 'D':
        strcpy(art[i], "███████\n███░░███\n███░░███\n███░░███\n███████");
        break;
      case 'E':
        strcpy(art[i], "███████\n███░░░░░\n██████\n███░░░░░\n███████");
        break;
      case 'F':
        strcpy(art[i], "███████\n███░░░░░\n██████\n███░░░░░\n███░░░░░");
        break;
      case 'G':
        strcpy(art[i], "████████\n███░░░░░░\n███  ████\n███░░░░░░\n████████");
        break;
      case 'H':
        strcpy(art[i], "███░░███\n███░░███\n███████\n███░░███\n███░░███");
        break;
      case 'I':
        strcpy(art[i], "███████\n░░░███░░░\n░░░███░░░\n░░░███░░░\n███████");
        break;
      case 'J':
        strcpy(art[i], "████████\n░░░░███░░\n░░░░███░░\n███░░███\n█████░░░");
        break;
      case 'K':
        strcpy(art[i], "███░░███\n███░███\n██████\n███░███\n███░░███");
        break;
      case 'L':
        strcpy(art[i], "███░░░░░\n███░░░░░\n███░░░░░\n███░░░░░\n████████");
        break;
      case 'M':
        strcpy(art[i], "███░░░░░███\n████░░░████\n███░░░███\n███░░░███\n███░░░███");
        break;
      case 'N':
        strcpy(art[i], "███░░░░░███\n████░░░███\n███░██░███\n███░░███\n███░░░███");
        break;
      case 'O':
        strcpy(art[i], "████████\n███░░░░███\n███░░░░███\n███░░░░███\n████████");
        break;
      case 'P':
        strcpy(art[i], "███████\n███░░███\n███████\n███░░░░░\n███░░░░░");
        break;
      case 'Q':
        strcpy(art[i], "████████\n███░░░░███\n███░░░░███\n███░░░░███\n████████\n░░░░░░░░██");
        break;
      case 'R':
        strcpy(art[i], "███████\n███░░███\n███████\n███░███\n███░░███");
        break;
      case 'S':
        strcpy(art[i], "████████\n███░░░░░░\n████░░░░░\n░░░░███░░\n████████");
        break;
      case 'T':
        strcpy(art[i], "████████\n░░░███░░░\n░░░███░░░\n░░░███░░░\n░░░███░░░");
        break;
      case 'U':
        strcpy(art[i], "███░░░░░███\n███░░░░░███\n███░░░░░███\n███░░░░░███\n████████");
        break;
      case 'V':
        strcpy(art[i], "███░░░░░███\n███░░░░░███\n███░░░░░███\n████░░░████\n░░░░███░░░░");
        break;
      case 'W':
        strcpy(art[i], "███░░░░░███\n███░░░░░███\n███░░░░░███\n████░░░████\n███░░░███");
        break;
      case 'X':
        strcpy(art[i], "███░░░░░███\n████░░░████\n░░░░████░░░░\n████░░░████\n███░░░░░███");
        break;
      case 'Y':
        strcpy(art[i], "███░░░░░███\n████░░░████\n░░░░████░░░░\n░░░░████░░░░\n░░░████░░░");
        break;
      case 'Z':
        strcpy(art[i], "████████\n░░░░░░███\n░░░░░███\n░░░███\n█████");
        break;
      default:
        strcpy(art[i], " ");
        break;
    }
  }

  // Print the ASCII art
  for (int i = 0; i < len; i++) {
    printf("%s\n", art[i]);
  }

  // Free the memory allocated for the ASCII art
  for (int i = 0; i < len; i++) {
    free(art[i]);
  }
  free(art);
}

int main() {
  // Get the input string from the user
  char str[100];
  printf("Enter a string: ");
  scanf("%s", str);

  // Convert the string to ASCII art
  stringToASCII(str);

  return 0;
}