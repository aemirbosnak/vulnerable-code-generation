//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING 1000
#define MAX_VIRUS_LENGTH 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char name[MAX_STRING];
    int size;
} file_t;

file_t files[MAX_FILE_SIZE];
int num_files = 0;

void add_file(char *filename, int size) {
    if (num_files >= MAX_FILE_SIZE) {
        printf("Error: Too many files.\n");
        exit(1);
    }
    strcpy(files[num_files].name, filename);
    files[num_files].size = size;
    num_files++;
}

void scan_files() {
    int i;
    for (i = 0; i < num_files; i++) {
        FILE *fp = fopen(files[i].name, "rb");
        if (!fp) {
            printf("Error: File not found.\n");
            exit(1);
        }
        char buffer[MAX_STRING];
        int j = 0;
        while (fgets(buffer, MAX_STRING, fp)) {
            int len = strlen(buffer);
            if (len > MAX_VIRUS_LENGTH) {
                printf("Error: Line too long.\n");
                exit(1);
            }
            int k;
            for (k = 0; k < len; k++) {
                if (!isprint(buffer[k])) {
                    printf("Error: Invalid character.\n");
                    exit(1);
                }
            }
            j += len;
        }
        fclose(fp);
    }
}

int main() {
    char filename[MAX_STRING];
    while (1) {
        printf("Enter filename: ");
        scanf("%s", filename);
        add_file(filename, 0);
    }
    scan_files();
    return 0;
}