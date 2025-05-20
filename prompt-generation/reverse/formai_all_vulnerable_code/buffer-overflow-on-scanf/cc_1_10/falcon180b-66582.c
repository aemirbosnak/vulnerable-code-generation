//Falcon-180B DATASET v1.0 Category: System administration ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_LINE_SIZE 1024
#define MAX_FILE_SIZE 1024*1024*100 // 100MB

typedef struct {
    char *name;
    int size;
} FileInfo;

int main() {
    DIR *dir;
    struct dirent *ent;
    char path[MAX_LINE_SIZE];
    char file_path[MAX_LINE_SIZE];
    FILE *file;
    char buffer[MAX_LINE_SIZE];
    int file_size = 0;

    printf("Enter the directory path: ");
    scanf("%s", path);

    dir = opendir(path);

    if (dir == NULL) {
        printf("Directory not found.\n");
        return 1;
    }

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) { // Regular file
            strcpy(file_path, path);
            strcat(file_path, "/");
            strcat(file_path, ent->d_name);

            file = fopen(file_path, "r");

            if (file == NULL) {
                printf("Error opening file: %s\n", file_path);
                continue;
            }

            while (fgets(buffer, MAX_LINE_SIZE, file)!= NULL) {
                if (strlen(buffer) > MAX_LINE_SIZE) {
                    printf("Line too long: %s\n", buffer);
                    continue;
                }

                if (file_size + strlen(buffer) > MAX_FILE_SIZE) {
                    printf("File too large: %s\n", file_path);
                    fclose(file);
                    remove(file_path);
                    continue;
                }

                file_size += strlen(buffer);
            }

            fclose(file);
        }
    }

    closedir(dir);

    return 0;
}