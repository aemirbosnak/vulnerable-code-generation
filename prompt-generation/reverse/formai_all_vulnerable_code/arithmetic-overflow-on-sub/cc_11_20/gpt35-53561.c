//FormAI DATASET v1.0 Category: Database simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

struct student {
   int rollno;
   char name[50];
   float marks;
};

int main() {
   int num, i, j;
   printf("Enter the number of students: ");
   scanf("%d", &num);

   struct student* arr;
   arr = (struct student*) malloc(num * sizeof(struct student));

   for (i = 0; i < num; ++i) {
      printf("Enter Rollno and Name and Marks:\n");
      scanf("%d", &(arr+i)->rollno);
      scanf("%s", (arr+i)->name);
      scanf("%f", &(arr+i)->marks);
   }

   printf("\nDisplaying Information:\n\n");
   for (i = 0; i < num; ++i) {
      printf("Roll no.%d\n", (arr+i)->rollno);
      printf("Name: %s\n", (arr+i)->name);
      printf("Marks: %.2f\n\n", (arr+i)->marks);
   }

   int choice;
   printf("Enter 1 to search for a roll no. and 2 to sort the records by roll no.: ");
   scanf("%d", &choice);

   if (choice == 1) {
      int rollno, found = 0;
      printf("\nEnter Roll No. to search: ");
      scanf("%d", &rollno);

      for (i = 0; i < num; ++i) {
         if ((arr+i)->rollno == rollno) {
            printf("\nRoll no.%d\n", (arr+i)->rollno);
            printf("Name: %s\n", (arr+i)->name);
            printf("Marks: %.2f\n\n", (arr+i)->marks);
            found = 1;
            break;
         }
      }
      if (found == 0)
         printf("Roll No. %d not found.\n", rollno);
   }

   else if (choice == 2) {
      struct student temp;
      for (i = 0; i < num-1; ++i) {
         for (j = i+1; j < num; ++j) {
            if ((arr+i)->rollno > (arr+j)->rollno) {
               temp = *(arr+i);
               *(arr+i) = *(arr+j);
               *(arr+j) = temp;
            }
         }
      }

      printf("\nSorted Information:\n\n");
      for (i = 0; i < num; ++i) {
         printf("Roll no.%d\n", (arr+i)->rollno);
         printf("Name: %s\n", (arr+i)->name);
         printf("Marks: %.2f\n\n", (arr+i)->marks);
      }
   }

   free(arr);
   return 0;
}