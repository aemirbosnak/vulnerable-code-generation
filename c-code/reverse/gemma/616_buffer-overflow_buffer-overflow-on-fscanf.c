#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
  char name[50];
  int roll_no;
  float marks;
} Student;

int main() {
  Student students[100];
  FILE *fp = fopen("student_records.txt", "r");
  fscanf(fp, "%d", &students[0].roll_no);
  fclose(fp);

  return 0;
}
