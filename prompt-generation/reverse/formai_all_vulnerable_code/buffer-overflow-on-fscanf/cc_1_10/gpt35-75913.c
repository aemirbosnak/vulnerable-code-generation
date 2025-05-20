//FormAI DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

void compress(char* input, char* output) {
    FILE *fin, *fout;
    fin = fopen(input, "rb");
    fout = fopen(output, "wb");

    if(fin == NULL || fout == NULL) {
        printf("Error opening files");
        exit(1);
    }

    int prev_char = EOF;
    int count = 0;

    while(1) {
        int curr_char = fgetc(fin);

        if(curr_char == EOF) {
            fprintf(fout, "%d %d", prev_char, count);
            break;
        }

        if(prev_char == curr_char) {
            count++;
        } else {
            fprintf(fout, "%d %d ", prev_char, count);
            prev_char = curr_char;
            count = 1;
        }
    }

    fclose(fin);
    fclose(fout);
}

void decompress(char* input, char* output) {
    FILE *fin, *fout;
    fin = fopen(input, "rb");
    fout = fopen(output, "wb");

    if(fin == NULL || fout == NULL) {
        printf("Error opening files");
        exit(1);
    }

    while(!feof(fin)) {
        int curr_char, count;
        fscanf(fin, "%d %d ", &curr_char, &count);

        for(int i=0; i<count; i++) {
            fprintf(fout, "%c", curr_char);
        }
    }

    fclose(fin);
    fclose(fout);
}

int main() {
    char input[] = "input.txt";
    char compressed[] = "compressed.txt";
    char decompressed[] = "decompressed.txt";

    printf("Compressing file...\n");
    compress(input, compressed);
    printf("Done.\n\n");

    printf("Decompressing file...\n");
    decompress(compressed, decompressed);
    printf("Done.");

    return 0;
}