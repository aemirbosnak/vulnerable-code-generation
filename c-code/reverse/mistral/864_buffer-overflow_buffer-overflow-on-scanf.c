#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 10
#define MAX_CONTENT_LENGTH 50
#define BUFFER_SIZE 100

void create_file(char *name, char *content) {
    FILE *file = fopen(name, "w");
    if (file != NULL) {
        fprintf(file, "%s", content);
        fclose(file);
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    char content[MAX_CONTENT_LENGTH];

    printf("Simple File System\n");
    printf("1. Create File\n");
    printf("2. Exit\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter file name: ");
        scanf("%s", name);
        printf("Enter file content: ");
        scanf("%s", content);

        create_file(name, content);
    }

    return 0;
}
