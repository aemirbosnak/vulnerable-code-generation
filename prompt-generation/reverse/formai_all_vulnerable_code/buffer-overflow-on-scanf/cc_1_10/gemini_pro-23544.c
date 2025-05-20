//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the color codes
#define BLACK "\x1b[30m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"

// Define the reset code
#define RESET "\x1b[0m"

// Define the color code array
char *color_codes[] = {BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};

// Define the color name array
char *color_names[] = {"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"};

// Define the color code to name map
struct color_code_to_name {
    char *code;
    char *name;
};

struct color_code_to_name color_code_to_name_map[] = {
    {BLACK, "black"},
    {RED, "red"},
    {GREEN, "green"},
    {YELLOW, "yellow"},
    {BLUE, "blue"},
    {MAGENTA, "magenta"},
    {CYAN, "cyan"},
    {WHITE, "white"}
};

// Get the color code from the color name
char *get_color_code_from_name(char *name) {
    for (int i = 0; i < sizeof(color_code_to_name_map) / sizeof(struct color_code_to_name); i++) {
        if (strcmp(name, color_code_to_name_map[i].name) == 0) {
            return color_code_to_name_map[i].code;
        }
    }

    return NULL;
}

// Print the color codes
void print_color_codes() {
    for (int i = 0; i < sizeof(color_codes) / sizeof(char *); i++) {
        printf("%s%s%s\n", color_codes[i], color_names[i], RESET);
    }
}

// Convert a string to a color code
char *convert_string_to_color_code(char *string) {
    char *color_code = get_color_code_from_name(string);
    if (color_code == NULL) {
        return NULL;
    }

    return color_code;
}

// Convert a color code to a string
char *convert_color_code_to_string(char *color_code) {
    for (int i = 0; i < sizeof(color_code_to_name_map) / sizeof(struct color_code_to_name); i++) {
        if (strcmp(color_code, color_code_to_name_map[i].code) == 0) {
            return color_code_to_name_map[i].name;
        }
    }

    return NULL;
}

// Main function
int main() {
    // Print the color codes
    print_color_codes();

    // Get the color code from the user
    char color_name[256];
    printf("Enter a color name: ");
    scanf("%s", color_name);

    // Convert the color name to a color code
    char *color_code = convert_string_to_color_code(color_name);

    // Print the color code
    if (color_code == NULL) {
        printf("Invalid color name.\n");
    } else {
        printf("The color code for %s is %s.\n", color_name, color_code);
    }

    return 0;
}