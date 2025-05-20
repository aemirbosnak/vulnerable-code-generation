//FormAI DATASET v1.0 Category: Educational ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the Medieval C Programming Adventure!\n");
  printf("Your task is to input the amount of peasants needed to collect the harvest.\n");

  int peasants;
  scanf("%d", &peasants);

  if (peasants <= 0) {
    printf("The harvest cannot be collected without peasants. Try again.\n");
    return 0;
  }

  printf("The Lord of the Manor has dispatched %d peasants to collect the harvest. They set off early in the morning with their wooden carts and pitchforks in hand.\n", peasants);
  printf("As they arrived at the fields, they began to work tirelessly. They gathered the ripe wheat, barley, and oats into their carts.\n");

  int wheat = 0;
  int barley = 0;
  int oats = 0;
  int amount = 0;
  
  for (int i = 1; i <= peasants; i++) {
    amount = rand() % 10 + 1;
    wheat += amount;
    amount = rand() % 10 + 1;
    barley += amount;
    amount = rand() % 10 + 1;
    oats += amount;
  }

  printf("After a long day's work, the peasants return to the manor with their harvest. They have collected:\n");
  printf("- %d bushels of wheat\n", wheat);
  printf("- %d bushels of barley\n", barley);
  printf("- %d bushels of oats\n", oats);

  printf("The Lord of the Manor is pleased with their work and grants each peasant a sum of gold equivalent to the amount they collected. Their daily wage was %d gold coins per bushel.\n", 5);

  int total_gold = 0;
  int wage = 5;
  total_gold += wheat * wage;
  total_gold += barley * wage;
  total_gold += oats * wage;

  printf("The total amount of gold spent on peasant wages is %d gold coins.\n", total_gold);

  printf("Thank you for participating in the Medieval C Programming Adventure! Fare thee well.\n");

  return 0;
}