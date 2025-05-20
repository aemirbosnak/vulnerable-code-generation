//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000
#define WATERMARK "bravebot"

void writeWatermark(FILE *file, int pos) {
    int i;
    fseek(file, pos, SEEK_SET);
    for (i = 0; i < strlen(WATERMARK); i++) {
        fputc(WATERMARK[i], file);
    }
}

int readWatermark(FILE *file, int pos) {
    int i;
    char buffer[MAX_LEN];
    fseek(file, pos, SEEK_SET);
    for (i = 0; i < strlen(WATERMARK); i++) {
        buffer[i] = fgetc(file);
    }
    buffer[i] = '\0';
    if (strcmp(buffer, WATERMARK) == 0) {
        return 1;
    }
    return 0;
}

int main() {
    FILE *file;
    char filename[MAX_LEN], buffer[MAX_LEN];
    int option, pos;
    printf("Enter the name of the file: ");
    scanf("%s", filename);
    file = fopen(filename, "r+");
    if (file == NULL) {
        printf("Failed to open file %s\n", filename);
        return 1;
    }
    do {
        printf("\n1 - Write watermark\n2 - Read watermark\n3 - Exit\nEnter your choice: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter the position to start watermarking (0-%ld): ", ftell(file));
                scanf("%d", &pos);
                writeWatermark(file, pos);
                printf("Watermark written successfully\n");
                break;
            case 2:
                printf("Enter the position to read watermarking (0-%ld): ", ftell(file));
                scanf("%d", &pos);
                if (readWatermark(file, pos)) {
                    printf("The watermark was found\n");
                } else {
                    printf("The watermark was not found\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option, please try again\n");
                break;
        }
    } while (option != 3);
    fclose(file);
    return 0;
}