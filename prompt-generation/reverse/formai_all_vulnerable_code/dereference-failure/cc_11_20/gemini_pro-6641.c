//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <regex.h>

#define MAX_DICE_SIDES 6
#define MAX_DICE_NUMBER 100
#define MAX_DICE_ROLLS 10000

int main(int argc, char *argv[]) {
  int num_dice = 0;
  int num_sides = 0;
  int num_rolls = 0;
  int seed = 0;
  char *dice_expr = NULL;
  regex_t regex;
  int reti;

  if (argc != 5) {
    fprintf(stderr, "Usage: %s <num_dice> <num_sides> <num_rolls> <seed>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  num_dice = atoi(argv[1]);
  num_sides = atoi(argv[2]);
  num_rolls = atoi(argv[3]);
  seed = atoi(argv[4]);

  if (num_dice <= 0 || num_dice > MAX_DICE_NUMBER) {
    fprintf(stderr, "Error: Number of dice must be between 1 and %d\n", MAX_DICE_NUMBER);
    exit(EXIT_FAILURE);
  }

  if (num_sides <= 0 || num_sides > MAX_DICE_SIDES) {
    fprintf(stderr, "Error: Number of sides per die must be between 1 and %d\n", MAX_DICE_SIDES);
    exit(EXIT_FAILURE);
  }

  if (num_rolls <= 0 || num_rolls > MAX_DICE_ROLLS) {
    fprintf(stderr, "Error: Number of rolls must be between 1 and %d\n", MAX_DICE_ROLLS);
    exit(EXIT_FAILURE);
  }

  if (seed <= 0) {
    fprintf(stderr, "Error: Seed must be a positive integer\n");
    exit(EXIT_FAILURE);
  }

  srand(seed);

  dice_expr = malloc(strlen(argv[1]) + strlen(argv[2]) + strlen(argv[3]) + strlen(argv[4]) + 5);
  if (dice_expr == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  sprintf(dice_expr, "%dd%d+%d", num_dice, num_sides, num_rolls);

  reti = regcomp(&regex, dice_expr, REG_EXTENDED);
  if (reti) {
    fprintf(stderr, "Error: Could not compile regular expression '%s'\n", dice_expr);
    exit(EXIT_FAILURE);
  }

  int fd = open("/dev/random", O_RDONLY);
  if (fd < 0) {
    perror("open");
    exit(EXIT_FAILURE);
  }

  char buf[1024];
  ssize_t nread = read(fd, buf, sizeof(buf));
  if (nread < 0) {
    perror("read");
    exit(EXIT_FAILURE);
  }

  close(fd);

  int i, j;
  for (i = 0; i < num_rolls; i++) {
    for (j = 0; j < num_dice; j++) {
      int roll = rand() % num_sides + 1;
      printf("%d ", roll);
    }

    printf("\n");
  }

  regfree(&regex);
  free(dice_expr);

  return EXIT_SUCCESS;
}