//FormAI DATASET v1.0 Category: File handling ; Style: calm
#include <stdio.h>

int main() {
   FILE *filePointer; //Declare file pointer
   char data[50]; //Declare array to store data
   int option; //Declare variable to store user input option

   //Menu for user to choose an option
   printf("Select an option:\n");
   printf("1. Create a new file\n");
   printf("2. Write to an existing file\n");
   printf("3. Read from an existing file\n");
   scanf("%d", &option);

   switch(option) {
      case 1:
         //Creating a new file
         filePointer = fopen("newfile.txt", "w"); //Opening a new file in write mode

         if(filePointer == NULL) {
            printf("Unable to create a new file.\n");
            return 1; //Exit the program
         }

         printf("Enter the data to be written in the file:\n");
         scanf(" %[^\n]", data); //Reading input from the user

         fprintf(filePointer, "%s", data); //Writing data to the new file
         fclose(filePointer); //Closing the file
         printf("Data written successfully!\n");
         break;

      case 2:
         //Writing to an existing file
         filePointer = fopen("existingfile.txt", "a"); //Opening an existing file in append mode

         if(filePointer == NULL) {
            printf("Unable to open an existing file.\n");
            return 1; //Exit the program
         }

         printf("Enter the data to be written to the file:\n");
         scanf(" %[^\n]", data); //Reading input from the user

         fprintf(filePointer, "%s\n", data); //Appending data to the existing file
         fclose(filePointer); //Closing the file
         printf("Data written successfully!\n");
         break;

      case 3:
         //Reading from an existing file
         filePointer = fopen("existingfile.txt", "r"); //Opening an existing file in read mode

         if(filePointer == NULL) {
            printf("Unable to open an existing file.\n");
            return 1; //Exit the program
         }

         printf("The data in the file is:\n");
         while(fgets(data, 50, filePointer)) {
            printf("%s", data); //Printing the contents of the file
         }

         fclose(filePointer); //Closing the file
         break;

      default:
         printf("Invalid option selected!\n");
         break;
   }

   return 0; //Exit the program
}