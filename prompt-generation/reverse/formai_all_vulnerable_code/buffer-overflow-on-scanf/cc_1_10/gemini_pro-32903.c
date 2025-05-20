//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: inquisitive
#include <stdio.h>

void meow(int times) {
  while (times--) {
    printf("Meow! ");
  }
}

void purr(int duration) {
  for (int i = 0; i < duration; i++) {
    printf("Purr");
  }
}

void hiss(int volume) {
  for (int i = 0; i < volume; i++) {
    printf("Hiss!");
  }
}

void cuddle(int intensity) {
  for (int i = 0; i < intensity; i++) {
    printf("Cuddle!");
  }
}

int main() {
  int wake_up_time;
  printf("What time did you wake up, little one? ");
  scanf("%d", &wake_up_time);

  if (wake_up_time < 4) {
    meow(1);
    hiss(3);
    printf("I'm not ready to get up yet! Go back to sleep!");
  } else if (wake_up_time < 7) {
    meow(2);
    printf("Good morning! Let's cuddle!");
  } else {
    meow(4);
    purr(10);
    printf("I'm all ready for the day! Let's go!");
  }

  int playtime;
  printf("How much playtime would you like today? ");
  scanf("%d", &playtime);

  if (playtime < 10) {
    printf("That's not enough playtime! I want at least 10 minutes!");
  } else if (playtime > 30) {
    printf("I don't have that much time! Let's keep it under 30 minutes.");
  } else {
    printf("Purrfect! Let's play!");
  }

  int food_rating;
  printf("How would you rate your food today? (1-10) ");
  scanf("%d", &food_rating);

  if (food_rating < 5) {
    hiss(5);
    printf("This food is terrible! Don't feed me this again!");
  } else if (food_rating > 8) {
    purr(10);
    printf("This food is amazing! Can I have more please?");
  } else {
    printf("It's okay. Thanks for the food!");
  }

  int bedtime;
  printf("What time do you want to go to bed? ");
  scanf("%d", &bedtime);

  if (bedtime < 9) {
    hiss(3);
    printf("I'm not tired yet! I want to stay up longer!");
  } else if (bedtime > 11) {
    meow(1);
    printf("I'm really tired. Can we go to bed now?");
  } else {
    purr(5);
    printf("Good night! I'll see you in the morning!");
  }

  return 0;
}