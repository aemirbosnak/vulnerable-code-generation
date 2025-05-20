//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int size;
} File;

void create_file(File *file, char *name, int size) {
    file->name = (char *) malloc(strlen(name) + 1);
    strcpy(file->name, name);
    file->size = size;
}

void display_file(File file) {
    printf("Name: %s\n", file.name);
    printf("Size: %d\n", file.size);
}

int main() {
    File files[MAX_SIZE];
    int num_files = 0;

    char search_name[100];
    int search_size;

    printf("Enter the number of files: ");
    scanf("%d", &num_files);

    for (int i = 0; i < num_files; i++) {
        printf("Enter the name of file %d: ", i + 1);
        scanf("%s", files[i].name);
        printf("Enter the size of file %d: ", i + 1);
        scanf("%d", &files[i].size);
    }

    printf("\nEnter the name of the file to search: ");
    scanf("%s", search_name);
    printf("Enter the size of the file to search: ");
    scanf("%d", &search_size);

    int found = 0;

    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, search_name) == 0 && files[i].size == search_size) {
            printf("\nFile found: %s\n", files[i].name);
            display_file(files[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nFile not found.\n");
    }

    return 0;
}