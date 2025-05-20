//FormAI DATASET v1.0 Category: File Encyptor ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILENAME_LENGTH 100 
#define MAX_PASSWORD_LENGTH 16 

void encrypt(FILE *fptr, char password[]) {
  char ch;
  long int i = 0;
  while((ch = fgetc(fptr)) != EOF) {
    if (i >= strlen(password)) {
      i = 0;
    }
    ch = ch + password[i];
    i++;
    fseek(fptr, -1, SEEK_CUR);
    fputc(ch, fptr);
  }
  printf("File Encrypted Successfully!\n");
}

void decrypt(FILE *fptr, char password[]) {
  char ch;
  long int i = 0;
  while((ch = fgetc(fptr)) != EOF) {
    if (i >= strlen(password)) {
      i = 0;
    }
    ch = ch - password[i];
    i++;
    fseek(fptr, -1, SEEK_CUR);
    fputc(ch, fptr);
  }
  printf("File Decrypted Successfully!\n");
}

int main() {
  char filename[MAX_FILENAME_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
  int choice = 3;
  printf("Welcome to File Encryptor!\n");

  while (choice > 2) {
    printf("Please Enter Your Choice:\n");
    printf("1. Encrypt File\n");
    printf("2. Decrypt File\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
      printf("Enter File Name to Encrypt (with extension): ");
      scanf("%s", filename);
      printf("Enter Password (Max Length 16): ");
      scanf("%s", password);

      FILE *fptr = fopen(filename, "r+");
      if (fptr == NULL) {
        printf("File Not Found!\n");
        exit(1);
      }

      encrypt(fptr, password);
      fclose(fptr);
    }
    else if (choice == 2) {
      printf("Enter File Name to Decrypt (with extension): ");
      scanf("%s", filename);
      printf("Enter Password (Max Length 16): ");
      scanf("%s", password);

      FILE *fptr = fopen(filename, "r+");
      if (fptr == NULL) {
        printf("File Not Found!\n");
        exit(1);
      }

      decrypt(fptr, password);
      fclose(fptr);
    }
    else {
      printf("Invalid Choice, Please try again!\n");
    }
    choice = 3;
  }

  return 0;
}