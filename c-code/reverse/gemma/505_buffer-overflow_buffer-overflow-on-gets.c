#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  char name[20];
  char date[20];
  int secretCode;
  char alienType[20];
  int alienStrength;
  int probability;

  printf("Enter your name: ");
  scanf("%s", name);

  printf("Enter the date: ");
  scanf("%s", date);

  printf("Enter your secret code: ");
  scanf("%d", &secretCode);

  printf("Enter the alien type: ");
  scanf("%s", alienType);

  printf("Enter the alien strength: ");
  scanf("%d", &alienStrength);

  srand(time(NULL));
  probability = rand() % 100;

  if (secretCode == 123) {
    if (probability < 20) {
      printf("Risk assessment: Low.\n");
    } else if (probability >= 20 && probability < 50) {
      printf("Risk assessment: Moderate.\n");
    } else {
      printf("Risk assessment: High.\n");
    }
  } else {
    printf("Error: Invalid secret code.\n");
  }

  return 0;
}
