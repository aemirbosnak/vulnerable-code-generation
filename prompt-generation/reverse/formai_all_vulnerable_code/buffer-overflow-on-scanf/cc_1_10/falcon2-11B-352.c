//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Function to convert an integer to a character
char int_to_char(int num) {
    char ch;
    ch = num % 62 + 'A';
    return ch;
}

// Function to convert a character to an integer
int char_to_int(char ch) {
    int num = (ch - 'A') % 62;
    return num;
}

// Function to convert a character to its corresponding image file name
char image_filename(char ch) {
    char filename[10];
    int num = char_to_int(ch);
    if (num >= 0 && num <= 9) {
        sprintf(filename, "image%d.jpg", num);
        return filename[0];
    }
    else {
        sprintf(filename, "image%d.png", num);
        return filename[0];
    }
}

// Function to open an image file
void open_image_file(char *filename) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(0);
    }
    else {
        printf("File %s opened successfully\n", filename);
    }
}

// Function to save an image file
void save_image_file(char *filename, char *image) {
    FILE *fp;
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(0);
    }
    else {
        fputs(image, fp);
        printf("Image %s saved successfully\n", filename);
    }
}

// Function to display an image
void display_image(char *image) {
    printf("%s", image);
}

// Function to edit an image
void edit_image(char *image, char ch) {
    char filename[10];
    char image_name[100];
    char new_image[100];
    int num = char_to_int(ch);
    if (num >= 0 && num <= 9) {
        sprintf(image_name, "image%d.jpg", num);
        sprintf(new_image, "image%d_edited.jpg", num);
        sprintf(filename, "image%d.jpg", num);
        open_image_file(filename);
        save_image_file(new_image, image);
        display_image(new_image);
    }
    else {
        sprintf(image_name, "image%d.png", num);
        sprintf(new_image, "image%d_edited.png", num);
        sprintf(filename, "image%d.png", num);
        open_image_file(filename);
        save_image_file(new_image, image);
        display_image(new_image);
    }
}

int main() {
    char ch;
    char image[100];
    do {
        printf("Enter a character (A-J): ");
        scanf("%c", &ch);
        if (ch >= 'A' && ch <= 'J') {
            sprintf(image, "image%c.jpg", int_to_char(ch));
            open_image_file(image);
            save_image_file(image, image);
            display_image(image);
            edit_image(image, ch);
        }
        else {
            printf("Invalid input\n");
        }
    } while (ch >= 'A' && ch <= 'J');
    return 0;
}