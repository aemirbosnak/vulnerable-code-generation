//FormAI DATASET v1.0 Category: Educational ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main() {

   // Display introductory message
   printf("Welcome to the Sherlock Holmes Mystery Solver!\n");
   printf("Please enter the details of the case:\n");

   // Collect case details from user
   char suspect1[20], suspect2[20], location[20];
   int time, weapon;
   printf("Enter the name of suspect 1: ");
   scanf("%s", suspect1);
   printf("Enter the name of suspect 2: ");
   scanf("%s", suspect2);
   printf("Enter the location of the crime: ");
   scanf("%s", location);
   printf("Enter the time of the crime: ");
   scanf("%d", &time);

   // Display collected case details
   printf("\nYou have entered the following case details:\n");
   printf("Suspect 1: %s\n", suspect1);
   printf("Suspect 2: %s\n", suspect2);
   printf("Location: %s\n", location);
   printf("Time: %d\n", time);

   // Conduct investigation
   printf("\nConducting investigation...\n");

   // Search for clues
   int clue1 = strstr(suspect1, "knife") != NULL || strstr(suspect2, "knife") != NULL;
   int clue2 = strstr(suspect1, "blood") != NULL || strstr(suspect2, "blood") != NULL;

   // Determine weapon
   if (clue1) {
      weapon = 1;
   } else if (!clue1 && !clue2) {
      weapon = 2;
   } else {
      weapon = 3;
   }

   // Display investigation results
   printf("\nInvestigation results:\n");
   printf("Weapon: %d\n", weapon);

   // Determine culprit
   char culprit[20];
   if (weapon == 1) {
      strcpy(culprit, suspect2);
   } else {
      strcpy(culprit, suspect1);
   }

   // Display conclusion
   printf("\nThe culprit is:\n");
   printf("%s\n", culprit);

   return 0;
}