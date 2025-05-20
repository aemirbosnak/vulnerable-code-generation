//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void intrude(char **arr, int n) {
  printf("Inserting myself into your memory...\n");
  arr = (char *)realloc(arr, n * sizeof(char) * 2);
  arr[n] = '\0';
  arr[n-1] = ' ';
  printf("I've expanded your memory and inserted a space. You're welcome.\n");
}

int main() {
  char *arr = NULL;
  int n = 0;
  char op;

  printf("Please enter the number of operations you want to perform: ");
  scanf("%d", &n);

  arr = (char *)malloc(n * sizeof(char));

  for (int i = 0; i < n; i++) {
    printf("Enter the operation you want to perform: ");
    scanf(" %c", &op);

    switch (op) {
      case '+':
        intrude(&arr, n);
        printf("Enter the two operands: ");
        scanf("%f %f", &arr[n-1], &arr[n]);
        arr = (char *)realloc(arr, n * sizeof(char) * 2);
        arr[n] = '\0';
        arr[n-1] = ' ';
        printf("The result is: %.2f\n", arr[n-2] + arr[n-1]);
        break;
      case '-':
        intrude(&arr, n);
        printf("Enter the two operands: ");
        scanf("%f %f", &arr[n-1], &arr[n]);
        arr = (char *)realloc(arr, n * sizeof(char) * 2);
        arr[n] = '\0';
        arr[n-1] = ' ';
        printf("The result is: %.2f\n", arr[n-2] - arr[n-1]);
        break;
      case '*':
        intrude(&arr, n);
        printf("Enter the two operands: ");
        scanf("%f %f", &arr[n-1], &arr[n]);
        arr = (char *)realloc(arr, n * sizeof(char) * 2);
        arr[n] = '\0';
        arr[n-1] = ' ';
        printf("The result is: %.2f\n", arr[n-2] * arr[n-1]);
        break;
      case '/':
        intrude(&arr, n);
        printf("Enter the two operands: ");
        scanf("%f %f", &arr[n-1], &arr[n]);
        arr = (char *)realloc(arr, n * sizeof(char) * 2);
        arr[n] = '\0';
        arr[n-1] = ' ';
        printf("The result is: %.2f\n", arr[n-2] / arr[n-1]);
        break;
    }
  }

  return 0;
}