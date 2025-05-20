//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LEN 100
#define MAX_FILE_SIZE 1000

typedef struct {
    char name[MAX_FILE_NAME_LEN];
    char content[MAX_FILE_SIZE];
    int size;
} File;

int num_files = 0;
File files[MAX_FILES];

void create_file(char *name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("Error: File already exists.\n");
            return;
        }
    }
    strcpy(files[num_files].name, name);
    files[num_files].size = 0;
    num_files++;
}

void delete_file(char *name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(files[i].content, 0, MAX_FILE_SIZE);
            strcpy(files[i].name, "");
            files[i].size = 0;
            num_files--;
            return;
        }
    }
    printf("Error: File not found.\n");
}

void write_to_file(char *name, char *content) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strcat(files[i].content, content);
            files[i].size += strlen(content);
            return;
        }
    }
    printf("Error: File not found.\n");
}

void read_from_file(char *name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("%s", files[i].content);
            return;
        }
    }
    printf("Error: File not found.\n");
}

int main() {
    int choice;
    char name[MAX_FILE_NAME_LEN];
    char content[MAX_FILE_SIZE];

    while (1) {
        printf("\n1. Create file\n2. Delete file\n3. Write to file\n4. Read from file\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter file name: ");
            scanf("%s", name);
            create_file(name);
            break;
        case 2:
            printf("Enter file name: ");
            scanf("%s", name);
            delete_file(name);
            break;
        case 3:
            printf("Enter file name: ");
            scanf("%s", name);
            printf("Enter content: ");
            scanf("%s", content);
            write_to_file(name, content);
            break;
        case 4:
            printf("Enter file name: ");
            scanf("%s", name);
            read_from_file(name);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}