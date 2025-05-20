//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: introspective
#include <stdio.h>
#include <string.h>

int main() {
   char c_cat[100];
   char english[100];
   int choice;

   printf("Welcome to the C Cat Language Translator!\n");
   printf("Please choose an option:\n");
   printf("1. C Cat to English\n");
   printf("2. English to C Cat\n");
   scanf("%d", &choice);

   if(choice == 1) {
      printf("Please enter a C Cat sentence:\n");
      scanf("%[^\n]s", c_cat);
      for(int i = 0; i < strlen(c_cat); i++) {
         if(c_cat[i] == 'm') {
            printf("Meow ");
         }
         else if(c_cat[i] == 'p') {
            printf("Purr ");
         }
         else if(c_cat[i] == 'h') {
            printf("Hiss ");
         }
         else if(c_cat[i] == 'a') {
            printf("Scratch ");
         }
         else if(c_cat[i] == 'f') {
            printf("Fish ");
         }
         else if(c_cat[i] == 'c') {
            printf("Catnip ");
         }
         else {
            printf("%c", c_cat[i]);
         }
      }
      printf("\n");
   }

   if(choice == 2) {
      printf("Please enter an English sentence:\n");
      scanf(" %[^\n]s", english);
      for(int i = 0; i < strlen(english); i++) {
         if(english[i] == 'm' && english[i+1] == 'e' && english[i+2] == 'o' && english[i+3] == 'w') {
            printf("Cat says: meow\n");
            i += 3;
         }
         else if(english[i] == 'p' && english[i+1] == 'u' && english[i+2] == 'r' && english[i+3] == 'r') {
            printf("Cat says: purr\n");
            i += 3;
         }
         else if(english[i] == 'h' && english[i+1] == 'i' && english[i+2] == 's' && english[i+3] == 's') {
            printf("Cat says: hiss\n");
            i += 3;
         }
         else if(english[i] == 's' && english[i+1] == 'c' && english[i+2] == 'r' && english[i+3] == 'a' && english[i+4] == 't' && english[i+5] == 'c' && english[i+6] == 'h') {
            printf("Cat says: scratch\n");
            i += 6;
         }
         else if(english[i] == 'f' && english[i+1] == 'i' && english[i+2] == 's' && english[i+3] == 'h') {
            printf("Cat says: fish\n");
            i += 3;
         }
         else if(english[i] == 'c' && english[i+1] == 'a' && english[i+2] == 't' && english[i+3] == 'n' && english[i+4] == 'i' && english[i+5] == 'p') {
            printf("Cat says: catnip\n");
            i += 5;
         }
         else {
            printf("%c", english[i]);
         }
      }
      printf("\n");
   }

   return 0;
}