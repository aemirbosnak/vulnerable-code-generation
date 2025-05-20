//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 256
#define MAX_COLOR_VALUES 256
#define MAX_COLOR_CODES 256

typedef struct {
    char name[20];
    char hex[8];
    int value;
} Color;

Color colors[MAX_COLOR_NAMES];
int numColors = 0;

void addColor(char* name, char* hex, int value) {
    strcpy(colors[numColors].name, name);
    strcpy(colors[numColors].hex, hex);
    colors[numColors].value = value;
    numColors++;
}

int main() {
    addColor("red", "#FF0000", 0xFF0000);
    addColor("green", "#00FF00", 0x00FF00);
    addColor("blue", "#0000FF", 0x0000FF);

    int choice;
    while(1) {
        printf("1. Convert color code to name\n");
        printf("2. Convert color name to code\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the color code: ");
                char code[8];
                scanf("%s", code);

                int index = -1;
                for(int i=0; i<numColors; i++) {
                    if(strcmp(colors[i].hex, code) == 0) {
                        index = i;
                        break;
                    }
                }

                if(index == -1) {
                    printf("Color not found.\n");
                } else {
                    printf("Color name: %s\n", colors[index].name);
                }
                break;

            case 2:
                printf("Enter the color name: ");
                char name[20];
                scanf("%s", name);

                index = -1;
                for(int i=0; i<numColors; i++) {
                    if(strcmp(colors[i].name, name) == 0) {
                        index = i;
                        break;
                    }
                }

                if(index == -1) {
                    printf("Color not found.\n");
                } else {
                    printf("Color code: %s\n", colors[index].hex);
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}