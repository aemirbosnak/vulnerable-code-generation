//FormAI DATASET v1.0 Category: Email Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Define functions for each shape:
void draw_circle(){
    printf("       **       \n");
    printf("    **    **    \n");
    printf("  **        **  \n");
    printf(" **          ** \n");
    printf("**            **\n");
    printf("**            **\n");
    printf("**            **\n");
    printf(" **          ** \n");
    printf("  **        **  \n");
    printf("    **    **    \n");
    printf("       **       \n");
}

void draw_triangle(){
    printf("        /\\        \n");
    printf("      /    \\      \n");
    printf("    /        \\    \n");
    printf("  /            \\  \n");
    printf("/________________\\\n");
}

void draw_square(){
    printf(" ____________ \n");
    printf("|            |\n");
    printf("|            |\n");
    printf("|            |\n");
    printf("|            |\n");
    printf("|____________|\n");
}

// Main function
int main() {
    int option;
    printf("Welcome to the Shape Shifting Email Client!\n\n");

    // Menu
    printf("Choose your shape:\n");
    printf("1. Circle\n");
    printf("2. Triangle\n");
    printf("3. Square\n");
    scanf("%d", &option);

    // Shape selection
    switch(option){
        case 1:
            draw_circle();
            break;
        case 2:
            draw_triangle();
            break;
        case 3:
            draw_square();
            break;
        default:
            printf("Invalid option\n");
            break;
    }

    return 0;
}