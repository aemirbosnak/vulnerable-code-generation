//FormAI DATASET v1.0 Category: File handling ; Style: shape shifting
#include <stdio.h>

int main() {
  int choice;
  char filename[50];
  FILE *fp;
  
  printf("Welcome to Shape Shifting File Handling!\n");

  do {
    printf("\nPlease select an option:\n");
    printf("1. Create a new file\n");
    printf("2. Add content to an existing file\n");
    printf("3. Read the contents of a file\n");
    printf("4. Modify the contents of a file\n");
    printf("5. Delete a file\n");
    printf("6. Exit\n");

    scanf("%d", &choice);
    getchar();

    switch (choice) {
      case 1:
        printf("\nEnter the name of the file you want to create: ");
        fgets(filename, 50, stdin);

        fp = fopen(filename, "w");

        if (fp == NULL) {
          printf("Error creating file.\n");
          break;
        }

        printf("File created successfully!\n");
        fclose(fp);

        break;

      case 2:
        printf("\nEnter the name of the file you want to add content to: ");
        fgets(filename, 50, stdin);

        fp = fopen(filename, "a");

        if (fp == NULL) {
          printf("Error opening file.\n");
          break;
        }

        char content[100];
        printf("Enter the content to add: ");
        fgets(content, 100, stdin);
        fprintf(fp, "%s", content);

        printf("Content added successfully!\n");
        fclose(fp);

        break;

      case 3:
        printf("\nEnter the name of the file you want to read: ");
        fgets(filename, 50, stdin);

        fp = fopen(filename, "r");

        if (fp == NULL) {
          printf("Error opening file.\n");
          break;
        }

        char data[100];
        printf("Contents:\n");

        while (fgets(data, 100, fp)) {
          printf("%s", data);
        }

        fclose(fp);

        break;

      case 4:
        printf("\nEnter the name of the file you want to modify: ");
        fgets(filename, 50, stdin);

        fp = fopen(filename, "w");

        if (fp == NULL) {
          printf("Error opening file.\n");
          break;
        }

        char newContent[100];
        printf("Enter the new content: ");
        fgets(newContent, 100, stdin);
        fprintf(fp, "%s", newContent);

        printf("Content modified successfully!\n");
        fclose(fp);

        break;

      case 5:
        printf("\nEnter the name of the file you want to delete: ");
        fgets(filename, 50, stdin);

        if (remove(filename) == 0) {
          printf("File deleted successfully!\n");
        } else {
          printf("Error deleting file.\n");
        }

        break;

      case 6:
        printf("\nThank you for using Shape Shifting File Handling!\n");
        break;

      default:
        printf("\nInvalid choice. Please try again.\n");
        break;
    }
  } while (choice != 6);

  return 0;
}