//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLASSES 10
#define MAX_CLASS_NAME_LENGTH 20

struct Class {
    char name[MAX_CLASS_NAME_LENGTH];
    int count;
};

void train(char *filename, int num_classes, struct Class *classes) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, " \t\n\r\f\v");
        if (token == NULL)
            continue;

        int class_idx = -1;
        for (int i = 0; i < num_classes; i++) {
            if (strcmp(classes[i].name, token) == 0) {
                class_idx = i;
                break;
            }
        }

        if (class_idx == -1) {
            printf("Error: unknown class '%s'\n", token);
            exit(1);
        }

        classes[class_idx].count++;
    }

    fclose(fp);
}

void classify(char *filename, int num_classes, struct Class *classes) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, " \t\n\r\f\v");
        if (token == NULL)
            continue;

        int max_count = 0;
        int max_idx = -1;
        for (int i = 0; i < num_classes; i++) {
            if (strcmp(classes[i].name, token) == 0) {
                if (classes[i].count > max_count) {
                    max_count = classes[i].count;
                    max_idx = i;
                }
            }
        }

        if (max_idx == -1) {
            printf("Error: unknown class '%s'\n", token);
            exit(1);
        }

        printf("%s\n", classes[max_idx].name);
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s train <train_file> <num_classes> <class1_name>...\n", argv[0]);
        printf("        %s classify <classify_file>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "train") == 0) {
        int num_classes = argc - 3;
        struct Class classes[MAX_CLASSES];
        memset(classes, 0, sizeof(classes));

        for (int i = 0; i < num_classes; i++) {
            strncpy(classes[i].name, argv[i + 3], MAX_CLASS_NAME_LENGTH);
            classes[i].name[MAX_CLASS_NAME_LENGTH - 1] = '\0';
        }

        train(argv[2], num_classes, classes);
    } else if (strcmp(argv[1], "classify") == 0) {
        classify(argv[2], argc - 3, argv + 3);
    } else {
        printf("Error: invalid command\n");
        return 1;
    }

    return 0;
}