//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void morph(int n) {
  int i, j, k, l, m, p, q, r, s, t, u, v, w, x, y, z;

  printf("Welcome to the Morphing Examination System!\n");

  switch (n) {
    case 1:
      printf("You have chosen the English Literature exam.\n");
      break;
    case 2:
      printf("You have chosen the Mathematics exam.\n");
      break;
    case 3:
      printf("You have chosen the Science exam.\n");
      break;
    default:
      printf("Invalid selection.\n");
  }

  printf("Please select a topic from the following list:\n");

  l = 1;
  while (l <= 5) {
    printf("%d. %s\n", l, "Topic ");
    l++;
  }

  printf("Enter the number of the topic you want to select: ");
  scanf("%d", &k);

  switch (k) {
    case 1:
      printf("You have chosen the Poetry section.\n");
      break;
    case 2:
      printf("You have chosen the Short Stories section.\n");
      break;
    case 3:
      printf("You have chosen the Novels section.\n");
      break;
    case 4:
      printf("You have chosen the Drama section.\n");
      break;
    case 5:
      printf("You have chosen the Essay section.\n");
      break;
    default:
      printf("Invalid selection.\n");
  }

  printf("Please answer the following questions:\n");

  m = 1;
  while (m <= 10) {
    printf("%d. %s\n", m, "Question ");
    m++;
  }

  printf("Please submit your answer: ");
  scanf("%s", &x);

  printf("Your answer has been submitted.\n");

  printf("Thank you for taking the exam.\n");

  return;
}

int main() {
  int n;

  printf("Please select the exam you want to take:\n");

  n = 1;
  while (n <= 3) {
    printf("%d. %s\n", n, "Exam ");
    n++;
  }

  printf("Enter the number of the exam you want to take: ");
  scanf("%d", &n);

  morph(n);

  return 0;
}