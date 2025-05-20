//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: standalone
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_DICE 1000
#define MAX_SIDES 1000

typedef struct _Die {
  int sides;
  int value;
} Die;

typedef struct _RollResult {
  int num_dice;
  int num_sides;
  int total;
  Die dice[MAX_DICE];
} RollResult;

void print_roll(RollResult *result) {
  int i;
  printf("Rolled %d dice with %d sides:\n", result->num_dice, result->num_sides);
  for (i = 0; i < result->num_dice; i++) {
    printf("%d ", result->dice[i].value);
  }
  printf("Total: %d\n", result->total);
}

RollResult roll_dice(int num_dice, int num_sides) {
  RollResult result;
  int i;
  for (i = 0; i < num_dice; i++) {
    result.dice[i].sides = num_sides;
    result.dice[i].value = rand() % num_sides + 1;
  }
  result.num_dice = num_dice;
  result.num_sides = num_sides;
  result.total = 0;
  for (i = 0; i < num_dice; i++) {
    result.total += result.dice[i].value;
  }
  return result;
}

int parse_int(char *str) {
  int result;
  char *endptr;

  result = (int)strtol(str, &endptr, 10);
  if (*endptr != '\0') {
    return -1;
  }
  return result;
}

int main(int argc, char *argv[]) {
  int num_dice, num_sides;
  RollResult result;
  if (argc != 3) {
    printf("Usage: %s <num_dice> <num_sides>\n", argv[0]);
    return 1;
  }

  num_dice = parse_int(argv[1]);
  if (num_dice < 1 || num_dice > MAX_DICE) {
    printf("Invalid number of dice: %s\n", argv[1]);
    return 1;
  }

  num_sides = parse_int(argv[2]);
  if (num_sides < 1 || num_sides > MAX_SIDES) {
    printf("Invalid number of sides: %s\n", argv[2]);
    return 1;
  }

  result = roll_dice(num_dice, num_sides);
  print_roll(&result);

  return 0;
}