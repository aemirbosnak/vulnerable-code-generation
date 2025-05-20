#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_image(char *filename, char *filter) {
    FILE *fp;
    int i, j;
    int img[3][1024];
    char buffer[1024];

    if (!(fp = fopen(filename, "r"))) {
        printf("Error opening file.\n");
        return;
    }

    for (i = 0; fscanf(fp, "%s", buffer) == 1; i++) {
        for (j = 0; j < strlen(buffer); j++) {
            img[i % 3][j] = filter[(buffer[j] - '0') % 10];
        }
    }

    fclose(fp);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 1024; j++) {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./image_filter <image_file> <filter_string>\n");
        return 1;
    }

    process_image(argv[1], argv[2]);

    return 0;
}
