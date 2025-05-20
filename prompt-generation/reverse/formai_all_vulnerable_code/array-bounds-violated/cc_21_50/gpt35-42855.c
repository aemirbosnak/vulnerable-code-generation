//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: paranoid
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

char *convertToMorse(char character);
void printMorseCode(char *message);

int main()
{
  char input[MAX_LENGTH];
  int i, j = 0;

  printf("Enter your secret message: ");
  fgets(input, MAX_LENGTH, stdin);

  char message[strlen(input) * 6]; // Morse code uses 6 characters for each letter
  for (i = 0; i < strlen(input) - 1; i++)
  {
    if (input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z') // Only convert letters to Morse code
    {
      char *morse = convertToMorse(input[i]); // Convert character to Morse code
      for (int k = 0; k < strlen(morse); k++)
      {
        message[j] = morse[k]; // Add Morse code to message string
        j++;
      }
      message[j] = ' '; // Add space between letters
      j++;
    }
  }

  printf("Your encoded message is:\n");
  printMorseCode(message);

  return 0;
}

char *convertToMorse(char character)
{
  switch (character)
  {
  case 'a':
  case 'A':
    return ".-";
    break;
  case 'b':
  case 'B':
    return "-...";
    break;
  case 'c':
  case 'C':
    return "-.-.";
    break;
  case 'd':
  case 'D':
    return "-..";
    break;
  case 'e':
  case 'E':
    return ".";
    break;
  case 'f':
  case 'F':
    return "..-.";
    break;
  case 'g':
  case 'G':
    return "--.";
    break;
  case 'h':
  case 'H':
    return "....";
    break;
  case 'i':
  case 'I':
    return "..";
    break;
  case 'j':
  case 'J':
    return ".---";
    break;
  case 'k':
  case 'K':
    return "-.-";
    break;
  case 'l':
  case 'L':
    return ".-..";
    break;
  case 'm':
  case 'M':
    return "--";
    break;
  case 'n':
  case 'N':
    return "-.";
    break;
  case 'o':
  case 'O':
    return "---";
    break;
  case 'p':
  case 'P':
    return ".--.";
    break;
  case 'q':
  case 'Q':
    return "--.-";
    break;
  case 'r':
  case 'R':
    return ".-.";
    break;
  case 's':
  case 'S':
    return "...";
    break;
  case 't':
  case 'T':
    return "-";
    break;
  case 'u':
  case 'U':
    return "..-";
    break;
  case 'v':
  case 'V':
    return "...-";
    break;
  case 'w':
  case 'W':
    return ".--";
    break;
  case 'x':
  case 'X':
    return "-..-";
    break;
  case 'y':
  case 'Y':
    return "-.--";
    break;
  case 'z':
  case 'Z':
    return "--..";
    break;
  default:
    // If the character is not a letter, return an error message
    return "ERROR";
    break;
  }
}

void printMorseCode(char *message)
{
  for (int i = 0; i < strlen(message); i++)
  {
    if (message[i] == '.') // Print a dot for a dot in Morse code
    {
      printf(". ");
    }
    else if (message[i] == '-') // Print a dash for a dash in Morse code
    {
      printf("- ");
    }
    else if (message[i] == ' ') // Print a space for a space in Morse code
    {
      printf("/ ");
    }
    else // If the character is not a dot, dash or space, print an error message
    {
      printf("ERROR ");
    }
  }
}