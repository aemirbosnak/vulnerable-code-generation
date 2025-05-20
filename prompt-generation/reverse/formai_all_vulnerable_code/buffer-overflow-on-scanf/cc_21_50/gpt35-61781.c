//FormAI DATASET v1.0 Category: Syntax parsing ; Style: puzzling
#include <stdio.h>

int main() {

   char code[50]; 

   int i;

   printf("Enter C syntax code that needs to be parsed:\n");

   scanf("%s", code);

   printf("Parsing the code...\n");

   for (i = 0; i < strlen(code); i++) {

      if (code[i] == '{')

         printf("Opening braces found at position %d\n", i+1);

      else if (code[i] == '}')

         printf("Closing braces found at position %d\n", i+1);

      else if (code[i] == '(')

         printf("Opening parenthesis found at position %d\n", i+1);

      else if (code[i] == ')')

         printf("Closing parenthesis found at position %d\n", i+1);

      else if (code[i] == '[')

         printf("Opening bracket found at position %d\n", i+1);

      else if (code[i] == ']')

         printf("Closing bracket found at position %d\n", i+1);

      else if (code[i] == ';')

         printf("Semicolon found at position %d\n", i+1);

      else if (code[i] == ',')

         printf("Comma found at position %d\n", i+1);

      else if (code[i] == ':')

         printf("Colon found at position %d\n", i+1);

      else if (code[i] == '?')

         printf("Question mark found at position %d\n", i+1);

      else if (code[i] == '#')

         printf("Hash symbol found at position %d\n", i+1);

      else if (code[i] == '.')

         printf("Period found at position %d\n", i+1);

      else if (code[i] == '!')

         printf("Exclamation mark found at position %d\n", i+1);

      else if (code[i] == '=')

         printf("Equal sign found at position %d\n", i+1);

      else if (code[i] == '>')

         printf("Greater than operator found at position %d\n", i+1);

      else if (code[i] == '<')

         printf("Less than operator found at position %d\n", i+1);

      else if (code[i] == '+')

         printf("Plus sign found at position %d\n", i+1);

      else if (code[i] == '-')

         printf("Minus sign found at position %d\n", i+1);

      else if (code[i] == '*')

         printf("Asterisk found at position %d\n", i+1);

      else if (code[i] == '/')

         printf("Forward slash found at position %d\n", i+1);

      else if (code[i] == '%')

         printf("Modulus operator found at position %d\n", i+1);

   }

   return 0;
}