//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: complete
#include <stdio.h>
#include <string.h>

int main() {
   char ccl[100], tac[100];
   int i, j;
   
   printf("Enter a text in C Cat Language:\n");
   fgets(ccl, sizeof(ccl), stdin);

   for(i = 0, j = 0; i < strlen(ccl); i++, j++) {

      if(ccl[i] == 'm' || ccl[i] == 'M') {
         tac[j] = 't';
         tac[++j] = 'a';
         tac[++j] = 'u';
         tac[++j] = ' ';
         tac[++j] = 'i';
         tac[++j] = 'a';
         tac[++j] = 'o';
         tac[++j] = '\n';
      } else if(ccl[i] == 'n' || ccl[i] == 'N') {
         tac[j] = 't';
         tac[++j] = 's';
         tac[++j] = 'a';
         tac[++j] = ' ';
         tac[++j] = 'k';
         tac[++j] = 'i';
         tac[++j] = 'o';
         tac[++j] = '\n';
      } else if (ccl[i] == 'a' || ccl[i] == 'A') {
         tac[j] = 'n';
         tac[++j] = 'y';
         tac[++j] = 'a';
         tac[++j] = 'n';
         tac[++j] = '\n';
      } else if (ccl[i] == 't' || ccl[i] == 'T') {
         tac[j] = 'i';
         tac[++j] = 'n';
         tac[++j] = 'u';
         tac[++j] = '\n';
      } else if (ccl[i] == 's' || ccl[i] == 'S') {
         tac[j] = 'u';
         tac[++j] = 's';
         tac[++j] = 'i';
         tac[++j] = ' ';
         tac[++j] = 'k';
         tac[++j] = 'i';
         tac[++j] = 'o';
         tac[++j] = '\n';
      } else {
         tac[j] = ccl[i];
      }
   }
   
   printf("\nTranslated text in TAC (The Actual Cat) Language:\n%s", tac);
   
   return 0;
}