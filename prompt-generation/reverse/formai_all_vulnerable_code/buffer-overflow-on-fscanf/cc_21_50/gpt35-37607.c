//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

// C Cat Language Translator

int main() {
   char jibberish[1000];
   char english[1000];
   char choice[5];
   int i;
   printf("Welcome to the C Cat Language Translator!\n");
   printf("Enter 'j' to translate from Cat to English.\n");
   printf("Enter 'e' to translate from English to Cat.\n");
   fscanf(stdin, "%s", choice);

   switch(choice[0]) {
      case 'j':
         printf("Enter the Cat language to translate: \n");
         fscanf(stdin, "%s", jibberish);
         for(i = 0; i < strlen(jibberish); i++) {
            switch(jibberish[i]) {
               case 'P':
                  printf("Meow");
                  break;
               case 'M':
                  printf("Purr");
                  break;
               case 'S':
                  printf("Hiss");
                  break;
               case 'T':
                  printf("Scratch");
                  break;
               default:
                  printf("Unknown Cat word found!");
            }
         }
         printf("\n");
         break;
      case 'e':
         printf("Enter the English language to translate: \n");
         fscanf(stdin, "%s", english);
         for(i = 0; i < strlen(english); i++) {
            if(english[i] == 'm' && english[i+1] == 'e' && english[i+2] == 'o' && english[i+3] == 'w') {
               printf("P");
               i = i + 3;
            } else if(english[i] == 'p' && english[i+1] == 'u' && english[i+2] == 'r' && english[i+3] == 'r') {
               printf("M");
               i = i + 3;
            } else if(english[i] == 'h' && english[i+1] == 'i' && english[i+2] == 's' && english[i+3] == 's') {
               printf("S");
               i = i + 3;
            } else if(english[i] == 's' && english[i+1] == 'c' && english[i+2] == 'r' && english[i+3] == 'a' && english[i+4] == 't' && english[i+5] == 'c' && english[i+6] == 'h') {
               printf("T");
               i = i + 6;
            } else {
               printf("Unknown word found");
            }
         }
         printf("\n");
         break;
      default:
         printf("Unknown operation requested");
   }
   return 0;
}