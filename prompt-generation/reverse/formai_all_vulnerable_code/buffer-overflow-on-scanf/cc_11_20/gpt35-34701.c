//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: paranoid
#include<stdio.h>
int main() {
  char answer;
  int num_attempts = 1;
  printf("Welcome to the Paranoid Adventure!");

  printf("You suddenly wake up in a dark room...do you want to try to find the light switch? ");
  scanf(" %c", &answer);

  if(answer == 'y' || answer == 'Y') {
    printf("You fumble around and find a switch...the lights flicker on and reveal a small room with no windows and only one door.\n");
    printf("The door is locked, there must be a key somewhere...do you want to look for it? ");
    scanf(" %c", &answer);
    if(answer == 'y' || answer == 'Y') {
      printf("You search the room and find a key behind a painting...you unlock the door and walk out into the hallway.\n");
      printf("As you walk down the hallway, you hear a faint whispering behind you...do you want to turn around? ");
      scanf(" %c", &answer);
      if(answer == 'y' || answer == 'Y') {
        printf("You turn around and see a shadowy figure...as you approach it, it disappears...you feel like you're being watched.\n");
      } else {
        printf("You walk down the hallway, feeling like you're being followed...you hear whispers and see shadows moving.\n");
      }
      printf("You come to a set of stairs...do you want to go up or down? ");
      scanf(" %c", &answer);
      if(answer == 'u' || answer == 'U') {
        printf("You climb the stairs and come to a closed door...do you want to open it? ");
        scanf(" %c", &answer);
        if(answer == 'y' || answer == 'Y') {
          printf("The door creaks open and you find yourself in a dimly lit room with strange symbols on the walls.\n");
          printf("You hear whispers and footsteps...do you want to investigate? ");
          scanf(" %c", &answer);
          if(answer == 'y' || answer == 'Y') {
            printf("As you approach the symbols, you feel a strange energy...the whispers get louder and the footsteps get heavier.\n");
            printf("Suddenly, the symbols come to life and levitate around you...you feel terror and confusion as a disembodied voice speaks to you.\n");
            printf("Congratulations, you have completed the Paranoid Adventure...or have you?");
          } else {
            printf("You walk back down the stairs, feeling like you're being followed...you hear whispers and see shadows moving.\n");
          }
        } else {
          printf("You walk back down the hallway, feeling like you're being followed...you hear whispers and see shadows moving.\n");
        }
      } else {
        printf("You descend the stairs and come to a locked door...do you want to try to open it? ");
        scanf(" %c", &answer);
        while(num_attempts <= 3) {
          if(answer == 'y' || answer == 'Y') {
            printf("You try to open the door, but it's stuck...you hear footsteps getting closer.\n");
            printf("Attempt %d: ", num_attempts);
            scanf(" %c", &answer);
            num_attempts++;
          } else {
            printf("You have no other option...the footsteps are getting closer.\n");
            printf("Attempt %d: ", num_attempts);
            scanf(" %c", &answer);
            num_attempts++;
          }
        }
        printf("The door suddenly bursts open and you find yourself face-to-face with a shadowy figure.\n");
        printf("You can't make out any details, but you feel a sense of dread as the figure approaches you.\n");
        printf("Congratulations, you have failed the Paranoid Adventure...or have you?");
      }
    } else {
      printf("You sit in the darkness, feeling like you're being watched...the whispers get louder and the footsteps get heavier.\n");
      printf("Congratulations, you have failed the Paranoid Adventure...or have you?");
    }
  } else {
    printf("You decide to stay in the darkness...the whispers get louder and the footsteps get heavier.\n");
    printf("Congratulations, you have failed the Paranoid Adventure...or have you?");
  }

  return 0;
}