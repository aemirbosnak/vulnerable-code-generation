//GEMINI-pro DATASET v1.0 Category: File handling ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  char *filename = "cyberpunk.txt";
  FILE *file = fopen(filename, "w");

  if (file == NULL) {
    printf("Error opening file %s", filename);
    return 1;
  }

  srand(time(NULL));

  for (int i = 0; i < 100; i++) {
    int random = rand() % 100;
    char *string = malloc(100);

    switch (random) {
      case 0:
        strcpy(string, "Wake up, samurai!");
        break;
      case 1:
        strcpy(string, "The streets are paved with neon.");
        break;
      case 2:
        strcpy(string, "The rain washes away the tears.");
        break;
      case 3:
        strcpy(string, "The city never sleeps.");
        break;
      case 4:
        strcpy(string, "The corporations control everything.");
        break;
      case 5:
        strcpy(string, "The people are just numbers.");
        break;
      case 6:
        strcpy(string, "The future is uncertain.");
        break;
      case 7:
        strcpy(string, "The past is a lie.");
        break;
      case 8:
        strcpy(string, "The truth is in the shadows.");
        break;
      case 9:
        strcpy(string, "The world is a simulation.");
        break;
      default:
        strcpy(string, "I am a lonely cyberpunk.");
        break;
    }

    fprintf(file, "%s\n", string);
    free(string);
  }

  fclose(file);

  return 0;
}