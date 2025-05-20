//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: innovative
#include <stdio.h>
#include <string.h>

// Alien Language Dictionary
const char* alienDic[] = {
   "ali",
   "jou",
   "fre",
   "nis",
   "rak"
};

// Alien Language Translator function
void alienTranslator(char alienWord[])
{
   int i;
   int dicLength = sizeof(alienDic) / sizeof(alienDic[0]);
   int found = 0;

   // Translate the alien word if present in the dictionary
   for(i = 0; i < dicLength; i++) {
      if(strcmp(alienWord, alienDic[i]) == 0) {
         printf("Alien word '%s' is translated to '%c%c%c'.\n", alienWord, alienWord[0], alienWord[1], alienWord[2]);
         found = 1;
         break;
      }
   }

   // If the alien word is not in dictionary, prompt for message to enter the word in dictionary
   if(!found) {
      printf("The alien word '%s' is not in the dictionary. Would you like to add it? (y/n): ", alienWord);
      char choice;
      scanf("%c", &choice);

      // Add the alien word to dictionary if user chooses to add
      if(choice == 'y') {
         int newDicLength = dicLength + 1;
         alienDic[newDicLength - 1] = alienWord;
         printf("The alien word '%s' has been added to the dictionary.\n", alienWord);
      }
   }
}

int main() 
{
   char alienWord[4];

   printf("Please enter an alien word (3 characters only): ");
   scanf("%s", alienWord);

   alienTranslator(alienWord);

   return 0;
}