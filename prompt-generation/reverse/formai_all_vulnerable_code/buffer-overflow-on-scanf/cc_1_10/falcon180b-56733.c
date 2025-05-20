//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 1000
#define MAX_FILENAME_LENGTH 1000

typedef struct {
    int key_length;
    char key[MAX_KEY_LENGTH];
} Key;

typedef struct {
    FILE *in_file;
    FILE *out_file;
    int key_length;
    char key[MAX_KEY_LENGTH];
} Context;

void generate_key(char *key, int key_length) {
    int i;
    for (i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_length] = '\0';
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char key[MAX_KEY_LENGTH];
    int key_length;

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    printf("Enter the key length: ");
    scanf("%d", &key_length);

    generate_key(key, key_length);

    Context context = {
       .in_file = fopen(filename, "r"),
       .out_file = fopen("encrypted.txt", "w"),
       .key_length = key_length,
       .key = key
    };

    if (context.in_file == NULL || context.out_file == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }

    char buffer[1024];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), context.in_file)) > 0) {
        int i;
        for (i = 0; i < bytes_read; i++) {
            char c = tolower(buffer[i]);
            if (isalpha(c)) {
                int j = (c - 'a') % 26;
                if (j < 0) {
                    j += 26;
                }
                c = (char) ((int) c + (int) key[j]);
                if (c > 'z') {
                    c = (char) ((int) c - 26);
                }
            }
            fprintf(context.out_file, "%c", c);
        }
    }

    fclose(context.in_file);
    fclose(context.out_file);

    printf("File encrypted successfully.\n");

    return 0;
}