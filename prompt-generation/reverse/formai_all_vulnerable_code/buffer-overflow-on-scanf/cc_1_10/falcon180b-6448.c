//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

struct color_code {
    char name[MAX_LENGTH];
    int value;
};

int main() {
    int num_colors;
    struct color_code colors[MAX_LENGTH];
    char input[MAX_LENGTH];

    // Read in number of colors
    printf("Enter the number of color codes: ");
    scanf("%d", &num_colors);

    // Read in each color code
    for (int i = 0; i < num_colors; i++) {
        printf("Enter color code %d: ", i+1);
        scanf("%s", input);

        // Convert input to uppercase
        for (int j = 0; j < strlen(input); j++) {
            input[j] = toupper(input[j]);
        }

        // Look up color code in table
        int found = 0;
        for (int k = 0; k < num_colors; k++) {
            if (strcmp(input, colors[k].name) == 0) {
                found = 1;
                break;
            }
        }

        // If color code not found, add it to table
        if (!found) {
            strcpy(colors[num_colors].name, input);
            colors[num_colors].value = num_colors;
            num_colors++;
        }
    }

    // Print out table of color codes
    printf("\nColor Code Table:\n");
    printf("--------------------\n");
    printf("Name\tValue\n");
    for (int i = 0; i < num_colors; i++) {
        printf("%s\t%d\n", colors[i].name, colors[i].value);
    }

    return 0;
}