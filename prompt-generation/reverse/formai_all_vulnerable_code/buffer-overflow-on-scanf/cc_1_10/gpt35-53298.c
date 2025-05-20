//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random pixel color */
char* generateColor() {
    /* Array of valid pixel colors */
    char colors[16][7] = {"#ffffff", "#000000", "#ff0000", "#00ff00", "#0000ff", "#ffff00", "#ff00ff", "#00ffff", 
                          "#c0c0c0", "#808080", "#800000", "#808000", "#008000", "#800080", "#008080", "#000080"};
    /* Generate a random index between 0 and 15 */
    int randomIndex = rand() % 16;
    /* Return the corresponding color value */
    return colors[randomIndex];
}

/* Function to generate a random pixel art image */
void generateArt(int width, int height) {
    /* Open a file for writing the pixel art image */
    FILE *fp = fopen("pixel-art.html", "w");
    /* Write the starting HTML code */
    fprintf(fp, "<!DOCTYPE html>\n<html>\n<head>\n<title>Pixel Art Generator</title>\n</head>\n<body>\n");
    /* Write the CSS styles for the pixel grid */
    fprintf(fp, "<style>\n");
    fprintf(fp, "table {\nborder-collapse: collapse;\n}\n");
    fprintf(fp, "td {\nwidth: 20px;\nheight: 20px;\n}\n");
    fprintf(fp, "</style>\n");
    /* Write the opening tag for the pixel grid */
    fprintf(fp, "<table>\n");
    /* Loop through each row and column to generate random pixels */
    for(int i = 0; i < height; i++) {
        fprintf(fp, "<tr>\n");
        for(int j = 0; j < width; j++) {
            /* Generate a random pixel color */
            char* color = generateColor();
            /* Write the pixel to the HTML file */
            fprintf(fp, "<td style=\"background-color:%s;\"></td>\n", color);
        }
        fprintf(fp, "</tr>\n");
    }
    /* Write the closing tag for the pixel grid */
    fprintf(fp, "</table>\n");
    /* Write the ending HTML code */
    fprintf(fp, "</body>\n</html>");
    /* Close the file */
    fclose(fp);
}

int main() {
    /* Seed the random number generator */
    srand(time(NULL));
    /* Prompt the user for the pixel art dimensions */
    int width, height;
    printf("Please enter the width and height of the pixel art image: ");
    scanf("%d %d", &width, &height);
    /* Generate the pixel art */
    generateArt(width, height);
    /* Notify the user that the image has been generated */
    printf("The pixel art image has been generated as pixel-art.html.\n");
    return 0;
}