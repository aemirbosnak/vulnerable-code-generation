//FormAI DATASET v1.0 Category: System boot optimizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main() {
   printf("Welcome to the System Boot Optimizer!\n");

   // Reading the input file
   FILE *fptr;
   char filename[100], c;
   int num_lines = 0;
   
   printf("Enter the name of the input file: ");
   scanf("%s", filename);

   fptr = fopen(filename, "r");
   if (fptr == NULL) {
       printf("Cannot open file %s\n", filename);
       exit(0);
   }
   
   // Counting the number of lines in the file
   c = fgetc(fptr);
   while (c != EOF) {
       if (c == '\n') {
           num_lines++;
       }
       c = fgetc(fptr);
   }
   
   fclose(fptr);
   
   printf("The input file %s has %d lines\n", filename, num_lines);

   // Parsing the input file
   fptr = fopen(filename, "r");
   if (fptr == NULL) {
       printf("Cannot open file %s\n", filename);
       exit(0);
   }
   
   char line[100];
   int boot_time;
   int optimizer_time;
   
   while (fgets(line, sizeof(line), fptr)) {
       sscanf(line, "%d %d", &boot_time, &optimizer_time);
       printf("Boot time = %d seconds, Optimizer time = %d seconds\n", boot_time, optimizer_time);
       
       // TODO: Implement your C System boot optimizer code here
       
       printf("System Boot Optimized!\n");
   }
   
   fclose(fptr);
   
   return 0;
}