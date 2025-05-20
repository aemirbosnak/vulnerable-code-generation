//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to convert a string to ASCII art
char *string_to_ascii_art(char *string) {
  // Allocate memory for the ASCII art
  char *ascii_art = malloc(strlen(string) * 10);
  if (ascii_art == NULL) {
    return NULL;
  }

  // Initialize the ASCII art string
  ascii_art[0] = '\0';

  // Loop through each character in the string
  for (int i = 0; i < strlen(string); i++) {
    // Get the ASCII code for the character
    int ascii_code = string[i];

    // Convert the ASCII code to ASCII art
    char *ascii_art_character = malloc(10);
    if (ascii_art_character == NULL) {
      free(ascii_art);
      return NULL;
    }

    switch (ascii_code) {
      case 'A':
        strcpy(ascii_art_character, "  ___  \n / _ \ \n| | | |\n| |_| |\n \___/ \n");
        break;
      case 'B':
        strcpy(ascii_art_character, " _____ \n|  __ \ \n| |__) |\n|  ___/ \n| |     \n|_|     \n");
        break;
      case 'C':
        strcpy(ascii_art_character, "  ___  \n / _ \ \n| | | |\n| |_| |\n \___/ \n");
        break;
      case 'D':
        strcpy(ascii_art_character, " _____ \n|  __ \ \n| |__) |\n|  ___/ \n| |     \n|_|     \n");
        break;
      case 'E':
        strcpy(ascii_art_character, " _____ \n|  __ \ \n| |__) |\n|  ___/ \n| |     \n|_|     \n");
        break;
      case 'F':
        strcpy(ascii_art_character, " _____ \n|  __ \ \n| |__) |\n|  ___/ \n| |     \n|_|     \n");
        break;
      case 'G':
        strcpy(ascii_art_character, "  ___  \n / _ \ \n| | | |\n| |_| |\n \___/ \n      \n");
        break;
      case 'H':
        strcpy(ascii_art_character, "| | | |\n| | | |\n| |_| |\n|  _  |\n| | | |\n|_| |_|\n");
        break;
      case 'I':
        strcpy(ascii_art_character, "  ___  \n / _ \ \n| | | |\n| |_| |\n \___/ \n");
        break;
      case 'J':
        strcpy(ascii_art_character, "   ___  \n  / _ \ \n | | | |\n |_| | |\n  \___/ \n       \n");
        break;
      case 'K':
        strcpy(ascii_art_character, "| | | |\n| | | |\n| |_| |\n|  _  |\n| | | |\n|_| |_|\n");
        break;
      case 'L':
        strcpy(ascii_art_character, "| | | |\n| | | |\n| |_| |\n|  _  |\n| | | |\n|_| |_|\n");
        break;
      case 'M':
        strcpy(ascii_art_character, "| | | |\n| | | |\n| | | |\n| | | |\n| |_| |\n|_|_|_|\n");
        break;
      case 'N':
        strcpy(ascii_art_character, "| | | |\n| | | |\n| | | |\n| |_| |\n \___/ \n");
        break;
      case 'O':
        strcpy(ascii_art_character, "  ___  \n / _ \ \n| | | |\n| |_| |\n \___/ \n");
        break;
      case 'P':
        strcpy(ascii_art_character, " _____ \n|  __ \ \n| |__) |\n|  ___/ \n| |     \n|_|     \n");
        break;
      case 'Q':
        strcpy(ascii_art_character, "  ___  \n / _ \ \n| | | |\n| |_| |\n \___/ \n      \n      \n");
        break;
      case 'R':
        strcpy(ascii_art_character, " _____ \n|  __ \ \n| |__) |\n|  ___/ \n| |     \n|_|     \n");
        break;
      case 'S':
        strcpy(ascii_art_character, "  ___  \n / _ \ \n| | | |\n| |_| |\n \___/ \n");
        break;
      case 'T':
        strcpy(ascii_art_character, " _____ \n|  ___|\n| |__  \n|  __| \n| |___ \n\_____|\n");
        break;
      case 'U':
        strcpy(ascii_art_character, "| | | |\n| | | |\n| | | |\n| | | |\n| | | |\n|_|_|_|\n");
        break;
      case 'V':
        strcpy(ascii_art_character, "| | | |\n| | | |\n| | | |\n \ \_/ /\n  \___/ \n");
        break;
      case 'W':
        strcpy(ascii_art_character, "| | | |\n| | | |\n| | | |\n| | | |\n \ \_/ /\n  \___/ \n");
        break;
      case 'X':
        strcpy(ascii_art_character, "| | | |\n| | | |\n \ \_/ /\n  \___/ \n| | | |\n|_|_|_|\n");
        break;
      case 'Y':
        strcpy(ascii_art_character, "| | | |\n| | | |\n \ \_/ /\n  \___/ \n  | |  \n  |_|  \n");
        break;
      case 'Z':
        strcpy(ascii_art_character, " _____ \n|  __ \ \n| |__) |\n|  ___/ \n| |     \n|_|     \n");
        break;
      default:
        strcpy(ascii_art_character, " ");
        break;
    }

    // Append the ASCII art character to the ASCII art string
    strcat(ascii_art, ascii_art_character);

    // Free the memory allocated for the ASCII art character
    free(ascii_art_character);
  }

  // Return the ASCII art string
  return ascii_art;
}

// Main function
int main() {
  // Get the input string from the user
  char input_string[MAX_LINE_LENGTH];
  printf("Enter a string: ");
  fgets(input_string, MAX_LINE_LENGTH, stdin);

  // Convert the input string to ASCII art
  char *ascii_art = string_to_ascii_art(input_string);

  // Print the ASCII art to the console
  printf("%s", ascii_art);

  // Free the memory allocated for the ASCII art
  free(ascii_art);

  return 0;
}