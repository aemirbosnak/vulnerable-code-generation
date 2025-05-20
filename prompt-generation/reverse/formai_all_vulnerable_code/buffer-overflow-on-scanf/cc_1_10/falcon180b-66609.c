//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char filename[100];
    int size;
    char data[1024];
} file_info;

int main() {
    FILE *fp;
    char line[1024];
    file_info files[100];
    int count = 0;
    char directory[100];
    printf("Enter the directory path: ");
    scanf("%s", directory);

    fp = fopen(directory, "r");

    if (fp == NULL) {
        printf("Error opening directory\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (line[0]!= '.') {
            strcpy(files[count].filename, line);
            files[count].size = strlen(line);
            count++;
        }
    }

    fclose(fp);

    printf("Enter the filename to recover: ");
    scanf("%s", line);

    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(line, files[i].filename) == 0) {
            printf("Recovering %s...\n", line);
            fp = fopen(line, "r");
            if (fp == NULL) {
                printf("Error opening file\n");
                exit(1);
            }

            char ch;
            while ((ch = fgetc(fp))!= EOF) {
                strcat(files[i].data, &ch);
            }

            fclose(fp);
            printf("File recovered successfully!\n");
            break;
        }
    }

    return 0;
}