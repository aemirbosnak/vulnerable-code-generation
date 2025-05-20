//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define WIDTH 80
#define HEIGHT 25
#define CHAR_SET "~!@#$%^&*()_-+=[{]}\\|;:'\",.<>/?`~"

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[256];
    char *data;
    int size, i, j, k;
    int foreground = 0, background = 0;
    int color = 0;
    int pos = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);
    if ((file = fopen(filename, "r")) == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    data = (char *) malloc(size + 1);
    if (data == NULL) {
        printf("Error: Could not allocate memory.\n");
        fclose(file);
        return 1;
    }

    fread(data, size, 1, file);
    fclose(file);

    for (i = 0; i < size; i++) {
        if (isprint(data[i]) || data[i] == '\n') {
            pos = (pos + 1) % WIDTH;
            if (pos == 0) {
                printf("\n");
            }
            if (isupper(data[i])) {
                foreground = 1;
            } else if (islower(data[i])) {
                foreground = 2;
            } else if (data[i] == '\n') {
                foreground = 0;
            }
            if (foreground == 0) {
                printf("%c", data[i]);
            } else {
                printf("\033[1;%d;%dm%c\033[0m", foreground + 30, background + 40, data[i]);
            }
        } else {
            printf("%c", data[i]);
        }
    }

    free(data);
    return 0;
}