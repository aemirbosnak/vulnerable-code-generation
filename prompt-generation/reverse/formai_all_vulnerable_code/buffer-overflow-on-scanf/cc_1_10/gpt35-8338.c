//FormAI DATASET v1.0 Category: System administration ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{
  pid_t pid = getpid();
  printf("The magic conch declares your process ID is: %d\n", pid);
  
  printf("The world around you swirls with chaos and confusion...\n");
  printf("Reality begins to shift and warp, as if you are in a dream...\n");
  printf("You hear a faint whisper in the distance: 'lost shard'...\n");
  printf("Suddenly, a holographic screen flickers into view before you...\n");
  printf("It appears to be an administrator console for the fabric of space-time itself...\n");
  
  int choice;
  printf("\nWhat do you wish to do with your newfound power?\n");
  printf("1. Manipulate gravity\n");
  printf("2. Restart the universe\n");
  printf("3. Summon a black hole\n");
  printf("4. Exit the program\n");
  scanf("%d", &choice);
  
  switch(choice){
      case 1:
          printf("\nYou are wielding the power of gravity, your thoughts coalesce into the physical world...\n");
          printf("You can feel the weight of the universe at your fingertips...\n");
          printf("Do you increase or decrease gravitational force? (1 or 2): ");
          int action;
          scanf("%d", &action);
          if(action == 1){
              printf("The universe's gravitational force increases...\n");
              printf("Objects begin to experience an increased pull towards one another...\n");
              printf("Small planets are brought together, becoming larger...\n");
              printf("The very fabric of the universe is bending under the intense gravity...\n");
              printf("\nCongratulations, you have irrevocably altered the universe's fate!\n");
          }else{
              printf("The universe's gravitational force decreases...\n");
              printf("Planets begin to drift apart from one another...\n");
              printf("The stars in the sky begin to grow smaller...\n");
              printf("The very fabric of the universe seems to be stretching...\n");
              printf("\nCongratulations, you have irrevocably altered the universe's fate!\n");
          }
      break;
      
      case 2:
          printf("\nYou have chosen to restart the universe...\n");
          printf("Are you sure you want to proceed? (y/n): ");
          char proceed;
          scanf(" %c", &proceed);
          if(proceed == 'y'){
              printf("The universe begins to collapse in on itself...\n");
              printf("A blinding light emits from the center, as all matter is sucked in...\n");
              printf("The universe disappears into a singularity...\n");
              printf("In an instant, a new universe is born...\n");
              printf("Congratulations, you have wiped the slate clean!\n");
          }else{
              printf("You have chosen not to restart the universe...\n");
              printf("You may now continue with your day...\n");
          }
      break;
      
      case 3:
          printf("\nYou have summoned a black hole...\n");
          printf("As the black hole begins to form, your mind becomes aware of the universe's secrets...\n");
          printf("The black hole's gravity is so strong that it can bend the fabric of space-time...\n");
          printf("You can feel your body begin to warp under the intense gravity...\n");
          printf("Do you step into the black hole's event horizon? (y/n): ");
          char step;
          scanf(" %c", &step);
          if(step == 'y'){
              printf("\nAs you step into the black hole, your body is stretched and torn apart...\n");
              printf("Your atoms, once contained in a single form, are now spread out across the universe...\n");
              printf("You can feel yourself becoming one with the stars...\n");
              printf("Congratulations, you have discovered the true nature of the universe!\n");
          }else{
              printf("\nYou have chosen not to step into the black hole's event horizon...\n");
              printf("You may now continue with your day...\n");
          }
      break;
      
      case 4:
          printf("\nYou have chosen to exit the program...\n");
          printf("Goodbye, and may you wield your new-found power responsibly...\n");
          exit(0);
      break;
      
      default:
          printf("\nInvalid choice... Exiting program...\n");
          exit(0);
      break;
  }
  
  return 0;
}