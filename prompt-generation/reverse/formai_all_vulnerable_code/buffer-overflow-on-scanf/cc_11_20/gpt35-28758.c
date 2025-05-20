//FormAI DATASET v1.0 Category: Data validation ; Style: excited
#include<stdio.h>
#include<ctype.h>
#define SIZE 100

int main() {
  char str[SIZE];
  int intVar;
  float floatVar;
  double doubleVar;
  
  // Get input from user
  printf("Enter a string: ");
  fgets(str, SIZE, stdin);
  
  // Remove newline character
  str[strcspn(str, "\n")] = 0;
  
  // Validate string input
  int valid = 1;
  for (int i = 0; i < strlen(str); i++) {
    if (!isalpha(str[i]) && str[i] != ' ') {
      valid = 0;
      break;
    }
  }
  if (!valid) {
    printf("Invalid input! Only alphabets and spaces allowed.\n");
    return 0;
  }
  
  // Get integer input from user
  printf("Enter an integer: ");
  scanf("%d", &intVar);
  while (getchar() != '\n');
  
  // Validate integer input
  if (intVar < 0 || intVar > 100) {
    printf("Invalid input! Only integers between 0 and 100 allowed.\n");
    return 0;
  }
  
  // Get float input from user
  printf("Enter a float: ");
  scanf("%f", &floatVar);
  while (getchar() != '\n');
  
  // Validate float input
  if (floatVar < 0 || floatVar > 10) {
    printf("Invalid input! Only floats between 0 and 10 allowed.\n");
    return 0;
  }
  
  // Get double input from user
  printf("Enter a double: ");
  scanf("%lf", &doubleVar);
  while (getchar() != '\n');
  
  // Validate double input
  if (doubleVar < 0 || doubleVar > 10000) {
    printf("Invalid input! Only doubles between 0 and 10000 allowed.\n");
    return 0;
  }
  
  // Display validated inputs
  printf("String: %s\n", str);
  printf("Integer: %d\n", intVar);
  printf("Float: %f\n", floatVar);
  printf("Double: %lf\n", doubleVar);
  
  return 0;
}