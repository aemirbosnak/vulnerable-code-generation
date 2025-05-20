//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 1000

typedef struct {
    char name[20];
    int size;
    int creation_time;
} File;

File file_system[MAX_FILES];
int num_files = 0;

void create_file(char *name, int size) {
    if (num_files >= MAX_FILES) {
        printf("Error: File system is full.\n");
        return;
    }

    strcpy(file_system[num_files].name, name);
    file_system[num_files].size = size;
    file_system[num_files].creation_time = time(NULL);

    num_files++;
}

void delete_file(char *name) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(file_system[i].name, name) == 0) {
            num_files--;
            break;
        }
    }
}

void display_file_system() {
    int i;

    printf("File System:\n");
    printf("--------------------\n");
    printf("Name\t\tSize\t\tCreation Time\n");
    printf("--------------------\n");

    for (i = 0; i < num_files; i++) {
        printf("%-20s\t%d\t\t%d\n", file_system[i].name, file_system[i].size, file_system[i].creation_time);
    }
}

int main() {
    int choice, size;
    char name[20];

    srand(time(NULL));

    printf("Welcome to File System Simulator\n");
    printf("---------------------------------\n");

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Display File System\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file name (max 20 characters): ");
                scanf("%s", name);

                printf("Enter file size (1-1000): ");
                scanf("%d", &size);

                create_file(name, size);
                break;

            case 2:
                printf("Enter file name to delete: ");
                scanf("%s", name);

                delete_file(name);
                break;

            case 3:
                display_file_system();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}