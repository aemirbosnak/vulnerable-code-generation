//FormAI DATASET v1.0 Category: Matrix operations ; Style: mind-bending
/* Welcome to the Matrix operations program. 
 * This is not your ordinary matrix program. 
 * Brace yourself for a mind-bending experience. 
 * Follow the instructions carefully to get the best results. 
 * Good luck.
 */

#include <stdio.h>

int main() {
  int matrix[10][10], result[10][10], row, col, i, j, k, choice;
  char operator;

  printf("\nHello there! Are you ready for the Matrix challenge? (enter 1 for Yes, 0 for No): ");
  scanf("%d", &choice);

  if(choice == 0) {
    printf("\nYou're no fun. Bye!");
    return 0;
  } else if(choice != 1) {
    printf("\nInvalid input. Terminating program.");
    return 0;
  }

  printf("\nFirst, let's enter the dimensions of your matrix (max size 10x10).");
  printf("\nEnter the number of rows: ");
  scanf("%d", &row);
  printf("\nEnter the number of columns: ");
  scanf("%d", &col);

  printf("\nGreat! Now, you are going to enter your matrix element by element.");
  printf("\nBut... here comes the tricky part. You have to use only odd numbers between 1-99, and you have to use each odd number only once in the matrix.\nAre you ready? (enter 1 for Yes, 0 for No): ");
  scanf("%d", &choice);

  if(choice == 0) {
    printf("\nYou're no fun. Bye!");
    return 0;
  } else if(choice != 1) {
    printf("\nInvalid input. Terminating program.");
    return 0;
  }

  printf("\nStart entering your matrix elements:");

  for(i = 0; i < row; i++) {
    for(j = 0; j < col; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }

  int sum = 0;
  for(k = 1; k < 10; k += 2) {
    for(i = 0; i < row; i++) {
      for(j = 0; j < col; j++) {
        if(matrix[i][j] == k) {
          sum += matrix[i][j];
        }
      }
    }
  }

  printf("\nFascinating! Now let's move on to the next step.");
  printf("\nYou are going to choose an operator (+, -, *, /) to perform an operation on your matrix elements.");
  printf("\nBut... here comes the second tricky part. You have to choose an operator by entering a letter that corresponds to an odd number from the ASCII chart.\nAre you ready? (enter 1 for Yes, 0 for No): ");
  scanf("%d", &choice);

  if(choice == 0) {
    printf("\nYou're no fun. Bye!");
    return 0;
  } else if(choice != 1) {
    printf("\nInvalid input. Terminating program.");
    return 0;
  }

  printf("\nEnter an operator (+, -, *, /): ");
  scanf(" %c", &operator);

  switch(operator) {
    case 'U':
      operator = '+';
      break;
    case 'W':
      operator = '-';
      break;
    case 'Y':
      operator = '*';
      break;
    case '[':
      operator = '/';
      break;
    default:
      printf("\nInvalid operator. Terminating program.");
      return 0;
  }

  printf("\nIncredible! Now, we will perform the operation on the matrix.");

  for(i = 0; i < row; i++) {
    for(j = 0; j < col; j++) {
      switch(operator) {
        case '+':
          result[i][j] = matrix[i][j] + sum;
          break;
        case '-':
          result[i][j] = matrix[i][j] - sum;
          break;
        case '*':
          result[i][j] = matrix[i][j] * sum;
          break;
        case '/':
          result[i][j] = matrix[i][j] / sum;
          break;
        default:
          printf("\nInvalid operator. Terminating program.");
          return 0;
      }
    }
  }

  printf("\nLast but not least, let's display the result matrix.");

  for(i = 0; i < row; i++) {
    printf("\n");
    for(j = 0; j < col; j++) {
      printf("%d ", result[i][j]);
    }
  }

  printf("\n\nCongratulations! You have successfully completed the Matrix challenge. Thank you for playing.\n");

  return 0;
}