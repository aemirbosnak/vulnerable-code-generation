//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// Function to clear the screen
void clearScreen() {
    system("clear");
}

// Function to print the menu
void printMenu() {
    printf("\n");
    printf("1. Open Ebook\n");
    printf("2. Save Ebook\n");
    printf("3. Quit\n");
}

// Function to open an ebook
void openEbook() {
    FILE *fp;
    char ch;
    char filename[100];
    printf("\nEnter the filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("\nFile not found!");
        exit(0);
    }
    clearScreen();
    while ((ch = fgetc(fp))!= EOF) {
        printf("%c", ch);
    }
    fclose(fp);
}

// Function to save an ebook
void saveEbook() {
    FILE *fp;
    char ch;
    char filename[100];
    printf("\nEnter the filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("\nFile not found!");
        exit(0);
    }
    printf("\nEnter the text to save: ");
    while ((ch = getchar())!= '\n') {
        fputc(ch, fp);
    }
    fclose(fp);
}

// Function to quit the program
void quit() {
    exit(0);
}

int main() {
    int choice;
    char filename[100];
    do {
        clearScreen();
        printMenu();
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            openEbook();
            break;
        case 2:
            saveEbook();
            break;
        case 3:
            quit();
            break;
        default:
            printf("\nInvalid choice!");
            break;
        }
    } while (true);
    return 0;
}