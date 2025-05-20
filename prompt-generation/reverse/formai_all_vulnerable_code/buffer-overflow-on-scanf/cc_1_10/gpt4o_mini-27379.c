//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 100

typedef struct {
    int r, g, b;
} Color;

void welcome_message() {
    printf("======================================\n");
    printf("     C Color Code Converter v1.0     \n");
    printf("======================================\n");
    printf(" Convert RGB to Hex and vice versa!  \n");
    printf("======================================\n");
}

void display_colors(Color colors[], int count) {
    printf("\nColor List:\n");
    for (int i = 0; i < count; i++) {
        printf("Color %d: R:%d G:%d B:%d  | Hex: #%02X%02X%02X\n", 
                i + 1, colors[i].r, colors[i].g, colors[i].b, colors[i].r, colors[i].g, colors[i].b);
    }
    printf("--------------------------------------\n");
}

void rgb_to_hex(Color color) {
    printf("RGB(%d, %d, %d) -> Hex: #%02X%02X%02X\n", 
            color.r, color.g, color.b, color.r, color.g, color.b);
}

void hex_to_rgb(char* hex) {
    int r, g, b;

    if (sscanf(hex, "#%02X%02X%02X", &r, &g, &b) == 3) {
        printf("Hex: %s -> RGB(%d, %d, %d)\n", hex, r, g, b);
    } else {
        printf("Invalid hexadecimal color code format!\n");
    }
}

void add_color(Color colors[], int *count) {
    if (*count >= MAX_COLORS) {
        printf("Color list is full!\n");
        return;
    }

    Color new_color;
    printf("Enter Red (0-255): ");
    scanf("%d", &new_color.r);
    printf("Enter Green (0-255): ");
    scanf("%d", &new_color.g);
    printf("Enter Blue (0-255): ");
    scanf("%d", &new_color.b);
    
    colors[*count] = new_color;
    (*count)++;
    printf("Color added successfully!\n");
}

void menu() {
    printf("Menu Options:\n");
    printf("1. Add Color\n");
    printf("2. Show Colors\n");
    printf("3. Convert RGB to Hex\n");
    printf("4. Convert Hex to RGB\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Color colors[MAX_COLORS];
    int count = 0;
    int choice;

    welcome_message();

    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_color(colors, &count);
                break;
            case 2:
                display_colors(colors, count);
                break;
            case 3:
                if (count > 0) {
                    int index;
                    printf("Select color index (1 to %d): ", count);
                    scanf("%d", &index);
                    if (index >= 1 && index <= count) {
                        rgb_to_hex(colors[index - 1]);
                    } else {
                        printf("Invalid color index!\n");
                    }
                } else {
                    printf("No colors in the list!\n");
                }
                break;
            case 4:
                {
                    char hex[8];
                    printf("Enter hex color code (e.g., #FF5733): ");
                    scanf("%s", hex);
                    hex_to_rgb(hex);
                }
                break;
            case 5:
                printf("Exiting... Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }

    } while (choice != 5);

    return 0;
}