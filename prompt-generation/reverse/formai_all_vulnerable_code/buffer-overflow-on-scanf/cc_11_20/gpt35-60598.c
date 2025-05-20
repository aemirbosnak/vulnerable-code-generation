//FormAI DATASET v1.0 Category: Database simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
   int id;
   char name[20];
   int age;
   float gpa;
};

int main() {
   FILE *fp;
   struct student s, s1;
   char file_name[20], name[20], ch;
   int id, age, choice, found = 0, to_delete;

   printf("Enter file name: ");
   scanf("%s", file_name);

   fp = fopen(file_name, "w+b");
   if (fp == NULL) {
      printf("Cannot open file\n");
      exit(1);
   }

   do {
      printf("\n1. Add a record\n2. Search a record\n3. Delete a record\n4. Display all records\n5. Exit\n");
      printf("\nEnter your choice: ");
      scanf("%d", &choice);

      switch (choice) {
         case 1:
            printf("\nEnter student ID, name, age, GPA: ");
            scanf("%d %s %d %f", &s.id, s.name, &s.age, &s.gpa);
            fwrite(&s, sizeof(struct student), 1, fp);
            break;

         case 2:
            printf("\nEnter student name to search: ");
            scanf("%s", name);
            rewind(fp);
            while (fread(&s1, sizeof(struct student), 1, fp) == 1) {
               if (strcmp(s1.name, name) == 0) {
                  printf("\nRecord found!\nID: %d\nName: %s\nAge: %d\nGPA: %.2f\n", s1.id, s1.name, s1.age, s1.gpa);
                  found = 1;
                  break;
               }
            }
            if (found == 0)
               printf("\nRecord not found!\n");
            break;

         case 3:
            printf("\nEnter student ID to delete: ");
            scanf("%d", &to_delete);
            rewind(fp);
            while (fread(&s1, sizeof(struct student), 1, fp) == 1) {
               if (s1.id != to_delete)
                  fwrite(&s1, sizeof(struct student), 1, fp);
               else
                  found = 1;
            }
            if (found == 0)
               printf("\nRecord not found!\n");
            else
               printf("\nRecord deleted successfully!\n");
            break;

         case 4:
            rewind(fp);
            printf("\nID\tName\tAge\tGPA\n");
            while (fread(&s1, sizeof(struct student), 1, fp) == 1) {
               printf("%d\t%s\t%d\t%.2f\n", s1.id, s1.name, s1.age, s1.gpa);
            }
            break;

         case 5:
            fclose(fp);
            exit(0);

         default:
            printf("\nInvalid choice!\n");
      }

      printf("\nDo you want to continue? (y/n): ");
      scanf(" %c", &ch);
   } while (ch == 'y' || ch == 'Y');

   fclose(fp);
   return 0;
}