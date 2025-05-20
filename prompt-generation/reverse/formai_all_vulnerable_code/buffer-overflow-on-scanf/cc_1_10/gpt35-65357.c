//FormAI DATASET v1.0 Category: File handling ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *fp;
   char ch, filename[20];
   int choice;

   printf("PRISONER RECORD MANAGEMENT SYSTEM\n");
   printf("------------------------------\n");
   printf("1. Create prisoner record file\n");
   printf("2. View prisoner record\n");
   printf("3. Update prisoner record\n");
   printf("4. Exit\n");

   printf("Enter your choice: ");
   scanf("%d", &choice);

   switch (choice) {
      case 1:
         printf("Enter the name of the file: ");
         scanf("%s", filename);
         fp = fopen(filename, "w");
         printf("\nEnter the prisoner name: ");
         while(ch != '\n') {
            ch = getchar();
            fputc(ch, fp);
         }
         fclose(fp);
         break;
      case 2:
         printf("Enter the name of the file: ");
         scanf("%s", filename);
         fp = fopen(filename, "r");
         if(fp == NULL) {
            printf("File does not exist!\n");
            exit(1);
         }
         printf("The contents of the file are: ");
         while((ch = fgetc(fp)) != EOF)
            printf("%c", ch);
         fclose(fp);
         break;
      case 3:
         printf("Enter the name of the file: ");
         scanf("%s", filename);
         fp = fopen(filename, "r+");
         if(fp == NULL) {
            printf("File does not exist!\n");
            exit(1);
         }
         printf("Enter the new content: ");
         while(ch != '\n') {
            ch = getchar();
            fputc(ch, fp);
         }
         fclose(fp);
         break;
      case 4:
         printf("Exiting the program...\n");
         exit(0);
      default:
         printf("Invalid input!\n");
         exit(1);
   }

   return 0;
}