//FormAI DATASET v1.0 Category: Data recovery tool ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[100], ch;
    int num_chars, i;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: File not found\n");
        return 1;
    }

    // Count number of characters in file
    num_chars = 0;
    while (fscanf(fp, "%c", &ch) != EOF) {
        num_chars++;
    }
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for data storage
    char **data = malloc(num_chars * sizeof(char*));
    for (i = 0; i < num_chars; i++) {
        data[i] = malloc(2 * sizeof(char));
    }

    // Read data from file into memory
    i = 0;
    while (fscanf(fp, "%c", &ch) != EOF) {
        sprintf(data[i], "%c", ch);
        i++;
    }

    fclose(fp);

    // Print recovered data
    for (i = 0; i < num_chars; i++) {
        printf("%s", data[i]);
    }

    // Free allocated memory
    for (i = 0; i < num_chars; i++) {
        free(data[i]);
    }
    free(data);

    return 0;
}