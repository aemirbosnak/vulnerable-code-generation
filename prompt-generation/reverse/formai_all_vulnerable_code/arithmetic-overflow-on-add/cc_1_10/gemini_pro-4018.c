//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: curious
#include <stdio.h>
#include <stdlib.h>

void welcome() {
  printf("Welcome to the fortune teller! Prepare to be amazed!\n\n");
}

int get_age() {
  int age;
  printf("How old are you, my curious soul?\n");
  scanf("%d", &age);
  return age;
}

char* get_name() {
  char* name = malloc(20);
  printf("And what is your name, if I may ask?\n");
  scanf("%s", name);
  return name;
}

int get_birth_month() {
  int month;
  printf("Which month were you born, my dear? (Enter the number, 1 for January, 12 for December)\n");
  scanf("%d", &month);
  return month;
}

char* get_pet_name() {
  char* pet_name = malloc(20);
  printf("And what is the name of your beloved pet?\n");
  scanf("%s", pet_name);
  return pet_name;
}

void reveal_fortune(int age, char* name, int birth_month, char* pet_name) {
  printf("\nPrepare yourself, for your fortune is about to unfold...\n\n");
  printf("I see that you, %s, will live to the ripe old age of %d.\n", name, age + 10);
  printf("In the coming year, you will embark on a grand adventure to a faraway land.\n");
  printf("Along the way, you will encounter a wise old sage who will impart upon you the secrets of the universe.\n");
  printf("But beware, danger lurks in the shadows. A treacherous foe will attempt to thwart your plans.\n");
  printf("Fear not, for your loyal companion, %s, will stand by your side and protect you from harm.\n", pet_name);
  printf("Your birth month, %d, reveals that you are destined for greatness. You possess a unique gift that will lead you to success.\n", birth_month);
  printf("So go forth, %s, and embrace your destiny. The stars have aligned in your favor, and your future is bright!\n", name);
}

int main() {
  welcome();
  int age = get_age();
  char* name = get_name();
  int birth_month = get_birth_month();
  char* pet_name = get_pet_name();
  reveal_fortune(age, name, birth_month, pet_name);
  free(name);
  free(pet_name);
  return 0;
}