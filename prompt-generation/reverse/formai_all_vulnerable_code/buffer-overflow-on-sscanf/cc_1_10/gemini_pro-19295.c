//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *name;
    char *path;
    time_t last_modified;
} file_info;

int find_file(FILE *fp, char *name) {
    char buf[BUFSIZ];
    int line = 1;
    while (fgets(buf, sizeof(buf), fp)) {
        if (strstr(buf, name)) {
            return line;
        }
        line++;
    }
    return -1;
}

void print_file_info(file_info *file) {
    printf("Name: %s\n", file->name);
    printf("Path: %s\n", file->path);
    printf("Last Modified: %s\n", ctime(&file->last_modified));
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp1 = fopen(argv[1], "r");
    if (fp1 == NULL) {
        perror("Error opening file1");
        return EXIT_FAILURE;
    }

    FILE *fp2 = fopen(argv[2], "r");
    if (fp2 == NULL) {
        perror("Error opening file2");
        return EXIT_FAILURE;
    }

    int line1 = find_file(fp1, argv[2]);
    if (line1 == -1) {
        printf("File %s not found in file1\n", argv[2]);
        return EXIT_FAILURE;
    }

    int line2 = find_file(fp2, argv[1]);
    if (line2 == -1) {
        printf("File %s not found in file2\n", argv[1]);
        return EXIT_FAILURE;
    }

    fseek(fp1, 0, SEEK_SET);
    fseek(fp2, 0, SEEK_SET);

    char buf1[BUFSIZ];
    char buf2[BUFSIZ];

    while (fgets(buf1, sizeof(buf1), fp1)) {
        if (strstr(buf1, argv[2])) {
            file_info file1;
            sscanf(buf1, "%s %s %ld", file1.name, file1.path, &file1.last_modified);
            print_file_info(&file1);
        }
    }

    while (fgets(buf2, sizeof(buf2), fp2)) {
        if (strstr(buf2, argv[1])) {
            file_info file2;
            sscanf(buf2, "%s %s %ld", file2.name, file2.path, &file2.last_modified);
            print_file_info(&file2);
        }
    }

    fclose(fp1);
    fclose(fp2);

    return EXIT_SUCCESS;
}