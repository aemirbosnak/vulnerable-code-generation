//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BankingRecordSystem(char *filename) {
  FILE *fp = fopen(filename, "r");
  char line[1024];
  int account_no, i, j, k;
  float amount;
  char operation;

  if (fp == NULL) {
    fp = fopen(filename, "w");
  }

  printf("Enter account number: ");
  scanf("%d", &account_no);

  while (getline(fp, line, 1024) != NULL) {
    char *p = line;
    i = 0;
    k = 0;

    while (*p) {
      if (*p == account_no) {
        k++;
      } else if (*p == ' ' && k) {
        j++;
      }
      p++;
    }

    if (k) {
      printf("Operation: ");
      scanf("%c", &operation);
      amount = atof(stdin);

      switch (operation) {
        case 'D':
          fprintf(fp, "Debit: %f\n", amount);
          break;
        case 'C':
          fprintf(fp, "Credit: %f\n", amount);
          break;
        default:
          printf("Invalid operation.\n");
      }
    } else {
      printf("Account not found.\n");
    }
  }

  fclose(fp);
}

int main() {
  BankingRecordSystem("banking_records.txt");
  return 0;
}