//FormAI DATASET v1.0 Category: Image Editor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME 100
#define MAX_COMMAND_LENGTH 20
#define IMAGE_HEIGHT 10
#define IMAGE_WIDTH 10

// Function declarations
void loadImage(int image[IMAGE_HEIGHT][IMAGE_WIDTH], char fileName[]);
void saveImage(int image[IMAGE_HEIGHT][IMAGE_WIDTH], char fileName[]);
void printImage(int image[IMAGE_HEIGHT][IMAGE_WIDTH]);
void invertColors(int image[IMAGE_HEIGHT][IMAGE_WIDTH]);
void blurImage(int image[IMAGE_HEIGHT][IMAGE_WIDTH]);
void encryptImage(int image[IMAGE_HEIGHT][IMAGE_WIDTH], char key[]);
void decryptImage(int image[IMAGE_HEIGHT][IMAGE_WIDTH], char key[]);

// Main function
int main() {
    int image[IMAGE_HEIGHT][IMAGE_WIDTH];
    char fileName[MAX_FILE_NAME];
    char command[MAX_COMMAND_LENGTH];
    char key[MAX_COMMAND_LENGTH];
    
    // Prompt user to enter file name and load image
    printf("Enter file name: ");
    fgets(fileName, MAX_FILE_NAME, stdin);
    fileName[strcspn(fileName, "\n")] = 0; // Remove trailing newline character
    loadImage(image, fileName);

    // Prompt user to enter command and key (if applicable)
    printf("\nAvailable commands: invert, blur, encrypt, decrypt, save, exit\n");
    printf("Enter command: ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    command[strcspn(command, "\n")] = 0; // Remove trailing newline character

    while (strcmp(command, "exit") != 0) {
        if (strcmp(command, "invert") == 0) {
            invertColors(image);
            printf("Colors inverted.\n");
        } else if (strcmp(command, "blur") == 0) {
            blurImage(image);
            printf("Image blurred.\n");
        } else if (strcmp(command, "encrypt") == 0) {
            printf("Enter encryption key (maximum length %d): ", MAX_COMMAND_LENGTH);
            fgets(key, MAX_COMMAND_LENGTH, stdin);
            key[strcspn(key, "\n")] = 0; // Remove trailing newline character
            encryptImage(image, key);
            printf("Image encrypted.\n");
        } else if (strcmp(command, "decrypt") == 0) {
            printf("Enter decryption key: ");
            fgets(key, MAX_COMMAND_LENGTH, stdin);
            key[strcspn(key, "\n")] = 0; // Remove trailing newline character
            decryptImage(image, key);
            printf("Image decrypted.\n");
        } else if (strcmp(command, "save") == 0) {
            printf("Enter file name: ");
            fgets(fileName, MAX_FILE_NAME, stdin);
            fileName[strcspn(fileName, "\n")] = 0; // Remove trailing newline character
            saveImage(image, fileName);
            printf("Image saved.\n");
        } else {
            printf("Invalid command. Please try again.\n");
        }

        // Prompt user to enter another command
        printf("\nAvailable commands: invert, blur, encrypt, decrypt, save, exit\n");
        printf("Enter command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0; // Remove trailing newline character
    }

    printf("Exiting program.\n");

    return 0;
}

// Function to load image from file
void loadImage(int image[IMAGE_HEIGHT][IMAGE_WIDTH], char fileName[]) {
    FILE *fp;
    int i, j;

    fp = fopen(fileName, "r");
    if (fp != NULL) {
        for (i = 0; i < IMAGE_HEIGHT; i++) {
            for (j = 0; j < IMAGE_WIDTH; j++) {
                fscanf(fp, "%d", &image[i][j]);
            }
        }
        fclose(fp);
        printf("Image loaded.\n");
    } else {
        printf("Error: Could not open file.\n");
        exit(1);
    }
}

// Function to save image to file
void saveImage(int image[IMAGE_HEIGHT][IMAGE_WIDTH], char fileName[]) {
    FILE *fp;
    int i, j;

    fp = fopen(fileName, "w");
    if (fp != NULL) {
        for (i = 0; i < IMAGE_HEIGHT; i++) {
            for (j = 0; j < IMAGE_WIDTH; j++) {
                fprintf(fp, "%d ", image[i][j]);
            }
            fprintf(fp, "\n");
        }
        fclose(fp);
    } else {
        printf("Error: Could not open file.\n");
        exit(1);
    }
}

// Function to print image to console
void printImage(int image[IMAGE_HEIGHT][IMAGE_WIDTH]) {
    int i, j;

    for (i = 0; i < IMAGE_HEIGHT; i++) {
        for (j = 0; j < IMAGE_WIDTH; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
}

// Function to invert colors of image
void invertColors(int image[IMAGE_HEIGHT][IMAGE_WIDTH]) {
    int i, j;

    for (i = 0; i < IMAGE_HEIGHT; i++) {
        for (j = 0; j < IMAGE_WIDTH; j++) {
            image[i][j] = 255 - image[i][j];
        }
    }
}

// Function to blur image
void blurImage(int image[IMAGE_HEIGHT][IMAGE_WIDTH]) {
    int i, j, k, l, sum, count;
    int tempImage[IMAGE_HEIGHT][IMAGE_WIDTH];

    // Copy image to temporary array
    memcpy(tempImage, image, sizeof(image));

    for (i = 0; i < IMAGE_HEIGHT; i++) {
        for (j = 0; j < IMAGE_WIDTH; j++) {
            sum = 0;
            count = 0;
            for (k = -1; k <= 1; k++) {
                for (l = -1; l <= 1; l++) {
                    if ((i+k) >= 0 && (i+k) < IMAGE_HEIGHT && (j+l) >= 0 && (j+l) < IMAGE_WIDTH) {
                        sum += tempImage[i+k][j+l];
                        count++;
                    }
                }
            }
            image[i][j] = sum / count;
        }
    }
}

// Function to encrypt image
void encryptImage(int image[IMAGE_HEIGHT][IMAGE_WIDTH], char key[]) {
    int i, j, k, index, keyLength;
    char encryptedChar;

    keyLength = strlen(key);

    for (i = 0; i < IMAGE_HEIGHT; i++) {
        for (j = 0; j < IMAGE_WIDTH; j++) {
            index = i * IMAGE_WIDTH + j;
            k = index % keyLength;
            encryptedChar = tolower(key[k]) ^ image[i][j];
            image[i][j] = (int)encryptedChar;
        }
    }
}

// Function to decrypt image
void decryptImage(int image[IMAGE_HEIGHT][IMAGE_WIDTH], char key[]) {
    int i, j, k, index, keyLength;
    char decryptedChar;

    keyLength = strlen(key);

    for (i = 0; i < IMAGE_HEIGHT; i++) {
        for (j = 0; j < IMAGE_WIDTH; j++) {
            index = i * IMAGE_WIDTH + j;
            k = index % keyLength;
            decryptedChar = tolower(key[k]) ^ image[i][j];
            image[i][j] = (int)decryptedChar;
        }
    }
}