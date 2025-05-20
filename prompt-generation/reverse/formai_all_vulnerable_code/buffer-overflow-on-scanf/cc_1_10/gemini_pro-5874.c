//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A Montague and Capulet "Romeo and Juliet" style searching algorithm

// Declare the Montagues and Capulets
char *Montagues[] = {"Romeo", "Juliet", "Tybalt", "Mercutio", "Benvolio"};
char *Capulets[] = {"Paris", "Lord Capulet", "Lady Capulet", "Nurse", "Friar Laurence"};

// Declare the search function
int search(char **family, char *name, int start, int end) {
  // Base case: the search has reached the end of the array
  if (start > end) {
    return -1;
  }

  // Calculate the middle index
  int middle = (start + end) / 2;

  // Compare the search name to the middle name
  int comparison = strcmp(name, family[middle]);

  // If the search name is equal to the middle name, the search is successful
  if (comparison == 0) {
    return middle;
  }

  // If the search name is less than the middle name, the search continues in the first half of the array
  else if (comparison < 0) {
    return search(family, name, start, middle - 1);
  }

  // If the search name is greater than the middle name, the search continues in the second half of the array
  else {
    return search(family, name, middle + 1, end);
  }
}

// Declare the main function
int main() {
  // Prompt the user to enter a name to search for
  printf("Enter a name to search for: ");
  char name[256];
  scanf("%s", name);

  // Search for the name in the Montagues
  int montagueIndex = search(Montagues, name, 0, sizeof(Montagues) / sizeof(char *));

  // Search for the name in the Capulets
  int capuletIndex = search(Capulets, name, 0, sizeof(Capulets) / sizeof(char *));

  // Print the results of the search
  if (montagueIndex >= 0) {
    printf("%s is a Montague.\n", name);
  } else if (capuletIndex >= 0) {
    printf("%s is a Capulet.\n", name);
  } else {
    printf("%s is not a Montague or Capulet.\n", name);
  }

  return 0;
}