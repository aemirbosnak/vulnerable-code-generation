//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

/* Encrypt a file using a Caesar cipher with a given key */
void encrypt_file(FILE *in_file, FILE *out_file, int key) {
    char c;
    while ((c = fgetc(in_file))!= EOF) {
        if (isalpha(c)) {
            if (isupper(c)) {
                c = (c + key - 65) % 26 + 65;
            } else {
                c = (c + key - 97) % 26 + 97;
            }
        }
        fputc(c, out_file);
    }
}

int main() {
    /* Prompt user for input file name */
    printf("Enter input file name: ");
    char in_file_name[100];
    scanf("%s", in_file_name);

    /* Open input file for reading */
    FILE *in_file = fopen(in_file_name, "r");
    if (in_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    /* Prompt user for output file name */
    printf("Enter output file name: ");
    char out_file_name[100];
    scanf("%s", out_file_name);

    /* Open output file for writing */
    FILE *out_file = fopen(out_file_name, "w");
    if (out_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    /* Prompt user for encryption key */
    int key;
    printf("Enter encryption key (1-25): ");
    scanf("%d", &key);

    /* Encrypt the file */
    encrypt_file(in_file, out_file, key);

    /* Close files and exit */
    fclose(in_file);
    fclose(out_file);
    printf("File encrypted successfully.\n");
    return 0;
}