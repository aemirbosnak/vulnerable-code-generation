//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: curious
#include <stdio.h>

int main() {

   printf("Welcome to the Curious Adventure!\n");
   printf("You find yourself in a mysterious forest. You see a signpost with two directions, which way do you go? (left/right)\n");

   char direction[10];
   scanf("%s", direction);

   if(strcmp(direction, "left") == 0) {
      printf("You stumble upon an enchanted lake. A beautiful mermaid appears and asks you a riddle. If you answer correctly, I will grant you a wish. If not, I will drag you underwater and keep you as my pet. Are you ready?(yes/no)\n");

      char answer[10];
      scanf("%s", answer);

      if(strcmp(answer, "yes") == 0) {
         printf("Great! Here's your riddle: What can you keep after giving it to someone?\n");

         char riddle_answer[30];
         scanf("%s", riddle_answer);

         if(strcmp(riddle_answer, "your word") == 0) {
            printf("Well done! You have been granted one wish. What do you desire?\n");

            char wish[30];
            scanf("%s", wish);

            printf("Your wish, '%s', has been granted. Enjoy!\n", wish);
         }
         else {
            printf("Sorry, that was not the correct answer. You are now the mermaid's pet.\n");
         }
      }
      else {
         printf("You turn to run, but the mermaid catches you and keeps you as her pet.\n");
      }

   }
   else if(strcmp(direction, "right") == 0) {
      printf("You come across a dark, winding tunnel. You hear strange noises coming from within. Do you want to proceed? (yes/no)\n");

      char answer[10];
      scanf("%s", answer);

      if(strcmp(answer, "yes") == 0) {
         printf("You carefully make your way through the tunnel. Suddenly, you are ambushed by a group of goblins!\n");

         printf("What do you do?\n");
         printf("1. Fight\n");
         printf("2. Run\n");

         int choice;
         scanf("%d", &choice);

         if(choice == 1) {
            printf("You bravely fight off the goblins and emerge victorious. You find a treasure chest containing a magical ring. Do you put it on? (yes/no)\n");

            char answer[10];
            scanf("%s", answer);

            if(strcmp(answer, "yes") == 0) {
               printf("You put on the ring and feel its power coursing through your body. You have gained the ability to fly!\n");
            }
            else {
               printf("You decide not to risk it. You continue on your adventure.\n");
            }
         }
         else {
            printf("You run as fast as you can, but the goblins catch up to you and take you prisoner.\n");
         }

      }
      else {
         printf("You turn back, but soon realize you are completely lost.\n");
      }
   }
   else {
      printf("You can't seem to make a decision. You stand there indecisively for eternity.\n");
   }

   return 0;
}