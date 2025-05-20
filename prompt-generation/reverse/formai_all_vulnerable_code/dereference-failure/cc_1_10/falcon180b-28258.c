//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 256

struct color_name {
    char *name;
    int value;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        return 1;
    }

    char *color_name = argv[1];
    int value = 0;

    // Check if color name is a valid hexadecimal value
    if (strlen(color_name) == 6 && color_name[0] == '#') {
        sscanf(color_name + 1, "%02x%02x%02x", &value, &value, &value);
    } else {
        // Search for color name in the color_names array
        struct color_name *color_names = malloc(MAX_COLOR_NAMES * sizeof(struct color_name));
        int num_color_names = 0;

        FILE *fp = fopen("color_names.txt", "r");
        if (fp!= NULL) {
            char line[256];
            while (fgets(line, sizeof(line), fp)!= NULL) {
                char *name = strtok(line, " ");
                int rgb_value = strtol(name, NULL, 16);

                struct color_name *color = realloc(color_names, (num_color_names + 1) * sizeof(struct color_name));
                color[num_color_names].name = strdup(name);
                color[num_color_names].value = rgb_value;
                num_color_names++;
            }
            fclose(fp);
        } else {
            printf("Error: Could not open color_names.txt\n");
            return 1;
        }

        for (int i = 0; i < num_color_names; i++) {
            if (strcmp(color_name, color_names[i].name) == 0) {
                value = color_names[i].value;
                break;
            }
        }

        free(color_names);
    }

    printf("Color name: %s\n", color_name);
    printf("RGB value: %06x\n", value);
    printf("Hex value: #%06x\n", value);

    return 0;
}