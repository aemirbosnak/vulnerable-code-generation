//FormAI DATASET v1.0 Category: System administration ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Welcome to the "Happy Admin" tool!

  printf("Welcome to the Happy Admin tool!\n");
  printf("We here at Happy Admin are dedicated to making your system admin job as fun as possible.\n");
  printf("So let's dive in and see what kind of fun we can have today!\n");

  // First, check if the user is in a good mood

  char mood[10];
  printf("What is your current mood? (happy/sad/angry): ");
  scanf("%s", mood);

  // If the user is sad or angry, offer some encouragement

  if (strcmp(mood, "sad") == 0 || strcmp(mood, "angry") == 0) {
    printf("Cheer up! Things can't be that bad if you're using the Happy Admin tool!\n");
    printf("Let's start by checking your system status.\n");
  }

  // Otherwise, if the user is happy, offer some high-fives

  else if (strcmp(mood, "happy") == 0) {
    printf("Awesome! You're in a great mood and ready to kick some system admin butt!\n");
    printf("Let's start by checking your system status.\n");
  }

  // If they're in neither an expected mood, apologize

  else {
    printf("I'm sorry, I don't understand your mood. Please try again with 'happy', 'sad', or 'angry'.\n");
    return 1;
  }

  // Now, let's check the system status

  printf("Checking system status...\n");

  system("uptime");

  // Let's offer some jokes while we wait for the command to finish

  printf("Why was the computer cold?\n");
  printf("Because it left its Windows open!\n");

  printf("What is a programmer's favorite hangout spot?\n");
  printf("The Foo Bar.\n");

  // Now let's check some CPU information

  printf("Checking CPU info...\n");

  system("cat /proc/cpuinfo");

  // More jokes!

  printf("Why did the programmer quit his job?\n");
  printf("He didn't get arrays.\n");

  printf("Why do programmers always mix up Halloween and Christmas?\n");
  printf("Because Oct 31 equals Dec 25.\n");

  // Finally, wrap up the program

  printf("Thanks for using the Happy Admin tool! We hope we made your system admin job a little more fun today.\n");

  return 0;
}