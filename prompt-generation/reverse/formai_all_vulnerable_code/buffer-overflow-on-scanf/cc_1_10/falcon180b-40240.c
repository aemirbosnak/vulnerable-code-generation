//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct color {
    char name[MAX];
    int value;
};

void add_color(struct color *list, char *name, int value) {
    int i = 0;
    while (i < MAX && list[i].name[0]!= '\0') {
        i++;
    }
    strcpy(list[i].name, name);
    list[i].value = value;
}

int main() {
    struct color list[MAX];
    int i = 0;
    char name[MAX];
    int value;

    printf("Enter color names and their corresponding values (enter 'done' when finished):\n");

    while (scanf("%s %d", name, &value) == 2) {
        if (strcmp(name, "done") == 0) {
            break;
        }
        add_color(list, name, value);
        i++;
    }

    printf("Enter a color name to convert:\n");
    scanf("%s", name);

    int found = 0;
    for (int j = 0; j < i; j++) {
        if (strcmp(list[j].name, name) == 0) {
            printf("The %s color code is: %d\n", name, list[j].value);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Color '%s' not found\n", name);
    }

    return 0;
}