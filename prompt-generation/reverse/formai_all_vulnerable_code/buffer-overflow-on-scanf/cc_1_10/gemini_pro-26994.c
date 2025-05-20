//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the color codes
#define BLACK   0
#define RED     1
#define GREEN   2
#define YELLOW  3
#define BLUE    4
#define MAGENTA 5
#define CYAN    6
#define WHITE   7

// Define the color names
char *color_names[] = {
    "Black",
    "Red",
    "Green",
    "Yellow",
    "Blue",
    "Magenta",
    "Cyan",
    "White"
};

// Define the color codes to HTML codes
char *html_codes[] = {
    "#000000",
    "#FF0000",
    "#00FF00",
    "#FFFF00",
    "#0000FF",
    "#FF00FF",
    "#00FFFF",
    "#FFFFFF"
};

// Get the color code from the user
int get_color_code() {
    int color_code;
    printf("Enter the color code (0-7): ");
    scanf("%d", &color_code);
    return color_code;
}

// Get the color name from the user
char *get_color_name() {
    char *color_name;
    printf("Enter the color name: ");
    scanf("%s", color_name);
    return color_name;
}

// Get the HTML code from the user
char *get_html_code() {
    char *html_code;
    printf("Enter the HTML code: ");
    scanf("%s", html_code);
    return html_code;
}

// Print the color code, color name, and HTML code
void print_color_info(int color_code, char *color_name, char *html_code) {
    printf("Color code: %d\n", color_code);
    printf("Color name: %s\n", color_name);
    printf("HTML code: %s\n", html_code);
}

// Main function
int main() {
    // Get the color code from the user
    int color_code = get_color_code();

    // Get the color name from the user
    char *color_name = get_color_name();

    // Get the HTML code from the user
    char *html_code = get_html_code();

    // Print the color code, color name, and HTML code
    print_color_info(color_code, color_name, html_code);

    return 0;
}