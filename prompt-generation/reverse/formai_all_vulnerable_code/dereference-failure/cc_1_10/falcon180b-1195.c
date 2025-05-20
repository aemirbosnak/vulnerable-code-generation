//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_NAME_SIZE 1024

typedef struct {
    FILE *file;
    char filename[MAX_FILE_NAME_SIZE];
    int current_line;
} FileHandle;

void read_file_line(FileHandle *file, char *buffer) {
    char c;
    int i = 0;
    do {
        c = fgetc(file->file);
        if (c!= '\n' && c!= EOF) {
            buffer[i++] = c;
        }
    } while (c!= EOF && i < MAX_FILE_NAME_SIZE);
    buffer[i] = '\0';
    file->current_line++;
}

int is_virus(char *line) {
    if (strstr(line, "virus")!= NULL) {
        return 1;
    }
    return 0;
}

void scan_directory(char *path) {
    DIR *dir;
    struct dirent *ent;
    dir = opendir(path);
    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_REG) {
                FileHandle file;
                char filename[MAX_FILE_NAME_SIZE];
                sprintf(filename, "%s/%s", path, ent->d_name);
                file.file = fopen(filename, "r");
                if (file.file!= NULL) {
                    int virus_found = 0;
                    char line[1024];
                    while (fgets(line, sizeof(line), file.file)!= NULL) {
                        if (is_virus(line)) {
                            virus_found = 1;
                            break;
                        }
                    }
                    if (virus_found) {
                        printf("Virus found in file: %s\n", file.filename);
                    }
                    fclose(file.file);
                }
            }
        }
        closedir(dir);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    scan_directory(argv[1]);
    return 0;
}