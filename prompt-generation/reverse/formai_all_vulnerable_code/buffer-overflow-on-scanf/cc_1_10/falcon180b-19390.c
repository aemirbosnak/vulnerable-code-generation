//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 100
#define MAX_NUM_FILES 10

typedef struct {
    char filename[20];
    char content[MAX_FILE_SIZE];
    int size;
} File;

File files[MAX_NUM_FILES];
int num_files = 0;

void create_file(char *filename) {
    if (num_files >= MAX_NUM_FILES) {
        printf("Error: Too many files\n");
        return;
    }
    strcpy(files[num_files].filename, filename);
    files[num_files].size = 0;
    num_files++;
}

void write_to_file(char *filename, char *content) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            strcat(files[i].content, content);
            files[i].size += strlen(content);
            break;
        }
    }
}

void read_from_file(char *filename) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            printf("%s\n", files[i].content);
            break;
        }
    }
}

void delete_file(char *filename) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            memset(files[i].filename, 0, 20);
            memset(files[i].content, 0, MAX_FILE_SIZE);
            files[i].size = 0;
            break;
        }
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Create file\n2. Write to file\n3. Read from file\n4. Delete file\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter filename: ");
                scanf("%s", files[num_files-1].filename);
                break;
            case 2:
                printf("Enter content: ");
                scanf("%s", files[num_files-1].content);
                break;
            case 3:
                read_from_file(files[num_files-1].filename);
                break;
            case 4:
                delete_file(files[num_files-1].filename);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);
    return 0;
}