//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 100
#define MAX_COLOR_CODE_LENGTH 7

typedef struct {
    char *name;
    char code[MAX_COLOR_CODE_LENGTH];
} Color;

Color colorList[MAX_COLOR_NAMES];
int numColors = 0;

void addColor(char *name, char *code) {
    if (numColors >= MAX_COLOR_NAMES) {
        printf("Error: Too many colors!\n");
        exit(1);
    }

    strcpy(colorList[numColors].name, name);
    strcpy(colorList[numColors].code, code);

    numColors++;
}

int main() {
    addColor("red", "#FF0000");
    addColor("green", "#00FF00");
    addColor("blue", "#0000FF");
    addColor("yellow", "#FFFF00");
    addColor("purple", "#FF00FF");
    addColor("orange", "#FFA500");

    int choice;

    printf("Color Code Converter\n");
    printf("---------------------\n");

    do {
        printf("\nEnter your choice:\n");
        printf("1. Convert color name to code\n");
        printf("2. Convert color code to name\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter color name: ");
                char name[100];
                scanf("%s", name);

                int i;
                for (i = 0; i < numColors; i++) {
                    if (strcmp(name, colorList[i].name) == 0) {
                        printf("Color code: %s\n", colorList[i].code);
                        break;
                    }
                }

                if (i == numColors) {
                    printf("Color not found!\n");
                }
                break;

            case 2:
                printf("Enter color code: ");
                char code[MAX_COLOR_CODE_LENGTH];
                scanf("%s", code);

                int j;
                for (j = 0; j < numColors; j++) {
                    if (strcmp(colorList[j].code, code) == 0) {
                        printf("Color name: %s\n", colorList[j].name);
                        break;
                    }
                }

                if (j == numColors) {
                    printf("Color not found!\n");
                }
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}