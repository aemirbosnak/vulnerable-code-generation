//FormAI DATASET v1.0 Category: File Synchronizer ; Style: visionary
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> // for sleep function
#include <pthread.h> // for multi-threading
#include <string.h> // for string operations

// function to synchronize the contents of two files
void fileSync(char* filename1, char* filename2) {

   // open the first file for reading
   FILE *fp1 = fopen(filename1, "r");
   if (fp1 == NULL) {
      printf("%s not found...\n", filename1);
      return;
   }

   // open the second file for writing
   FILE *fp2 = fopen(filename2, "w");
   if (fp2 == NULL) {
      printf("%s couldn't be created\n", filename2);
      return;
   }

   // copy contents of the first file to the second file
   char c;
   while ((c = fgetc(fp1)) != EOF) {
      fputc(c, fp2);
   }

   // close both files when done
   fclose(fp1);
   fclose(fp2);

   printf("File synchronization complete\n");

}

// thread function to synchronize files
void* syncThread(void* arg) {

   // cast the argument back to char**
   char** filenames = (char**) arg;

   // synchronize the files
   fileSync(filenames[0], filenames[1]);

   return NULL;
}


int main() {

   // prompt user for file names
   char filename1[100], filename2[100];
   printf("Enter the names of the two files to synchronize: \n");
   scanf("%s %s", filename1, filename2);

   // create a thread for file synchronization
   pthread_t tid;
   char* filenames[2];
   filenames[0] = filename1;
   filenames[1] = filename2;

   // create the thread
   pthread_create(&tid, NULL, syncThread, filenames);

   // wait for thread to complete
   pthread_join(tid, NULL);

   return 0;
}