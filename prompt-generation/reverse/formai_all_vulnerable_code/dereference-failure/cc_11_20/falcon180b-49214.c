//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 100) // 100 MB

typedef struct {
    char *filename;
    FILE *file;
    int size;
    char *data;
} FileRecovery;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file '%s'\n", filename);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    if (size > MAX_FILE_SIZE) {
        printf("File is too large (%d bytes)\n", size);
        fclose(file);
        return 1;
    }

    rewind(file);
    char *data = (char *) malloc(size + 1);
    if (!data) {
        printf("Error allocating memory\n");
        fclose(file);
        return 1;
    }

    int bytes_read = fread(data, 1, size, file);
    if (bytes_read!= size) {
        printf("Error reading file\n");
        free(data);
        fclose(file);
        return 1;
    }

    fclose(file);

    FileRecovery recovery = {
       .filename = filename,
       .file = NULL,
       .size = size,
       .data = data
    };

    int choice;
    while (1) {
        printf("\nData Recovery Tool\n");
        printf("1. Save recovered data to a file\n");
        printf("2. View recovered data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the output filename: ");
            char *output_filename = (char *) malloc(strlen(filename) + 10);
            strcpy(output_filename, filename);
            strcat(output_filename, "_recovered.txt");
            FILE *output_file = fopen(output_filename, "w");
            if (!output_file) {
                printf("Error opening output file\n");
                free(output_filename);
                break;
            }
            fwrite(recovery.data, 1, recovery.size, output_file);
            fclose(output_file);
            printf("Data saved to %s\n", output_filename);
            free(output_filename);
            break;

        case 2:
            printf("Recovered data:\n%s", recovery.data);
            break;

        case 3:
            free(recovery.data);
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}