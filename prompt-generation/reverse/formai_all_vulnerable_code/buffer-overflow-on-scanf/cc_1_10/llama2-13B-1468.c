//LLAMA2-13B DATASET v1.0 Category: Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024
#define MAX_NAME_LENGTH 64

void generate_name(char *name) {
  int i, j;
  for (i = 0; i < MAX_NAME_LENGTH; i++) {
    j = rand() % 26 + 1;
    name[i] = (j + 'a');
  }
}

int main() {
  char name[MAX_NAME_LENGTH];
  generate_name(name);
  printf("Your name is: %s\n", name);

  int age;
  printf("Enter your age: ");
  scanf("%d", &age);
  printf("You are %d years old\n", age);

  int birthday;
  printf("Enter your birthday (mm/dd/yy): ");
  scanf("%d/%d/%d", &birthday, &birthday, &birthday);
  printf("Your birthday is: %d/%d/%d\n", birthday, birthday, birthday);

  int height;
  printf("Enter your height: ");
  scanf("%d", &height);
  printf("You are %d feet tall\n", height);

  int weight;
  printf("Enter your weight: ");
  scanf("%d", &weight);
  printf("You weigh %d pounds\n", weight);

  int eyes;
  printf("Enter your eye color: ");
  scanf("%d", &eyes);
  printf("You have %d eyes\n", eyes);

  int hair;
  printf("Enter your hair color: ");
  scanf("%d", &hair);
  printf("You have %d hair\n", hair);

  return 0;
}