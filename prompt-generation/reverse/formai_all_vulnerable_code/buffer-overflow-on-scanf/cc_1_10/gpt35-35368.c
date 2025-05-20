//FormAI DATASET v1.0 Category: System administration ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {
  int choice;
  char filename[50], command[100];

  printf("Welcome to the Super Admin Tool\n");

  while(1) {
    printf("\nWhat would you like to do?\n");
    printf("1. Create a File\n");
    printf("2. Delete a File\n");
    printf("3. Run a Command\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("\nEnter the name of the file to create: ");
        scanf("%s", filename);

        FILE* fp = fopen(filename, "w");
        if(fp == NULL) {
          printf("Error creating file %s\n", filename);
        }
        else {
          printf("File %s created successfully\n", filename);
          fclose(fp);
        }
        break;

      case 2:
        printf("\nEnter the name of the file to delete: ");
        scanf("%s", filename);

        int ret = remove(filename);
        if(ret == 0) {
          printf("File %s deleted successfully\n", filename);
        }
        else {
          printf("Error deleting file %s\n", filename);
        }
        break;

      case 3:
        printf("\nEnter the command to run: ");
        scanf("%s", command);

        system(command);
        break;

      case 4:
        printf("\nThank you for using the Super Admin Tool\n");
        exit(0);

      default:
        printf("\nInvalid Choice. Please try again\n");
    }
  }
  return 0;
}