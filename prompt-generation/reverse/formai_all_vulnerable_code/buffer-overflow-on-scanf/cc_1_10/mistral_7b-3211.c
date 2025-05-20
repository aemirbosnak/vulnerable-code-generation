//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 50
#define MAX_NAME_LEN 20
#define MAX_CONTENT_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char content[MAX_CONTENT_LEN];
    int is_file;
} File;

File files[MAX_FILES];
int num_files = 0;

void create_file(char *name) {
    if (num_files >= MAX_FILES) {
        printf("Error: Max number of files reached.\n");
        return;
    }
    strcpy(files[num_files].name, name);
    files[num_files].is_file = 1;
    num_files++;
}

void delete_file(char *name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memmove(&files[i], &files[i+1], sizeof(File) * (num_files - i - 1));
            num_files--;
            break;
        }
    }
}

void write_file(char *name, char *data) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0 && files[i].is_file) {
            strcpy(files[i].content, data);
            break;
        }
    }
}

char *read_file(char *name, int *len) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0 && files[i].is_file) {
            *len = strlen(files[i].content);
            return strdup(files[i].content);
        }
    }
    *len = 0;
    return NULL;
}

int main() {
    char cmd[50], name[MAX_NAME_LEN], data[MAX_CONTENT_LEN], *content;
    int len;

    while (1) {
        printf(">> ");
        scanf("%s", cmd);

        if (strcmp(cmd, "create") == 0) {
            scanf("%s", name);
            create_file(name);
            printf("File %s created.\n", name);
        }

        else if (strcmp(cmd, "delete") == 0) {
            scanf("%s", name);
            delete_file(name);
            printf("File %s deleted.\n", name);
        }

        else if (strcmp(cmd, "write") == 0) {
            scanf("%s", name);
            scanf("%s", data);
            write_file(name, data);
            printf("File %s written.\n", name);
        }

        else if (strcmp(cmd, "read") == 0) {
            scanf("%s", name);
            content = read_file(name, &len);
            if (content != NULL) {
                printf("File %s contents:\n%s\n", name, content);
                free(content);
            } else {
                printf("Error: File %s not found.\n", name);
            }
        }

        else if (strcmp(cmd, "exit") == 0) {
            break;
        }

        else {
            printf("Error: Invalid command.\n");
        }
    }

    return 0;
}