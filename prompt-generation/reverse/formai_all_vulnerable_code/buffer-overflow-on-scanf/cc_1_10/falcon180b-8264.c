//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

struct color_code {
    char name[10];
    int value;
};

void print_colors() {
    printf("Color Name\tColor Code\n");
    printf("-----------------\n");
    printf("Black\t\t0\n");
    printf("Maroon\t\t1\n");
    printf("Green\t\t2\n");
    printf("Olive\t\t3\n");
    printf("Navy\t\t4\n");
    printf("Purple\t\t5\n");
    printf("Teal\t\t6\n");
    printf("Silver\t\t7\n");
    printf("Gray\t\t8\n");
    printf("Red\t\t9\n");
    printf("Lime\t\t10\n");
    printf("Yellow\t\t11\n");
    printf("Blue\t\t12\n");
    printf("Fuchsia\t13\n");
    printf("Aqua\t\t14\n");
    printf("White\t\t15\n");
}

void add_color_code(struct color_code *colors, int size, char *name, int value) {
    if (size >= MAX_COLORS) {
        printf("Error: Maximum number of colors reached.\n");
        return;
    }

    strcpy(colors[size].name, name);
    colors[size].value = value;
    size++;
}

int main() {
    struct color_code colors[MAX_COLORS];
    int size = 0;

    print_colors();

    char name[10];
    int value;

    while (1) {
        printf("\nEnter color name: ");
        scanf("%s", name);

        if (strcmp(name, "exit") == 0) {
            break;
        }

        printf("Enter color value: ");
        scanf("%d", &value);

        add_color_code(colors, size, name, value);
    }

    printf("\nColor Codes:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%d\n", colors[i].name, colors[i].value);
    }

    return 0;
}