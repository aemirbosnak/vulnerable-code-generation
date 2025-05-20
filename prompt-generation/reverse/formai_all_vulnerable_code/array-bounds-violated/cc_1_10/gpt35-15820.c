//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: excited
#include <stdio.h>
#include <string.h>

int main () {
   char c_cat_language[100];
   printf("Welcome to the C Cat Language Translator!\n");

   // Asking User for Input
   printf("Type in your sentence in C Cat Language:\n");
   fgets(c_cat_language, 100, stdin);

   // Removing Newline Character
   if(c_cat_language[strlen(c_cat_language)-1] == '\n') {
      c_cat_language[strlen(c_cat_language)-1] = '\0';
   }

   // Translating the Input
   printf("Original Sentence: %s\n", c_cat_language);
   printf("Translation: ");
   for(int i=0; i<strlen(c_cat_language); i++) {
      switch (c_cat_language[i]) {
         case 'm':
            printf("Meow");
            break;

         case 'p':
            printf("Purr");
            break;

         case 'h':
            printf("Hiss");
            break;

         case 'c':
            printf("Chirp");
            break;

         case 'y':
            printf("Yowl");
            break;
         
         default:
            printf("%c", c_cat_language[i]);
            break;
      }
   }
   printf("\n");

   printf("Thank you for using the C Cat Language Translator!\n");

   return 0;
}