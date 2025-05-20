//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void embedWatermark(char *filename, char *watermark) {
    FILE *fp = fopen(filename, "r+b");
    if (!fp) {
        printf("Error: Unable to open file\n");
        return;
    }

    char ch, c;
    int i = 0;
    int watermarkLen = strlen(watermark);

    while (1) {
        ch = fgetc(fp);
        if (ch == EOF) {
            printf("Error: End of file reached without embedding watermark\n");
            fclose(fp);
            return;
        }

        if (ch == '0' || ch == '1') {
            c = watermark[i];
            if (c == '\0') {
                fclose(fp);
                return;
            }
            if (c == '0' && ch == '1')
                fseek(fp, -1, SEEK_CUR);
            else if (c == '1' && ch == '0')
                fseek(fp, -1, SEEK_CUR);

            i++;
        }
    }
}

int main() {
    char filename[100], watermark[500];
    printf("Enter name of file to embed watermark: ");
    scanf("%s", filename);

    printf("Enter watermark (binary string): ");
    scanf("%s", watermark);

    embedWatermark(filename, watermark);

    printf("Watermark embedded successfully!\n");

    return 0;
}