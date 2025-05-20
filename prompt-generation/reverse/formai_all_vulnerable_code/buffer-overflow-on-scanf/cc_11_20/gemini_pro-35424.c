//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Welcome to the post-apocalyptic realm!

int main() {
  // Step 1: Scavenge for survivors (create matrices)
  int scavengers[3][4];  // A band of resourceful survivors
  int raiders[3][4];     // A ruthless gang lurking in the shadows

  // Step 2: Gather supplies (initialize matrices)
  printf("Survivors, gather your wits and supplies!\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      printf("Survivor %d, how many rations do you have?\n", i + 1);
      scanf("%d", &scavengers[i][j]);
    }
  }

  printf("Raiders, sharpen your knives and gather your loot!\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      printf("Raider %d, how much plunder do you carry?\n", i + 1);
      scanf("%d", &raiders[i][j]);
    }
  }

  printf("\n");

  // Step 3: Fight for survival (perform matrix operations)

  // 3a: Check for superiority with element-wise comparison
  printf("Survivors, assess the raiders' strength!\n");
  printf("Raiders, mock the survivors' weakness!\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      if (scavengers[i][j] > raiders[i][j]) {
        printf("Survivor %d: \"Ha! We outnumber you!\"\n", i + 1);
      } else if (scavengers[i][j] < raiders[i][j]) {
        printf("Raider %d: \"Pathetic! We'll crush you!\"\n", i + 1);
      } else {
        printf("Tie! We're evenly matched.\n");
      }
    }
  }

  printf("\n");

  // 3b: Calculate total supplies (matrix summation)
  int survivor_supplies = 0;
  int raider_supplies = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      survivor_supplies += scavengers[i][j];
      raider_supplies += raiders[i][j];
    }
  }

  printf("Survivors' total supplies: %d\n", survivor_supplies);
  printf("Raiders' total supplies: %d\n", raider_supplies);

  printf("\n");

  // Step 4: Redistribute resources (matrix transposition)
  printf("Survivors, share your supplies!\n");
  printf("Raiders, divide your loot!\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      int temp = scavengers[i][j];
      scavengers[i][j] = scavengers[j][i];
      scavengers[j][i] = temp;

      temp = raiders[i][j];
      raiders[i][j] = raiders[j][i];
      raiders[j][i] = temp;
    }
  }

  // Step 5: Rebuild (print transposed matrices)
  printf("Survivors' supplies after redistribution:\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%d ", scavengers[i][j]);
    }
    printf("\n");
  }

  printf("\n");
  printf("Raiders' loot after redistribution:\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%d ", raiders[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  // Conclusion:
  printf("In this post-apocalyptic world, we may be scarred and divided, but together we can survive and rebuild.\n");

  return 0;
}