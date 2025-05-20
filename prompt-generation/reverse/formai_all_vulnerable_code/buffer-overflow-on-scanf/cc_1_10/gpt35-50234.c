//FormAI DATASET v1.0 Category: File handling ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

void createFile() {
  FILE *fp;
  fp = fopen("example.txt", "w"); // create a file and open it in write mode
  if(fp == NULL) {
    printf("Error creating file\n");
    exit(1);
  }
  printf("File created successfully\n");
  fclose(fp); // close the file
}

void writeToFile() {
  FILE *fp;
  fp = fopen("example.txt", "a"); // open the file in append mode
  if(fp == NULL) {
    printf("Error opening file\n");
    exit(1);
  }
  char str[50];
  printf("Enter a string to write to file: ");
  fgets(str, 50, stdin); // read input from user
  fprintf(fp, "%s", str); // write content to file
  printf("Content written to file successfully\n");
  fclose(fp); // close the file
}

void readFromFile() {
  FILE *fp;
  fp = fopen("example.txt", "r"); // open the file in read mode
  if(fp == NULL) {
    printf("Error opening file\n");
    exit(1);
  }
  char ch;
  printf("Content of file:\n");
  while((ch = fgetc(fp)) != EOF) {
    printf("%c", ch); // print file content
  }
  fclose(fp); // close the file
}

int main() {
  int choice;
  while(1) {
    printf("\nEnter your choice:\n1. Create a new file\n2. Write to file\n3. Read from file\n4. Exit\n");
    scanf("%d", &choice);
    switch(choice) {
      case 1: createFile();
              break;
      case 2: writeToFile();
              break;
      case 3: readFromFile();
              break;
      case 4: printf("Exiting program\n");
              exit(0); // exit the program
      default: printf("Invalid choice\n");
    }
  }
  return 0;
}