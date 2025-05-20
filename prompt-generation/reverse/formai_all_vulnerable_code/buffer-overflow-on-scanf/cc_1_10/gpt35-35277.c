//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int question_num;
  char *questions[] = {"What is your name?", "What is your favorite color?", "What is your biggest fear?", "What is your biggest dream?"};
  char *fortunes[] = {"You will have a great day today!",
                      "Your hard work will pay off soon.",
                      "Be ready for an unexpected journey.",
                      "Good news is coming your way.",
                      "Your luck will turn around soon.",
                      "You will make a new friend today.",
                      "Take a risk and it will pay off.",
                      "A loved one will bring you joy today.",
                      "Your creativity will be at an all-time high today.",
                      "Today is your day! Embrace it!"};

  srand(time(NULL)); // seed for random number generator

  printf("Welcome to the Automated Fortune Teller! Ask a question (1-4): \n");
  printf("1. %s\n", questions[0]);
  printf("2. %s\n", questions[1]);
  printf("3. %s\n", questions[2]);
  printf("4. %s\n", questions[3]);

  scanf("%d", &question_num);

  switch(question_num) {
    case 1:
      printf("Hello, what is your name?\n");

      char name[50];
      scanf("%s", name);

      printf("Hello, %s! ", name);
      break;
    case 2:
      printf("What is your favorite color?\n");

      char color[10];
      scanf("%s", color);

      if(strcmp(color, "blue") == 0) {
        printf("Great choice! Blue is a very calming color.\n");
      } else if(strcmp(color, "red") == 0) {
        printf("Red is a very passionate color!\n");
      } else if(strcmp(color, "green") == 0) {
        printf("Green is the color of growth and prosperity.\n");
      } else {
        printf("That's an interesting color choice.\n");
      }
      break;
    case 3:
      printf("What is your biggest fear?\n");

      char fear[50];
      scanf("%s", fear);

      printf("I understand, %s can be very scary. ", fear);
      break;
    case 4:
      printf("What is your biggest dream?\n");

      char dream[50];
      scanf("%s", dream);

      printf("That sounds like an amazing dream, %s! ", dream);
      break;
    default:
      printf("Invalid choice.\n");
      break;
  }

  int random_num = rand() % 10; // generates a random number between 0 and 9
  printf("Your fortune for the day is: %s\n", fortunes[random_num]);

  return 0;
}