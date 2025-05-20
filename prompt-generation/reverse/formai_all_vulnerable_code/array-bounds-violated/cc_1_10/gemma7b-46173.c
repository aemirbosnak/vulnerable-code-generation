//Gemma-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char morse_code[26][4] = {
  {'.---', '-..---', '.-..', '-..'},
  {'.---', '-..---', '.-..', '-..'},
  {'.---', '-..---', '.-..', '-..'},
  {'.---', '-..---', '.-..', '-..'},
  {'.---', '-..---', '.-..', '-..'},
  {'.---', '-..---', '.-..', '-..'},
  {'.---', '-..---', '.-..', '-..'},
  {'-..', '--..---', '.-.', '-..'},
  {'-..', '--..---', '.-.', '-..'},
  {'-..', '--..---', '.-.', '-..'},
  {'-..', '--..---', '.-.', '-..'},
  {'-..', '--..---', '.-.', '-..'},
  {'-..', '--..---', '.-.', '-..'},
  {'.---', '-..---', '.-..', '-..'},
  {'-..', '--..---', '.-.', '-..'},
  {'.---', '-..---', '.-..', '-..'},
  {'-..', '--..---', '.-.', '-..'},
  {'-..', '--..---', '.-.', '-..'},
  {'.---', '-..---', '.-..', '-..'}
};

void convert_text_to_morse_code(char *text)
{
  int i = 0;
  char word[20];
  char letter;

  while (text[i] != '\0')
  {
    letter = text[i];
    word[0] = morse_code[letter - 'a'][0];
    word[1] = morse_code[letter - 'a'][1];
    word[2] = morse_code[letter - 'a'][2];
    word[3] = morse_code[letter - 'a'][3];
    word[4] = '\0';
    printf("%s ", word);
    i++;
  }
}

int main()
{
  char text[] = "Hello, world!";

  convert_text_to_morse_code(text);

  return 0;
}