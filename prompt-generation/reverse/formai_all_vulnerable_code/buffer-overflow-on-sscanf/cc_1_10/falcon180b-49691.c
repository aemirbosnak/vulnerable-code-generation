//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 256

struct Color {
    char name[20];
    int red, green, blue;
};

int main() {
    FILE *file;
    char line[100];
    int count = 0;
    struct Color colors[MAX_COLORS];

    file = fopen("colors.txt", "r");

    if (file == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (count >= MAX_COLORS) {
            printf("Error: Maximum colors reached\n");
            exit(2);
        }

        sscanf(line, "%s %d %d %d", colors[count].name, &colors[count].red, &colors[count].green, &colors[count].blue);
        count++;
    }

    fclose(file);

    printf("Enter a color name: ");
    scanf("%s", line);

    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(line, colors[i].name) == 0) {
            printf("RGB: %d %d %d\n", colors[i].red, colors[i].green, colors[i].blue);
            return 0;
        }
    }

    printf("Error: Color not found\n");
    return 1;
}