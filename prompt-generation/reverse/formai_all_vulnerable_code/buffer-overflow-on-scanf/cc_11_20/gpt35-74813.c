//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: innovative
#include <stdio.h>

int main() {
   int option, num;
   char char_input;
   
   printf("Welcome to ASCII Art Generator!\n");
   printf("Please enter your desired output option:\n");
   printf("1. Convert text to ASCII art\n");
   printf("2. Convert number to ASCII art\n");
   printf("3. Convert character to ASCII art\n");
   scanf("%d", &option);
   
   switch (option) {
      case 1:
         printf("Please enter your desired text: ");
         scanf("%s", &char_input);
         for (int i = 0; i < sizeof(char_input); i++) {
            printf("  ,_         _\n");
            printf(" |  \\\\.___//  |\n");
            printf("      `--'\\--'\n");
            printf("        / |\n");
            printf("   ,--'  |_    _____\n");
            printf(" / \\__/)\\__)\\__)\n");
            printf(" \\_\\_|_______________\n");
            printf("        /_/_/     \n");
         }
         break;
      
      case 2:
         printf("Please enter your desired number(1-9): ");
         scanf("%d", &num);
         switch (num) {
            case 1:
               printf(" ________________\n");
               printf("|                |\n");
               printf("|        1       |\n");
               printf("|________________|\n");
               break;
            case 2:
               printf(" ________________\n");
               printf("|                |\n");
               printf("|        2       |\n");
               printf("|________________|\n");
               break;
            case 3:
               printf(" ________________\n");
               printf("|                |\n");
               printf("|        3       |\n");
               printf("|________________|\n");
               break;
            case 4:
               printf(" ________________\n");
               printf("|                |\n");
               printf("|        4       |\n");
               printf("|________________|\n");
               break;
            case 5:
               printf(" ________________\n");
               printf("|                |\n");
               printf("|        5       |\n");
               printf("|________________|\n");
               break;
            case 6:
               printf(" ________________\n");
               printf("|                |\n");
               printf("|        6       |\n");
               printf("|________________|\n");
               break;
            case 7:
               printf(" ________________\n");
               printf("|                |\n");
               printf("|        7       |\n");
               printf("|________________|\n");
               break;
            case 8:
               printf(" ________________\n");
               printf("|                |\n");
               printf("|        8       |\n");
               printf("|________________|\n");
               break;
            case 9:
               printf(" ________________\n");
               printf("|                |\n");
               printf("|        9       |\n");
               printf("|________________|\n");
               break;
            default:
               printf("Invalid input.\n");
               break;
         }
         break;
      
      case 3:
         printf("Please enter your desired character: ");
         scanf(" %c", &char_input);
         printf("     ,_         _\n");
         printf("   ,' |___ ___| `.\n");
         printf("   `-._   `   _,-'\n");
         printf("       `\"\"\"\"\"`    \n");
         printf("       %c          \n", char_input);
         break;
      
      default:
         printf("Invalid input.\n");
         break;
   }
   
   return 0;
}