//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define SIZE 100
#define LETTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[20];
    char cipher[SIZE];
    int i, j, k, n;
    int key = 0;
    char letter;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("Enter the key: ");
    scanf("%d", &key);

    rewind(file);

    while ((letter = fgetc(file))!= EOF) {
        cipher[i] = letter;
        i++;
    }

    fclose(file);

    for (i = 0; i < strlen(cipher); i++) {
        if (isalpha(cipher[i])) {
            cipher[i] = LETTERS[(int)cipher[i] + key % 26];
        } else {
            cipher[i] = cipher[i];
        }
    }

    file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    for (i = 0; i < strlen(cipher); i++) {
        fprintf(file, "%c", cipher[i]);
    }

    fclose(file);

    printf("File encrypted successfully.\n");

    return 0;
}