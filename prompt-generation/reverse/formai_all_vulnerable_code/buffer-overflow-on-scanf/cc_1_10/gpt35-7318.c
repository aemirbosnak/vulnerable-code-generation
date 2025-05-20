//FormAI DATASET v1.0 Category: File handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {

   FILE *fptr; // declare a file pointer
   fptr = fopen("user_data.txt", "w"); // create a text file to write to

   if (fptr == NULL) { // check if file was created successfully
      printf("Error creating file!");
      exit(1);
   }

   char name[50];
   int age;
   char occupation[50];

   printf("Please enter your name: ");
   scanf("%s", name);

   printf("Please enter your age: ");
   scanf("%d", &age);

   printf("Please enter your occupation: ");
   scanf("%s", occupation);

   fprintf(fptr, "Name: %s\n", name); // write user input to file
   fprintf(fptr, "Age: %d\n", age);
   fprintf(fptr, "Occupation: %s\n", occupation);

   fclose(fptr); // close the file

   fptr = fopen("user_data.txt", "r"); // open the file for reading

   if (fptr == NULL) { // check if file was opened successfully
      printf("Error opening file!");
      exit(1);
   }

   char c;
   printf("User data:\n");

   while((c = fgetc(fptr)) != EOF) { // read file character by character and print to console
      printf("%c", c);
   }

   fclose(fptr); // close the file

   return 0;
}