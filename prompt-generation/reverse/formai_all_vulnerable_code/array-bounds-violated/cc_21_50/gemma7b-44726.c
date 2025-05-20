//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(NULL));

  int num1 = rand() % 11;
  int num2 = rand() % 11;
  int num3 = rand() % 11;

  char oracle_answer[20] = "Your future is ";

  switch (num1)
  {
    case 0:
      oracle_answer[20] = oracle_answer[20] + 'A';
      break;
    case 1:
      oracle_answer[20] = oracle_answer[20] + 'B';
      break;
    case 2:
      oracle_answer[20] = oracle_answer[20] + 'C';
      break;
    case 3:
      oracle_answer[20] = oracle_answer[20] + 'D';
      break;
    case 4:
      oracle_answer[20] = oracle_answer[20] + 'E';
      break;
    case 5:
      oracle_answer[20] = oracle_answer[20] + 'F';
      break;
    case 6:
      oracle_answer[20] = oracle_answer[20] + 'G';
      break;
    case 7:
      oracle_answer[20] = oracle_answer[20] + 'H';
      break;
    case 8:
      oracle_answer[20] = oracle_answer[20] + 'I';
      break;
    case 9:
      oracle_answer[20] = oracle_answer[20] + 'J';
      break;
    case 10:
      oracle_answer[20] = oracle_answer[20] + 'K';
      break;
  }

  switch (num2)
  {
    case 0:
      oracle_answer[20] = oracle_answer[20] + 'A';
      break;
    case 1:
      oracle_answer[20] = oracle_answer[20] + 'B';
      break;
    case 2:
      oracle_answer[20] = oracle_answer[20] + 'C';
      break;
    case 3:
      oracle_answer[20] = oracle_answer[20] + 'D';
      break;
    case 4:
      oracle_answer[20] = oracle_answer[20] + 'E';
      break;
    case 5:
      oracle_answer[20] = oracle_answer[20] + 'F';
      break;
    case 6:
      oracle_answer[20] = oracle_answer[20] + 'G';
      break;
    case 7:
      oracle_answer[20] = oracle_answer[20] + 'H';
      break;
    case 8:
      oracle_answer[20] = oracle_answer[20] + 'I';
      break;
    case 9:
      oracle_answer[20] = oracle_answer[20] + 'J';
      break;
    case 10:
      oracle_answer[20] = oracle_answer[20] + 'K';
      break;
  }

  switch (num3)
  {
    case 0:
      oracle_answer[20] = oracle_answer[20] + 'A';
      break;
    case 1:
      oracle_answer[20] = oracle_answer[20] + 'B';
      break;
    case 2:
      oracle_answer[20] = oracle_answer[20] + 'C';
      break;
    case 3:
      oracle_answer[20] = oracle_answer[20] + 'D';
      break;
    case 4:
      oracle_answer[20] = oracle_answer[20] + 'E';
      break;
    case 5:
      oracle_answer[20] = oracle_answer[20] + 'F';
      break;
    case 6:
      oracle_answer[20] = oracle_answer[20] + 'G';
      break;
    case 7:
      oracle_answer[20] = oracle_answer[20] + 'H';
      break;
    case 8:
      oracle_answer[20] = oracle_answer[20] + 'I';
      break;
    case 9:
      oracle_answer[20] = oracle_answer[20] + 'J';
      break;
    case 10:
      oracle_answer[20] = oracle_answer[20] + 'K';
      break;
  }

  printf("%s", oracle_answer);

  return 0;
}