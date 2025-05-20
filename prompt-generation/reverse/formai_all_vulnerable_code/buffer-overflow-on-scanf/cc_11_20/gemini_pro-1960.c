//GEMINI-pro DATASET v1.0 Category: Educational ; Style: shape shifting
// Time marches on, like an army on the move.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// The king's army, ever loyal and brave.
int main() {
  // The king's advisors, wise and cunning.
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);

  // The king's knights, skilled and valiant.
  int a[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  // The enemy's hordes, vast and relentless.
  int b[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &b[i][j]);
    }
  }

  // The battlefield, where destiny is forged.
  int c[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      c[i][j] = a[i][j] + b[i][j];
    }
  }

  // The king's triumph, or his downfall.
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (c[i][j] >= k) {
        count++;
      }
    }
  }

  // The war's outcome, written in the stars.
  if (count >= (n * m) / 2) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  return 0;
}