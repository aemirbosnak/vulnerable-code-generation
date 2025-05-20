//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: lively
#include <stdio.h>
#include <string.h>

int main()
{
  char alien[100], english[100];
  int i, j;
  
  printf("Enter the Alian language: ");
  gets(alien);

  for(i = 0; alien[i] != '\0'; i++)
  {
    if(alien[i] == '!')
      english[i] = 'a';
    else if(alien[i] == '1')
      english[i] = 'b';
    else if(alien[i] == '@')
      english[i] = 'c';
    else if(alien[i] == '+')
      english[i] = 'd';
    else if(alien[i] == '*')
      english[i] = 'e';
    else if(alien[i] == ';')
      english[i] = 'f';
    else if(alien[i] == '-')
      english[i] = 'g';
    else if(alien[i] == '/')
      english[i] = 'h';
    else if(alien[i] == '?')
      english[i] = 'i';
    else if(alien[i] == '&')
      english[i] = 'j';
    else if(alien[i] == '#')
      english[i] = 'k';
    else if(alien[i] == '>')
      english[i] = 'l';
    else if(alien[i] == '<')
      english[i] = 'm';
    else if(alien[i] == '[')
      english[i] = 'n';
    else if(alien[i] == ']')
      english[i] = 'o';
    else if(alien[i] == '{')
      english[i] = 'p';
    else if(alien[i] == '}')
      english[i] = 'q';
    else if(alien[i] == '(')
      english[i] = 'r';
    else if(alien[i] == ')')
      english[i] = 's';
    else if(alien[i] == '`')
      english[i] = 't';
    else if(alien[i] == '~')
      english[i] = 'u';
    else if(alien[i] == '|')
      english[i] = 'v';
    else if(alien[i] == '^')
      english[i] = 'w';
    else if(alien[i] == '_')
      english[i] = 'x';
    else if(alien[i] == '=')
      english[i] = 'y';
    else if(alien[i] == ':')
      english[i] = 'z';
    else
      english[i] = alien[i]; //No translation needed
  }
  
  printf("The translated English is: ");
  puts(english);
  
  return 0;
}