//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 32

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    char hex[8];
} Color;

Color colors[] = {
    {"Black", "000000"},
    {"White", "FFFFFF"},
    {"Red", "FF0000"},
    {"Green", "00FF00"},
    {"Blue", "0000FF"},
    {"Yellow", "FFFF00"},
    {"Cyan", "00FFFF"},
    {"Magenta", "FF00FF"},
    {"Silver", "C0C0C0"},
    {"Gray", "808080"},
    {"Maroon", "800000"},
    {"Olive", "808000"},
    {"Lime", "00FF00"},
    {"Teal", "008080"},
    {"Navy", "000080"},
    {"Purple", "800080"},
    {"Fuchsia", "FF00FF"}
};

int main() {
    Color color;
    char input[MAX_COLOR_NAME_LENGTH];
    char hex[9];
    int i;

    printf("Enter a color name (or 'exit' to quit): ");
    scanf("%s", input);

    while (strcmp(input, "exit")!= 0) {
        for (i = 0; i < sizeof(colors)/sizeof(Color); i++) {
            if (strcmp(colors[i].name, input) == 0) {
                strcpy(color.name, colors[i].name);
                strcpy(color.hex, colors[i].hex);
                printf("%s (%s)\n", color.name, color.hex);
                break;
            }
        }

        if (i == sizeof(colors)/sizeof(Color)) {
            printf("Invalid color name\n");
        }

        printf("Enter a color name (or 'exit' to quit): ");
        scanf("%s", input);
    }

    return 0;
}