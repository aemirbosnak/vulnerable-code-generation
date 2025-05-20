//FormAI DATASET v1.0 Category: Database simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
  int id;
  char name[50];
  int marks;
} s;

int main() {
  FILE *fp;
  int choice, studentNo, i;
  char fileName[50];

  printf("Enter the name of the file: ");
  scanf("%s", fileName);

  fp = fopen(fileName, "wb+");
  
  if (fp == NULL) {
    printf("Error opening file.");
    exit(1);
  }

  while (1) {
    printf("\n1. Add Student\n2. Show Students\n3. Search Students\n4. Quit\n\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter Student ID: ");
        scanf("%d", &s.id);
        printf("Enter Student Name: ");
        scanf("%s", s.name);
        printf("Enter Student Marks: ");
        scanf("%d", &s.marks);

        fwrite(&s, sizeof(s), 1, fp);
        break;

      case 2:
        rewind(fp);
        printf("\n------------------------------\n");
        printf("Students in %s\n", fileName);
        printf("------------------------------\n");
        while (fread(&s, sizeof(s), 1, fp) == 1) 
          printf("\nID:%d\nName:%s\nMarks:%d\n", s.id, s.name, s.marks);
        printf("\n------------------------------\n");
        break;

      case 3:
        printf("Enter Student ID to search for: ");
        scanf("%d", &studentNo);
        rewind(fp);

        while (fread(&s, sizeof(s), 1, fp) == 1) {
          if (s.id == studentNo) {
            printf("\nID:%d\nName:%s\nMarks:%d\n", s.id, s.name, s.marks);
            break;
          }
        }
        if (s.id != studentNo) 
          printf("Student not found.\n");
        break;

      case 4:
        fclose(fp);
        exit(0);

      default:
        printf("Invalid choice!\n");
        break;
    }
  }
  return 0;
}