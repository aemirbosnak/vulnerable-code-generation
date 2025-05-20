//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_SIZE 1024 //maximum key size

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];
    char key[MAX_KEY_SIZE];
    int key_size, ch;

    //get key from user
    printf("Enter encryption key: ");
    fgets(key, MAX_KEY_SIZE, stdin);
    key_size = strlen(key);

    //remove newline character from key
    if (key[key_size - 1] == '\n') {
        key[key_size - 1] = '\0';
        key_size--;
    }

    //get input file name from user
    printf("Enter input file name: ");
    scanf("%s", input_filename);

    //open input file
    input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    //get output file name from user
    printf("Enter output file name: ");
    scanf("%s", output_filename);

    //open output file
    output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    //encrypt file
    int i, j;
    char buffer[1024];
    while ((ch = fgetc(input_file))!= EOF) {
        buffer[0] = ch;
        for (i = 1; i < key_size; i++) {
            buffer[i] = ch ^ key[i - 1];
        }
        for (i = 0; i < key_size; i++) {
            j = (i + 1) % key_size;
            buffer[j] = buffer[i];
            buffer[i] = ch ^ key[j];
        }
        fputc(buffer[0], output_file);
    }

    //close files
    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully!\n");
    return 0;
}