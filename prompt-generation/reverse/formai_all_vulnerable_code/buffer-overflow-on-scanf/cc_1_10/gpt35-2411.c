//FormAI DATASET v1.0 Category: Data recovery tool ; Style: multiplayer
// C Data recovery tool
// Multiplayer style

#include <stdio.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_SIZE 100

int main() {
  // Declare variables
  char filenames[MAX_FILES][MAX_SIZE];
  int num_files;
  char search_term[MAX_SIZE];
  int player_score[MAX_FILES];
  int highest_score = 0;
  int winner_index = -1;

  // Prompt for number of files to recover data from
  printf("Enter number of files to recover data from (up to %d): ", MAX_FILES);
  scanf("%d", &num_files);

  // Prompt for filenames and initialize scores to 0
  for (int i = 0; i < num_files; i++) {
    printf("Enter filename for file %d: ", i+1);
    scanf("%s", filenames[i]);
    player_score[i] = 0;
  }

  // Prompt for search term
  printf("Enter the search term: ");
  scanf("%s", search_term);

  // Search for the search term in each file and update player scores
  for (int i = 0; i < num_files; i++) {
    FILE* fp = fopen(filenames[i], "r");
    char line[MAX_SIZE];
    while (fgets(line, MAX_SIZE, fp)) {
      if (strstr(line, search_term)) {
        player_score[i]++;
      }
    }
    fclose(fp);
  }

  // Determine highest score and winner
  for (int i = 0; i < num_files; i++) {
    if (player_score[i] > highest_score) {
      highest_score = player_score[i];
      winner_index = i;
    }
  }

  // Print results
  printf("Results:\n");
  for (int i = 0; i < num_files; i++) {
    printf("%s: %d\n", filenames[i], player_score[i]);
  }
  printf("The winner is: %s with a score of %d\n", filenames[winner_index], highest_score);

  return 0;
}