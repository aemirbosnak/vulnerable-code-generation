//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_SIZE 1024
#define MAX_NUM_STRUCTS 10

typedef struct {
    char name[MAX_STRING_SIZE];
    int age;
} Person;

typedef struct {
    char title[MAX_STRING_SIZE];
    Person employees[MAX_NUM_STRUCTS];
} Department;

void extract_metadata(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Error opening file.");
        return;
    }

    char line[MAX_STRING_SIZE];
    char token[MAX_STRING_SIZE];
    int line_num = 1;

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%s %s", token, token + strlen(token) + 1);

        if (strcmp(token, "typedef") == 0) {
            size_t name_len = strlen(token) + strlen(token + strlen(token) + 1);
            char name[name_len];
            strncpy(name, token, name_len - 1);
            name[name_len - 1] = '\0';

            fgets(line, sizeof(line), file);
            sscanf(line, "%s %s", token, token + strlen(token) + 1);

            printf("Metadata: typedef %s %s\n", name, token);
        } else if (strcmp(token, "struct") == 0 || strcmp(token, "union") == 0) {
            size_t name_len = strlen(token) + strlen(token + strlen(token) + 1);
            char name[name_len];
            strncpy(name, token, name_len - 1);
            name[name_len - 1] = '\0';

            Department department;
            strcpy(department.title, name);

            fgets(line, sizeof(line), file);
            sscanf(line, "%s", token);
            int num_fields = atoi(token);

            for (int i = 0; i < num_fields; i++) {
                fgets(line, sizeof(line), file);
                sscanf(line, "%s %s", token, token + strlen(token) + 1);

                size_t field_name_len = strlen(token) + strlen(token + strlen(token) + 1);
                char field_name[field_name_len];
                strncpy(field_name, token, field_name_len - 1);
                field_name[field_name_len - 1] = '\0';

                fgets(line, sizeof(line), file);
                sscanf(line, "%s", token);
                int field_type_size = atoi(token);

                printf("Metadata: %s %s %d\n", name, field_name, field_type_size);
            }

            fgets(line, sizeof(line), file); // consume newline character
        }

        line_num++;
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    extract_metadata(argv[1]);
    return 0;
}