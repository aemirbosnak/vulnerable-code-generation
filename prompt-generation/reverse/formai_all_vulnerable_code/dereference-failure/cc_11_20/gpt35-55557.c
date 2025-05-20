//FormAI DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
   int id;
   char name[50];
   float marks;
};

int main() {
   FILE * fp;
   int choice, count, id, i;
   char ch, filename[50];
   struct student s;

   printf("Enter filename to open: ");
   scanf("%s", filename);

   fp = fopen(filename, "rb");
   if (fp == NULL) {
      fp = fopen(filename, "wb");
      if (fp == NULL) {
         printf("Unable to create file.");
         exit(EXIT_FAILURE);
      }

      printf("File created successfully.\n");
      fclose(fp);
      fp = fopen(filename, "rb");
   }

   fseek(fp, 0, SEEK_END);
   count = ftell(fp) / sizeof(struct student);
   printf("There are %d students on record.\n", count);
   printf("Do you want to add, delete or view a student record?\n");
   printf("1.Add\n2.Delete\n3.View\nChoice: ");
   scanf("%d", &choice);

   switch (choice) {
      case 1:
         fp = fopen(filename, "ab");
         s.id = count + 1;
         printf("Enter name: ");
         fflush(stdin);
         gets(s.name);
         printf("Enter marks: ");
         scanf("%f", &s.marks);
         fwrite(&s, sizeof(struct student), 1, fp);
         printf("Student record added successfully.\n");
         fclose(fp);
         break;
      case 2:
         printf("Enter student ID to delete: ");
         scanf("%d", &id);
         fp = fopen(filename, "rb");
         FILE *fp1;
         fp1 = fopen("temp.txt", "wb");
         rewind(fp);
         while (fread(&s, sizeof(struct student), 1, fp) == 1) {
            if (s.id != id)
               fwrite(&s, sizeof(struct student), 1, fp1);
         }
         fclose(fp);
         fclose(fp1);
         remove(filename);
         rename("temp.txt", filename);
         printf("Student record deleted successfully.\n");
         break;
      case 3:
         printf("Enter student ID to view: ");
         scanf("%d", &id);
         fp = fopen(filename, "rb");
         while (fread(&s, sizeof(struct student), 1, fp) == 1) {
            if (s.id == id) {
               printf("ID   : %d\n", s.id);
               printf("Name : %s\n", s.name);
               printf("Marks: %.2f\n", s.marks);
               break;
            }
         }
         if (feof(fp))
            printf("Student record not found.\n");
         fclose(fp);
         break;
      default:
         printf("Invalid choice.\n");
         break;
   }

   return EXIT_SUCCESS;
}