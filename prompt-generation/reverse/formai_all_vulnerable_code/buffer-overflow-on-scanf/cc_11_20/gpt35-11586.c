//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: shape shifting
#include <stdio.h>

int main() {
   int candidate1 = 0, candidate2 = 0, candidate3 = 0;
   int total_voters = 100, voted = 0;
   int option;
   
   printf("Welcome to the Electronic Voting System!\n");

   while (voted < total_voters) {
      printf("\nPlease choose a candidate:\n");
      printf("1. Candidate A\n");
      printf("2. Candidate B\n");
      printf("3. Candidate C\n");
      printf("4. Exit\n");

      scanf("%d", &option);

      switch (option) {
         case 1:
            candidate1++;
            voted++;
            printf("You've voted for Candidate A.\n");
            printf("Thank you for voting!\n");
            break;
         case 2:
            candidate2++;
            voted++;
            printf("You've voted for Candidate B.\n");
            printf("Thank you for voting!\n");
            break;
         case 3:
            candidate3++;
            voted++;
            printf("You've voted for Candidate C.\n");
            printf("Thank you for voting!\n");
            break;
         case 4:
            printf("Exiting the system, thank you for your participation.\n");
            return 0;
         default:
            printf("Invalid option, please try again.");
            break;
      }


      // Shape shifting block
      if (voted % 10 == 0) {
         printf("\nChanging the visual representation...\n");
         printf("Press Enter to continue...\n");
         getchar();
         getchar();

         // Choose the style based on the last digit of the total votes
         switch (total_voters % 10) {
            case 0:
            case 1:
            case 2:
               printf("███     ██  ████████  ██      ██      \n");
               printf("░░██    ░██░██░░░░░██░██     ░██      \n");
               printf(" ░██    ░██░██     ░░░██    ░██       \n");
               printf(" ░██    ░██░█████████ ░██   ░██        \n");
               printf(" ░██    ░██░██░░░░░░  ░██  ░██░██████ \n");
               printf(" ░██░   ░██░██        ░██ ░██░░░░░░██\n");
               printf(" ░░████████ ░██        ░██░██      ░██\n");
               printf("  ░░░░░░░░  ░░░         ░░ ░░       ░░ \n");
               break;
            case 3:
            case 4:
            case 5:
               printf(" ████████████   ████████████ ████████████ ████████████ █████     █████\n");
               printf("░░██░░██░░██░░██░░██░░██░░██░░██░░██░░██░░██░░██░░██░░██░░██   ░░██░\n");
               printf(" ░██ ░██ ░██ ░██ ░██ ░██ ░██ ░██ ░██ ░██ ░██ ░██ ░██ ░██░░██ ░██░\n");
               printf(" ░██ ░██ ░██ ░██ ░██ ░██ ░██ ░██ ░██ ░██ ░██ ░███████ ░██ ░░█████░\n");
               printf(" ░██ ░██ ░██ ░██ ░██ ░██ ░██ ░██ ░██ ░██ ░██ ░██░░░░  ░██   ░░░██░\n");
               printf(" ░██ ░██ ░██ ░██ ░██ ░██ ░██ ░██ ░██ ░██ ░██ ░██       ░██  ░██ ░██\n");
               printf("░██████ ░██ ░░██████░░██████░██ ████████░██ ░██       ░░███████░░██\n");
               printf("░░░░░  ░░   ░░░░░░░  ░░░░░░ ░░ ░░░░░░░░ ░░  ░░         ░░░░░██░░ ░░ \n");
               break;
            case 6:
            case 7:
            case 8:
            case 9:
               printf("╔═════════════════════════════════════════╗\n");
               printf("║                                         ║\n");
               printf("║           ██████╗ ██╗   ██╗             ║\n");
               printf("║           ██╔══██╗██║   ██║             ║\n");
               printf("║           ██████╔╝██║   ██║             ║\n");
               printf("║           ██╔═══╝ ██║   ██║             ║\n");
               printf("║           ██║     ╚██████╔╝             ║\n");
               printf("║           ╚═╝      ╚═════╝              ║\n");
               printf("║                                         ║\n");
               printf("║             ███████╗ ██████╗            ║\n");
               printf("║             ██╔════╝██╔═══██╗           ║\n");
               printf("║             █████╗  ██║   ██║           ║\n");
               printf("║             ██╔══╝  ██║   ██║           ║\n");
               printf("║             ██║     ╚██████╔╝           ║\n");
               printf("║             ╚═╝      ╚═════╝            ║\n");
               printf("║                                         ║\n");
               printf("╚═════════════════════════════════════════╝\n");
               break;
         }

         // Reset the counter
         voted = 0;
      }
   }

   printf("\nTotal votes:\n");
   printf("Candidate A: %d\n", candidate1);
   printf("Candidate B: %d\n", candidate2);
   printf("Candidate C: %d\n", candidate3);

   printf("\nThank you for your votes!\n");
   
   return 0;
}