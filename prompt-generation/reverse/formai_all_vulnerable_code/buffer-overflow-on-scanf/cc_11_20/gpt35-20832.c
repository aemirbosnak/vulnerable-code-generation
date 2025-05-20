//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL)); // initialize random seed
   printf("Welcome to the Time Travel Simulator!\n");
   printf("Enter a year to travel to (between 500 and 3000):\n");
   int year;
   scanf("%d", &year);
   while (year < 500 || year > 3000) { // validate input
       printf("Invalid year! Please enter a year between 500 and 3000:\n");
       scanf("%d", &year);
   }
   printf("Now entering the year %d...\n", year);
   printf("Loading simulation...\n");
   for (int i = 0; i < 10; i++) { // simulate loading progress
       printf("*");
       fflush(stdout);
       int delay = rand() % 1000 + 500;
       usleep(delay * 1000);
   }
   printf("\nSimulation loaded!\n");
   printf("You look around and see...\n");
   switch (year) {
       case 500 ... 999: // medieval period
           printf("A castle in the distance, surrounded by peasants and knights.\n");
           break;
       case 1000 ... 1499: // renaissance period
           printf("Artisans and philosophers discussing ideas on the street.\n");
           break;
       case 1500 ... 1799: // enlightenment period
           printf("A brilliant scientist conducting experiments in his laboratory.\n");
           break;
       case 1800 ... 1999: // modern era
           printf("Cars zooming down the road and people talking on cell phones.\n");
           break;
       case 2000 ... 3000: // futuristic era
           printf("Hovercars flying in the air and robots walking the streets.\n");
           break;
   }
   printf("You decide to explore further...\n");
   int steps = rand() % 21 + 10; // generate random number of steps to take
   for (int i = 1; i <= steps; i++) {
       printf("*step*\n");
       fflush(stdout);
       int delay = rand() % 500 + 250;
       usleep(delay * 1000);
   }
   printf("You come across...\n");
   int randomEvent = rand() % 4; // generate random event
   switch (randomEvent) {
       case 0: // meet a historical figure
           printf("Leonardo da Vinci! He looks up from his sketchbook and greets you.\n");
           break;
       case 1: // witness a famous event
           printf("The Wright Brothers are flying their first airplane! You watch in awe.\n");
           break;
       case 2: // experience a disaster
           printf("An earthquake! The ground shakes violently and you struggle to stay upright.\n");
           break;
       case 3: // encounter an alien
           printf("An alien spaceship lands in front of you! The extraterrestrial beings emerge.\n");
           break;
   }
   printf("You chat with the historical figure, watch the famous event unfold, survive the disaster, or communicate with the alien.\n");
   printf("You begin to feel a sense of longing to stay in this time period...\n");
   printf("Do you stay or return to your own time? (type stay or return):\n");
   char choice[10];
   scanf("%s", choice);
   while (strcmp(choice, "stay") != 0 && strcmp(choice, "return") != 0) { // validate input
       printf("Invalid choice! Please type stay or return:\n");
       scanf("%s", choice);
   }
   if (strcmp(choice, "stay") == 0) {
       printf("You have chosen to stay in this time period. Good luck in your new life!\n");
   } else {
       printf("You return to your own time. Thank you for using the Time Travel Simulator!\n");
   }
   return 0;
}