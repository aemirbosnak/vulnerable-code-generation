#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char name[100];
  FILE *fp;
  int roll_no;
  int marks;

  printf("Enter file name:");
  scanf("%s", name);

  fp = fopen(name, "r");
  if (fp == NULL) {
    printf("Error opening file");
    return 1;
  }

  fscanf(fp, "%d %s %d", &roll_no, name, &marks);
  fclose(fp);

  printf("Roll no: %d\n", roll_no);
  printf("Name: %s\n", name);
  printf("Marks: %d\n", marks);

  return 0;
}
