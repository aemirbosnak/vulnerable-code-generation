//FormAI DATASET v1.0 Category: Data recovery tool ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp;
  char filename[50], data[100];
  int choice, i = 0, len;

  printf("Welcome to Data Recovery Tool\n");
  printf("-----------------------------\n");

  printf("Please enter the name of the file you would like to recover: ");
  scanf("%s", filename);

  printf("Please select a recovery option:\n");
  printf("1. Recover all data\n");
  printf("2. Recover data by keyword\n");
  printf("3. Recover data by file type\n");
  printf("4. Exit\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      fp = fopen(filename, "r");
      if(fp == NULL) {
        printf("Error: Cannot open file!\n");
        exit(1);
      }

      while(fgets(data, 100, fp) != NULL) {
        printf("%s", data);
      }

      fclose(fp);
      break;

    case 2:
      printf("Please enter the keyword to search: ");
      scanf("%s", data);

      fp = fopen(filename, "r");
      if(fp == NULL) {
        printf("Error: Cannot open file!\n");
        exit(1);
      }

      len = strlen(data);

      while(fgets(data, 100, fp) != NULL) {
        if(strstr(data, data) != NULL) {
          printf("%s", data);
          i++;
        }
      }

      if(i == 0) {
        printf("Sorry, no data found for keyword (%s)!\n", data);
      }

      fclose(fp);
      break;

    case 3:
      printf("Please enter the file type to search (e.g. txt, doc, pdf): ");
      scanf("%s", data);

      fp = fopen(filename, "r");
      if(fp == NULL) {
        printf("Error: Cannot open file!\n");
        exit(1);
      }

      len = strlen(data);

      while(fgets(data, 100, fp) != NULL) {
        int length = strlen(data);
        char *type = &data[length-len];
        if(strcmp(type, data) == 0) {
          printf("%s", data);
          i++;
        }
      }

      if(i == 0) {
        printf("Sorry, no data found for file type (%s)!\n", data);
      }

      fclose(fp);
      break;

    case 4:
      printf("Exiting program...\n");
      exit(0);
      break;

    default:
      printf("Invalid choice, please try again!\n");
      break;
  }

  return 0;
}