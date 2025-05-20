//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    char input_file[MAX_SIZE];
    char output_file[MAX_SIZE];
    char key[MAX_SIZE];

    strcpy(input_file, argv[1]);
    strcpy(output_file, argv[2]);
    strcpy(key, argv[3]);

    FILE *in_file = fopen(input_file, "r");
    if (in_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE *out_file = fopen(output_file, "w");
    if (out_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(in_file);
        return 1;
    }

    char ch;
    int key_index = 0;
    while ((ch = fgetc(in_file))!= EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            ch = ch + key[key_index];
            if (ch > 'Z') {
                ch = ch - 26;
            } else if (ch < 'A') {
                ch = ch + 26;
            }
            key_index = (key_index + 1) % strlen(key);
        } else {
            ch = ch;
        }
        fprintf(out_file, "%c", ch);
    }

    fclose(in_file);
    fclose(out_file);

    printf("File encryption successful.\n");

    return 0;
}