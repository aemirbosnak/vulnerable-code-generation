//FormAI DATASET v1.0 Category: QR code reader ; Style: introspective
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define QR_CODE_SIZE 21
#define MAX_FILENAME_SIZE 100

void displayLogo();
void displayMenu();
bool isValidFileName(char *fileName);
void readQRCodeFromFile(char *fileName);
void readQRCodeFromCamera();

/* Main function */
int main() {
  displayLogo(); // Displaying the logo
  
  int choice;
  do {
    displayMenu(); // Displaying the menu
    scanf("%d", &choice);

    switch(choice) {
      case 1: {
        char fileName[MAX_FILENAME_SIZE];
        printf("Enter the file name to read QR code from: ");
        scanf("%s", &fileName);

        if(isValidFileName(fileName)) {
          readQRCodeFromFile(fileName);
        } else {
          printf("Invalid file name! Please enter a valid file name.\n");
        }
        break;
      }
      case 2: {
        readQRCodeFromCamera();
        break;
      }
      case 3: {
        printf("Exiting the program.\n");
        exit(0);
      }
      default: {
        printf("Invalid choice! Please enter a valid choice.\n");
        break;
      }
    }
  } while(true);

  return 0;
}

/* Function to display the logo */
void displayLogo() {
  printf("\n");
  printf("___  ____ ___   ___  ____      _    ____ _  __\n");
  printf("|  \\/  (_) _ ) / _ \\/ ___|    / \\  / ___| |/ /\n");
  printf("| |\\/| | | _ \\| | | \\___ \\   / _ \\| |   | ' / \n");
  printf("| |  | | | |_) | |_| |___) | / ___ \\ |___| . \\ \n");
  printf("|_|  |_|_|___/ \\___/|____/ /_/   \\_\\____|_|\\_\\\n");
  printf("\n");
}

/* Function to display the menu */
void displayMenu() {
  printf("\nChoose an option:\n");
  printf("1. Read QR code from file\n");
  printf("2. Read QR code from camera\n");
  printf("3. Exit\n");
  printf("Enter your choice: ");
}

/* Function to check if the file name is valid */
bool isValidFileName(char *fileName) {
  if(strstr(fileName, ".txt") != NULL && strlen(fileName) == 14) {
    return true;
  } else {
    return false;
  }
}

/* Function to read the QR code from a file */
void readQRCodeFromFile(char *fileName) {
  FILE *file = fopen(fileName, "r");
  if(file == NULL) {
    printf("Error opening file %s.\n", fileName);
    return;
  }

  char qrCode[QR_CODE_SIZE];
  fgets(qrCode, QR_CODE_SIZE, (FILE*)file);
  printf("The QR code read from file %s is: %s\n", fileName, qrCode);

  fclose(file);
}

/* Function to read the QR code from the camera */
void readQRCodeFromCamera() {
  printf("Please bring the QR code in front of the camera.\n");

  // Actual implementation of the camera to be added here
  printf("The QR code read from camera is: ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
}