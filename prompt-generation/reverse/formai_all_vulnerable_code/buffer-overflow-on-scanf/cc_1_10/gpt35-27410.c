//FormAI DATASET v1.0 Category: Color Code Converter ; Style: imaginative
#include <stdio.h>
#include <string.h>

// Function to convert color names to their respective codes
void color_name_to_code(char *color_name) {
    if (strcmp(color_name, "red") == 0) {
        printf("Code for red is #FF0000\n");
    } else if (strcmp(color_name, "green") == 0) {
        printf("Code for green is #00FF00\n");
    } else if (strcmp(color_name, "blue") == 0) {
        printf("Code for blue is #0000FF\n");
    } else if (strcmp(color_name, "yellow") == 0) {
        printf("Code for yellow is #FFFF00\n");
    } else if (strcmp(color_name, "pink") == 0) {
        printf("Code for pink is #FFC0CB\n");
    } else {
        printf("Sorry, I do not know the code for %s\n", color_name);
    }
}

// Function to convert color codes to their respective names
void color_code_to_name(char *color_code) {
    if (strcmp(color_code, "#FF0000") == 0) {
        printf("The color code #FF0000 corresponds to red\n");
    } else if (strcmp(color_code, "#00FF00") == 0) {
        printf("The color code #00FF00 corresponds to green\n");
    } else if (strcmp(color_code, "#0000FF") == 0) {
        printf("The color code #0000FF corresponds to blue\n");
    } else if (strcmp(color_code, "#FFFF00") == 0) {
        printf("The color code #FFFF00 corresponds to yellow\n");
    } else if (strcmp(color_code, "#FFC0CB") == 0) {
        printf("The color code #FFC0CB corresponds to pink\n");
    } else {
        printf("Sorry, I do not know the name for the color with code %s\n", color_code);
    }
}

int main() {
    int choice;
    char color[20];
    printf("Welcome to the Color Converter!\n\n");
    printf("What do you want to do?\n");
    printf("1. Convert color name to code\n");
    printf("2. Convert color code to name\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter the name of the color: ");
        scanf("%s", color);
        color_name_to_code(color);
    } else if (choice == 2) {
        printf("Enter the code of the color: ");
        scanf("%s", color);
        color_code_to_name(color);
    } else {
        printf("Invalid choice!\n");
    }
    return 0;
}