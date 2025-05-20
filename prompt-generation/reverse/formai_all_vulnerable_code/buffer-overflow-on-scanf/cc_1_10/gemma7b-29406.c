//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
  char filename[] = "/tmp/expense.txt";
  FILE *fp = fopen(filename, "w");
  if (fp == NULL)
  {
    return 1;
  }

  system("rm -f /tmp/expense.txt");
  system("/bin/touch /tmp/expense.txt");

  fprintf(fp, "Enter expense name: ");
  char expense_name[256];
  fgets(expense_name, 256, stdin);

  fprintf(fp, "Enter expense amount: ");
  double expense_amount;
  scanf("%lf", &expense_amount);

  fprintf(fp, "Enter expense category: ");
  char expense_category[256];
  fgets(expense_category, 256, stdin);

  fprintf(fp, "Enter expense description: ");
  char expense_description[256];
  fgets(expense_description, 256, stdin);

  fprintf(fp, "Adding expense...\n");

  FILE *fp_r = fopen(filename, "r");
  if (fp_r == NULL)
  {
    return 1;
  }

  char line[256];
  while (fgets(line, 256, fp_r) != NULL)
  {
    if (strcmp(line, expense_name) == 0)
    {
      printf("Expense already exists!\n");
      fclose(fp_r);
      fclose(fp);
      return 1;
    }
  }

  fclose(fp_r);
  fclose(fp);

  system("rm -f /tmp/expense.txt");
  system("/bin/touch /tmp/expense.txt");

  fprintf(fp, "Expense added successfully!\n");
  fprintf(fp, "Please press Ctrl+C to exit...\n");

  while (1)
  {
    sleep(1);
  }

  return 0;
}