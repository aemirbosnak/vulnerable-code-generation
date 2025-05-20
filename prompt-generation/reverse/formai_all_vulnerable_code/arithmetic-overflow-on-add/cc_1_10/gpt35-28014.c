//FormAI DATASET v1.0 Category: Compression algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

void compress(char *input_file, char *output_file) {
    FILE *fp1, *fp2;
    char buffer[MAX_SIZE];
    char compressed[MAX_SIZE];
    int count, i, j, k, len;
    int output_size = 0;

    fp1 = fopen(input_file, "rb");
    if(fp1 == NULL) {
        printf("Error: cannot open file %s\n", input_file);
        exit(1);
    }

    fp2 = fopen(output_file, "wb");
    if(fp2 == NULL) {
        printf("Error: cannot open file %s\n", output_file);
        exit(1);
    }

    while(!feof(fp1)) {
        int c = fgetc(fp1);
        if(c != EOF) {
            buffer[count++] = c; 
        }
        if(count == MAX_SIZE) {
            len = count;
            i = 0;
            while(i < len) {
                j = i + 1;
                while(j < len && buffer[i] == buffer[j]) {
                    ++j;
                }
                compressed[k++] = buffer[i];
                compressed[k++] = j - i;
                i = j;
            }
            fwrite(compressed, sizeof(char), k, fp2);
            output_size += k;
            count = 0;
            k = 0;
        }
    }

    if(count > 0) {
        len = count;
        i = 0;
        while(i < len) {
            j = i + 1;
            while(j < len && buffer[i] == buffer[j]) {
                ++j;
            }
            compressed[k++] = buffer[i];
            compressed[k++] = j - i;
            i = j;
        }
        fwrite(compressed, sizeof(char), k, fp2);
        output_size += k;
    }

    printf("Compressed %s to %s (%d%% reduction)\n", input_file, output_file, (int)((1 - (float)output_size / (float)ftell(fp1)) * 100));
    fclose(fp1);
    fclose(fp2);
}

int main(int argc, char const *argv[]) {
    if(argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 0;
    }
    compress(argv[1], argv[2]);
    return 0;
}