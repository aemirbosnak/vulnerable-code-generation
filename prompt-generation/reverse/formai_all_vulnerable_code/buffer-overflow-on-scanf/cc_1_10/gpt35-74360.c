//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main () {

   int health = 100;
   int gold = 0;
   char name[50];

   printf("Welcome to the Adventure!\n");
   printf("Please enter your name: ");
   scanf("%s", name);

   printf("Congratulations %s! You have been chosen to embark on a dangerous quest to the heart of the jungle.\n", name);
   printf("You find yourself on a dirt path surrounded by dense foliage.\n");
   printf("After walking for some time, you encounter a strange man.\n");
   printf("Do you stop and talk to him? (y/n): ");

   char answer1;
   scanf(" %c", &answer1);

   if (answer1 == 'y') {

      printf("You approach the man, who has a stern look on his face.\n");
      printf("He stares at you for a few moments before speaking.\n");
      printf("\"I have a job for you, if you're interested.\"\n");
      printf("Press any key to continue...");
      getchar();

      printf("He hands you a map and a compass.\n");
      printf("\"Your job is to find a hidden temple deep in the jungle and retrieve a valuable artifact.\"\n");
      printf("Press any key to continue...");
      getchar();

      printf("\"But be warned, many have tried and many have failed.\"\n");
      printf("\"Oh, and one more thing, you'll need this.\" He hands you a machete.\n");
      printf("Press any key to continue...");
      getchar();

      printf("You thank the man and head off into the jungle.\n");
      printf("After walking for a few hours, you come across a river.\n");
      printf("The water is murky and there are crocodiles lurking in the shadows.\n");
      printf("Do you cross the river? (y/n):");

      char answer2;
      scanf(" %c", &answer2);

      if (answer2 == 'y') {

         printf("You wade into the river, holding your machete aloft to ward off any crocodiles.\n");
         printf("The water is freezing and up to your knees.\n");
         printf("You eventually make it to the other side, completely drenched.\n");
         printf("As you dry off, you see what appears to be a clearing in the distance.\n");
         printf("Do you investigate? (y/n):");

         char answer3;
         scanf(" %c", &answer3);
         if (answer3 == 'n') {
            printf("You decide to continue on your way, and avoid the unknown.\n");
            printf("After a while, you come across a small village.\n");
            printf("The villagers are wary of you and refuse to speak with you.\n");
            printf("You decide to make camp for the night.\n");
            printf("Press any key to continue...");
            getchar();
         } else {
            printf("You cautiously approach the clearing. In the distance, you see a temple.\n");
            printf("As you get closer, you hear the sound of drums.\n");
            printf("Suddenly, a group of masked men appear, surrounding you.\n");
            printf("\"What business do you have here?\" one of them asks.\n");
            printf("Press any key to continue...");
            getchar();

            printf("You explain your mission, showing them the map and compass.\n");
            printf("\"Ah, we know of this temple. We will help you, but you must do something for us first.\"\n");
            printf("They hand you a basket and ask you to collect berries from the forest.\n");
            printf("Press any key to continue...");
            getchar();

            int berries = 0;
            for (int i = 0; i < 5; i++) {
               printf("You search the forest and find a bush full of berries.\n");
               printf("You collect as many as you can fit in the basket.\n");
               berries++;
            }

            printf("\"Very good,\" the masked man says. \"We will guide you to the temple.\"\n");
            printf("Press any key to continue...");
            getchar();
         }
      } else {
         printf("You decide not to cross the river and continue on your way.\n");
         printf("After a while, you come across a small village.\n");
         printf("The villagers are wary of you and refuse to speak with you.\n");
         printf("You decide to make camp for the night.\n");
         printf("Press any key to continue...");
         getchar();
      }

      printf("The next morning, the masked men lead you to the temple.\n");
      printf("It's hidden behind a waterfall, and you never would have found it without their help.\n");
      printf("You enter the temple and search for the artifact.\n");
      printf("After a while, you find a small chest.\n");
      printf("You open it and find a golden statue, worth a fortune!\n");
      printf("Press any key to continue...");
      getchar();

      printf("You grab the artifact and head back to the masked men, who are waiting outside.\n");
      printf("You thank them for their help and hand them the basket of berries.\n");
      printf("\"Very good,\" the masked man says. \"You have proven yourself.\"\n");
      printf("\"We will take care of the artifact, as it is very valuable and dangerous.\"\n");
      printf("Press any key to continue...");
      getchar();

      printf("They lead you out of the jungle and back to civilization.\n");
      printf("With the artifact secured and a fortune in gold, you can finally retire and live a life of luxury.\n");
      printf("Congratulations on completing the adventure!\n");

   } else {

      printf("You decide not to talk to the man and continue on your way.\n");
      printf("After a while, you come across a small village.\n");
      printf("The villagers are wary of you and refuse to speak with you.\n");
      printf("You decide to make camp for the night.\n");
      printf("Press any key to continue...");
      getchar();

      printf("The next morning, you wake up and find your gold missing.\n");
      printf("It seems like one of the villagers has stolen it from you in the night.\n");
      printf("You search the village, but you can't find the thief.\n");
      printf("Do you give up and return home? (y/n):");

      char answer4;
      scanf(" %c", &answer4);

      if (answer4 == 'n') {

         printf("You decide to continue your search, realizing that the thief must still be in the village.\n");
         printf("After questioning the villagers, you narrow down the suspects to two individuals.\n");
         printf("They both deny stealing your gold, but you can tell that one of them is lying.\n");
         printf("Do you confront the liar? (y/n):");

         char answer5;
         scanf(" %c", &answer5);

         if (answer5 == 'y') {

            printf("You confront the liar and demand your gold back.\n");
            printf("He finally confesses and returns your gold to you.\n");
            gold += 50;

            printf("Press any key to continue...");
            getchar();

            printf("You decide to investigate the area more closely and find a hidden cave.\n");
            printf("You enter the cave and find a chest full of gold and jewels.\n");
            printf("Press any key to continue...");
            getchar();

            printf("You grab the treasure and leave the village, heading back home.\n");
            printf("Despite the setback, you have still managed to come out ahead!\n");
            printf("Congratulations on completing the adventure!\n");

         } else {

            printf("You decide not to confront the liar and return home.\n");
            printf("Despite the setback, you have still managed to come out ahead!\n");
            printf("Congratulations on completing the adventure!\n");

         }

      } else {

         printf("You decide to give up and return home.\n");
         printf("Despite the setback, you have still managed to come out ahead!\n");
         printf("Congratulations on completing the adventure!\n");

      }
   }

   return 0;
}