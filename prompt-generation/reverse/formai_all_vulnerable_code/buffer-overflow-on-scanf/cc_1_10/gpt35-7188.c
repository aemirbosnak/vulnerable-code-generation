//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surrealist
#include <stdio.h>
#include <string.h>

// Define a function for calculating the Levenshtein distance
int levenshteinDistance(char *str1, char *str2) {

  int len1 = strlen(str1); // Get the length of the first string
  int len2 = strlen(str2); // Get the length of the second string
  int dist[len1 + 1][len2 + 1]; // Create a 2D array for storing the distances

  // Fill in the top row and left column of the distances array
  for (int i = 0; i <= len1; i++) {
    dist[i][0] = i;
  }
  for (int j = 0; j <= len2; j++) {
    dist[0][j] = j;
  }

  // Calculate the distances for the rest of the array
  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      int substitutionCost = 0;
      if (str1[i - 1] != str2[j - 1]) {
        substitutionCost = 1;
      }
      int insertionCost = dist[i][j - 1] + 1;
      int deletionCost = dist[i - 1][j] + 1;
      int substitutionOrNothingCost = dist[i - 1][j - 1] + substitutionCost;
      dist[i][j] = fmin(fmin(insertionCost, deletionCost), substitutionOrNothingCost); // Compute the minimum cost
    }
  }

  return dist[len1][len2]; // Return the final distance
}

int main() {

  char str1[50], str2[50];

  printf("Welcome to the Levenshtein Distance Calculator! Please enter two strings:\n");
  fgets(str1, sizeof(str1), stdin);
  strtok(str1, "\n"); // Remove the newline character from the end of the first string
  fgets(str2, sizeof(str2), stdin);
  strtok(str2, "\n"); // Remove the newline character from the end of the second string

  int distance = levenshteinDistance(str1, str2); // Calculate the distance
  printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", str1, str2, distance);

  printf("Do you want to compute the distance for another pair of strings? (Y/N)\n");
  char response;
  scanf("%c", &response);
  if (response == 'Y' || response == 'y') {
    getchar(); // Consume the newline character left by scanf
    main(); // Call the main function recursively
  } else {
    printf("Thank you for using the Levenshtein Distance Calculator!\n");
  }

  return 0; // Return 0 to indicate successful completion of the program
}