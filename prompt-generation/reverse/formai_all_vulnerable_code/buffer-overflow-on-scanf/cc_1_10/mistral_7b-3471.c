//MISTRAL-7B DATASET v1.0 Category: Memory Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_SEQUENCE_LENGTH 2
#define MAX_SEQUENCE_LENGTH 10

void print_sequence(int *sequence, int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", sequence[i]);
  }
  printf("\n");
}

void generate_sequence(int *sequence, int *length) {
  *length = rand() % (MAX_SEQUENCE_LENGTH - MIN_SEQUENCE_LENGTH + 1) + MIN_SEQUENCE_LENGTH;
  for (int i = 0; i < *length; i++) {
    sequence[i] = rand() % 100 + 1;
  }
}

int main() {
  int sequence[MAX_SEQUENCE_LENGTH];
  int length, user_input, i;

  srand(time(NULL));

  printf("Welcome to The Memorizer, the memory game that will test your skills!\n");
  printf("Your goal is to remember and repeat sequences of random numbers in ascending order.\n");
  printf("Press enter to start.\n");
  getchar();

  generate_sequence(sequence, &length);
  printf("Here is your sequence: \n");
  print_sequence(sequence, length);

  for (i = 0; i < length; i++) {
    printf("Enter the number %d in the sequence: ", i + 1);
    scanf("%d", &user_input);

    if (user_input != sequence[i]) {
      printf("Sorry, that is incorrect. The correct answer was %d.\n", sequence[i]);
      i = length;
      break;
    }
  }

  if (i == length) {
    printf("Congratulations! You have successfully remembered and repeated the entire sequence.\n");
  }

  return 0;
}