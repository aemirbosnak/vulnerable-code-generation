//FormAI DATASET v1.0 Category: Database simulation ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student { //declaring a structure to hold student data
   int roll_no;
   char name[20];
   int age;
};

int main() {
   struct student s[50];
   int n, i, choice, roll, flag = 0;
   FILE *fp; //declaring file pointer to read and write data to file

   while(1) {
      printf("\n1. Add a student record\n2. Display all student records\n3. Search for a student record\n4. Modify a student record\n5. Delete a student record\n6. Exit\nEnter your choice: ");
      scanf("%d", &choice);

      switch(choice) {
         case 1: //Adding data to file using fwrite function
            fp = fopen("students.txt", "ab");
            printf("\nEnter number of students you want to add: ");
            scanf("%d", &n);
            for(i=0; i<n; i++) {
               printf("\nEnter Roll No, Name and Age of student %d: ", i+1);
               scanf("%d %s %d", &s[i].roll_no, s[i].name, &s[i].age);
               fwrite(&s[i], sizeof(struct student), 1, fp);
            }
            printf("\nData added successfully!");
            fclose(fp);
            break;

         case 2: //Displaying data from file using fread function
            fp = fopen("students.txt", "rb");
            if(fp == NULL) {
               printf("\nFile not found!");
               exit(1);
            }
            printf("\nStudent Records:\n");
            while(fread(&s, sizeof(struct student), 1, fp)) {
               printf("\nRoll No: %d\nName: %s\nAge: %d\n", s[0].roll_no, s[0].name, s[0].age);
            }
            fclose(fp);
            break;

         case 3: //Searching for a student record using fread function
            fp = fopen("students.txt", "rb");
            if(fp == NULL) {
               printf("\nFile not found!");
               exit(1);
            }
            printf("\nEnter roll no you want to search: ");
            scanf("%d", &roll);
            while(fread(&s, sizeof(struct student), 1, fp)) {
               if(s[0].roll_no == roll) {
                  printf("\nRoll No: %d\nName: %s\nAge: %d\n", s[0].roll_no, s[0].name, s[0].age);
                  flag = 1;
                  break;
               }
            }
            if(flag == 0) {
               printf("\nRecord not found!");
            }
            fclose(fp);
            break;

         case 4: //Modifying a student record using fwrite function
            fp = fopen("students.txt", "r+b");
            if(fp == NULL) {
               printf("\nFile not found!");
               exit(1);
            }
            printf("\nEnter roll no you want to modify: ");
            scanf("%d", &roll);
            while(fread(&s, sizeof(struct student), 1, fp)) {
               if(s[0].roll_no == roll) {
                  printf("\nEnter new Roll No, Name and Age of student: ");
                  scanf("%d %s %d", &s[0].roll_no, s[0].name, &s[0].age);
                  fseek(fp, -sizeof(struct student), SEEK_CUR);
                  fwrite(&s, sizeof(struct student), 1, fp);
                  flag = 1;
                  break;
               }
            }
            if(flag == 0) {
               printf("\nRecord not found!");
            } else {
               printf("\nData modified successfully!");
            }
            fclose(fp);
            break;

         case 5: //Deleting a student record using fread and fwrite function
            fp = fopen("students.txt", "r+b");
            if(fp == NULL) {
               printf("\nFile not found!");
               exit(1);
            }
            printf("\nEnter roll no you want to delete: ");
            scanf("%d", &roll);
            i = 0;
            while(fread(&s[i], sizeof(struct student), 1, fp)) {
               if(s[i].roll_no == roll) {
                  while(fread(&s[i+1], sizeof(struct student), 1, fp)) {
                     s[i] = s[i+1];
                     i++;
                  }
                  fseek(fp, -sizeof(struct student)*i, SEEK_CUR);
                  fwrite(&s[0], sizeof(struct student)*(i+1), 1, fp);
                  flag = 1;
                  break;
               }
               i++;
            }
            if(flag == 0) {
               printf("\nRecord not found!");
            } else {
               printf("\nData deleted successfully!");
            }
            fclose(fp);
            break;

         case 6: //Exiting the program
            exit(0);

         default: //Invalid input
            printf("\nInvalid choice! Please try again.");
            break;
      }
   }
   return 0;
}