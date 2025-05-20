//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: funny
#include <stdio.h>

int main() {

   printf("Welcome to the C Disk space analyzer program! Let's dive into your files and see what we can find.\n");

   int used_space = 0;
   int total_space = 100;

   printf("\nCalculating your disk space usage...\n");

   // Simulating the scanning of files
   for(int i = 0; i < 20; i++) {
       used_space += 5;
       printf("Scanning file %d... Found 5MB of data to add to the total.\n", i+1);
   }

   // Calculating remaining space
   int remaining_space = total_space - used_space;

   printf("\nAnalysis complete!\n");
   printf("You are currently using %dMB of space out of a total of %dMB.\n", used_space, total_space);
   printf("You have %dMB of space left.", remaining_space);

   printf("\n\nDo you want to know which files are taking up the most space? (y/n)\n");

   char choice;
   scanf(" %c", &choice);

   if (choice == 'y') {
       printf("\nOk, let me just sort those files for you...\n");

       // Simulating sorting of files
       char file_names[20][20] = {"file1.txt", "file2.jpeg", "file3.doc", "file4.mp3", "file5.mov",
                                  "file6.c", "file7.h", "file8.pdf", "file9.ppt", "file10.xls",
                                  "file11.txt", "file12.jpeg", "file13.doc", "file14.mp3", "file15.mov",
                                  "file16.c", "file17.h", "file18.pdf", "file19.ppt", "file20.xls"};
       
       int file_sizes[20] = {5, 10, 2, 7, 12, 1, 3, 8, 4, 6, 5, 10, 2, 7, 12, 1, 3, 8, 4, 6};

       for (int i = 0; i < 20; i++) {
           for (int j = i+1; j < 20; j++) {
               if (file_sizes[i] < file_sizes[j]) {
                   // Swapping file sizes
                   int temp_size = file_sizes[i];
                   file_sizes[i] = file_sizes[j];
                   file_sizes[j] = temp_size;

                   // Swapping file names
                   char temp_name[20];
                   strcpy(temp_name, file_names[i]);
                   strcpy(file_names[i], file_names[j]);
                   strcpy(file_names[j], temp_name);
               }
           }
       }

       printf("\nHere are your files sorted by size:\n");
       for (int i = 0; i < 20; i++) {
           printf("%s - %dMB\n", file_names[i], file_sizes[i]);
       }

       printf("\nThanks for using the C Disk space analyzer program! Have a nice day!\n");
   }
   else {
       printf("\nAlright, thanks for using the C Disk space analyzer program! Have a nice day!\n");
   }

   return 0;
}