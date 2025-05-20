//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Color {
    char name[20];
    int value;
};

void readColors(struct Color colors[]) {
    FILE *file;
    file = fopen("colors.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }
    int count = 0;
    while (fscanf(file, "%s %d\n", colors[count].name, &colors[count].value)!= EOF) {
        count++;
    }
    fclose(file);
}

void displayColors(struct Color colors[], int count) {
    printf("Color Name\tColor Value\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%d\n", colors[i].name, colors[i].value);
    }
}

void searchColor(struct Color colors[], int count, char search[]) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(colors[i].name, search) == 0) {
            printf("Color Name: %s\nColor Value: %d\n", colors[i].name, colors[i].value);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("Color not found.\n");
    }
}

int main() {
    struct Color colors[100];
    int count;
    readColors(colors);
    count = sizeof(colors) / sizeof(colors[0]);
    printf("Enter a color name to search:\n");
    char search[20];
    scanf("%s", search);
    searchColor(colors, count, search);
    return 0;
}