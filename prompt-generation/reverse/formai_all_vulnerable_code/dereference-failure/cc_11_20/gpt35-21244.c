//FormAI DATASET v1.0 Category: Syntax parsing ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to check if a string is a valid integer
int isNumber(char str[]) {
   int i, len = strlen(str);
   if (len == 0)
      return 0;
   for (i = 0; i < len; i++) {
      if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9')
         return 0;
   }
   return 1;
}

// function to parse the arithmetic expression
int parseExpression(char *arg) {
   int i, n1 = 0, n2 = 0, res = 0;
   char op;
   char *token;

   // using strtok to tokenize the input expression based on operators
   token = strtok(arg, "+-/*");

   i = 0;
   while (token != NULL) {
      if (i == 0) {
         // the first token is always a number
         if (!isNumber(token)) {
            printf("Invalid input\n");
            return -1;
         }
         n1 = atoi(token);
      } else {
         // the second token is always an operator
         if (strlen(token) != 1 || (token[0] != '+' && token[0] != '-' && token[0] != '*' && token[0] != '/')) {
            printf("Invalid input\n");
            return -1;
         }
         op = token[0];
         i++;
         token = strtok(NULL, "+-/*");
         if (token == NULL) {
            printf("Invalid input\n");
            return -1;
         }
         // the third token is always a number
         if (!isNumber(token)) {
            printf("Invalid input\n");
            return -1;
         }
         n2 = atoi(token);
         switch (op) {
            case '+':
               res = n1 + n2;
               break;
            case '-':
               res = n1 - n2;
               break;
            case '*':
               res = n1 * n2;
               break;
            case '/':
               if (n2 == 0) {
                  printf("Division by zero!\n");
                  return -1;
               }
               res = n1 / n2;
               break;
         }
         n1 = res;
      }
      i++;
      token = strtok(NULL, "+-/*");
   }

   return res;
}

int main(int argc, char *argv[]) {
   int i, res;
   if (argc < 2) {
      printf("Syntax: %s <expression>\n", argv[0]);
      return -1;
   }
   // parse each argument separately
   for (i = 1; i < argc; i++) {
      res = parseExpression(argv[i]);
      if (res >= 0)
         printf("%d\n", res);
   }
   return 0;
}