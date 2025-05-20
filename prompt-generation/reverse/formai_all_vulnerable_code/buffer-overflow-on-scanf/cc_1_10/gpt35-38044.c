//FormAI DATASET v1.0 Category: Graph representation ; Style: inquisitive
#include <stdio.h>

int main() {
  // Let's find out what the user wants to represent using a C graph
  printf("What would you like to represent using a C graph?\n");
  char user_input[100];
  scanf("%s", user_input);

  // First let's print the header of the graph
  printf("Here is a C graph representing %s:\n\n", user_input);
  printf("          |\n");
  printf("     /    |    \\\n");
  printf("    /     |     \\\n");
  printf("   /      |      \\\n");
  printf("  /       |       \\\n");
  printf(" /        |        \\\n");
  printf("|-------------------|\n");

  // Let's ask the user how many data points they want to input
  printf("How many data points do you want to input?\n");
  int num_data_points;
  scanf("%d", &num_data_points);

  // Make sure the user inputs a reasonable number of data points
  if (num_data_points <= 0) {
    printf("Invalid number of data points. Please input a positive integer.\n");
    return 0;
  }

  // Let's ask the user to input the data points
  int data_points[num_data_points];
  printf("Please input %d data points:\n", num_data_points);
  for (int i = 0; i < num_data_points; i++) {
    scanf("%d", &data_points[i]);
  }

  // Let's find the maximum value among the data points
  int max_value = data_points[0];
  for (int i = 1; i < num_data_points; i++) {
    if (data_points[i] > max_value) {
      max_value = data_points[i];
    }
  }

  // Let's find out how many units each * should represent on the graph
  int units_per_ast = max_value / 10;

  // Let's print the data points on the graph
  for (int i = 0; i < num_data_points; i++) {
    printf("%2d |", data_points[i]);
    int num_asts = data_points[i] / units_per_ast;
    for (int j = 0; j < num_asts; j++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}