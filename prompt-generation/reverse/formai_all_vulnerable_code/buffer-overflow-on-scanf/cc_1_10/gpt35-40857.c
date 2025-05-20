//FormAI DATASET v1.0 Category: Image Editor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_SIZE 50
#define MAX_COMMAND_SIZE 20

// function prototypes
void printMenu();
void executeCommand(char command[], char fileName[]);
void openImage(char fileName[]);
void saveImage(char fileName[]);
void invertColors();
void flipHorizontal();
void grayScale();
void printImage();

// global variables
int** image; // 2D array to store image
int rows, cols; // dimensions of image

int main() {
    char fileName[MAX_FILE_NAME_SIZE] = "";
    char command[MAX_COMMAND_SIZE] = "";
    int isExit = 0;
    
    // initialization of image array
    image = (int**) malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++){
        image[i] = (int*) malloc(cols * sizeof(int));
    }
    
    // loop that prompts user for input until they choose to exit
    while(!isExit){
        printf("Enter command (type 'help' for menu): ");
        scanf("%s", command);
        
        if(strcmp(command, "help") == 0){
            printMenu();
        } else if(strcmp(command, "open") == 0){
            printf("Enter name of file to open: ");
            scanf("%s", fileName);
            openImage(fileName);
        } else if(strcmp(command, "save") == 0){
            printf("Enter name of file to save to: ");
            scanf("%s", fileName);
            saveImage(fileName);
        } else if(strcmp(command, "invert") == 0){
            invertColors();
        } else if(strcmp(command, "flip") == 0){
            flipHorizontal();
        } else if(strcmp(command, "grayscale") == 0){
            grayScale();
        } else if(strcmp(command, "print") == 0){
            printImage();
        } else if(strcmp(command, "exit") == 0){
            isExit = 1;
        } else {
            printf("Invalid command. Type 'help' to see available commands.\n");
        }
    }
    
    // freeing allocated memory
    for(int i = 0; i < rows; i++){
        free(image[i]);
    }
    free(image);
    printf("Program exited successfully.\n");
    return 0;
}

void printMenu(){
    printf("\n---MENU---\n");
    printf("open [file_name]: opens an image file\n");
    printf("save [file_name]: saves the image to a file\n");
    printf("invert: inverts the colors of the image\n");
    printf("flip: flips the image horizontally\n");
    printf("grayscale: converts the image to grayscale\n");
    printf("print: prints the current image\n");
    printf("exit: ends the program\n\n");
}

void executeCommand(char command[], char fileName[]){
    if(strcmp(command, "open") == 0){
        openImage(fileName);
    } else if(strcmp(command, "save") == 0){
        saveImage(fileName);
    } else {
        printf("Invalid command. Type 'help' to see available commands.\n");
    }
}

void openImage(char fileName[]){
    FILE* file = fopen(fileName, "r");
    if(file == NULL){
        printf("Unable to open file '%s'\n", fileName);
        return;
    }
    
    // reading dimensions from file
    fscanf(file, "%d %d", &rows, &cols);
    if(rows <= 0 || cols <= 0){
        printf("Invalid dimensions in file '%s'\n", fileName);
        rows = 0;
        cols = 0;
        return;
    }
    
    // reallocating memory for image array
    image = (int**) realloc(image, rows * sizeof(int*));
    for(int i = 0; i < rows; i++){
        image[i] = (int*) realloc(image[i], cols * sizeof(int));
    }
    
    // reading pixel values from file
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            fscanf(file, "%d", &image[i][j]);
        }
    }
    
    printf("Opened file '%s'\n", fileName);
    fclose(file);
}

void saveImage(char fileName[]){
    FILE* file = fopen(fileName, "w");
    if(file == NULL){
        printf("Unable to save to file '%s'\n", fileName);
        return;
    }
    
    // writing dimensions to file
    fprintf(file, "%d %d\n", rows, cols);
    
    // writing pixel values to file
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            fprintf(file, "%d ", image[i][j]);
        }
        fprintf(file, "\n");
    }
    
    printf("Saved image to file '%s'\n", fileName);
    fclose(file);
}

void invertColors(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            image[i][j] = 255 - image[i][j];
        }
    }
    printf("Inverted colors of image.\n");
}

void flipHorizontal(){
    int temp;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols/2; j++){
            temp = image[i][j];
            image[i][j] = image[i][cols-1-j];
            image[i][cols-1-j] = temp;
        }
    }
    printf("Flipped image horizontally.\n");
}

void grayScale(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            int r = (image[i][j] >> 16) & 0xff;
            int g = (image[i][j] >> 8) & 0xff;
            int b = image[i][j] & 0xff;
            int grayValue = (r + g + b) / 3;
            image[i][j] = (grayValue << 16) | (grayValue << 8) | grayValue;
        }
    }
    printf("Converted image to grayscale.\n");
}

void printImage(){
    printf("\n---IMAGE---\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    printf("-----------\n");
}