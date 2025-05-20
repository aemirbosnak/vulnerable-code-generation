//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

typedef struct {
    char* path;
    char* name;
    long long size;
} FileEntry;

void addEntry(FileEntry* entries, int* numEntries, char* path, char* name, long long size) {
    entries = realloc(entries, sizeof(FileEntry) * (*numEntries + 1));
    entries[*numEntries].path = strdup(path);
    entries[*numEntries].name = strdup(name);
    entries[*numEntries].size = size;
    (*numEntries)++;
}

void printEntries(FileEntry* entries, int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        printf("%s/%s (%lld bytes)\n", entries[i].path, entries[i].name, entries[i].size);
    }
}

void freeEntries(FileEntry* entries, int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        free(entries[i].path);
        free(entries[i].name);
    }
    free(entries);
}

int compareEntries(const void* a, const void* b) {
    FileEntry* entryA = (FileEntry*)a;
    FileEntry* entryB = (FileEntry*)b;
    return strcmp(entryA->name, entryB->name);
}

void analyzeDirectory(char* path) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("Error: Could not open directory '%s'\n", path);
        return;
    }

    FileEntry* entries = NULL;
    int numEntries = 0;

    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        char* fullPath = malloc(strlen(path) + strlen(ent->d_name) + 2);
        strcat(strcat(strcpy(fullPath, path), "/"), ent->d_name);

        struct stat st;
        stat(fullPath, &st);

        if (S_ISDIR(st.st_mode)) {
            printf("Directory: %s\n", ent->d_name);
        } else {
            addEntry(entries, &numEntries, path, ent->d_name, st.st_size);
        }

        free(fullPath);
    }

    closedir(dir);

    qsort(entries, numEntries, sizeof(FileEntry), compareEntries);
    printEntries(entries, numEntries);
    freeEntries(entries, numEntries);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char* path = argv[1];
    analyzeDirectory(path);

    return 0;
}