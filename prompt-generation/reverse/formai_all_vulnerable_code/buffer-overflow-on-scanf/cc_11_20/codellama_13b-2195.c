//Code Llama-13B DATASET v1.0 Category: Color Code Converter ; Style: Linus Torvalds
// Color Code Converter
// By Linus Torvalds

#include <stdio.h>

int main(void) {
    char input[256];
    char color_code[10];
    char color_name[256];

    // Ask user for input
    printf("Enter a color code: ");
    scanf("%s", input);

    // Check if input is a valid color code
    if (input[0] == '#') {
        strncpy(color_code, input, 7);
        color_code[7] = '\0';
    } else {
        strncpy(color_code, "##", 2);
        strncat(color_code, input, 7);
        color_code[9] = '\0';
    }

    // Check if color code is valid
    if (strlen(color_code) != 9 || color_code[0] != '#' || color_code[1] != '#') {
        printf("Invalid color code.\n");
        return 1;
    }

    // Convert color code to name
    if (strcmp(color_code, "#FF0000") == 0) {
        strcpy(color_name, "Red");
    } else if (strcmp(color_code, "#00FF00") == 0) {
        strcpy(color_name, "Green");
    } else if (strcmp(color_code, "#0000FF") == 0) {
        strcpy(color_name, "Blue");
    } else if (strcmp(color_code, "#FFFF00") == 0) {
        strcpy(color_name, "Yellow");
    } else if (strcmp(color_code, "#00FFFF") == 0) {
        strcpy(color_name, "Cyan");
    } else if (strcmp(color_code, "#FF00FF") == 0) {
        strcpy(color_name, "Magenta");
    } else if (strcmp(color_code, "#C0C0C0") == 0) {
        strcpy(color_name, "Silver");
    } else if (strcmp(color_code, "#808080") == 0) {
        strcpy(color_name, "Gray");
    } else if (strcmp(color_code, "#000000") == 0) {
        strcpy(color_name, "Black");
    } else if (strcmp(color_code, "#FFFFFF") == 0) {
        strcpy(color_name, "White");
    } else {
        strcpy(color_name, "Unknown");
    }

    // Print result
    printf("Color name: %s\n", color_name);

    return 0;
}