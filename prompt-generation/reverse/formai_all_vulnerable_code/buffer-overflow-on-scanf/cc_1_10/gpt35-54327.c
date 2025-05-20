//FormAI DATASET v1.0 Category: Data recovery tool ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DATA 100
#define MAX_FILES 10 

struct Data {
    int id;
    char filename[MAX_DATA];
    char content[MAX_DATA];
};

void initialize(struct Data* data);
void generate_files(struct Data* data, int num_files);
int recover_file(struct Data* data, int num_files, char* filename);
void print_files(struct Data* data, int num_files);

int main() {
    srand(time(NULL));

    struct Data data[MAX_FILES];
    initialize(data);

    int num_files = rand() % MAX_FILES + 1;
    generate_files(data, num_files);

    printf("Files on disk: \n");
    print_files(data, num_files);

    char filename[MAX_DATA];
    printf("Enter filename to recover: ");
    scanf("%s", filename);

    int recovered_file = recover_file(data, num_files, filename);

    if (recovered_file == -1) {
        printf("\nFile not found.\n");
    } else {
        printf("\nRecovered file:\n");
        printf("File ID: %d\n", data[recovered_file].id);
        printf("Filename: %s\n", data[recovered_file].filename);
        printf("Content: %s\n", data[recovered_file].content);
    }

    return 0;
}

void initialize(struct Data* data) {
    for (int i = 0; i < MAX_FILES; i++) {
        data[i].id = i + 1;
        strcpy(data[i].filename, "");
        strcpy(data[i].content, "");
    }
}

void generate_files(struct Data* data, int num_files) {
    for (int i = 0; i < num_files; i++) {
        int id = i + 1;
        char filename[MAX_DATA];
        char content[MAX_DATA];

        sprintf(filename, "file%d.txt", id);
        sprintf(content, "Random text for file %d.", id);

        strcpy(data[i].filename, filename);
        strcpy(data[i].content, content);
    }
}

int recover_file(struct Data* data, int num_files, char* filename) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(data[i].filename, filename) == 0) {
            return i;
        }
    }
    return -1;
}

void print_files(struct Data* data, int num_files) {
    for (int i = 0; i < num_files; i++) {
        printf("File ID: %d \tFilename: %s\n", data[i].id, data[i].filename);
    }
}